#include "AssetManager.hpp"

AssetManager::~AssetManager() {
    unloadAll();
}

// Textures
void AssetManager::loadTexture(const std::string& name, const std::string& path) {
    if (textures.contains(name)) return;
    Texture2D t = loadTexture(path.c_str());
    if (t.id == 0) {
        throw std::runtime_error("Failed to load texture: " + path);
    }
    textures[name] = t;
}

Texture2D& AssetManager::getTexture(const std::string& name) {
    auto it = textures.find(name);
    if (it == texture.end()) {
        throw std::runtime_error("Texture not found: " + name);
    }
    return it->second;
}


// Sounds
void AssetManager::loadSound(const std::string& name, const std::string& path) {
    if (sounds.contains(name)) return;
    Sound s = LoadSound(path.c_str());
    if (s.stream.buffer == nullptr) {
        throw std::runtime_error("Failed to load sound: " + path);
    }
    sounds[name] = s;
}

Sound& AssetManager::getSound(const std::string& name) {
    auto it = sounds.find(name);
    if (it == sounds.end()) {
        throw std::runtime_error("Sound not found: " + name);
    }
    return it->second;
}


// Music
void AssetManager::loadMusic(const std::string& name, const std::string& path) {
    if (music.contains(name)) return;
    Music m = LoadMusicStream(path.c_str());
    if (m.stream.buffer == nullptr) {
        throw std::runtime_error("Failed to load music: " + path);
    }
    music[name] = m;
}

Music& AssetManager::getMusic(const std::string& name) {
    auto it = music.find(name);
    if (it == music.end()) {
        throw std::runtime_error("Music not found: " + name);
    }
    return it->second;
}


// Unloading
void AssetManager::unloadAll() {
    for (auto& [name, t] : textures) UnloadTexture(t);
    for (auto& [name, s] : sounds) UnloadSound(s);
    for (auto& [name, m] : music) UnloadMusicStream(m);

    textures.clear();
    sounds.clear();
    music.clear();
}