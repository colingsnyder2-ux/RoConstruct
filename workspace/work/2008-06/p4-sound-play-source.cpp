// Implementation: C:\Users\colin\RoConstruct\src\2008-06\005bceb0.cpp
// Build pointer preserved: C:\Users\colin\RoConstruct\src\2008-06\005bceb0.cpp
// from server: 100% by coldek
// roc 2008-06 005bceb0  unit: SoundServiceStatsItem  size: 569 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005bceb0
//
// 005bceb0  55                   push ebp
// 005bceb1  8bec                 mov ebp, esp
// 005bceb3  6aff                 push -1
// 005bceb5  68d03d7d00           push 0x7d3dd0
// 005bceba  64a100000000         mov eax, dword ptr fs:[0]
// 005bcec0  50                   push eax
// 005bcec1  64892500000000       mov dword ptr fs:[0], esp
// 005bcec8  83ec1c               sub esp, 0x1c
// 005bcecb  53                   push ebx
// 005bcecc  56                   push esi
// 005bcecd  8bf1                 mov esi, ecx
// 005bcecf  b304                 mov bl, 4
// 005bced1  57                   push edi
// 005bced2  8965f0               mov dword ptr [ebp - 0x10], esp
// 005bced5  849e65010000         test byte ptr [esi + 0x165], bl
// 005bcedb  7546                 jne 0x5bcf23
// 005bcedd  f6866501000002       test byte ptr [esi + 0x165], 2
// 005bcee4  c745fc00000000       mov dword ptr [ebp - 4], 0
// 005bceeb  7449                 je 0x5bcf36
// 005bceed  8b863c010000         mov eax, dword ptr [esi + 0x13c]
// 005bcef3  85c0                 test eax, eax
// 005bcef5  743f                 je 0x5bcf36
// 005bcef7  8d4def               lea ecx, [ebp - 0x11]
// 005bcefa  51                   push ecx
// 005bcefb  50                   push eax
// 005bcefc  e8e12c0e00           call 0x69fbe2
// 005bcf01  83f824               cmp eax, 0x24
// 005bcf04  7430                 je 0x5bcf36
// 005bcf06  807def00             cmp byte ptr [ebp - 0x11], 0
// 005bcf0a  742a                 je 0x5bcf36
// 005bcf0c  8b963c010000         mov edx, dword ptr [esi + 0x13c]
// 005bcf12  6a00                 push 0
// 005bcf14  52                   push edx
// 005bcf15  e8582d0e00           call 0x69fc72
// 005bcf1a  50                   push eax
// 005bcf1b  e8c0a0ffff           call 0x5b6fe0
// 005bcf20  83c404               add esp, 4
// 005bcf23  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 005bcf26  64890d00000000       mov dword ptr fs:[0], ecx
// 005bcf2d  5f                   pop edi
// 005bcf2e  5e                   pop esi
// 005bcf2f  5b                   pop ebx
// 005bcf30  8be5                 mov esp, ebp
// 005bcf32  5d                   pop ebp
// 005bcf33  c20400               ret 4
// 005bcf36  8b4508               mov eax, dword ptr [ebp + 8]
// 005bcf39  50                   push eax
// 005bcf3a  e87138fcff           call 0x5807b0
// 005bcf3f  83c404               add esp, 4
// 005bcf42  8945e8               mov dword ptr [ebp - 0x18], eax
// 005bcf45  85c0                 test eax, eax
// 005bcf47  74da                 je 0x5bcf23
// 005bcf49  83b83401000000       cmp dword ptr [eax + 0x134], 0
// 005bcf50  7519                 jne 0x5bcf6b
// 005bcf52  089e65010000         or byte ptr [esi + 0x165], bl
// 005bcf58  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 005bcf5b  64890d00000000       mov dword ptr fs:[0], ecx
// 005bcf62  5f                   pop edi
// 005bcf63  5e                   pop esi
// 005bcf64  5b                   pop ebx
// 005bcf65  8be5                 mov esp, ebp
// 005bcf67  5d                   pop ebp
// 005bcf68  c20400               ret 4
// 005bcf6b  8bce                 mov ecx, esi
// 005bcf6d  e87ec8ffff           call 0x5b97f0
// 005bcf72  83be6c01000000       cmp dword ptr [esi + 0x16c], 0
// 005bcf79  8dbe40010000         lea edi, [esi + 0x140]
// 005bcf7f  0f95c1               setne cl
// 005bcf82  328e65010000         xor cl, byte ptr [esi + 0x165]
// 005bcf88  80e101               and cl, 1
// 005bcf8b  308e65010000         xor byte ptr [esi + 0x165], cl
// 005bcf91  8a8665010000         mov al, byte ptr [esi + 0x165]
// 005bcf97  2401                 and al, 1
// 005bcf99  0fb6d0               movzx edx, al
// 005bcf9c  52                   push edx
// 005bcf9d  83ec20               sub esp, 0x20
// 005bcfa0  8bdc                 mov ebx, esp
// 005bcfa2  8965e0               mov dword ptr [ebp - 0x20], esp
// 005bcfa5  57                   push edi
// 005bcfa6  8bcb                 mov ecx, ebx
// 005bcfa8  ff155c248000         call dword ptr [0x80245c]
// 005bcfae  8b471c               mov eax, dword ptr [edi + 0x1c]
// 005bcfb1  89431c               mov dword ptr [ebx + 0x1c], eax
// 005bcfb4  8b5de8               mov ebx, dword ptr [ebp - 0x18]
// 005bcfb7  8d4ddc               lea ecx, [ebp - 0x24]
// 005bcfba  51                   push ecx
// 005bcfbb  8bcb                 mov ecx, ebx
// 005bcfbd  e82ee6ffff           call 0x5bb5f0
// 005bcfc2  8b10                 mov edx, dword ptr [eax]
// 005bcfc4  83c004               add eax, 4
// 005bcfc7  50                   push eax
// 005bcfc8  8d8e38010000         lea ecx, [esi + 0x138]
// 005bcfce  c645fc01             mov byte ptr [ebp - 4], 1
// 005bcfd2  899634010000         mov dword ptr [esi + 0x134], edx
// 005bcfd8  e8d355e4ff           call 0x4025b0
// 005bcfdd  8d4ddc               lea ecx, [ebp - 0x24]
// 005bcfe0  c645fc00             mov byte ptr [ebp - 4], 0
// 005bcfe4  e877360400           call 0x600660
// 005bcfe9  8b8634010000         mov eax, dword ptr [esi + 0x134]
// 005bcfef  ff4008               inc dword ptr [eax + 8]
// 005bcff2  8b4508               mov eax, dword ptr [ebp + 8]
// 005bcff5  8b8e34010000         mov ecx, dword ptr [esi + 0x134]
// 005bcffb  50                   push eax
// 005bcffc  e8eff6ffff           call 0x5bc6f0
// 005bd001  85c0                 test eax, eax
// 005bd003  0f841affffff         je 0x5bcf23
// 005bd009  8b8b34010000         mov ecx, dword ptr [ebx + 0x134]
// 005bd00f  8dbe3c010000         lea edi, [esi + 0x13c]
// 005bd015  57                   push edi
// 005bd016  6a01                 push 1
// 005bd018  50                   push eax
// 005bd019  6aff                 push -1
// 005bd01b  51                   push ecx
// 005bd01c  e84b2c0e00           call 0x69fc6c
// 005bd021  50                   push eax
// 005bd022  e8b99fffff           call 0x5b6fe0
// 005bd027  83c404               add esp, 4
// 005bd02a  8bce                 mov ecx, esi
// 005bd02c  e85fc8ffff           call 0x5b9890
// 005bd031  8b17                 mov edx, dword ptr [edi]
// 005bd033  52                   push edx
// 005bd034  8bce                 mov ecx, esi
// 005bd036  e8e5c8ffff           call 0x5b9920
// 005bd03b  d98660010000         fld dword ptr [esi + 0x160]
// 005bd041  8b07                 mov eax, dword ptr [edi]
// 005bd043  51                   push ecx
// 005bd044  d91c24               fstp dword ptr [esp]
// 005bd047  50                   push eax
// 005bd048  e8192c0e00           call 0x69fc66
// 005bd04d  50                   push eax
// 005bd04e  e88d9fffff           call 0x5b6fe0
// 005bd053  8b0f                 mov ecx, dword ptr [edi]
// 005bd055  83c404               add esp, 4
// 005bd058  56                   push esi
// 005bd059  51                   push ecx
// 005bd05a  e8952b0e00           call 0x69fbf4
// 005bd05f  50                   push eax
// 005bd060  e87b9fffff           call 0x5b6fe0
// 005bd065  8b17                 mov edx, dword ptr [edi]
// 005bd067  83c404               add esp, 4
// 005bd06a  6a00                 push 0
// 005bd06c  68c0c65b00           push 0x5bc6c0
// 005bd071  6a00                 push 0
// 005bd073  52                   push edx
// 005bd074  e8e72b0e00           call 0x69fc60
// 005bd079  50                   push eax
// 005bd07a  e8619fffff           call 0x5b6fe0
// 005bd07f  8b07                 mov eax, dword ptr [edi]
// 005bd081  83c404               add esp, 4
// 005bd084  6a00                 push 0
// 005bd086  50                   push eax
// 005bd087  e8e62b0e00           call 0x69fc72
// 005bd08c  50                   push eax
// 005bd08d  e84e9fffff           call 0x5b6fe0
// 005bd092  83c404               add esp, 4
// 005bd095  8bce                 mov ecx, esi
// 005bd097  e814f5ffff           call 0x5bc5b0
// 005bd09c  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 005bd09f  5f                   pop edi
// 005bd0a0  5e                   pop esi
// 005bd0a1  64890d00000000       mov dword ptr fs:[0], ecx
// 005bd0a8  5b                   pop ebx
// 005bd0a9  8be5                 mov esp, ebp
// 005bd0ab  5d                   pop ebp
// 005bd0ac  c20400               ret 4
// 005bd0af  8d4de4               lea ecx, [ebp - 0x1c]
// 005bd0b2  51                   push ecx
// 005bd0b3  e868c5faff           call 0x569620
// 005bd0b8  83c404               add esp, 4
// 005bd0bb  8b4dd8               mov ecx, dword ptr [ebp - 0x28]
// 005bd0be  8b11                 mov edx, dword ptr [ecx]
// 005bd0c0  8b30                 mov esi, dword ptr [eax]
// 005bd0c2  8b4204               mov eax, dword ptr [edx + 4]
// 005bd0c5  c645fc03             mov byte ptr [ebp - 4], 3
// 005bd0c9  ffd0                 call eax
// 005bd0cb  50                   push eax
// 005bd0cc  6a03                 push 3
// 005bd0ce  56                   push esi
// 005bd0cf  e8ccc2faff           call 0x5693a0
// 005bd0d4  83c40c               add esp, 0xc
// 005bd0d7  8d4de4               lea ecx, [ebp - 0x1c]
// 005bd0da  c645fc02             mov byte ptr [ebp - 4], 2
// 005bd0de  e87d350400           call 0x600660
// 005bd0e3  b823cf5b00           mov eax, 0x5bcf23
// 005bd0e8  c3                   ret 

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
