/**
 @file AudioDevice.cpp

 @maintainer Morgan McGuire, morgan@cs.brown.edu

 @created 2004-07-31
 @edited  2004-07-31
 */

#include "AudioDevice.h"

bool AudioDevice::init(Log* _debugLog) {

    debugLog = _debugLog;

    if (debugLog != NULL) {
        debugLog->printf("Initializing audio system with default settings\n");
    }

    int audioRate           = MIX_DEFAULT_FREQUENCY;
    uint16 audioFormat      = MIX_DEFAULT_FORMAT;
    int audioChannels       = 2; // stereo

    bool ret = Mix_OpenAudio(audioRate, audioFormat, audioChannels, 4096) >= 0;

    if (debugLog != NULL) {
        if (ret) {
            debugLog->println("Audio initalization      Ok");
        } else {
            debugLog->println("Audio initalization      FAIL");
            debugLog->printf("Couldn't open audio: %s\n", SDL_GetError());
        }
    }

    if (ret) {
        Mix_QuerySpec(&audioRate, &audioFormat, &audioChannels);
    }

    return ret;
}


void AudioDevice::cleanup() {
    Mix_CloseAudio();
}


SoundEffectRef AudioDevice::createSoundEffect(const std::string& filename) {
    if (debugLog != NULL) {
        debugLog->printf("Loading \"%s\".\n", filename.c_str());
        if (! fileExists(filename)) {
            debugLog->printf("Error!  file does not exist\n");
            return NULL;
        }
    }

    return new SoundEffect(filename);
}


MusicStreamRef AudioDevice::createMusicStream(const std::string& filename) {
    if (debugLog != NULL) {
        debugLog->printf("Loading \"%s\".\n", filename.c_str());
        if (! fileExists(filename)) {
            debugLog->printf("Error!  file does not exist\n");
            return NULL;
        }
    }

    return new MusicStream(filename);
}

////////////////////////////////////////////////////////////////////////////////////

SoundEffect::SoundEffect(const std::string& filename) {
    sample = Mix_LoadWAV(filename.c_str());
}


SoundEffect::~SoundEffect() {
    Mix_FreeChunk(sample);
    sample = NULL;
}


void SoundEffect::play(double volume) const {
    Mix_PlayChannel(-1, sample, 0);
}

///////////////////////////////////////////////////////////////////////////////////

MusicStream::MusicStream(const std::string& filename) {
    // Don't load music in debug mode
    #ifdef _DEBUG
        music   = NULL;
    #else
        music   = Mix_LoadMUS(filename.c_str());
    #endif
    playing = false;
    channel = 0;
}


MusicStream::~MusicStream() {
    Mix_FreeMusic(music);
}


void MusicStream::play(double volume) {
    if (! playing && (music != NULL)) {
        Mix_PlayMusic(music, false);
        playing = true;
    }
}

void MusicStream::setVolume(double volume) {
    if (playing) {
        //TODO
    }
}


void MusicStream::stop() {
    if (playing && (music != NULL)) {
        Mix_HaltMusic();
        playing = false;
    }
}

