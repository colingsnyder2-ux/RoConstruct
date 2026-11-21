// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include
// 0066fe30 (slot 12): AdornRbxGfx::get2DStringBounds -> RbxFont::get2DStringBounds 00684640 on font2d (pRep 00962dac).
// INFERRED: slot/signature from AdornRbxGfx2008.h; body shape (forward, copy x/y) mirrors drawFont2D 0066fda0.
#include "RbxGraphics/AdornRbxGfx2008.h"
#include "OgreRbx/VisualEngine2008.h"
#include "OgreRbx/VRbxFont2008.h"
#include <OgreSceneManager.h>
#include <OgreSceneNode.h>
#include <OgreParticleSystem.h>
#include <OgreParticleEmitter.h>
#include <OgreParticleSystemManager.h>
#include <OgreMaterialManager.h>
#include <OgreTechnique.h>
#include <OgrePass.h>
#include <OgreTextureUnitState.h>
#include <OgreLogManager.h>
#include <OgreStringConverter.h>
#include <OgreDataStream.h>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <G3D/Sphere.h>
#include "OgreRbx/RbxEntity2008.h"
#include "AppUnit67C_2008/RbxSubEntity2008.h"

namespace RBX
{
    extern Ogre::SharedPtr<Ogre::RbxFont> font2d;

    G3D::Vector2 AdornRbxGfx::get2DStringBounds(const std::string& s, double size, Spacing spacing) const
    {
        G3D::Vector2 bounds = font2d->get2DStringBounds(s, size, (Ogre::RbxFont::Spacing)spacing);
        return G3D::Vector2(bounds.x, bounds.y);
    }

    // 00671d60: the sub-entity pool of the 3D primitives (+0x48 free, +0x60 in use; constructor 00685660 with entity +0x98).
    Ogre::RbxSubEntity* AdornRbxGfx::allocateSubEntity()
    {
        Ogre::RbxSubEntity* subEntity;
        if (freeSubEntities.size() != 0)
        {
            subEntity = freeSubEntities[freeSubEntities.size() - 1];
            freeSubEntities.pop_back();
            usedSubEntities.push_back(subEntity);
            return subEntity;
        }
        subEntity = new Ogre::RbxSubEntity(entity);
        usedSubEntities.push_back(subEntity);
        return subEntity;
    }

#ifdef NATIVE_ADORN_ADDMESH_PENDING
    // 00671f00: BLOCKED on AppUnit67C_2008/RbxSubEntity2008.h (owner: AppUnit67C / RbxSubEntity family):
    //   * the original calls an out-of-line one-argument SubMesh setter on the sub-entity (`push submesh; call
    //     004208f0`, ICF-folded `mov [ecx+0x54], arg; ret 4` = SubEntity::mSubMesh); RbxSubEntity declares only the
    //     two-argument setSubMesh(int, SubMesh*) 006850b0;
    //   * the 0x40-byte `rep movsd` into +0xf0 writes the protected RbxSubEntity::mTransform, which needs a friend
    //     declaration for RBX::AdornRbxGfx (or an inline public setter) in that header.
    // The body below is the evidence-backed shape for when both land (names INFERRED: setSubMesh / mTransform).
    void AdornRbxGfx::addMesh(const Ogre::MeshPtr& mesh, const Ogre::Matrix4& transform, const Ogre::MaterialPtr& material)
    {
        for (int i = 0; i < mesh->getNumSubMeshes(); ++i)
        {
            Ogre::RbxSubEntity* subEntity = allocateSubEntity();
            subEntity->setSubMesh(mesh->getSubMesh(i));
            subEntity->mTransform = transform;
            subEntity->setMaterial(material);
            entity->func_0067da50(subEntity);
        }
    }
#endif

    // 0066fe30 neighbourhood ends here; the members below are the sparkle effect of the same original unit.

    // INFERRED name: 0055d0b0 (folded with RBX::LDraw2Lua::resolveMapPath, native-classes/LDrawPath.cpp) maps an asset
    // path below the content folder; sparkle passes "textures\\sparkle.png" (0084d578).
    namespace LDraw2Lua { std::string resolveMapPath(const char* path); }

    // 0097db0c / 0097daf0: file-scope std::string objects built by the dynamic initializers 007f9030 / 007f9050 from the
    // literals 0084d688 / 0084d750 (atexit destructors 00801490 / 008014a0). Names are naming choices.
    static std::string sparkleMaterialScript =
    "material sparkle/sparkleMatl\n"
    "{\n"
    "\ttechnique\n"
    "\t{\n"
    "\t\tpass\n"
    "\t\t{\n"
    "\t\t\tlighting off\n"
    "\t\t\tdepth_write off\n"
    "\t\t\tscene_blend add\n"
    "\n"
    "\t\t\ttexture_unit\n"
    "\t\t\t{\n"
    "\t\t\t\ttexture sparkle.png\n"
    "\t\t\t\tcolour_op modulate\n"
    "\t\t\t}\n"
    "\t\t}\n"
    "\t}\n"
    "}\n";
    static std::string sparkleParticleScript =
    "sparkle/sparkle1\n"
    "{\n"
    "\tquota\t40\n"
    "\tmaterial\tsparkle/sparkleMatl\n"
    "\tparticle_width\t1\n"
    "\tparticle_height\t1\n"
    "\tcull_each\tfalse\n"
    "\trenderer\tbillboard\n"
    "\tsorted\tfalse\n"
    "\tlocal_space\tfalse\n"
    "\titeration_interval\t0\n"
    "\tnonvisible_update_timeout\t0\n"
    "\tbillboard_type\tpoint\n"
    "\tbillboard_origin\tcenter\n"
    "\tbillboard_rotation_type\tvertex\n"
    "\tcommon_up_vector\t0 1 0\n"
    "\tpoint_rendering\tfalse\n"
    "\taccurate_facing\tfalse\n"
    "\n"
    "\temitter Point\n"
    "\t{\n"
    "\t\tangle\t180\n"
    "\t\tcolour\t0.3 0.3 0.3 .6\n"
    "\t\tcolour_range_start\t0.25 0.25 0.25 1\n"
    "\t\tcolour_range_end\t0.5 0.5 0.5 1\n"
    "\t\tdirection\t0 -1 0\n"
    "\t\temission_rate\t160\n"
    "\t\tposition\t0 0 0\n"
    "\t\tvelocity_min\t5\n"
    "\t\tvelocity_max\t10\n"
    "\t\tduration\t.2\n"
    "\t\ttime_to_live\t1\n"
    "\t}\n"
    "\n"
    "\taffector Rotator\n"
    "\t{\n"
    "\t\trotation_speed_range_end 360\n"
    "\t\trotation_range_start 0\n"
    "\t\trotation_range_end   360\n"
    "\t}\n"
    "\n"
    "}\n"
;

    // 00674790 (slot 19): one sparkle emitter per position (key "%.1f %.1f %.1f" of the derived position of the current
    // object-to-world frame) in sparkles (+0xf4); emitters live on child nodes of sparkleRoot (+0xd8), pooled in
    // sparkleNodes (+0xdc). Callees: map find 00696f30, erase 00696c50, operator[] 00671910, vector push_back 006740e0.
    void AdornRbxGfx::sparkle()
    {
        Ogre::Quaternion q;
        q.FromRotationMatrix(reinterpret_cast<const Ogre::Matrix3&>(objectToWorld.rotation));
        Ogre::Vector3 pos = rootNode->createChildSceneNode(reinterpret_cast<const Ogre::Vector3&>(objectToWorld.translation), q)
                                ->getPosition();
        char buf[64];
        _snprintf(buf, 64, "%.1f %.1f %.1f", pos.x, pos.y, pos.z);

        if (sparkles.find(buf) != sparkles.end())
        {
            Ogre::ParticleSystem* system = static_cast<Ogre::ParticleSystem*>(sparkles[buf]->getAttachedObject(0));
            if (system->getNumParticles() == 0)
            {
                system->getEmitter(0)->setEnabled(false);
                system->setParticleQuota(1);
                sparkles.erase(sparkles.find(buf));
            }
            return;
        }

        std::vector<std::map<std::string, Ogre::SceneNode*>::iterator> finished;
        for (std::map<std::string, Ogre::SceneNode*>::iterator it = sparkles.begin(); it != sparkles.end(); ++it)
        {
            Ogre::ParticleSystem* system = static_cast<Ogre::ParticleSystem*>(it->second->getAttachedObject(0));
            if (system->getNumParticles() == 0)
                finished.push_back(it);
        }
        for (unsigned int j = 0; j < finished.size(); ++j)
        {
            Ogre::ParticleSystem* system = static_cast<Ogre::ParticleSystem*>(finished[j]->second->getAttachedObject(0));
            system->getEmitter(0)->setEnabled(false);
            sparkles.erase(finished[j]);
            system->setParticleQuota(1);
        }

        Ogre::SceneNode* node;
        unsigned int i;
        for (i = 0; i < sparkleNodes.size(); ++i)
        {
            Ogre::ParticleSystem* system = static_cast<Ogre::ParticleSystem*>(sparkleNodes[i]->getAttachedObject(0));
            if (!system->getEmitter(0)->getEnabled())
            {
                node = sparkleNodes[i];
                sparkles[buf] = node;
                node->setPosition(pos.x, pos.y, pos.z);
                Ogre::ParticleSystem* reused = static_cast<Ogre::ParticleSystem*>(node->getAttachedObject(0));
                reused->getEmitter(0)->setEnabled(true);
                reused->_update(0.001f);
                break;
            }
        }

        if (i == sparkleNodes.size())
        {
            if (!Ogre::MaterialManager::getSingleton().resourceExists("sparkle/sparkleMatl"))
            {
                Ogre::DataStreamPtr materialStream(new Ogre::MemoryDataStream(
                    (void*)sparkleMaterialScript.c_str(), sparkleMaterialScript.size() + 1, false));
                Ogre::MaterialManager::getSingleton().parseScript(materialStream, "General");
                Ogre::MaterialPtr material = Ogre::MaterialManager::getSingleton().getByName("sparkle/sparkleMatl");
                material->getTechnique(0)->getPass(0)->getTextureUnitState(0)->setTextureName(
                    LDraw2Lua::resolveMapPath("textures\\sparkle.png"));
                if (Ogre::ParticleSystemManager::getSingleton().getTemplate("sparkle/sparkle1") == NULL)
                {
                    Ogre::DataStreamPtr particleStream(new Ogre::MemoryDataStream(
                        (void*)sparkleParticleScript.c_str(), sparkleParticleScript.size() + 1, false));
                    Ogre::ParticleSystemManager::getSingleton().parseScript(particleStream, "General");
                }
            }
            if (sparkleRoot == NULL)
            {
                Ogre::SceneManager* sceneManager = visualEngine->sceneManager;
                sparkleRoot = sceneManager->getRootSceneNode()->createChildSceneNode(
                    visualEngine->sceneManager->getName() + "rbxsparkle", Ogre::Vector3::ZERO, Ogre::Quaternion::IDENTITY);
            }
            Ogre::SceneManager* sceneManager = visualEngine->sceneManager;
            Ogre::ParticleSystem* system = sceneManager->createParticleSystem(
                visualEngine->sceneManager->getName() + "sparkle" + Ogre::StringConverter::toString(i), "sparkle/sparkle1");
            if (system == NULL)
            {
                Ogre::LogManager::getSingleton().logMessage("RBX Error creating psys. John is an idiot.");
                return;
            }
            system->getEmitter(0);
            node = sparkleRoot->createChildSceneNode(Ogre::Vector3::ZERO, Ogre::Quaternion::IDENTITY);
            node->attachObject(system);
            sparkleNodes.push_back(node);
            sparkles[buf] = node;
            Ogre::LogManager::getSingleton().logMessage("RBX created " + system->getName());
        }
        node->setPosition(pos.x, pos.y, pos.z);
    }

    // 0097da84 / 0097daa0 / 0097da5c: built by the dynamic initializers 007f9070 / 007f9090 (literals 0084da30 /
    // 0084daf8) and 007f90b0 (MaterialPtr()), after the sparkle scripts. Names are naming choices.
    static std::string explosionMaterialScript =
    "material explosion/explosionMatl\n"
    "{\n"
    "\ttechnique\n"
    "\t{\n"
    "\t\tpass\n"
    "\t\t{\n"
    "\t\t\tlighting off\n"
    "\t\t\tdepth_write off\n"
    "\t\t\tscene_blend add\n"
    "\n"
    "\t\t\ttexture_unit\n"
    "\t\t\t{\n"
    "\t\t\t\ttexture explosion.png\n"
    "\t\t\t\tcolour_op modulate\n"
    "\t\t\t}\n"
    "\t\t}\n"
    "\t}\n"
    "}\n";
    static std::string explosionParticleScript =
    "explosion/explosion1\n"
    "{\n"
    "\tquota\t400\n"
    "\tmaterial\texplosion/explosionMatl\n"
    "\tparticle_width\t5\n"
    "\tparticle_height\t5\n"
    "\tcull_each\tfalse\n"
    "\trenderer\tbillboard\n"
    "\tsorted\tfalse\n"
    "\tlocal_space\tfalse\n"
    "\titeration_interval\t0\n"
    "\tnonvisible_update_timeout\t0\n"
    "\tbillboard_type\tpoint\n"
    "\tbillboard_origin\tcenter\n"
    "\tbillboard_rotation_type\tvertex\n"
    "\tcommon_up_vector\t0 1 0\n"
    "\tpoint_rendering\tfalse\n"
    "\taccurate_facing\tfalse\n"
    "\n"
    "\temitter Point\n"
    "\t{\n"
    "\t\tangle\t180\n"
    "\t\tcolour\t0.3 0.3 0.3 .6\n"
    "\t\tcolour_range_start\t0.25 0.25 0.25 1\n"
    "\t\tcolour_range_end\t0.5 0.5 0.5 1\n"
    "\t\tdirection\t0 -1 0\n"
    "\t\temission_rate\t20000\n"
    "\t\tposition\t0 0 0\n"
    "\t\tvelocity\t30\n"
    "\t\tvelocity_min\t20\n"
    "\t\tvelocity_max\t30\n"
    "\t\ttime_to_live\t0.3\n"
    "\t\ttime_to_live_min\t0.25\n"
    "\t\ttime_to_live_max\t0.35\n"
    "\t\tduration\t1.2\n"
    "\t\tduration_min\t1.2\n"
    "\t\tduration_max\t1.2\n"
    "\t\trepeat_delay\t10000\n"
    "\t\trepeat_delay_min\t10000\n"
    "\t\trepeat_delay_max\t10000\n"
    "\t}\n"
    "\n"
    "\taffector DeflectorPlane\n"
    "\t{\n"
    "\t\tplane_point\t0 0 0\n"
    "\t\tplane_normal\t0 1 0\n"
    "\t\tbounce\t0\n"
    "\t}\n"
    "\n"
    "\taffector DirectionRandomiser\n"
    "\t{\n"
    "\t\trandomness\t0\n"
    "\t\tscope\t1\n"
    "\t\tkeep_velocity\tfalse\n"
    "\t}\n"
    "}\n"
;
    static Ogre::MaterialPtr explosionMaterial;

    // The quota / velocity / duration block below appears three times in 00675360, twice with a constant 1.0 ratio
    // (atoi("400") without fmul, pow(1.0, 1/3) through _CIpow, atoi("1.2") without the (ratio - 1) * 0.4 term). An
    // out-of-line static helper is not inlined by VS2008 here, so the blocks are written out. The atoi strings repeat
    // the explosion1 script values.
    // 00675360 (slot 18): one explosion emitter per position (key "%.3f %.3f %.3f") in explosions (+0xb8); emitters live
    // on child nodes of explosionRoot (+0x9c), pooled in explosionNodes (+0xa0). The ratio is radius * 0.25 capped at 3.
    void AdornRbxGfx::explosion(const G3D::Sphere& sph, const G3D::Color4& solidColor, const G3D::Color4& wireColor)
    {
        Ogre::Quaternion q;
        q.FromRotationMatrix(reinterpret_cast<const Ogre::Matrix3&>(objectToWorld.rotation));
        Ogre::Vector3 pos = rootNode->createChildSceneNode(reinterpret_cast<const Ogre::Vector3&>(objectToWorld.translation), q)
                                ->getPosition();
        char buf[64];
        _snprintf(buf, 64, "%.3f %.3f %.3f", pos.x, pos.y, pos.z);
        Ogre::LogManager::getSingleton().logMessage(std::string("RBX expl ") + " r=" + Ogre::StringConverter::toString(sph.radius));

        if (explosions.find(buf) != explosions.end())
        {
            Ogre::ParticleSystem* system = static_cast<Ogre::ParticleSystem*>(explosions[buf]->getAttachedObject(0));
            if (system->getNumParticles() == 0)
            {
                Ogre::ParticleEmitter* emitter = system->getEmitter(0);
                system->setParticleQuota((unsigned int)(atoi("400") * 1.0f));
                emitter->setMinParticleVelocity(atoi("20") * pow(1.0f, 1.0f / 3.0f));
                emitter->setMaxParticleVelocity(atoi("30") * pow(1.0f, 1.0f / 3.0f));
                emitter->setMinDuration(atoi("1.2") + (1.0f - 1.0f) * 0.4f);
                emitter->setMaxDuration(atoi("1.2") + (1.0f - 1.0f) * 0.4f);
                emitter->setEnabled(false);
                explosions.erase(explosions.find(buf));
            }
            return;
        }

        std::vector<std::map<std::string, Ogre::SceneNode*>::iterator> finished;
        for (std::map<std::string, Ogre::SceneNode*>::iterator it = explosions.begin(); it != explosions.end(); ++it)
        {
            Ogre::ParticleSystem* system = static_cast<Ogre::ParticleSystem*>(it->second->getAttachedObject(0));
            if (system->getNumParticles() == 0)
                finished.push_back(it);
        }
        for (unsigned int j = 0; j < finished.size(); ++j)
        {
            Ogre::ParticleSystem* system = static_cast<Ogre::ParticleSystem*>(finished[j]->second->getAttachedObject(0));
            Ogre::ParticleEmitter* emitter = system->getEmitter(0);
            emitter->setEnabled(false);
            explosions.erase(finished[j]);
            Ogre::LogManager::getSingleton().logMessage("RBX retired " + system->getName());
            system->setParticleQuota((unsigned int)(atoi("400") * 1.0f));
            emitter->setMinParticleVelocity(atoi("20") * pow(1.0f, 1.0f / 3.0f));
            emitter->setMaxParticleVelocity(atoi("30") * pow(1.0f, 1.0f / 3.0f));
            emitter->setMinDuration(atoi("1.2") + (1.0f - 1.0f) * 0.4f);
            emitter->setMaxDuration(atoi("1.2") + (1.0f - 1.0f) * 0.4f);
        }

        float ratio = sph.radius * 0.25f;
        if (ratio > 3.0f)
            ratio = 3.0f;

        Ogre::SceneNode* node;
        unsigned int i;
        for (i = 0; i < explosionNodes.size(); ++i)
        {
            Ogre::ParticleSystem* system = static_cast<Ogre::ParticleSystem*>(explosionNodes[i]->getAttachedObject(0));
            if (!system->getEmitter(0)->getEnabled())
            {
                node = explosionNodes[i];
                explosions[buf] = node;
                node->setPosition(pos.x, pos.y, pos.z);
                Ogre::ParticleSystem* reused = static_cast<Ogre::ParticleSystem*>(node->getAttachedObject(0));
                Ogre::ParticleEmitter* emitter = reused->getEmitter(0);
                reused->setParticleQuota((unsigned int)(atoi("400") * ratio));
                emitter->setMinParticleVelocity(atoi("20") * pow(ratio, 1.0f / 3.0f));
                emitter->setMaxParticleVelocity(atoi("30") * pow(ratio, 1.0f / 3.0f));
                emitter->setMinDuration(atoi("1.2") + (ratio - 1.0f) * 0.4f);
                emitter->setMaxDuration(atoi("1.2") + (ratio - 1.0f) * 0.4f);
                emitter->setEnabled(true);
                reused->_update(0.001f);
                Ogre::LogManager::getSingleton().logMessage("RBX use " + reused->getName());
                break;
            }
        }

        if (i == explosionNodes.size())
        {
            if (!Ogre::MaterialManager::getSingleton().resourceExists("explosion/explosionMatl"))
            {
                Ogre::DataStreamPtr materialStream(new Ogre::MemoryDataStream(
                    (void*)explosionMaterialScript.c_str(), explosionMaterialScript.size() + 1, false));
                Ogre::MaterialManager::getSingleton().parseScript(materialStream, "General");
                explosionMaterial = Ogre::MaterialManager::getSingleton().getByName("explosion/explosionMatl");
                explosionMaterial->getTechnique(0)->getPass(0)->getTextureUnitState(0)->setTextureName(
                    LDraw2Lua::resolveMapPath("textures\\explosion.png"));
                if (Ogre::ParticleSystemManager::getSingleton().getTemplate("explosion/explosion1") == NULL)
                {
                    Ogre::DataStreamPtr particleStream(new Ogre::MemoryDataStream(
                        (void*)explosionParticleScript.c_str(), explosionParticleScript.size() + 1, false));
                    Ogre::ParticleSystemManager::getSingleton().parseScript(particleStream, "General");
                }
            }
            if (explosionRoot == NULL)
            {
                Ogre::SceneManager* sceneManager = visualEngine->sceneManager;
                explosionRoot = sceneManager->getRootSceneNode()->createChildSceneNode(
                    visualEngine->sceneManager->getName() + "rbxexpl", Ogre::Vector3::ZERO, Ogre::Quaternion::IDENTITY);
            }
            Ogre::ParticleSystem* system = visualEngine->sceneManager->createParticleSystem(
                visualEngine->sceneManager->getName() + "expl" + Ogre::StringConverter::toString(i), "explosion/explosion1");
            if (system == NULL)
            {
                Ogre::LogManager::getSingleton().logMessage("RBX Error creating psys");
                return;
            }
            Ogre::ParticleEmitter* emitter = system->getEmitter(0);
            system->setParticleQuota((unsigned int)(atoi("400") * ratio));
            emitter->setMinParticleVelocity(atoi("20") * pow(ratio, 1.0f / 3.0f));
            emitter->setMaxParticleVelocity(atoi("30") * pow(ratio, 1.0f / 3.0f));
            emitter->setMinDuration(atoi("1.2") + (ratio - 1.0f) * 0.4f);
            emitter->setMaxDuration(atoi("1.2") + (ratio - 1.0f) * 0.4f);
            node = explosionRoot->createChildSceneNode(Ogre::Vector3::ZERO, Ogre::Quaternion::IDENTITY);
            node->attachObject(system);
            explosionNodes.push_back(node);
            explosions[buf] = node;
            Ogre::LogManager::getSingleton().logMessage("RBX created " + system->getName());
        }
        node->setPosition(pos.x, pos.y, pos.z);
    }
}
