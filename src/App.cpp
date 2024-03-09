//
// Created by Shantanu Banerjee on 09/03/24.
//

#include "App.h"
#include "EnvVars.h"
#include "CumulusConnection.h"

App::App(int argc, char **argv, char **argp) {
    cumulus::EnvVars::parse_env_variables(argp);
}

App::~App() {

}

void App::run() {
    try {
        CumulusConnection connection(
                cumulus::EnvVars::get(cumulus::constants::app_global::CUMULUS_HOST),
                cumulus::constants::app_global::CUMULUS_PORT);

        connection.start();

    } catch (std::exception& ex) {
        throw ex;
    }
}
