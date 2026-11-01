// from server: 100% by coldek
// from server: 100% by EspClaude
// roc 2008-06 005bceb0  unit: RBX::Soundscape::SoundChannel
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
#include <exception>

namespace boost {
namespace detail {
class shared_count {
public:
    void* pi_;
    shared_count& operator=(const shared_count& r);
};
}
template<class T>
class shared_ptr {
public:
    T* px;
    detail::shared_count pn;
    T* operator->() const { return px; }
    ~shared_ptr();
};
}

enum FMOD_RESULT { FMOD_OK = 0, FMOD_ERR_INVALID_HANDLE = 0x24 };
typedef FMOD_RESULT (__stdcall *FMOD_CHANNEL_CALLBACK)(void*, int, int, unsigned int, unsigned int);
namespace FMOD {
class Sound;
class Channel {
public:
    FMOD_RESULT __stdcall isPlaying(bool* isplaying);
    FMOD_RESULT __stdcall setPaused(bool paused);
    FMOD_RESULT __stdcall setVolume(float volume);
    FMOD_RESULT __stdcall setUserData(void* userdata);
    FMOD_RESULT __stdcall setCallback(int type, FMOD_CHANNEL_CALLBACK callback, int command);
};
class System {
public:
    FMOD_RESULT __stdcall playSound(int channelid, Sound* sound, bool paused, Channel** channel);
};
}
void checkResult(FMOD_RESULT result);

namespace RBX {
enum MessageType { MESSAGE_OUTPUT, MESSAGE_INFO, MESSAGE_WARNING, MESSAGE_ERROR };
class StandardOut {
public:
    static boost::shared_ptr<StandardOut> singleton();
    void print(MessageType type, const char* format, ...);
};
class Instance;
namespace Soundscape {
struct SoundId { std::string id; int extra; };
class Sound {
public:
    FMOD::Sound* fmod_sound;
    FMOD::System* system;
    int refCount;
    FMOD::Sound* tryLoad(Instance* context);
};
class SoundService {
public:
    char pad[0x134];
    FMOD::System* system;
    boost::shared_ptr<Sound> getSound(SoundId id, bool is3D);
};
SoundService* findSoundService(Instance* context);

class SoundChannel {
public:
    char pad[0x134];
    boost::shared_ptr<Sound> sound;
    FMOD::Channel* fmod_channel;
    SoundId soundId;
    float volume;
    bool playOnRemove;
    bool is3D : 1;
    bool looped : 1;
    bool soundDisabled : 1;
    int playCount;
    void* part;

    void stop();
    void updateVolume();
    void update3D(FMOD::Channel* channel);
    void onPlayed();
    static FMOD_RESULT __stdcall channelCallback(void*, int, int, unsigned int, unsigned int);
    void play(Instance* context);
};

void SoundChannel::play(Instance* context)
{
    if (soundDisabled)
        return;
    try
    {
        if (looped && fmod_channel)
        {
            bool playing;
            if (fmod_channel->isPlaying(&playing) != FMOD_ERR_INVALID_HANDLE && playing)
            {
                checkResult(fmod_channel->setPaused(false));
                return;
            }
        }

        SoundService* service = findSoundService(context);
        if (!service)
            return;

        if (!service->system)
        {
            soundDisabled = true;
            return;
        }

        stop();
        is3D = part != 0;
        sound = service->getSound(soundId, is3D);
        sound->refCount++;

        FMOD::Sound* fmodSound = sound->tryLoad(context);
        if (!fmodSound)
            return;

        checkResult(service->system->playSound(-1, fmodSound, true, &fmod_channel));
        updateVolume();
        update3D(fmod_channel);
        checkResult(fmod_channel->setVolume(volume));
        checkResult(fmod_channel->setUserData(this));
        checkResult(fmod_channel->setCallback(0, channelCallback, 0));
        checkResult(fmod_channel->setPaused(false));
        onPlayed();
    }
    catch (std::exception& e)
    {
        StandardOut::singleton()->print(MESSAGE_ERROR, e.what());
    }
}
}
}
