//
// Created by Shantanu Banerjee on 09/03/24.
//

#include "CumulusConnection.h"
#include "ssl_socket.h"
#include "EnvVars.h"

using namespace cumulus;

CumulusConnection::CumulusConnection(const std::string &host, const unsigned int port) : _host(host), _port(port) {

}

CumulusConnection::~CumulusConnection() {

}

void CumulusConnection::start() {
    try {
        auto keyPath = EnvVars::get(constants::app_global::KEY_FILE_PATH_KEY);
        auto certPath = EnvVars::get(constants::app_global::CERT_FILE_PATH_KEY);
        auto serverHost = constants::app_global::CUMULUS_HOST.c_str();
        auto serverPort = constants::app_global::CUMULUS_PORT;

        _socket = connection::SSLSocket::connect(certPath, keyPath, serverHost, serverPort);

        char cmd = protocol::CONNECT_CMD;
        _socket->send(&cmd, protocol::CONNECT_CMD_LEN);

        char buf1[100] = { 0 };
        _socket->receive(buf1, sizeof "hello from server");
        std::cout << "Received from server -> " << buf1;

        _socket->send("hello world", sizeof "hello world");
    } catch (std::runtime_error& err) {
        std::cerr << err.what();
    }
}
