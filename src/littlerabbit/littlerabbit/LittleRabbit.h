// LittleRabbit.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CLittleRabbitApp:
// �йش����ʵ�֣������ LittleRabbit.cpp
//

class CLittleRabbitApp : public CWinApp
{
public:
	CLittleRabbitApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CLittleRabbitApp theApp;