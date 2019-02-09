# UAC

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

코드는 이와 같다고 한다.

하지만 특정 방법을 사용하면 사용자에게 들키지 않고 몰래 권한 상승이 가능하다.

UAC Bypass라는 이름을 가진 기술이다.

UAC Bypass를 사용한 대표적인 악성코드는 WannaCry가 있다.

또한 윈도우즈 시스템 프로세스는 자체적으로 보안 인증을 통해 UAC Bypass를 지원하고 있으며 이 프로세스에 취약점이 발견될 경우 이를 통해 악성코드가 더 크리티컬한 공격을 감행할 수 있을 것이다.

워너크라이같은 악성코드도 관리자권한을 획득하여 작동하였는데 권한을 얻는 소스가 있었다.

일단 uac창이 안뜨면서 권한 올리는 법을 찾아보는중이다
