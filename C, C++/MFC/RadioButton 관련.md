### 그룹 지정 방법
1. 리소스 뷰에서 그룹지을 버튼 위치시키기
2. 제일 앞 버튼만 Group을 True로 변경, 나머지는 False여야함
3. 그룹지을 버튼의 탭순서를 연속되게 지정 (Ctrl + D 누르면 탭순서 나옴, 마우스로 클릭하는 순서대로 지정된다.)

### 선택된 버튼 확인
1. Ctrl + shift + X 눌러서 클래스 마법사 띄우기
2. 클래스 이름에서 mainDlg 선택 후 멤버변수탭으로 이동
3. IDC_RADIO1 이런거 더블클릭해서 변수 추가
4. 범주는 값, 이름은 알아서 주고 확인
5. Dlg.h에 4. 에서 정한 이름의 int 자료형이 생성되어있음.
6. UpdateData(true) 명령어 삽입
7. 이제 4.에서 정한 변수가 0부터 시작하는 값을 가짐. 0이면 첫번째, 1이면 두번째 이런식

### RadioBtn 체크하기

	((CButton*)GetDlgItem (IDC_RADIO1))->SetCheck(0);   //체크 해제
	((CButton*)GetDlgItem (IDC_RADIO1))->SetCheck(1);   //체크