#include<iostream>
#include<stdlib.h>
#include<Windows.h>
#pragma comment(lib,"ws2_32.lib")

using namespace std;

int main()
{
    WSADATA wsaData;
    SOCKET SerSock{}, CliSock{};
    WORD wV = MAKEWORD(2,1);//主版本，辅版本
    sockaddr_in SerAddr{}, CliAddr{};

    //初始化网络库
    if(WSAStartup(wV,&wsaData) == -1)
    {
        printf("Error(WSAStartup) ErrorNumber(%d)\r\n",WSAGetLastError());
        WSACleanup();
        return -1;
    }
    //创建socket
    if((SerSock = socket(AF_INET,SOCK_STREAM,0)) == -1)
    {
        printf("socket ErrorNumber(%d)\r\n",WSAGetLastError());
        WSACleanup();
        return -1;
    }
    //
    SerAddr.sin_family = AF_INET;
    //SerAddr.sin_addr.s_addr = inet_addr("0.0.0.0");//绑定地址
    SerAddr.sin_addr.s_addr = htonl(INADDR_ANY);//监听本机所有IP 0x00000000
    //SerAddr.sin_addr.s_addr = inet_addr("127.0.0.1");//回环网络
    SerAddr.sin_port = htons(6969);

    //给服务端socket,将socket绑定到相应地址结构体
    if(bind(SerSock,(SOCKADDR*)&SerAddr,sizeof(SerAddr)) == -1)
    {
        printf("bind ErrorNumber(%d)\r\n",WSAGetLastError());
        closesocket(SerSock);
        WSACleanup();
        return -1;
    }
    //等待队列
    if(listen(SerSock,5) == -1)//等待最多为5
    {
        printf("listen ErrorNumber(%d)\r\n",WSAGetLastError());
        WSACleanup();
        return -1;
    }
    //客户端地址信息绑定一个套接字
    //等待连接 accept会堵塞
    int len = sizeof(CliAddr);
    if((CliSock = accept(SerSock,(SOCKADDR*)&CliAddr,&len)) == -1)
    {
        printf("accept ErrorNumber(%d)\r\n",WSAGetLastError());
        closesocket(SerSock);
        WSACleanup();
        return -1;
    }
    // I/O
    char RecvBuf[BUFSIZ]{};
    int ret = recv(CliSock,RecvBuf,sizeof(RecvBuf),0);//客户端套接字,要发送的缓冲区,缓冲区大小,标志
    if(ret <= 0)
    {
        printf("accept ErrorNumber(%d)\r\n",WSAGetLastError());
        closesocket(SerSock);
        WSACleanup();
        return -1;
    }
    //关闭
    closesocket(CliSock);
    closesocket(SerSock);
    WSACleanup();

    system("pause");
    return 0;
}   