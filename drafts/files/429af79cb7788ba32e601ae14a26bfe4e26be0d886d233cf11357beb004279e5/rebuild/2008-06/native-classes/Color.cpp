// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include "util/Color.h"
namespace RBX {
// 00600500: constants and local static from original x87 loads.
const G3D::Color3& Color::red() { static G3D::Color3 c(0.678431392f, 0.137254909f, 0.137254909f); return c; }
// 0064f6b0: constants and local static from original x87 loads.
const G3D::Color3& Color::blue() { static G3D::Color3 c(0.164705887f, 0.294117659f, 0.843137264f); return c; }
// 0064f6f0: constants and local static from original x87 loads.
const G3D::Color3& Color::green() { static G3D::Color3 c(0.113725491f, 0.411764711f, 0.0784313753f); return c; }
// 0064f730: constants and local static from original x87 loads.
const G3D::Color3& Color::purple() { static G3D::Color3 c(0.505882382f, 0.149019614f, 0.752941191f); return c; }
// 0064f770: constants and local static from original x87 loads.
const G3D::Color3& Color::orange() { static G3D::Color3 c(1.0f, 0.572549045f, 0.200000003f); return c; }
// 0064f7b0: constants and local static from original x87 loads.
const G3D::Color3& Color::yellow() { static G3D::Color3 c(1.0f, 0.933333337f, 0.200000003f); return c; }
// 0064f7f0: constants and local static from original x87 loads.
const G3D::Color3& Color::pink() { static G3D::Color3 c(1.0f, 0.80392158f, 0.952941179f); return c; }
// 0064f830: switch targets proven by target jump table.
const G3D::Color3& Color::colorFromIndex8(int index) { switch(index) {
case 0: return red();
case 1: return blue();
case 2: return green();
case 3: return purple();
case 4: return orange();
case 5: return yellow();
case 6: return pink();
default: { static G3D::Color3 c(0.913725495f, 0.870588243f, 0.733333349f); return c; } } }
}
