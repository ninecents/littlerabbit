#pragma once
#include "windows.h" 
#include "iostream"
#include "string"


void ExeCPUID(DWORD veax);//��ʼ��CPU
long GetCPUFreq();//��ȡCPUƵ��,��λ: MHZ
void GetManID(char *ID,int len);//��ȡ��������Ϣ
void GetCpuTypeMsg(char *CPUType,int len);