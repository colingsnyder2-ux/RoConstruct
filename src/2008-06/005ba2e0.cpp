// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_espeon_soundcollectsoundidd288aae93c4f1e29.cpp

// Candidate translation unit (score above; library headers required).
#pragma float_control(precise,off,push)
#include <map>
#include "util/Sound.h"
#include <cstdlib>
extern int __stdcall releaseSound(void*);
void checkSound(int);
struct Sound {void* handle;int reserved;int references;void release(){if(handle){checkSound(releaseSound(handle));handle=0;}}};
typedef std::map<RBX::Soundscape::SoundId,Sound*> Sounds;
void collect(Sounds& sounds){Sounds::iterator it=sounds.begin();while(it!=sounds.end()){if(it->second->references==0 && float(rand())/RAND_MAX>=0.7f){it->second->release();it=sounds.erase(it);}else ++it;}}
