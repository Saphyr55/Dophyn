#include <iostream>
#include "core/Engine.hpp"

int main(int argc, char **argv)
{   

    auto& engine = Dophyn::Engine();
    if (FAILURE == engine.init()) 
        exit(EXIT_FAILURE);
    
    engine.launch();

    return engine.clean();
}