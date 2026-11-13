#define BOOST_ALL_NO_LIB
#include "util/ContentProvider.h"
#include "util/RunStateOwner.h"
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/Stats.h"
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Workspace.h"
#undef main
// Compile the same cleanup body with public access in this isolated test;
// MSVC encodes access in symbol names, so this cannot call the private binary.
#define private public
#include "util/Sound.h"
#include "PlayerNativeSoundGC.cpp"
#undef private
#include "v8datamodel/GameSettings.h"
#include <fmod.hpp>
#include "PlayerNativeReverb.h"
#include <cstdio>
#include <cmath>
#include <cstring>
#include <stdexcept>
#include <sstream>
#include <limits>
#include <windows.h>
namespace RBX { namespace Soundscape {
bool sanitizeSoundVector(const G3D::Vector3&,G3D::Vector3&);
} }
#include <cstdlib>
// DLL exports the stdcall entry without decoration; generated import library
// preserves that export name. This is a symbol alias, not a calling-convention change.
#pragma comment(linker,"/alternatename:_FMOD_System_Create@4=_FMOD_System_Create")
#pragma comment(linker,"/alternatename:_FMOD_System_GetOutput@8=_FMOD_System_GetOutput")

// Native RTTI/constructors and factory allocation witnesses; no padding aliases.
typedef char NativeInstanceSize[sizeof(RBX::Instance)==0x130?1:-1];
typedef char NativeSoundChannelSize[sizeof(RBX::Soundscape::SoundChannel)==0x170?1:-1];
typedef char NativeSoundServiceSize[sizeof(RBX::Soundscape::SoundService)==0x1c8?1:-1];

static void check(FMOD_RESULT result){
    if(result!=FMOD_OK){std::printf("FMOD error %d\n",result);throw std::runtime_error("FMOD diagnostic failed");}
}

static void verify(bool condition){if(!condition)throw std::runtime_error("Sound assertion failed");}
static size_t readCounter(const size_t* value){return *value;}

class NoSoundArguments : public RBX::Reflection::FunctionDescriptor::Arguments {
public:
    size_t size() const{return 0;}
    void get(int,RBX::Reflection::Value&) const{throw std::runtime_error("Unexpected sound argument");}
};
static void invokeSound(RBX::Soundscape::SoundChannel& sound,const char* name){
    RBX::Reflection::FunctionIterator fn=sound.findFunction(RBX::Name::lookup(name));
    verify(fn!=sound.functions_end());NoSoundArguments args;fn.getDescriptor().execute(&sound,args);
}

// Exercise real descriptor dispatch and XML conversion without constructing
// SoundChannel, whose native ancestry dependencies are still being recovered.
class SoundIdProbe : public RBX::Reflection::TypedPropertyDescriptor<RBX::Soundscape::SoundId> {
    struct Access : GetSet {
        mutable RBX::Soundscape::SoundId value;
        bool isReadOnly() const{return false;}
        RBX::Soundscape::SoundId getValue(const RBX::Reflection::DescribedBase*) const{return value;}
        void setValue(RBX::Reflection::DescribedBase*,const RBX::Soundscape::SoundId& next) const{value=next;}
    };
public:
    SoundIdProbe():TypedPropertyDescriptor(RBX::Stats::Item::classDescriptor(),"SoundIdProbe","Data",std::auto_ptr<GetSet>(new Access),STANDARD){}
};
class SoundIdBinder : public RBX::IReferenceBinder {
public:
    void announceID(const XmlNameValuePair*,RBX::Instance*){}
    void announceIDREF(const XmlNameValuePair*,RBX::Reflection::DescribedBase*,const RBX::IIDREF*){}
};

int main(int argc,char** argv){
    try{
        if(argc>1 && std::strcmp(argv[1],"--device-test")==0){
            std::string path=__FILE__;path=path.substr(0,path.find_last_of("/\\"))+"/fixtures/p4-assets";
            RBX::ContentProvider::singleton().setAssetFolder(argc>2?argv[2]:path.c_str());
            RBX::GameSettings::singleton().soundEnabled=true;
            RBX::GameSettings::singleton().softwareSound=true;
            boost::shared_ptr<RBX::DataModel> model=RBX::DataModel::createDataModel();
            bool opened=false,played=false;int output=-1;
            {
                RBX::DataModel::Lock lock(model);
                boost::shared_ptr<RBX::Soundscape::SoundService> service=RBX::Creatable<RBX::Instance>::create<RBX::Soundscape::SoundService>();
                service->setParent(model.get());opened=service->system!=0;
                if(opened){
                    FMOD_OUTPUTTYPE mode;check(service->system->getOutput(&mode));output=mode;
                    verify(mode!=FMOD_OUTPUTTYPE_NOSOUND && mode!=FMOD_OUTPUTTYPE_NOSOUND_NRT);
                    boost::shared_ptr<RBX::Soundscape::SoundChannel> sound=RBX::Creatable<RBX::Instance>::create<RBX::Soundscape::SoundChannel>();
                    sound->setSoundId(RBX::Soundscape::SoundId("rbxasset://tone.wav"));sound->setParent(model->getWorkspace());
                    sound->play();played=sound->isPlaying();Sleep(50);service->system->update();sound->stop();sound->setParent(0);
                }
                service->setParent(0);
            }
            RBX::DataModel::closeDataModel(model,true);model.reset();
            std::printf("P4 Sound device opened=%d playing=%d output=%d\n",opened,played,output);
            return opened && played?0:2;
        }
        verify(std::strcmp(RBX::Soundscape::sSoundChannel,"Sound")==0);
        verify(std::strcmp(RBX::Soundscape::sSoundService,"SoundService")==0);
        {
            RBX::Soundscape::SoundService service;
            RBX::Soundscape::SoundId id("rbxasset://tone.wav");
            boost::shared_ptr<RBX::Soundscape::Sound> first=service.loadSound(id,false);
            verify(first && first==service.loadSound(id,false) && first!=service.loadSound(id,true));
            RBX::Soundscape::SoundChannel sound;
            sound.setSoundId(id);verify(sound.getSoundId()==id && sound.getPlayCount()==-1);
            sound.pause();verify(sound.getPlayCount()==0);sound.stop();verify(sound.getPlayCount()==-1);
            std::printf("P4 Sound service PASS constructor/cache/channel state\n");
        }
        {
            RBX::GameSettings::singleton().soundEnabled=false;
            boost::shared_ptr<RBX::DataModel> model=RBX::DataModel::createDataModel();
            {
                RBX::DataModel::Lock lock(model);
                boost::shared_ptr<RBX::Soundscape::SoundService> service=RBX::Creatable<RBX::Instance>::create<RBX::Soundscape::SoundService>();
                service->setParent(model.get());
                verify(service->getParent()==model.get() && service->getChildren() && service->getChildren().read()->size()==14);
                for(size_t i=0;i<service->getChildren().read()->size();++i){
                    RBX::Soundscape::SoundChannel* stock=dynamic_cast<RBX::Soundscape::SoundChannel*>((*service->getChildren().read())[i].get());
                    verify(stock && stock->getSoundId().toString().find("rbxasset://Sounds\\")==0);
                }
                service->setParent(0);verify(!service->getParent() && (!service->getChildren() || service->getChildren().read()->empty()));
            }
            RBX::DataModel::closeDataModel(model,true);model.reset();
            std::printf("P4 Sound service PASS provider/14 stock sounds/detach\n");
        }
        {
            boost::shared_ptr<RBX::DataModel> model=RBX::DataModel::createDataModel();
            {
                RBX::DataModel::Lock lock(model);
                std::istringstream xml("<roblox version=\"4\"><Item class=\"Workspace\"><Properties></Properties><Item class=\"Sound\"><Properties><string name=\"Name\">TestSound</string><Content name=\"SoundId\"><url>rbxasset://tone.wav</url></Content><float name=\"Volume\">0.25</float><bool name=\"Looped\">true</bool><bool name=\"PlayOnRemove\">true</bool></Properties></Item></Item></roblox>");
                SerializerV2 serializer;serializer.loadXML(xml,model.get());
                RBX::Soundscape::SoundChannel* sound=dynamic_cast<RBX::Soundscape::SoundChannel*>(model->getWorkspace()->findFirstChildByName("TestSound"));
                verify(sound && sound->getSoundId().toString()=="rbxasset://tone.wav");
                verify(sound->getVolume()==0.25f && sound->getLooped() && sound->playOnRemove);
            }
            RBX::DataModel::closeDataModel(model,true);model.reset();
            std::printf("P4 Sound service PASS serialized SoundId/volume/loop/remove/factory\n");
        }
        {
            static SoundIdProbe probe;
            verify(probe.type.name.toString()=="Content" && probe.type.tag.toString()=="Content");
            verify(probe.setStringValue(0,"rbxasset://sounds/test.wav"));
            verify(probe.getStringValue(0)=="rbxasset://sounds/test.wav");
            std::auto_ptr<XmlElement> xml(probe.write(0,true));
            RBX::ContentId value;verify(xml.get() && xml->getValue(value) && value.toString()=="rbxasset://sounds/test.wav");
            probe.setStringValue(0,"changed");SoundIdBinder binder;probe.read(0,xml.get(),binder);
            verify(probe.getStringValue(0)=="rbxasset://sounds/test.wav");
            std::printf("P4 SoundId reflection PASS text/XML roundtrip\n");
        }
        {
            SoundServiceStatsItem stats(0);
            verify(stats.getName()=="Sound" && stats.getChildren() && stats.getChildren().read()->size()==4);
            size_t bytes=1234,count=7;
            RBX::Stats::Item* memory=stats.createBoundMemChildItem("Probe memory",bytes);
            RBX::Stats::Item* counter=stats.createBoundChildItem("Probe count",count);
            boost::function0<size_t> read=boost::bind(&readCounter,&count);
            RBX::Stats::Item* functionCounter=stats.createChildItem("Probe function",read);
            verify(memory->getValue()==1234 && counter->getValue()==7 && functionCounter->getValue()==7);
            bytes=4321;count=11;
            verify(memory->getValue()==4321 && counter->getValue()==11 && functionCounter->getValue()==11);
            std::printf("P4 Sound stats PASS four children/bound counters/lifetimes\n");
        }
        {
            float denormal=std::numeric_limits<float>::denorm_min();
            G3D::Vector3 result(9,9,9);
            verify(RBX::Soundscape::sanitizeSoundVector(G3D::Vector3(denormal,6000,-7000),result));
            verify(result==G3D::Vector3(0,5000,-5000));
            verify(!RBX::Soundscape::sanitizeSoundVector(G3D::Vector3(std::numeric_limits<float>::infinity(),0,0),result));
            verify(result==G3D::Vector3(0,5000,-5000));
            std::printf("P4 Sound listener vector PASS denormal/clamp/infinity\n");
        }
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
            boost::shared_ptr<RBX::DataModel> model=RBX::DataModel::createDataModel();
            {
                RBX::DataModel::Lock lock(model);
                boost::shared_ptr<RBX::Soundscape::SoundService> service=RBX::Creatable<RBX::Instance>::create<RBX::Soundscape::SoundService>();
                service->setParent(model.get());service->system=system;
                boost::shared_ptr<RBX::Soundscape::SoundChannel> sound=RBX::Creatable<RBX::Instance>::create<RBX::Soundscape::SoundChannel>();
                sound->setSoundId(RBX::Soundscape::SoundId("rbxasset://tone.wav"));
                sound->setParent(model->getWorkspace());sound->setVolume(2.0f);sound->setLooped(true);invokeSound(*sound,"Play");
                verify(sound->getVolume()==1.0f && sound->getLooped() && sound->getPlayCount()==1 && sound->isPlaying() && !sound->isPaused());
                verify(sound->fmod_channel && sound->sound && sound->sound->refCount==1);
                bool playing=false;check(sound->fmod_channel->isPlaying(&playing));verify(playing);
                sound->setVolume(0.25f);float volume=0;check(sound->fmod_channel->getVolume(&volume));verify(volume==0.25f);
                FMOD_MODE mode;check(sound->fmod_channel->getMode(&mode));verify((mode & FMOD_LOOP_NORMAL)!=0);
                sound->setLooped(false);check(sound->fmod_channel->getMode(&mode));verify((mode & FMOD_LOOP_OFF)!=0);
                invokeSound(*sound,"Pause");bool paused=false;check(sound->fmod_channel->getPaused(&paused));verify(paused && sound->isPaused());
                invokeSound(*sound,"Stop");verify(!sound->fmod_channel && sound->getPlayCount()==-1 && !sound->isPlaying() && sound->isPaused());
                sound->setParent(0);verify(!sound->sound);
                service->system=0;service->setParent(0);
            }
            RBX::DataModel::closeDataModel(model,true);model.reset();
            std::printf("P4 Sound service PASS native FMOD play/pause/stop/volume/loop/detach NOSOUND\n");
        }
        {
            FMOD_REVERB_PROPERTIES preset;
            FILE* presets=std::fopen("reverb-presets.bin","wb");verify(presets!=0);
            for(int i=0;i<24;++i){
                verify(RBX::Soundscape::nativeReverbPreset(static_cast<RBX::Soundscape::ReverbType>(i),preset));
                verify(std::fwrite(&preset,sizeof(preset),1,presets)==1);
            }
            std::fclose(presets);
            verify(!RBX::Soundscape::nativeReverbPreset(static_cast<RBX::Soundscape::ReverbType>(24),preset));
            verify(!RBX::Soundscape::nativeReverbPreset(static_cast<RBX::Soundscape::ReverbType>(-1),preset));
            verify(RBX::Soundscape::nativeReverbPreset(RBX::Soundscape::NoReverb,preset));
            verify(preset.Environment==-1 && preset.Room==-10000 && preset.Flags==0x33f);
            verify(RBX::Soundscape::nativeReverbPreset(RBX::Soundscape::Room,preset));
            verify(preset.Environment==1 && preset.RoomHF==-6000); // Original shares padded-cell preset.
            check(system->setReverbProperties(&preset));
            std::printf("P4 Sound reverb PASS 24 presets/invalid/original room/FMOD\n");
        }
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
