#define BOOST_ALL_NO_LIB
#include "util/ContentProvider.h"
#include "util/RunStateOwner.h"
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/Stats.h"
// Compile the same cleanup body with public access in this isolated test;
// MSVC encodes access in symbol names, so this cannot call the private binary.
#define private public
#include "util/Sound.h"
#include "PlayerNativeSoundGC.cpp"
#undef private
#include "v8datamodel/GameSettings.h"
#include <fmod.hpp>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <stdexcept>
#include <windows.h>
#include <cstdlib>
// DLL exports the stdcall entry without decoration; generated import library
// preserves that export name. This is a symbol alias, not a calling-convention change.
#pragma comment(linker,"/alternatename:_FMOD_System_Create@4=_FMOD_System_Create")

// Native RTTI/constructors and factory allocation witnesses; no padding aliases.
typedef char NativeInstanceSize[sizeof(RBX::Instance)==0x130?1:-1];
typedef char NativeSoundChannelSize[sizeof(RBX::Soundscape::SoundChannel)==0x170?1:-1];
typedef char NativeSoundServiceSize[sizeof(RBX::Soundscape::SoundService)==0x1c8?1:-1];

static void check(FMOD_RESULT result){
    if(result!=FMOD_OK){std::printf("FMOD error %d\n",result);throw std::runtime_error("FMOD diagnostic failed");}
}

static void verify(bool condition){if(!condition)throw std::runtime_error("Sound assertion failed");}

int main(int argc,char** argv){
    try{
        verify(std::strcmp(RBX::Soundscape::sSoundChannel,"Sound")==0);
        verify(std::strcmp(RBX::Soundscape::sSoundService,"SoundService")==0);
        std::string path=__FILE__;path=path.substr(0,path.find_last_of("/\\"))+"/fixtures/p4-assets";
        RBX::ContentProvider::singleton().setAssetFolder(argc>1?argv[1]:path.c_str());
        RBX::GameSettings::singleton().softwareSound=true;
        FMOD::System* system=0;check(FMOD::System_Create(&system));
        unsigned version=0;check(system->getVersion(&version));verify(version>=0x41406);
        char dllPath[MAX_PATH];verify(GetModuleFileNameA(GetModuleHandleA("fmodex.dll"),dllPath,sizeof(dllPath))!=0);
        std::printf("fmod loaded: %s\n",dllPath);
        // Isolate loader/PCM ownership. No claim of audible or service playback.
        check(system->setOutput(FMOD_OUTPUTTYPE_NOSOUND));check(system->init(100,FMOD_INIT_NORMAL,0));
        {
            typedef std::map<RBX::Soundscape::SoundId,boost::shared_ptr<RBX::Soundscape::Sound> > Sounds;
            Sounds sounds;bool retained[64];
            for(int i=0;i<64;++i){
                char name[32];std::sprintf(name,"rbxasset://%02d.wav",i);
                RBX::Soundscape::SoundId id(name);
                boost::shared_ptr<RBX::Soundscape::Sound> sound(new RBX::Soundscape::Sound(system,id,false));
                sound->refCount=i%3==0?1:0;sounds[id]=sound;
            }
            std::srand(17);
            for(int i=0;i<64;++i)retained[i]=i%3==0 || static_cast<float>(std::rand())*(1.0f/32767.0f)<.7f;
            std::srand(17);RBX::Soundscape::SoundService::gcSounds(sounds);
            verify(sounds.size()<64 && sounds.size()>=22);
            for(int i=0;i<64;++i){
                char name[32];std::sprintf(name,"rbxasset://%02d.wav",i);
                verify((sounds.find(RBX::Soundscape::SoundId(name))!=sounds.end())==retained[i]);
            }
            sounds.clear();RBX::Soundscape::SoundId id("rbxasset://tone.wav");
            boost::shared_ptr<RBX::Soundscape::Sound> sound(new RBX::Soundscape::Sound(system,id,false));
            verify(sound->get()!=0);sounds[id]=sound;
            int seed=1;
            for(;;++seed){std::srand(seed);if(static_cast<float>(std::rand())*(1.0f/32767.0f)>=.7f)break;}
            std::srand(seed);RBX::Soundscape::SoundService::gcSounds(sounds);
            verify(sounds.empty() && sound->get()!=0);
            std::printf("P4 Sound cache cleanup PASS retained/in-use/evicted/reload\n");
        }
        for(int cycle=0;cycle<16;++cycle){
            RBX::Soundscape::Sound sound(system,RBX::Soundscape::SoundId("rbxasset://tone.wav"),false);
            verify(sound.refCount==0);
            FMOD::Sound* native=sound.get();verify(native!=0 && native==sound.get());
            // OPENMEMORY duplicates bytes: FMOD must survive provider cache release.
            RBX::ContentProvider::singleton().clearContentCache();
            unsigned bytes=0;check(native->getLength(&bytes,FMOD_TIMEUNIT_PCMBYTES));verify(bytes==11024);
            FMOD_SOUND_TYPE type;FMOD_SOUND_FORMAT format;int channels=0,bits=0;
            check(native->getFormat(&type,&format,&channels,&bits));verify(channels==1 && bits==16 && format==FMOD_SOUND_FORMAT_PCM16);
            void *first=0,*second=0;unsigned firstSize=0,secondSize=0;
            check(native->lock(0,bytes,&first,&second,&firstSize,&secondSize));verify(firstSize==bytes && secondSize==0);
            const short* samples=static_cast<const short*>(first);
            for(unsigned i=0;i<bytes/2;++i)
                verify(std::abs(int(samples[i])-int(4000*std::sin(2*3.141592653589793*440*i/22050)))<=1);
            check(native->unlock(first,second,firstSize,secondSize));
            FMOD_MODE mode=0;check(native->getMode(&mode));verify((mode&FMOD_SOFTWARE) && (mode&FMOD_2D));
            sound.detach();verify(sound.get()!=0); // Released handle can be loaded again.
        }
        {
            RBX::Soundscape::Sound sound(system,RBX::Soundscape::SoundId("rbxasset://tone.wav"),true);
            FMOD_MODE mode=0;check(sound.get()->getMode(&mode));verify((mode&FMOD_3D)!=0);
            RBX::Soundscape::Sound missing(system,RBX::Soundscape::SoundId("rbxasset://absent.wav"),false);
            verify(missing.get()==0 && missing.get()==0);
        }
        check(system->release());
        std::printf("P4 Sound loader PASS version=%08x cycles=16 pcm_bytes=11024 samples=5512 2D/3D/cache/detach/missing\n",version);
        return 0;
    }catch(const std::exception& error){std::printf("Sound test: %s\n",error.what());return 1;}
}
