#include <stdio.h>
#include "GetMsgInfo.h"
#include "windows.h" 
#include "iostream"
#include "string"

using namespace std;

//�����洢��Ϣ
DWORD deax;
DWORD debx;
DWORD decx;
DWORD dedx;

void ExeCPUID(DWORD veax)//��ʼ��CPU
{
	__asm
	{
		mov eax,veax
			cpuid
			mov deax,eax
			mov debx,ebx
			mov decx,ecx
			mov dedx,edx
	}
}

long GetCPUFreq()//��ȡCPUƵ��,��λ: MHZ
{
	int start1,start2;
	_asm rdtsc
	_asm mov start1,eax
	Sleep(50);
	_asm rdtsc
	_asm mov start2,eax
	return (start2-start1)/50000;
}

string GetManID()//��ȡ��������Ϣ
{
	char ID[25];//�洢��������Ϣ
	memset(ID,0,sizeof(ID));//��������� ID
	ExeCPUID(0);//��ʼ��
	memcpy(ID+0,&debx,4);//��������Ϣǰ�ĸ��ַ����Ƶ�����
	memcpy(ID+4,&dedx,4);//�м��ĸ�
	memcpy(ID+8,&decx,4);//����ĸ�
	//������� char * ,���������;�ʷ��� string ֵ
	return string(ID);
}

string GetCPUType()
{
	const DWORD id = 0x80000002; //��0x80000002��ʼ,��0x80000004����
	char CPUType[49];//�����洢CPU�ͺ���Ϣ
	memset(CPUType,0,sizeof(CPUType));//��ʼ������

	for(DWORD t = 0 ; t < 3 ; t++ )
	{
		ExeCPUID(id+t);
		//ÿ��ѭ������,������Ϣ������
		memcpy(CPUType+16*t+ 0,&deax,4);
		memcpy(CPUType+16*t+ 4,&debx,4);
		memcpy(CPUType+16*t+ 8,&decx,4);
		memcpy(CPUType+16*t+12,&dedx,4);
	}

	return string(CPUType);
}

void main()
{

	printf("hello\n");

	GetMsgInfo *msg = new GetMsgInfo();
	msg->Test();
	delete msg;
	cout<<"����CPU��Ϣ����:"<<endl;
	cout<<"CPU �� Ƶ: "<<GetCPUFreq()<<" MHZ"<<endl;
	cout<<"CPU ������: "<<GetManID()<<endl;
	cout<<"CPU �� ��: "<<GetCPUType()<<endl;
	getchar();
}