//
// Created by Shantanu Banerjee on 09/03/24.
//

#ifndef CUMULUSD_CUMULUSCONNECTION_H
#define CUMULUSD_CUMULUSCONNECTION_H

#include <iostream>
#include "ssl_socket.h"
#include "config.h"

class CumulusConnection {
public:
    CumulusConnection(const std::string& host, const unsigned int port);
    ~CumulusConnection();

    void start(void);

private:
    const std::string  _host;
    const unsigned int _port;
    cumulus::Pimpl<cumulus::connection::SSLSocket> _socket;
};


#endif //CUMULUSD_CUMULUSCONNECTION_H
