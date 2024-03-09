//
// Created by Shantanu Banerjee on 09/03/24.
//

#ifndef CUMULUSD_CUMULUSCONNECTION_H
#define CUMULUSD_CUMULUSCONNECTION_H

#include <iostream>

class CumulusConnection {
public:
    CumulusConnection(const std::string& host, const unsigned int port);
    ~CumulusConnection();
};


#endif //CUMULUSD_CUMULUSCONNECTION_H
