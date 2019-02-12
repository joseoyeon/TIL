# ASLR

Address Space Layout Randomization

Kernel 6(Windows Vista)부터 지원하는 기능이다.

PE파일이 메모리에 로딩될 때 로딩되는 시작 주소값을 랜덤하게 바꾸는 것.

프로세스의 스택, 힙의 시작주소도 랜덤하게 바뀐다. 보안성을 높이기 위해서 사용한다.

특정 익스플로잇을 대상으로 하는 공격의 소스코드는 메모리상의 특정 주소가 하드코딩되어있다.

기존 OS에서는 정해진 위치에만 로딩되는 것을 노린 공격이다.

# Session in Kernel 6

세션은 간단히 말해 로그온 사용자 환경을 의미한다.

Windows 버전이 올라오면서 XP시절 사용자가 1명이면 1개이던 세션이 지금은 사용자가 1명이라도 2개의 세션이 존재한다.

시스템 세션은 Session 0으로 정해져있고 사용자 세션이 Session 1부터 시작한다.

이런식으로 시스템 세션과 사용자 세션을 분리시켜 상호작용을 없애는 방식을 통해 보안성을 강화하였다.

하지만 세션이 분리되어있어도 완전한 분리가 된것은 아니기 때문에 Debug API등은 제대로 작동한다.

# DLL injection in Kernel 6

시스템 세션에서 돌아가는 프로세스에 대해서는 DLL Injection이 실패한다.

디버깅을 해보면 CreateRemoteThread()에서 GetLastError로 ERROR_NOT_ENOUGH_MEMORY(8)이 찍힌다고 함.

XP시절에는 Kernel32!CreateRemoteThread()에서 ntdll!ZwCreateThread()를 호출하는 구조였지만 Win7에서는 두 함수 사이에 KernelBase!CreateThreadEx()라는 함수가 추가되었다.

해당 함수에서 CreateRemoteThread는 성공하지만 내부적으로 CreateSuspend라는 파라미터가 False냐 True냐에 따라서 생성은 되었지만 Resume이 되느냐 안되느냐에 차이가 있다고 한다.

CreateRemoteThread()대신 내부에서 호출되는 ZwCreateThread()를 직접 호출하게 되면 DLL Injection이 성공한다고 한다.

윈도우 7기준이며 10에서는 시간관계상 테스트해보지못하였음.