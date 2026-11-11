// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /I{headers}/../../../tools/libs/ogre-1.4.5/ogrenew/OgreMain/include
// >>> native-status (generated) -- do not edit >>>
// TextureShadePixel2008 | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src b3851010 | roc native-status --write
#undef OGRE_NONCLIENT_BUILD
#define NOMINMAX
#include "RenderLib/TextureProxy2008.h"
#include <G3D/Color3uint8.h>
#include <G3D/g3dmath.h>
#include <algorithm>
#include <cmath>
namespace RBX { namespace RenderNew {
// INFERRED: method declaration from original resolve caller; body from 2008 donor.
void TextureProxy::shadePixel(const G3D::Color3uint8& base, G3D::Color3uint8& lighting) {
 for (int i = 0; i < 3; i++) {
  const int shade = lighting[i];
  float color = base[i];
  if (shade > 130) {
   float a = std::min(float((shade - 128.0f) / 128.0f), 1.0f);
   color = (1.0 - a) * color + 255.0f * a;
  } else if (shade < 126) {
   float a = shade / 128.0f;
   a = 0.5 + a * 0.5;
   color = color * a;
  }
  lighting[i] = std::min(255, std::max(0, G3D::iRound(255.0 * pow(color / 255.0, 1.0))));
 }
}
}}
