#include <SDL.h>
#include <libtcod.hpp>
#include <string>

#include<iostream>

#include "StackBox.h"
#include "MenuButton.h"

inline static bool should_quit = false;

static void quit_application()
{
    should_quit = true;
}

auto get_data_dir() -> std::filesystem::path 
{
    static auto root_directory = std::filesystem::path{"."};

    while(!std::filesystem::exists(root_directory / "data"))
    {
        root_directory /= "..";
        if (!std::filesystem::exists(root_directory))
        {
            throw std::runtime_error("Could not find the data directory");
        }
    }
    return root_directory / "data";
}

int main(int argc, char* argv[])
{

    tcod::Console console = tcod::Console{100, 40}; // Main Console

    // Configure the context
    TCOD_ContextParams params = TCOD_ContextParams{}; // We Create the Context Params struct
    params.tcod_version = TCOD_COMPILEDVERSION;  // This is required.
    params.console = console.get();  // Derive the window size from the console size.
    params.window_title = "Libtcod Project";
    params.sdl_window_flags = SDL_WINDOW_RESIZABLE | SDL_WINDOW_INPUT_FOCUS;
    params.renderer_type = TCOD_RENDERER_SDL2;
    params.vsync = true;
    params.argc = argc;  // This allows some user-control of the context.
    params.argv = argv;

    auto tileset = tcod::load_tilesheet(get_data_dir() / "dejavu16x16_gs_tc.png", {32, 8}, tcod::CHARMAP_TCOD);

    params.tileset = tileset.get();

    auto context = tcod::Context(params);

    Uint64 now = SDL_GetPerformanceCounter();
    Uint64 last = 0;
    double delta_time = 0.0;

    StackBox menu_stack_box;
    auto start_button = menu_stack_box.create_button(iVector2(40, 20), 20, 5, "Start", true);
    auto exit_button = menu_stack_box.create_button(iVector2(40, 26), 20, 5, "Exit", false);
    exit_button->set_action_callback(quit_application);

    // SDL_ShowCursor(0);

    while(!should_quit)
    {

        last = now;
        now = SDL_GetPerformanceCounter();

        delta_time = ((now - last) / (double)SDL_GetPerformanceFrequency());

        // Game Loop

        SDL_Event event;

        // SDL_WaitEvent(SDL_DISABLE);
        while(SDL_PollEvent(&event))
        {
            context.convert_event_coordinates(event);
            switch (event.type)
            {
                case SDL_KEYDOWN:
                    menu_stack_box.process_input(delta_time, event.key.keysym.sym);
                    break;
                case SDL_QUIT:
                    should_quit = true;
                    break; // Exit
            }
        }

        // render

        TCOD_console_clear(console.get());
        tcod::print(console, {100, 0}, std::to_string(delta_time), std::nullopt, std::nullopt, TCOD_alignment_t::TCOD_RIGHT);
        menu_stack_box.draw(&console);
        context.present(console);

    }

    SDL_Quit();

    return 0;
}