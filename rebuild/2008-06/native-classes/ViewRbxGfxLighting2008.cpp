// native-flags: /O2 /GS- /EHsc /MD /fp:fast /I{headers}/../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include
#undef OGRE_NONCLIENT_BUILD
#include "OgreRbx/OgreException2008.h"
#define NOMINMAX
#include <winsock2.h>
#include "RenderLib/ViewNew2008.h"
#include "RenderLib/RenderSceneNew2008.h"
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Lighting2008.h"
#include "util/standardout.h"
#include "OgreRbx/VisualEngine2008.h"
#include "OgreRbx/RbxSceneManager2008.h"
#include <OgreException.h>

// 004dab50: native field/call recovery; method/access spellings remain inferred.
void RBX::ViewNew::ViewRbxGfx::updateLighting(Ogre::VisualEngine* engine)
{
    if (lightingValid) return;
    Lighting* lighting = ServiceProvider::create<Lighting>(static_cast<ServiceProvider*>(dataModel.get()));
    if (!lighting->hasSky)
        engine->sceneManager->setSkyBox(false, "", 5000.0f);
    else if (!skyValid) {
        try {
            updateSkybox(engine);
            skyValid = true;
        } catch (Ogre::Exception& error) {
            // Original catch reads the base description without virtual dispatch.
            StandardOut::singleton()->print(MESSAGE_ERROR, "Failed to load sky box. %s", error.Ogre::Exception::getDescription().c_str());
        } catch (...) {
            StandardOut::singleton()->print(MESSAGE_ERROR, "Failed to load sky box");
        }
    }
    renderLibScene->presetLighting(G3D::ReferenceCountedPointer<G3D::Sky>(),
        lighting->skyParameters, lighting->ambientTop, lighting->ambientBottom);
    RenderNew::RenderScene* scene = dynamic_cast<RenderNew::RenderScene*>(renderLibScene.get());
    scene->colorClearValue = G3D::Color4(lighting->clearColor);
    scene->shadowColor = G3D::Color4(lighting->shadowColor);
    scene->colorShiftTop = G3D::Color3(lighting->colorShiftTop);
    scene->colorShiftBottom = G3D::Color3(lighting->colorShiftBottom);
    scene->brightness = lighting->brightness;
    scene->ambient = G3D::Color3(lighting->ambient);
    scene->lightingTerm0 = G3D::Vector3(lighting->mainDiffuse.r, lighting->mainDiffuse.g, lighting->mainDiffuse.b);
    scene->lightingTerm1 = G3D::Vector3(lighting->mainSpecular.r, lighting->mainSpecular.g, lighting->mainSpecular.b);
    scene->lightingTerm2 = G3D::Vector3(lighting->fillDiffuse.r, lighting->fillDiffuse.g, lighting->fillDiffuse.b);
    scene->lightingTerm3 = G3D::Vector3(lighting->fillSpecular.r, lighting->fillSpecular.g, lighting->fillSpecular.b);
    scene->lightingTerm4 = G3D::Vector3(lighting->fillScale.r, lighting->fillScale.g, lighting->fillScale.b);
    if (!static_cast<Ogre::RbxSceneManager*>(engine->sceneManager)->mRbxSky.isNull())
        static_cast<Ogre::RbxSceneManager*>(engine->sceneManager)->mRbxSky->setLighting(engine, lighting->skyParameters);
    lightingValid = true;
}
