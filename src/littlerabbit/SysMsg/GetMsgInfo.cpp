#include "StdAfx.h"
#include "GetMsgInfo.h"
#include <stdio.h>
#include <windows.h>
#include <iostream>

using namespace std;

GetMsgInfo::GetMsgInfo(void)
{
	printf("GetMsgInfo\n");
}


GetMsgInfo::~GetMsgInfo(void)
{
	printf("~GetMsgInfo\n");
}

void GetMsgInfo::Test()
{
	printf("test\n");
	GetCpuType();
}

void GetMsgInfo::GetCpuType()
{
	//���CPU�ͺ�
    SYSTEM_INFO systemInfo;
	GetSystemInfo (&systemInfo);
	cout << "����������: " << systemInfo.dwActiveProcessorMask << endl
		 << "����������: " << systemInfo.dwNumberOfProcessors << endl
		 << "��������ҳ��С: " << systemInfo.dwPageSize << endl
		 << "����������: " << systemInfo.dwProcessorType << endl
		 << "���Ѱַ��Ԫ: " << systemInfo.lpMaximumApplicationAddress << endl
		 << "��СѰַ��Ԫ: " << systemInfo.lpMinimumApplicationAddress << endl
		 << "�������ȼ�: " << systemInfo.wProcessorLevel << endl
		 << "�������汾: " << systemInfo.wProcessorRevision << endl;
	cout << "---------------------------------------------------"<<endl;

	MEMORYSTATUS memory;
	memory.dwLength =sizeof(memory); //��ʼ��
	GlobalMemoryStatus(&memory);
	cout << "���������ڴ���(Mb):"<<(int)(memory.dwTotalPhys /1024/1024)<<endl;
	cout << "���п����ڴ���(Kb):"<<(int)( memory.dwAvailPhys /1024)<<endl;

}
