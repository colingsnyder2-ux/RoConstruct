// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include
#include "RbxGraphics/AdornRbxGfx2008.h"
#include <GLG3D/Texture.h>

void RBX::AdornRbxGfx::setTexture(int id, TextureProxyBaseRef texture)
{
    if (texture.isNull()) {
        texture2d = "";
        return;
    }
    texture2d = texture->filename;
    texture->resolve(reinterpret_cast<G3D::RenderDevice*>(visualEngine));
}

#include "OgreRbx/VisualEngine2008.h"
#include <OgreSceneNode.h>
#include <OgreParticleSystem.h>
#include <OgreParticleEmitter.h>
#include <cmath>

void RBX::AdornRbxGfx::prepareRenderPass()
{
    unsigned int value = Ogre::getVideoMemory();
    int limit = 10000;
    if (value < 60000000) limit = 5000;
    else if (value > 300000000) limit = 12000;
    particleCount = 0;
    std::map<std::string, Ogre::SceneNode*>::iterator it;
    for (it = explosions.begin(); it != explosions.end(); ++it) {
        Ogre::ParticleSystem* system = static_cast<Ogre::ParticleSystem*>(it->second->getAttachedObject((unsigned short)0));
        particleCount += system->getParticleQuota();
    }
    for (it = sparkles.begin(); it != sparkles.end(); ++it) {
        Ogre::ParticleSystem* system = static_cast<Ogre::ParticleSystem*>(it->second->getAttachedObject((unsigned short)0));
        particleCount += system->getParticleQuota();
    }
    int count = particleCount;
    if (count > limit) {
        float ratio = (float)limit / count;
        for (it = explosions.begin(); it != explosions.end(); ++it) {
            Ogre::ParticleSystem* system = static_cast<Ogre::ParticleSystem*>(it->second->getAttachedObject((unsigned short)0));
            Ogre::ParticleEmitter* emitter = system->getEmitter(0);
            int quota = system->getParticleQuota();
            float minVelocity = emitter->getMinParticleVelocity();
            float maxVelocity = emitter->getMaxParticleVelocity();
            float duration = emitter->getDuration();
            system->setParticleQuota((unsigned int)(quota * ratio));
            float scale = (float)pow((double)ratio, 0.3333333432674408);
            emitter->setMinParticleVelocity(scale * minVelocity);
            emitter->setMaxParticleVelocity(scale * maxVelocity);
            float newDuration = duration + (ratio - 1.0f) * 0.4000000059604645f;
            emitter->setMinDuration(newDuration);
            emitter->setMaxDuration(newDuration);
        }
        for (it = sparkles.begin(); it != sparkles.end(); ++it) {
            Ogre::ParticleSystem* system = static_cast<Ogre::ParticleSystem*>(it->second->getAttachedObject((unsigned short)0));
            system->getEmitter(0);
            system->setParticleQuota(1);
        }
        particleCount = limit;
    }
}
