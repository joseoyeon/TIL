# Function Convention

- cdcel
- stdcall
- fastcall

함수 호출 규약은 위와 같이 3가지가 있다. Caller는 함수를 호출한 쪽을 말하고 Callee는 호출을 당한 함수를 말한다.
## cdcel
cdcel은 주로 C언어 방식에서 사용된다. Caller가 스택을 정리하는 특징을 가지고 있다.

    PUSH 2          //매개변수를 Stack에 PUSH
    PUSH 1
    CALL 00401000   //함수 호출
    ADD ESP, 8      //호출한 함수 RETN 후 스택에 정리 (1, 2가 들어있던 8바이트 공간)

위 코드와 같이 Caller가 스택을 정리한다. 단순히 ESP를 ADD하는 방식으로 정리하며 원래 있던 데이터를 0과 같은 값으로 채우지 않는다.

왜냐하면 어차피 덮어 쓸 것이라 CPU 사이클 낭비가 일어나게 된다.

## stdcall
stdcall 방식은 Win32 API에서 사용되며 Callee가 스택을 정리한다. C언어에서 stdcall 방식을 사용하고 싶다면 함수 이름 앞에 _stdcall 키워드를 붙여주면 된다.

    int _stdcall add(int a, int b)

    PUSH EBP                        //Stack Frame 생성
    MOV EBP, ESP
    MOV EAX, DWORD PTR SS:[EBP+8]   
    ADD EAX, DWORD PTR SS:[EBP+C]
    POP EBP
    RETN 8                          //Stack 정리

RETN 8은 RETN + POP 8Byte라는 의미이다. 즉 Callee가 add함수 내부에서 스택을 정리하는 방식이다. Win32 API에서 이러한 방식을 이용하는 이유는 C이외에 다른 언어가 Win32 API를 호출할 경우 호환성을 좋게 하기 위함이다.

## Fastcall
stdcall 방식과 동일하지만 매개변수 2개 까지는 스택이 아닌 레지스터(ECX, EDX)를 이용하여 매개변수를 전달한다. 스택은 메모리를 참조해야 하지만 CPU에 내장된 레지스터를 이용하기 때문에 속도가 빠르다. 하지만 오히려 레지스터를 이용해야 하기 때문에 해당 레지스터를 관리해줘야 하는 오버헤드가 발생할 수 있다. 예를 들어 함수 내부에서 ECX, EDX레지스터를 이용할 경우 이를 어딘가에 백업을 해둬야 한다.