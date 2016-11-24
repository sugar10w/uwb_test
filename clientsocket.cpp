#include "clientsocket.h"

using namespace std;

#define PORT 8887
#define IP_ADDRESS "192.168.1.1"



SOCKET ClientSocket;

int SocketInit()
{
    WSADATA Ws;//used to recv the struct info of Windows Socket

    struct sockaddr_in ServerAddr;
    int Ret = 0;
    int AddrLen = 0;
    HANDLE hThread = NULL;

    pos_info buffer;
    //Init Windows Socket
    if ( WSAStartup(MAKEWORD(2,2), &Ws) != 0 ) //ask for the version of WinSock
    {
        cout<<"Init Windows Socket Failed::"<<GetLastError()<<endl;
        return -1;
    }
    //Create Socket
    //SOCKET socket(int af, int type, int protocol);
    //指定地址簇(TCP/IP->AF_INET)
    //0 自动
    ClientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if ( ClientSocket == INVALID_SOCKET )
    {
        cout<<"Create Socket Failed::"<<GetLastError()<<endl;
        return -1;
    }

    ServerAddr.sin_family = AF_INET;
    ServerAddr.sin_addr.s_addr = inet_addr(IP_ADDRESS);
    ServerAddr.sin_port = htons(PORT);
    memset(ServerAddr.sin_zero, 0x00, 8);

    // int connect( SOCKET s, const struct sockaddr* name, int namelen)
    // s: the socket to connect
    // name: the addr info
    // len: the length of addr
    Ret = connect(ClientSocket,(struct sockaddr*)&ServerAddr, sizeof(ServerAddr));
    if ( Ret == SOCKET_ERROR )
    {
        cout<<"Connect Error::"<<GetLastError()<<endl;
        return -1;
    }
    else
    {
        cout<<"Connect Successfully"<<endl;
    }
    return 0;
}

void SocketFinish()
{
    closesocket(ClientSocket);
    WSACleanup();
}

