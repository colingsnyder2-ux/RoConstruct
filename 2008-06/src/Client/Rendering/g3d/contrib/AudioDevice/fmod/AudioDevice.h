/**
 @file AudioDevice.h

 @maintainer Morgan McGuire, morgan@cs.brown.edu

 @created 2002-11-26
 @edited  2002-12-06
 */

#ifndef AUDIODEVICE_H
#define AUDIODEVICE_H

#include <G3DAll.h>
#include <fmod.h>

#ifdef G3D_WIN32
    #pragma comment(lib, "fmodvc.lib")
#endif

class SoundEffect : public ReferenceCountedObject {
private:
    friend class AudioDevice;

    FSOUND_SAMPLE*          sample;
    SoundEffect::SoundEffect(const std::string& filename);

public:
    SoundEffect::~SoundEffect();

    /** Cannot be stopped once it has been played.  The same
      effect can be played multiple times, overlapped. */
    void play(double volume = 1.0) const;
};

typedef ReferenceCountedPointer<class SoundEffect> SoundEffectRef;

///////////////////////////////////////////////////////

class MusicStream : public ReferenceCountedObject {
private:
    friend class AudioDevice;

    /** If playing, this is the channel being used. */
    int                     channel;
    bool                    playing;
    FSOUND_STREAM*          music;

    MusicStream::MusicStream(const std::string& filename);

public:
    MusicStream::~MusicStream();

    bool isPlaying() const {
        return playing;
    }

    void play(double volume = 1.0);
    void setVolume(double volume);
    void stop();
};

typedef ReferenceCountedPointer<class MusicStream> MusicStreamRef;

///////////////////////////////////////////////////////

class AudioDevice {
private:
    Log*                    debugLog;

public:

    bool init(Log* debugLog = NULL);
    void cleanup();

    SoundEffectRef createSoundEffect(const std::string& filename);
    MusicStreamRef createMusicStream(const std::string& filename);
};

#endif

