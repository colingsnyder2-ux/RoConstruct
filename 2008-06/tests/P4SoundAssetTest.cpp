#define BOOST_ALL_NO_LIB
#include "util/Sound.h"
#include "v8datamodel/GameSettings.h"
#include <fmod.hpp>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <stdexcept>
#include <windows.h>
// DLL exports the stdcall entry without decoration; generated import library
// preserves that export name. This is a symbol alias, not a calling-convention change.
#pragma comment(linker,"/alternatename:_FMOD_System_Create@4=_FMOD_System_Create")

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
