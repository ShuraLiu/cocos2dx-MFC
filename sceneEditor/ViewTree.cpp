
#include "stdafx.h"
#include "ViewTree.h"
#include <string>
#include "HelloWorldScene.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CViewTree

CViewTree::CViewTree()
{
}

CViewTree::~CViewTree()
{
}

BEGIN_MESSAGE_MAP(CViewTree, CTreeCtrl)
	ON_NOTIFY_REFLECT(NM_CLICK, &CViewTree::OnNMClick)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CViewTree ��Ϣ�������

BOOL CViewTree::OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult)
{
	BOOL bRes = CTreeCtrl::OnNotify(wParam, lParam, pResult);

	NMHDR* pNMHDR = (NMHDR*)lParam;
	ASSERT(pNMHDR != NULL);
	if (pNMHDR && pNMHDR->code == TTN_SHOW && GetToolTips() != NULL)
	{
		GetToolTips()->SetWindowPos(&wndTop, -1, -1, -1, -1, SWP_NOMOVE | SWP_NOACTIVATE | SWP_NOSIZE);
	}

	return bRes;
}


void CViewTree::OnNMClick(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CViewTree::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (point != CPoint(-1, -1))
	{
		// ѡ���ѵ�������: 
		CPoint ptTree = point;
		UINT flags = 0;
		HTREEITEM hTreeItem = this->HitTest(ptTree, &flags);
		if (hTreeItem != NULL)
		{
			this->SelectItem(hTreeItem);
			auto cstr = this->GetItemText(hTreeItem);
			CT2A tmp(cstr);
			const char* sss = tmp;
			std::string str(sss);
			str = "select item :" + str;
			TestInstance::getInstance()->setCurrentSelectClassName(str);
		}
	}

	this->SetFocus();
	CTreeCtrl::OnLButtonDown(nFlags, point);
}
