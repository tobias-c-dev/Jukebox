#pragma once

#include <raylib.h>
#include <unordered_map>
#include <string>
#include <stdexcept>

class AssetManager {

    public:
        AssetManager() = default;
        ~AssetManager();

        // Textures
        void loadTexture(const std::string& name, const std::string& path);
        Texture2D& getTexture(const std::string& name);

        // Sounds - should be loaded into memory as .wav files for short sounds
        void loadSound(const std::string& name, const std::string& path);
        Sound& getSound(const std::string& name);

        // Music  - loaded in when needed as .ogg files for music themes
        void loadMusic(const std::string& name, const std::string& path);
        Music& getMusic(const std::string& name);
        void updateMusic();

        void unloadAll();
    
    private:
        std::unordered_map<std::string, Texture2D>  textures;
        std::unordered_map<std::string, Sound>      sounds;
        std::unordered_map<std::string, Music>      music;

};