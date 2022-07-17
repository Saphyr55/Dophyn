#include <iostream>
#include "core/Engine.hpp"
#include "core/Logger.hpp"

int main(int argc, char **argv)
{   
    if (FAILURE == Dophyn::Engine::getEngine()->init())
        exit(EXIT_FAILURE);
    
    Dophyn::Engine::getEngine()->launch();

    return Dophyn::Engine::getEngine()->clean();
}