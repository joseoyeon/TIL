## 헤더 삽입

```C++

	CRect rect;
	pListCtrl.GetClientRect(&rect);
	pListCtrl.InsertColumn(0, _T("Process Name"), LVCFMT_LEFT, 200);
	pListCtrl.InsertColumn(1, _T("Process ID"), LVCFMT_LEFT, rect.Width() - 200);
```

길이는 알아서..

## 개체 삽입

```C++
		pListCtrl.InsertItem(i, pe32.szExeFile, i);
		pListCtrl.SetItemText(i, 1, pid);
```

먼저 아이템으로 첫번째 식별값(?)을 집어넣고 set itemtext로 옆의 컬럼 채우는 방식인 듯 하다.

## 헤더 클릭 시 정렬

```C++
void CDLLInjecterDlg::OnColumnclickList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int column = pNMLV->iSubItem;

	if (column == m_SortedColumn) {
		m_Ascending = !m_Ascending;
	}
	else {
		m_Ascending = TRUE;
	}

	m_SortedColumn = column;

	int cnt = pListCtrl.GetItemCount();
	CString* str = new CString[cnt];
	for (int i = 0; i < cnt; i++) {
		str[i] = pListCtrl.GetItemText(i, column);
		pListCtrl.SetItemData(i, (DWORD)(LPCTSTR)str[i]);
	}

	pListCtrl.SortItems(CompareFunc, (LPARAM)m_Ascending);

	delete[]str;


	*pResult = 0;
}
```

중요한건 밑쪽에 SortItems라는 멤버함수이다. CompareFunc라는 콜백함수를 등록하고 옆에는 매개변수임

```C++
int CALLBACK CDLLInjecterDlg::CompareFunc(LPARAM lParam1, LPARAM lParam2, LPARAM lParam)
{
	BOOL Ascending = (BOOL)lParam;

	LPCTSTR s1 = (LPCTSTR)(DWORD)lParam1;
	LPCTSTR s2 = (LPCTSTR)(DWORD)lParam2;

	if (Ascending)
		return _tcscmp(s1, s2);
	else
		return -(_tcscmp(s1, s2));

	return 0;
}
```

콜백함수는 이렇게! 근데 숫자에 대해서는 조금 이상하게 작동함

숫자일 경우 따로 구현해도 괜찮지만 귀찮아서 안했다.

## 선택한 값 가져오기

![image](https://user-images.githubusercontent.com/41255291/53474649-04766080-3ab1-11e9-994f-5f63f3be8da9.png)

클래스 마법사에서 처리기 추가

```C++
void CDLLInjecterDlg::OnClickList1(NMHDR *pNMHDR, LRESULT *pResult)
{
		UpdateData();
		LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
		// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
		NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
		m_nSelectedIndex = pNMListView->iItem;
		*pResult = 0;
}
```

이러면 m_nSelectedIndex에 선택한 인덱스가 담긴다.

```C++
void CDLLInjecterDlg::OnBnClickedButton4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData();
	m_strSelectedValue = pListCtrl.GetItemText(m_nSelectedIndex, 1);
	pidEdit.SetWindowTextW(m_strSelectedValue);
	pid = _ttoi(m_strSelectedValue);
}
```

리스트 컨트롤 객체의 GetItemText메소드를 불러서 아까 만든 m_nSelectedIndex를 매개변수로 넣고 1은 컬럼 번호 같은데 이 둘을 매개변수로 넣어주면 된다.