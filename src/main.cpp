#include <iostream>
#include "Tracer/Controller.h"
#include "Tracer/Actions/RegisterActions.h"

using namespace std;

int main(int argc, char *argv[]) {
    registerActions();
    Controller controller;
    controller.start();
    return 0;
}
