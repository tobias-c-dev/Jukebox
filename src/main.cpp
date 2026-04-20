#include <raylib.h>
#include "Constants.hpp"
#include "AssetManager.hpp"

int main() {
    
    // Initialise window
    InitWindow(Constants::SCREEN_WIDTH, Constants::SCREEN_HEIGHT, "Game Window");
    InitAudioDevice();
    SetTargetFPS(60);

    AssetManager assets;
    // Load assets in here


    
    Font font = LoadFont("assets/fonts/ByteBounce.ttf");
    const char* text = "JUKEBOX";
    float textWidth = MeasureText(text, 60);
    float x = (Constants::SCREEN_WIDTH - textWidth) / 2;
    float y = (Constants::SCREEN_HEIGHT) / 2;
    Vector2 position = {x, y};

    // Game Loop
    while (!WindowShouldClose()) {
        
        assets.updateMusic();

        BeginDrawing();
            ClearBackground(BLACK);
            DrawTextEx(font, text, position, 60, 1, LIME);
        EndDrawing();
    }

    CloseWindow();
    
    return 0;
}
