#pragma comment(lib, "Ws2_32.lib")

#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>
#include <windows.h>

typedef struct 
{
    double x;
    double y;
    double z;
    double targetx;
    double targety;
    double targetz;
    int writeflag;
}pos_info;


int SocketInit()
{
    WORD wVersionRequested;
    WSADATA wsaData;
    int err;
    pos_info buffer;
    wVersionRequested = MAKEWORD(2, 2);

    err = WSAStartup(wVersionRequested, &wsaData);
    if (err != 0) {
        /* Tell the user that we could not find a usable */
        /* Winsock DLL.                                  */
        printf("WSAStartup failed with error: %d\n", err);
        return 1;
    }

    if (LOBYTE(wsaData.wVersion) != 2 || HIBYTE(wsaData.wVersion) != 2) {
        /* Tell the user that we could not find a usable */
        /* WinSock DLL.                                  */
        printf("Could not find a usable version of Winsock.dll\n");
        WSACleanup();
        return 1;
    }
    else
        printf("The Winsock 2.2 dll was found okay\n");


    SOCKET sockClient = socket(AF_INET,SOCK_DGRAM, 0);

    SOCKADDR_IN  addrServ;
    addrServ.sin_addr.S_un.S_addr = inet_addr("192.168.1.1");
    addrServ.sin_family = AF_INET;
    addrServ.sin_port = htons(8887);
 }

void senddata(pos_info *)
    char SendBuffer[256];
    while (1)
    {
        scanf("%lf %lf %lf %lf %lf %lf", &buffer.x, &buffer.y, &buffer.z, &buffer.targetx, &buffer.targety, &buffer.targetz);
        buffer.writeflag = 1;
        memcpy(SendBuffer, &buffer, sizeof(pos_info));
        sendto(sockClient,SendBuffer,sizeof(pos_info),0,(SOCKADDR*)&addrServ,sizeof(SOCKADDR));

    }
    
    closesocket(sockClient);
    WSACleanup();
        
    return 0;
}
