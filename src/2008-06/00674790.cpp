// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: ogre-1.4.5-dll roc_sparkle_native_context_accessord3483aed579e6edb.cpp

// Candidate translation unit (score above; library headers required).
#undef OGRE_NONCLIENT_BUILD
#include "roc_sparkle_native_quaternion_header85eb85047dae56f7.cpp"
// Partial binary-derived body, using the authentic Ogre 1.4.5 SDK.
// Opaque owner: only offsets observed in 00674790 are accessed. No size claim.
#undef OGRE_NONCLIENT_BUILD
#include <Ogre.h>
#include <OgreParticleEmitter.h>
#include <map>
#include <vector>
#include <cstdio>
using namespace Ogre;
extern String sparkleMaterialScript;
extern String sparkleParticleScript;
extern String resolveParticleTexture(const char*);
class ParticleAdornRecovery {
public:
    void sparkle();
    SceneManager* sceneManager() {return (*reinterpret_cast<SceneManager**>(static_cast<char*>(field<void*>(4))+4));}
    template<class T> T& field(unsigned offset) {
        return *reinterpret_cast<T*>(reinterpret_cast<char*>(this)+offset);
    }
};
void ParticleAdornRecovery::sparkle() {
    Vector3 position;
    {
        const Matrix3& rotation=field<Matrix3>(0x114);
        Quaternion orientation(1,0,0,0);
        orientation.FromRotationMatrix(rotation);
        position=field<SceneNode*>(0x30)->createChildSceneNode(field<Vector3>(0x138),orientation)->getPosition();
    }
    char name[64];
    _snprintf(name,64,"%.1f %.1f %.1f",position.x,position.y,position.z);
    typedef std::map<String,SceneNode*> Cache;
    if(field<Cache>(0xf4).find(name)!=field<Cache>(0xf4).end()) {
        ParticleSystem* system=static_cast<ParticleSystem*>(field<Cache>(0xf4)[name]->getAttachedObject(0));
        if(system->getNumParticles()) return;
        system->getEmitter(0)->setEnabled(false);
        system->setParticleQuota(1);
        field<Cache>(0xf4).erase(field<Cache>(0xf4).find(name));
        return;
    }
    std::vector<Cache::iterator> retired;
    Cache::iterator it;
    for(it=field<Cache>(0xf4).begin();it!=field<Cache>(0xf4).end();++it)
        if(!static_cast<ParticleSystem*>(it->second->getAttachedObject(0))->getNumParticles()) retired.push_back(it);
    for(unsigned i=0;i<retired.size();++i) {
        ParticleSystem* system=static_cast<ParticleSystem*>(retired[i]->second->getAttachedObject(0));
        system->getEmitter(0)->setEnabled(false);
        field<Cache>(0xf4).erase(retired[i]);
        system->setParticleQuota(1);
    }
    unsigned index;
    SceneNode* selected;
    for(index=0;index<field<std::vector<SceneNode*> >(0xdc).size();++index) {
        if(!static_cast<ParticleSystem*>(field<std::vector<SceneNode*> >(0xdc)[index]->getAttachedObject(0))->getEmitter(0)->getEnabled()) {
            selected=field<std::vector<SceneNode*> >(0xdc)[index];
            field<Cache>(0xf4)[name]=selected;
            selected->setPosition(position.x,position.y,position.z);
            ParticleSystem* system=static_cast<ParticleSystem*>(selected->getAttachedObject(0));
            system->getEmitter(0)->setEnabled(true);
            system->_update(0.001f);
            break;
        }
    }
    if(index==field<std::vector<SceneNode*> >(0xdc).size()) {
        if(!MaterialManager::getSingleton().resourceExists("sparkle/sparkleMatl")) {
            DataStreamPtr script(new MemoryDataStream(const_cast<char*>(sparkleMaterialScript.c_str()),sparkleMaterialScript.size()+1,false));
            MaterialManager::getSingleton().parseScript(script,"General");
            MaterialPtr material=MaterialManager::getSingleton().getByName("sparkle/sparkleMatl");
            material->getTechnique(0)->getPass(0)->getTextureUnitState(0)->setTextureName(resolveParticleTexture("textures\\sparkle.png"),TEX_TYPE_2D);
            if(!ParticleSystemManager::getSingleton().getTemplate("sparkle/sparkle1")) {
                DataStreamPtr particles(new MemoryDataStream(const_cast<char*>(sparkleParticleScript.c_str()),sparkleParticleScript.size()+1,false));
                ParticleSystemManager::getSingleton().parseScript(particles,"General");
            }
        }
        if(!field<SceneNode*>(0xd8)) field<SceneNode*>(0xd8)=sceneManager()->getRootSceneNode()->createChildSceneNode(sceneManager()->getName()+"rbxsparkle");
        ParticleSystem* system=sceneManager()->createParticleSystem(sceneManager()->getName()+"sparkle"+StringConverter::toString(index),"sparkle/sparkle1");
        if(!system) {
            LogManager::getSingleton().logMessage("RBX Error creating psys. John is an idiot.");
            return;
        }
        system->getEmitter(0);
        selected=field<SceneNode*>(0xd8)->createChildSceneNode();
        selected->attachObject(system);
        field<std::vector<SceneNode*> >(0xdc).push_back(selected);
        field<Cache>(0xf4)[name]=selected;
        LogManager::getSingleton().logMessage("RBX created "+system->getName());
    }
    selected->setPosition(position.x,position.y,position.z);
}
