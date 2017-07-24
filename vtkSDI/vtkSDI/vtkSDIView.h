
// vtkSDIView.h : interface of the CvtkSDIView class
//

#pragma once

#include "vtk.h"

class CvtkSDIView : public CView
{
protected: // create from serialization only
	CvtkSDIView();
	DECLARE_DYNCREATE(CvtkSDIView)

// Attributes
public:
	CvtkSDIDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~CvtkSDIView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

private:
	vtkSmartPointer<vtkImageViewer2> m_vtkImageViewer;
	vtkSmartPointer<vtkRenderWindowInteractor> m_vtkRenderWindowInteractor;
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
};

#ifndef _DEBUG  // debug version in vtkSDIView.cpp
inline CvtkSDIDoc* CvtkSDIView::GetDocument() const
   { return reinterpret_cast<CvtkSDIDoc*>(m_pDocument); }
#endif

