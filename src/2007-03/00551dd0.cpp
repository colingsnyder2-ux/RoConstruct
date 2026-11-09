// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs roc_unit_909f36e58bb868ca.cpp

// Candidate translation unit (score above; library headers required).
#include <G3D/Vector2.h>
#include <math.h>
namespace RBX {
class GuiRoot {
public:
 static G3D::Vector2 canvasSize;
 static G3D::Vector2 toPixelSize(const G3D::Vector2&);
};
G3D::Vector2 GuiRoot::toPixelSize(const G3D::Vector2& percent) {
 G3D::Vector2 pixelSize(0,0);
 if (canvasSize.y > 0.75f * canvasSize.x)
  pixelSize = (0.01f * percent) * G3D::Vector2(canvasSize.x, 0.75f * canvasSize.x);
 else
  pixelSize = (0.01f * percent) * G3D::Vector2(1.33f * canvasSize.y, canvasSize.y);
 return pixelSize;
}

}
