# ETW

Event Tracing for Windows의 약자

Windows 2000이상 버전 에서 제공하는 세션 이벤트 추적 기능이다. 커널 또는 응용프로그램 정의 이벤트를 로그 파일에 로그할 수 있는 커널레벨 추적 기능이다.

Application 디버깅 및 퍼포먼스 분석에 이용할 수 있으며 C, C++ 개발자를 위하여 설계되었다.


![ETW](https://docs.microsoft.com/en-us/windows/desktop/etw/images/etdiag2.png)


ETW는 위 Dialog과 같이 3개의 컴포넌트가 존재한다.

Controller : Provider를 enable하며 event tracing session을 시작하고 멈춘다.
로그 파일의 크기와 장소 등을 정의할 수 있다. 

Provider : event를 제공한다.

Consumers : event를 소모한다.


참고사이트

https://docs.microsoft.com/en-us/windows/desktop/etw/event-tracing-portal

https://docs.microsoft.com/en-us/windows/desktop/etw/about-event-tracing

