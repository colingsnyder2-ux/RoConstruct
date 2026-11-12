// from server: 100% by EspClaude
// roc-flags: /O2 /GS /EHsc /MD /fp:fast
// VS2005 checked std::map iteration with erase: purge unreferenced FMOD sounds at random.
// Node value at +0xc (VS2005 _Tree_nod); the target reads the mapped pointer at node+0x2c,
// i.e. value+0x20; the pointed record holds the FMOD::Sound* at +0 and a count at +8.
#include <map>
#include <stdlib.h>

namespace FMOD {
enum FMOD_RESULT { FMOD_OK };
class Sound { public: FMOD_RESULT __stdcall release(); };
}

struct SoundKey {
    int pad[8];  // value+0x00..0x1f (mapped pointer proven at value+0x20)
    bool operator<(const SoundKey& o) const { return pad[0] < o.pad[0]; }
};

struct SoundData {
    FMOD::Sound* sound;  // +0
    int pad4;            // +4
    int refs;            // +8
};

typedef std::map<SoundKey, SoundData*> SoundMap;

void purgeSounds(SoundMap& m)
{
    SoundMap::iterator it = m.begin();
    while (it != m.end()) {
        if (it->second->refs == 0 && (float)rand() * (1.0f / RAND_MAX) >= 0.7f) {
            SoundData* d = it->second;
            if (d->sound) {
                d->sound->release();
                d->sound = 0;
            }
            it = m.erase(it);
        } else {
            ++it;
        }
    }
}
