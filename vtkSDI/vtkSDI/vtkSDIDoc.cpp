
// vtkSDIDoc.cpp : implementation of the CvtkSDIDoc class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "vtkSDI.h"
#endif

#include "vtkSDIDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CvtkSDIDoc

IMPLEMENT_DYNCREATE(CvtkSDIDoc, CDocument)

BEGIN_MESSAGE_MAP(CvtkSDIDoc, CDocument)
	ON_COMMAND(ID_FILE_OPEN, &CvtkSDIDoc::OnFileOpen)
END_MESSAGE_MAP()


// CvtkSDIDoc construction/destruction

CvtkSDIDoc::CvtkSDIDoc()
{
	// TODO: add one-time construction code here
	m_vtkImageData = vtkSmartPointer<vtkImageData>::New();
	m_vtkImageData = NULL;
}

CvtkSDIDoc::~CvtkSDIDoc()
{
}

BOOL CvtkSDIDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// CvtkSDIDoc serialization

void CvtkSDIDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CvtkSDIDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modify this code to draw the document's data
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Support for Search Handlers
void CvtkSDIDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data. 
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CvtkSDIDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CvtkSDIDoc diagnostics

#ifdef _DEBUG
void CvtkSDIDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CvtkSDIDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CvtkSDIDoc commands


void CvtkSDIDoc::OnFileOpen()
{
	CFileDialog dlg(TRUE);
	if (IDOK == dlg.DoModal())
	{
		CString szFilePath = dlg.GetPathName();
		vtkSmartPointer<vtkBMPReader> reader = vtkSmartPointer<vtkBMPReader>::New();
		int iCount = WideCharToMultiByte(CP_ACP, NULL, szFilePath, -1, NULL, NULL, 0, NULL);
		char* c = new char[iCount];
		WideCharToMultiByte(CP_ACP, NULL, szFilePath, -1, c, iCount, 0, NULL);
		reader->SetFileName(c);
		m_vtkImageData = reader->GetOutput();
		delete[] c;
	}
}
