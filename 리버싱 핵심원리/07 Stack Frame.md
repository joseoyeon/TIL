# Stack Frame

- ESP가 아닌 EBP를 기준으로 스택에 접근하는 기법

ESP는 스택에 PUSH, POP하면서 계속 바뀌게 된다. 함수를 호출하는 과정을 반복하다보면 스택 관리가 매우 어렵게 된다. 이렇게 된다면 ESP기준으로 어디서부터 어디까지가 지금 함수의 스택영역인지 찾기가 매우 복잡할 것이다.

따라서 ESP가 아닌 EBP를 기준으로 스택에 접근한다.

구체적으로 함수 호출 전 아래와 같은 코드를 사용해 스택에 현재 스택 프레임의 EBP를 저장하고 갱신하여 새 스택 프레임을 만들고 원래 상태로 복귀한다.

    PUSH EBP            //새 스택 프레임 생성
    MOV EBP, ESP

    ...함수 본체

    MOV ESP, EBP
    POP EBP
    RETN                //스택 프레임 끝(?)

요즘 컴파일러는 간단한 함수의 경우는 최적화를 통해 스택 프레임을 생성하지 않는다.

또한 함수 호출 전 복귀 할 명령어 주소(함수 호출 명령 실행 시 EIP 레지스터 값)도 스택에 저장된 후 RETN을 만나면 스택에서 해당 주소를 꺼내 EIP가 갱신되는 식으로 작동하는데 이를 이용하여 Buffer Overflow 공격을 할 수 있다. 간단히 말하면 4비트 공간에 8비트를 때려박아 밑에 깔린 데이터가 덮어씌워지는 원리이다.

## 함수 호출과 매개변수, 스택 프레임

    int main()
    {
        long a = 1, b = 2;
        ADD(a, b);
        return 0;
    }

    PUSH EBP                       //main의 stack frame 생성
    MOV EBP ESP
    SUB ESP 8                      //공간 할당 (a, b가 각각 4bytes)
    MOV DWORD PTR SS:[EBP-4], 1    //a, b 각각 공간에 1, 2를 입력 (Local Variable)
    MOV DWORD PTR SS:[EBP-8], 2
    MOV EAX, DWORD PTR SS:[EBP-8]   //매개변수 2를 EAX에 담아 스택에 PUSH  (Parameter)
    PUSH EAX
    MOV EAX, DWORD PTR SS:[EBP-4]   //매개변수 1을 EAX에 담아 스택에 PUSH  (Parameter)
    PUSH EAX
    CALL ADD
    ADD ESP 8                       //할당된 8바이트 공간 반납
    ...
    XOR EAX, EAX                    //RETURN값이 EAX에 담기므로 EAX에 RETRUN값 담는 과정
    MOV ESP, EBP                    //현재 스택 프레임 해제
    POP EBP
    RETN

이러한 명령어를 통해 ESP를 조작해 스택 프레임 내에 공간을 할당하고 해당 공간에  매개변수를 역순으로 때려박아준다.

XOR EAX, EAX는 XOR명령어의 속도가 MOV보다 빨라서 레지스터의 초기화에 자주 사용된다.


시스템 소프트웨어 수강하여 내용 이해에 많은 도움이 되었다.
