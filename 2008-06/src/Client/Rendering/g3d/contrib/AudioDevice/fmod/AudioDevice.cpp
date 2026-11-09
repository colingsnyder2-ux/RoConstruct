/**
 @file AudioDevice.cpp

 @maintainer Morgan McGuire, morgan@cs.brown.edu

 @created 2002-11-26
 @edited  2002-12-06
 */

#include "AudioDevice.h"
#include <fmod.h>

bool AudioDevice::init(Log* _debugLog) {

    debugLog = _debugLog;

    if (debugLog != NULL) {
        debugLog->printf("Initializing audio system 44kHz 32 channels\n");
    }

    bool ret = FSOUND_Init(44100, 32, 0) != 0;

    if (debugLog != NULL) {
        if (ret) {
            debugLog->println("Audio initalization      Ok");
        } else {
            debugLog->println("Audio initalization      FAIL");
        }
    }

    return ret;
}


void AudioDevice::cleanup() {
    FSOUND_Close();
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
    sample = FSOUND_Sample_Load(FSOUND_UNMANAGED, filename.c_str(), FSOUND_LOOP_OFF, 0);
}


SoundEffect::~SoundEffect() {
    FSOUND_Sample_Free(sample);
    sample = NULL;
}


void SoundEffect::play(double volume) const {
    int channel = FSOUND_PlaySound(FSOUND_FREE, sample);
    FSOUND_SetVolume(channel, min(volume, 1) * 255);
}

///////////////////////////////////////////////////////////////////////////////////

MusicStream::MusicStream(const std::string& filename) {
    // Don't load music in debug mode
    #ifdef _DEBUG
        music   = NULL;
    #else
        music   = FSOUND_Stream_OpenFile(filename.c_str(), FSOUND_LOOP_NORMAL, 0);
    #endif
    playing = false;
    channel = 0;
}


MusicStream::~MusicStream() {
    FSOUND_Stream_Close(music);
}


void MusicStream::play(double volume) {
    if (! playing && (music != NULL)) {
        channel = FSOUND_Stream_Play(FSOUND_FREE, music);
        FSOUND_SetVolume(channel, min(volume, 1) * 255);
        playing = true;
    }
}

void MusicStream::setVolume(double volume) {
    if (playing) {
        FSOUND_SetVolume(channel, min(volume, 1) * 255);
    }
}


void MusicStream::stop() {
    if (playing && (music != NULL)) {
        FSOUND_Stream_Stop(music);
        playing = false;
    }
}

