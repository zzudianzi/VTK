#include "stdafx.h"
#include "vtkView.h"

BEGIN_MESSAGE_MAP(CvtkView, CStatic)
	ON_WM_PAINT()
END_MESSAGE_MAP()

void CvtkView::PreSubclassWindow()
{
	CRect rc;
	CWnd::GetClientRect(rc);

	m_vtkRenderer = vtkSmartPointer<vtkRenderer>::New();
	m_vtkRenderer->SetBackground(.4, .5, .6);

	m_vtkRenderWindow = vtkSmartPointer<vtkRenderWindow>::New();
	m_vtkRenderWindow->SetParentId(this->m_hWnd);
	m_vtkRenderWindow->SetSize(rc.Width(), rc.Height());
	m_vtkRenderWindow->AddRenderer(m_vtkRenderer);

	m_vtkRenderWindowInteractor = vtkSmartPointer<vtkRenderWindowInteractor>::New();
	vtkSmartPointer<vtkInteractorStyleImage> interactorStyleImage = vtkSmartPointer<vtkInteractorStyleImage>::New();
	m_vtkRenderWindowInteractor->SetInteractorStyle(interactorStyleImage);
	m_vtkRenderWindowInteractor->SetRenderWindow(m_vtkRenderWindow);
	m_vtkRenderWindowInteractor->Initialize();
	m_vtkRenderWindow->Start();

	CStatic::PreSubclassWindow();
}

void CvtkView::OnPaint()
{
	CPaintDC dc(this);
}

void CvtkView::SetImageData(vtkImageData* imageData)
{
	if (imageData == NULL)
		return;

	int dims[3];
	double origin[3];
	double spacing[3];
	imageData->GetDimensions(dims);
	imageData->GetOrigin(origin);
	imageData->GetSpacing(spacing);

	vtkSmartPointer<vtkImageChangeInformation> changer = vtkSmartPointer<vtkImageChangeInformation>::New();
	changer->SetInputData(imageData);
	changer->SetCenterImage(1);
	changer->Update();

	m_vtkImageActor = vtkSmartPointer<vtkImageActor>::New();
	m_vtkImageActor->GetMapper()->SetInputConnection(changer->GetOutputPort());
	m_vtkRenderer->AddActor(m_vtkImageActor);
	m_vtkRenderWindow->Render();
}
