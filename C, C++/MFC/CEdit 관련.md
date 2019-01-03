### SetSel함수 이용
    SetSel(시작 위치, 끝 위치.....)

### 커서 맨 끝으로

	CEdit.SetSel(-1, -1);

### 커서 임의 위치

	CEdit.SetSel(n, n);

### 커서 맨 앞으로

	CEdit.SetSel(0, 0);
### 커서 전체 선택

	CEdit.SetSel(0, -1);

### Ctrl + A 활성화
1. 클래스 뷰에서 MainDlg 우클릭, 속성
2. 재정의 버튼 클릭(번개 버튼 오른쪽)
3. PreTranslateMessage 오른쪽 빈칸 클릭
4. 콤보 박스 내려서 ADD 어쩌구 클릭
5. 아래 코드 삽입

<pre><code>if (pMsg->hwnd == CEdit)
	if (::GetKeyState(VK_CONTROL) < 0 && pMsg->wParam == 65)
		CEdit.SetSel(0, -1);
</code></pre>
우선 현재 핸들이 CEdit인지 확인하고 CTRL키가 눌린 상태에서 A키가 65번인가보다

그래서 두개가 눌린 경우 커서를 저렇게 해서 전체 선택이 되도록 할 수 있다.
키 조합은 저런식으로 처리할 수 있나보다.

### ESC, Enter 누를 시 종료 방지
	if ((pMsg->wParam == VK_ESCAPE) || (pMsg->wParam == VK_RETURN))
		return true;
위 코드를 PreTranslateMessage에 삽입