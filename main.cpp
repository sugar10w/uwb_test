// -------------------------------------------------------------------------------------------------------------------
//
//  File: main.cpp
//
//  Copyright 2016 (c) Decawave Ltd, Dublin, Ireland.
//
//  All rights reserved.
//
//  Author:
//
// -------------------------------------------------------------------------------------------------------------------

#include "RTLSDisplayApplication.h"
#include "mainwindow.h"
#include <QApplication>


#include "clientsocket.h"
#include "MapFile.h"

/**
* @brief this is the application main entry point
*
*/

int main(int argc, char *argv[])
{
    RTLSDisplayApplication app(argc, argv);
    SocketInit();
    MapFileInit();
    app.mainWindow()->show();
    //SocketFinish();
    return app.QApplication::exec();
}
