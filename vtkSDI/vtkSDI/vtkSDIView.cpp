
// vtkSDIView.cpp : implementation of the CvtkSDIView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "vtkSDI.h"
#endif

#include "vtkSDIDoc.h"
#include "vtkSDIView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CvtkSDIView

IMPLEMENT_DYNCREATE(CvtkSDIView, CView)

BEGIN_MESSAGE_MAP(CvtkSDIView, CView)
	ON_WM_CREATE()
	ON_WM_SIZE()
END_MESSAGE_MAP()

// CvtkSDIView construction/destruction

CvtkSDIView::CvtkSDIView()
{
	// TODO: add construction code here

}

CvtkSDIView::~CvtkSDIView()
{
}

BOOL CvtkSDIView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CvtkSDIView drawing

void CvtkSDIView::OnDraw(CDC* /*pDC*/)
{
	CvtkSDIDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
// 	m_vtkImageViewer->SetInputData(pDoc->m_vtkImageData);
// 	m_vtkImageViewer->Render();
}


// CvtkSDIView diagnostics

#ifdef _DEBUG
void CvtkSDIView::AssertValid() const
{
	CView::AssertValid();
}

void CvtkSDIView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CvtkSDIDoc* CvtkSDIView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CvtkSDIDoc)));
	return (CvtkSDIDoc*)m_pDocument;
}
#endif //_DEBUG


// CvtkSDIView message handlers


int CvtkSDIView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here
	m_vtkImageViewer = vtkSmartPointer<vtkImageViewer2>::New();
	m_vtkImageViewer->SetParentId(CWnd::GetSafeHwnd());
	m_vtkRenderWindowInteractor = vtkSmartPointer<vtkRenderWindowInteractor>::New();
	m_vtkImageViewer->SetupInteractor(m_vtkRenderWindowInteractor);
	m_vtkRenderWindowInteractor->Start();

	return 0;
}


void CvtkSDIView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here
	/*CRect rc;
	CWnd::GetClientRect(rc);
	m_vtkImageViewer->SetSize(rc.Width(), rc.Height());*/
}
