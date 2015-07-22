
// sceneEditorView.cpp : CsceneEditorView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "sceneEditor.h"
#endif

#include "sceneEditorDoc.h"
#include "sceneEditorView.h"
#include "MFCGLView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CsceneEditorView

IMPLEMENT_DYNCREATE(CsceneEditorView, CView)

BEGIN_MESSAGE_MAP(CsceneEditorView, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_TIMER()
	ON_WM_SIZE()
END_MESSAGE_MAP()

// CsceneEditorView ����/����

CsceneEditorView::CsceneEditorView()
{
	// TODO:  �ڴ˴���ӹ������

}

CsceneEditorView::~CsceneEditorView()
{
}

BOOL CsceneEditorView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CsceneEditorView ����

void CsceneEditorView::OnDraw(CDC* /*pDC*/)
{
	CsceneEditorDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}

void CsceneEditorView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CsceneEditorView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CsceneEditorView ���

#ifdef _DEBUG
void CsceneEditorView::AssertValid() const
{
	CView::AssertValid();
}

void CsceneEditorView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CsceneEditorDoc* CsceneEditorView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CsceneEditorDoc)));
	return (CsceneEditorDoc*)m_pDocument;
}
#endif //_DEBUG


// CsceneEditorView ��Ϣ�������


void CsceneEditorView::OnInitialUpdate()
{
	CView::OnInitialUpdate();
	RECT rc;
	::GetClientRect(m_hWnd, &rc);
	m_app.init(m_hWnd, rc.right - rc.left, rc.bottom - rc.top);
	SetTimer(1, 15, NULL);
	// TODO:  �ڴ����ר�ô����/����û���
}



void CsceneEditorView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	m_app.run();
	CView::OnTimer(nIDEvent);
}


void CsceneEditorView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);
	m_app.onSize(cx, cy);
	// TODO:  �ڴ˴������Ϣ����������
}


LRESULT CsceneEditorView::WindowProc(UINT message, WPARAM wParam, LPARAM lParam)
{
	// TODO:  �ڴ����ר�ô����/����û���
	m_app.WindowProc(message, wParam, lParam);
	return CView::WindowProc(message, wParam, lParam);
}
