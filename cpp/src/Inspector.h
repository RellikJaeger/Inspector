//
// Created by Paker on 2019-10-23.
//

#ifndef INSPECTOR_INSPECTOR_H
#define INSPECTOR_INSPECTOR_H

#include "HttpServer.h"
#include "DatabasePlugin.h"
#include "NetworkPlugin.h"

class Inspector : public DatabaseProvider {
    HttpServer *server;
    NetworkPlugin *networkPlugin;
    DatabasePlugin *databasePlugin;
public:
    Inspector();

    thread * bind(int port);

    void preselectDB();

    bool isConnected();

    void sendRequest(string uid, string headers, string body);

    void sendResponse(string uid, string headers, string body, bool compressed = false);
};


#endif //INSPECTOR_INSPECTOR_H
