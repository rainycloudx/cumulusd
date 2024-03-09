//
// Created by Shantanu Banerjee on 09/03/24.
//

#include "App.h"
#include "EnvVars.h"

App::App(int argc, char **argv, char **argp) {
    cumulus::EnvVars::parse_env_variables(argp);
}

App::~App() {

}

void App::run() {

}
