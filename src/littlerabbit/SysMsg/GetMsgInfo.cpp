#include "StdAfx.h"
#include "GetMsgInfo.h"
#include <stdio.h>
#include <windows.h>
#include <iostream>
#include "CpuMsg.h"

using namespace std;

void SetPCMsg(PCMsg *msg,int id,char* tpye,char* name,char* val)
{
	msg->msgID = id;
	sprintf(msg->msgName,name);
	sprintf(msg->msgType,tpye);
	sprintf(msg->msgVal,val);
}

GetMsgInfo::GetMsgInfo(void)
{
	
}


GetMsgInfo::~GetMsgInfo(void)
{
	
}

void GetMsgInfo::GetComputerMsg()
{
	msgVec.clear();
	GetCpuType();
	GetMemMsg();
}

void GetMsgInfo::GetCpuType()
{
	{
		PCMsg msg = {"","","",-1};
		char cc1[20];
		sprintf(cc1,"%d",GetCPUFreq());
		SetPCMsg(&msg,1,"CPU","CPU �� Ƶ",cc1);
		msgVec.push_back(msg);
	}
	{
		PCMsg msg = {"","","",-1};
		char cc[50];
		GetManID(cc,sizeof(cc));
		SetPCMsg(&msg,2,"CPU","CPU ������",cc);
		msgVec.push_back(msg);
	}
	{
		PCMsg msg = {"","","",-1};
		char cc[50];
		GetCpuTypeMsg(cc,sizeof(cc));
		SetPCMsg(&msg,3,"CPU","CPU �� ��",cc);
		msgVec.push_back(msg);
	}
}

void GetMsgInfo::GetMemMsg()
{
	MEMORYSTATUS memory;
	memory.dwLength =sizeof(memory); //��ʼ��
	GlobalMemoryStatus(&memory);
	{
		PCMsg msg = {"","","",-1};
		char cc1[20];
		sprintf(cc1,"%d",(int)(memory.dwTotalPhys /1024/1024));
		SetPCMsg(&msg,4,"Mem","�����ڴ���(Mb)",cc1);
		msgVec.push_back(msg);
	}
	{
		PCMsg msg = {"","","",-1};
		char cc1[20];
		sprintf(cc1,"%d",(int)(memory.dwAvailPhys /1024/1024));
		SetPCMsg(&msg,5,"Mem","�����ڴ���(Mb)",cc1);
		msgVec.push_back(msg);
	}
}
