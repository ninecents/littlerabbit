#include "CpuMsg.h"
#include "stdafx.h"
#include "windows.h" 
#include "iostream"
#include "string"

using namespace std;
//用来存储信息
DWORD deax;
DWORD debx;
DWORD decx;
DWORD dedx;

void ExeCPUID(DWORD veax)//初始化CPU
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

long GetCPUFreq()//获取CPU频率,单位: MHZ
{
	int start1,start2;
	_asm rdtsc
	_asm mov start1,eax
	Sleep(50);
	_asm rdtsc
	_asm mov start2,eax
	return (start2-start1)/50000;
}

void GetManID(char *ID,int len)//获取制造商信息
{
	//char ID[25];//存储制造商信息
	memset(ID,0,len);//先清空数组 ID
	ExeCPUID(0);//初始化
	memcpy(ID+0,&debx,4);//制造商信息前四个字符复制到数组
	memcpy(ID+4,&dedx,4);//中间四个
	memcpy(ID+8,&decx,4);//最后四个
	//如果返回 char * ,会出现乱码;故返回 string 值
	return;
}

void GetCpuTypeMsg(char *CPUType,int len)
{
	const DWORD id = 0x80000002; //从0x80000002开始,到0x80000004结束
	//char CPUType[49];//用来存储CPU型号信息
	memset(CPUType,0,len);//初始化数组

	for(DWORD t = 0 ; t < 3 ; t++ )
	{
		ExeCPUID(id+t);
		//每次循环结束,保存信息到数组
		memcpy(CPUType+16*t+ 0,&deax,4);
		memcpy(CPUType+16*t+ 4,&debx,4);
		memcpy(CPUType+16*t+ 8,&decx,4);
		memcpy(CPUType+16*t+12,&dedx,4);
	}

	return;
}