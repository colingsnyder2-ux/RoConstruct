// 005ba2e0: probabilistically release and erase unused cached sounds.
#include "util/Sound.h"
#include <cstdlib>

namespace RBX { namespace Soundscape {
void SoundService::gcSounds(std::map<SoundId,boost::shared_ptr<Sound> >& sounds){
    std::map<SoundId,boost::shared_ptr<Sound> >::iterator it=sounds.begin();
    while(it!=sounds.end()){
        if(it->second->refCount==0 && static_cast<float>(rand())*(1.0f/32767.0f)>=.7f){
            it->second->detach();it=sounds.erase(it);
        }else ++it;
    }
}
} }
