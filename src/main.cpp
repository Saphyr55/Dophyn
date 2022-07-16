#include <iostream>
#include "core/Engine.hpp"
#include "utils/matrix.hpp"
#include <SDL2/SDL.h>

int main(int argc, char **argv)
{   
    auto& engine = Dophyn::Engine();
    if (FAILURE == engine.init()) exit(EXIT_FAILURE);

    return engine.clean();
}