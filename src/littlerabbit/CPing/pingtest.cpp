// PingSock.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include<iostream>  
//#include <stdio.h>
#include <WinSock2.h>
#pragma comment(lib,"ws2_32.lib")
#include <Windows.h>

#define LEN 1024    //�������ݵĴ�С  
using namespace std;  

int main()
{
//�����׽��ֿ�  
    WORD wVersionRequested;  
    WSADATA wsaData;  
    int err;  
      
    wVersionRequested = MAKEWORD( 1, 1 );    //��ʼ��Socket��̬���ӿ�,����1.1�汾��winsocket��  
      
    err = WSAStartup( wVersionRequested, &wsaData );  
    if ( err != 0 ) {  
        return 0;  
    }  
  
    if ( LOBYTE( wsaData.wVersion ) != 1 ||   //�ж������winsocket�ǲ���1.1�İ汾  
        HIBYTE( wsaData.wVersion ) != 1 ) {  
        WSACleanup( );          //����  
        return 0;                   //��ֹ��winsocketʹ��  
    }  
    //WSADATA ws;  
    //WSAStartup(MAKEWORD(2,2),&ws);//  
    char http[60] = "www.baidu.com";           //���ʹȸ���ҳ  
    SOCKET sock = socket(AF_INET,SOCK_STREAM,0);//����socket  
    if (sock == INVALID_SOCKET)  
    {  
        cout<<"��������socket�׽���ʧ��!"<<endl;  
        return 0;  
    }  
    sockaddr_in hostadd;  
    hostent* host = gethostbyname(http);//ȡ��������IP��ַ  
    if(host==NULL)  
    {  
        cout<<"��������û������״̬;"<<endl;  
        return 0;  
    }  
    cout<<"������������״̬�����ڿ��Խ���ͨ��!"<<endl;  
    memcpy(&hostadd,host->h_addr,sizeof(hostadd));//�����ص�IP��ϢCopy����ַ�ṹ  
    hostadd.sin_family = AF_INET;  
    hostadd.sin_port = htons(80);  
      
      
    char buf[LEN]="GET / HTTP/1.1\r\nHost: ";//����Http�������ݰ�  
    strcat(buf,inet_ntoa(hostadd.sin_addr));  
    strcat(buf," \r\nContent-Length: 10\r\n\r\n");  
    strcat(buf,"Connection:close");  
      
      
    int time = 1000;    //��ʱʱ��  
    setsockopt(sock,SOL_SOCKET,SO_RCVTIMEO,(char*)&time,sizeof(time));  
      
      
    if (connect(sock,(sockaddr*)&hostadd,sizeof(hostadd)) == SOCKET_ERROR)//��������  
    {  
        cout<<"����ҳ��������ʧ��!"<<endl;  
        return 0;  
    }  
    if (SOCKET_ERROR == send(sock,buf,strlen(buf)+1,0))//���͹���õ�Http�����  
    {  
        cout<<"�������ݰ�ʧ��!"<<endl;  
        return 0;  
    }  
    memset(buf,0,LEN);  
    recv(sock,buf,LEN,0);               //���շ��ص�����  
    cout<<"����ҳ�л�ȡ������Ϊ:"<<buf;  
    closesocket(sock);  
    WSACleanup();  
     getchar();
    return 0;
}
