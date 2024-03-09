#include <iostream>
#include "src/App.h"

int main(int argc, char *argv[], char *argp[]) {

    try {
        App app(argc, argv, argp);
        app.run();
    } catch (std::runtime_error& err) {
        std::cerr << err.what();
    }

    return 0;
}
