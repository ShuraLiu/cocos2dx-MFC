
// sceneEditorView.h : CsceneEditorView ��Ľӿ�
//

#pragma once
#include "AppDelegate.h"


class CsceneEditorView : public CView
{
protected: // �������л�����
	CsceneEditorView();
	DECLARE_DYNCREATE(CsceneEditorView)

// ����
public:
	CsceneEditorDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CsceneEditorView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	virtual void OnInitialUpdate();

	AppDelegate m_app;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
};

#ifndef _DEBUG  // sceneEditorView.cpp �еĵ��԰汾
inline CsceneEditorDoc* CsceneEditorView::GetDocument() const
   { return reinterpret_cast<CsceneEditorDoc*>(m_pDocument); }
#endif

