// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: openrbx-client roc_turn_on_lights_2008_b4f608dafb30ded3.cpp

// Candidate translation unit (score above; library headers required).
#include "renderlib/EffectSettings.h"
#include <GLG3D/LightingParameters.h>
#include <GLG3D/RenderDevice.h>

namespace RBX { namespace Render {

class RenderScene2008 {
    char pad[0x2d4];
    EffectSettings effectSettings;
    G3D::ReferenceCountedPointer<G3D::Lighting> desiredLighting;
    G3D::ReferenceCountedPointer<G3D::Lighting> lighting;
public:
    void turnOnLights(G3D::RenderDevice* rd, bool allLights) const;
};

void RenderScene2008::turnOnLights(G3D::RenderDevice* rd, bool allLights) const {
    rd->enableLighting();
    for (int i = 0; i < lighting->lightArray.size(); i++)
        rd->setLight(i, lighting->lightArray[i]);
    if (allLights)
        for (int i = 0; i < lighting->shadowedLightArray.size(); i++)
            rd->setLight(lighting->lightArray.size() + i, lighting->shadowedLightArray[i]);
    G3D::Color3 average = (lighting->ambientTop + lighting->ambientBottom) / 2.0f;
    rd->setAmbientLightColor(average);
    int i = lighting->shadowedLightArray.size() * 2;
    G3D::Vector3 direction(-0.4f, -1.0f, 0.1f);
    if (lighting->shadowedLightArray.size() > 0)
        direction = -lighting->shadowedLightArray[0].position.xyz();
    if (effectSettings.hemisphereLighting()) {
        if (lighting->ambientBottom != average) {
            rd->setLight(i, G3D::GLight::directional(direction, lighting->ambientBottom - average, false));
            i++;
        }
        if (lighting->ambientTop != average)
            rd->setLight(i + 1, G3D::GLight::directional(G3D::Vector3::unitY(), lighting->ambientTop - average, false));
    }
}

} }
