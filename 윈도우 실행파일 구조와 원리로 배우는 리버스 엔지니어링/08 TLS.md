# TLS

책에서는 TLS, 보안, 리소스 등등 부가적인 내용 더 하는데 당장은 TMI일 부분으로 판단되어 TLS만 다루고 넘어갔음.

TLS는 Thread Local Storage의 약자이다.

TLS는 각각의 쓰레드에만 한정되는 전역변수라고 보면 된다.

MFC로 모듈 제작할 때 생성한 쓰레드로 메인 모달창의 객체를 컨트롤 하려면 무조건 메인 모달창의 포인터를 받아와서 조작해야 했는데 모달창에서 쓰던 전역변수가 TLS로 선언되어있어서 그런 것 같다.

TLS는 정적 TLS와 동적 TLS로 나뉜다.

동적 TLS는 명시적 DLL로드처럼 명령어를 통해 TLS 할당받고 막 그래서 상당히 귀찮다

```C++
DWORD g_dwTlsIncIdx;

int main()
{
    g_dwTlsIncIdx = TLSAlloc();    //빈TLS 슬롯 예약
    ...
    arhWorker = CreateThread(NULL, 0, ThreadProc, 1, 0, &dwThrId);
    ...
    TlsFree(g_dwTlsIncIdx); //TLS 슬롯 해제
}

DWORD WINAPI ThreadProc(PVOID lParam)
{
    int nVal = (int)lParam;
    PINT pnInc = new int(500);
    TlsSetValue(g_dwTlsIncIdx, pnInc); //TLS 슬롯에 실제 데이터 있는 곳의 주소 설정
    ...
    pnInc = (PINT)TlsGetValue(g_dwTlsIncIdx);   //TLS 슬롯에서 저장된 포인터 읽기
    ...
}
```

근데 TLS는 그림을 봐도 도대체 무슨 구조인지 감이 안온다.

~~특히 슬롯 예약을 왜 하는지 모르겠음. 같은 슬롯 번호를 사용해도 쓰레드마다 개별적인 값을 담을 수 있다는데~~

그냥 쓰는 전역변수랑 다르게 생각해야 하는것 같음

쓰레드의 전역변수는 그냥 저렇게 쓰는가 보다.

코드를 보면 알겠지만 실제 쓰레드별 전역변수(?)자체는 힙공간에 할당되며 해당 공간의 포인터를 이용해 접근한다.

저 코드는 인덱스를 1개만 받았지만 인덱스를 3개를 받으면 전역변수를 3개를 쓸 수 있고 1번 슬롯 2번 슬롯 3번슬롯마다 원하는 변수로 사용할 수 있다.

![image](https://user-images.githubusercontent.com/41255291/51363525-c71acc80-1b1b-11e9-9af9-59963387d803.png)

_출처 : https://msdn.microsoft.com/en-us/library/ms686749(v=vs.85).aspx_

동적 TLS는 위 코드처럼 변수 쓰기가 참 귀찮다.

하지만 동적 TLS는 정말 편하다.

```C++
__declspec(thread) int gt_dwInc = 500;
```

이렇게 변수 앞에 지시어 하나 추가한 다음 그냥 전역변수 쓰는 것 처럼 쓰면 끝이다.

과거에는 어떠한 문제가 있어 정적 TLS에 제약이 많았다고 하지만 지금은 말끔히 해소되었다고 한다.

하지만 정적TLS는 명시적 DLL 로딩에서는 작동하지 않는다고 한다.

따라서 정적 TLS를 사용하는 DLL은 반드시 암시적 DLL 로딩을 해야한다.

TLS를 저렇게 만들면 .tls라는 TLS섹션이 생긴다.

TLS 섹션에는 아래 코드와 같이 TLS로 선언한 변수를 가지고 있다.

```C++
__declspec(thread) int gt_dwInc = 500;
```

다른거는 TMI라서 쫌 넘어갔고 뒤에서도 다뤄서 쫌 넘어갔는데

중요한건 각 쓰레드가 .tls 섹션의 데이터를 직접 조작하는게 아니라 단지 정적TLS의 초기화를 위한 참고만 한다는 점이다.