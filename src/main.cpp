#include <iostream>
#include "core/Engine.hpp"
#include "utils/matrix.hpp"
#include <SDL2/SDL.h>

int main(int argc, char **argv)
{

    Dophyn::Engine *engine = new Dophyn::Engine();

    if (FAILURE == engine->init("My app"))
        exit(EXIT_FAILURE);

    while (engine->running())
    {
        engine->handleEvents();
        engine->update();
        engine->render();
    }

    return engine->clean();
}