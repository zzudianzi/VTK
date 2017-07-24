#pragma once

#include "vtk.h"

class CvtkView : public CStatic
{
public:
	void SetImageData(vtkImageData* imageData);

	virtual void PreSubclassWindow();
	afx_msg void OnPaint();

	DECLARE_MESSAGE_MAP()

private:
	vtkSmartPointer<vtkRenderer> m_vtkRenderer;
	vtkSmartPointer<vtkRenderWindow> m_vtkRenderWindow;
	vtkSmartPointer<vtkRenderWindowInteractor> m_vtkRenderWindowInteractor;
	vtkSmartPointer<vtkImageActor> m_vtkImageActor;
};