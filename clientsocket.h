#ifndef CLIENTSOCKET_H
#define CLIENTSOCKET_H

#include <iostream>
#include <winsock2.h>

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

typedef struct
{
    double x;
    double y;
    double z;
    int writeflag;
}pos_xyz_info;

extern SOCKET ClientSocket;

void SocketFinish();
int SocketInit();


#endif // CLIENTSOCKET_H
