# Thread

TestDlg.h에 쓰레드 함수 선언

```C++
class CTestDlg : public CDialogEx
{
public:
    static UINT CoreFunction(LPVOID _method);                                      
};
```

TestDlg.cpp에 쓰레드 함수 호출

메인 스레드의 메인 다이얼로그의 변수들은 직접 접근 불가능하여 함수 호출로 접근해야함.

TLS가 적용되어 그럴..거임..

```C++
UINT CTestDlg::ThreadFirst(LPVOID _method)
{
    CTestDlg *fir = (CTestDlg*)_method;
 
    //To do

    return 0;
}

```

쓰레드 호출 및 종료 대기

```C++
pThread = AfxBeginThread( MyThread, this,THREAD_PRIORITY_NORMAL, 0, CREATE_SUSPENDED);
::WaitForSingleObject(pThread->m_hThread,INFINITE);
```