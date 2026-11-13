// 005bcc40 / 005bcd80: native SoundService statistics item.
#include "util/Sound.h"
#include <fmod.hpp>
#pragma comment(linker,"/alternatename:_FMOD_Memory_GetStats@8=_FMOD_Memory_GetStats")

// 005c8e50: refresh the virtual item before returning its numeric value.
double RBX::Stats::Item::getValue(){update();return val;}

// 005c9bd0 / 005c9c50: memory item binds a counter and formats it on update.
RBX::Stats::TypedMemItem::TypedMemItem(const size_t* value):TypedStatsItem<size_t>(value){}
void RBX::Stats::TypedMemItem::update(){formatMem(func());}

// 005c9dc0: bind a memory counter to a new child Stats item.
RBX::Stats::Item* RBX::Stats::Item::createBoundMemChildItem(const char* name,const size_t& value){
    boost::shared_ptr<TypedMemItem> item=RBX::Creatable<RBX::Instance>::create<TypedMemItem>(&value);
    item->setName(name);item->setParent(this);return item.get();
}

SoundServiceStatsItem::SoundServiceStatsItem(const RBX::Soundscape::SoundService* source)
    :service(source),currentalloced(0),maxalloced(0){
    setName("Sound");
    createBoundMemChildItem("Current",currentalloced);
    createBoundMemChildItem("Max",maxalloced);
    createBoundChildItem("# Sounds",numSounds);
    createBoundChildItem("# Unused",numUnusedSounds);
}

static void countSounds(const std::map<RBX::Soundscape::SoundId,boost::shared_ptr<RBX::Soundscape::Sound> >& sounds,
    size_t& total,size_t& unused){
    for(std::map<RBX::Soundscape::SoundId,boost::shared_ptr<RBX::Soundscape::Sound> >::const_iterator i=sounds.begin();i!=sounds.end();++i){
        ++total;if(i->second->refCount==0)++unused;
    }
}

void SoundServiceStatsItem::update(){
    if(service->system){
        formatValue(static_cast<double>(service->fmod_version),"fmod %08x",service->fmod_version);
        int current,maximum;
        if(FMOD::Memory_GetStats(&current,&maximum)==FMOD_OK){currentalloced=current;maxalloced=maximum;}
        numSounds=0;numUnusedSounds=0;
        countSounds(service->loadedSounds,numSounds,numUnusedSounds);
        countSounds(service->loaded3DSounds,numSounds,numUnusedSounds);
    }else{
        val=0;sValue="-disabled-";
    }
}
