/*=========================================================================

  Program:   Visualization Toolkit
  Module:    vtkTextUnicodeProperty.h

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/

/**********************************************************************

  文件名: vtkTextUnicodeProperty.h
  Copyright (c) 张晓东, 罗火灵. All rights reserved.
  更多信息请访问: 
    http://www.vtkchina.org (VTK中国)
	http://blog.csdn.net/www_doling_net (东灵工作室) 

**********************************************************************/

#ifndef __vtkTextUnicodeProperty_h
#define __vtkTextUnicodeProperty_h

#include <string>
#include "vtkTextProperty.h"

class vtkTextUnicodeProperty :public vtkTextProperty
{
public:
	vtkTypeMacro(vtkTextUnicodeProperty,vtkTextProperty);
	void PrintSelf(ostream& os, vtkIndent indent);
	void SetFontFileName(const char* fontFileName) {m_FontFileName=fontFileName;}
	const char* GetFontFileName(){ return m_FontFileName.c_str();}
	void ShallowCopy(vtkTextUnicodeProperty *tprop);
	static vtkTextUnicodeProperty *New();

protected:
	vtkTextUnicodeProperty(void);
	~vtkTextUnicodeProperty(void);

private:
	std::string m_FontFileName;
};
#endif
