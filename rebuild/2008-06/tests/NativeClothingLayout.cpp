#include "v8datamodel/Clothing.h"
#include <stddef.h>
// Sizes from Creator::create allocations: Clothing/Shirt/Pants new(0x174) (0048f71f, 0049426f, 004941ef),
// ShirtGraphic new(0x154) (0048f4af), Skin new(0x138) (004901ff). Instance is 0x130 (NativeInstanceLayout).
// IModelModifier at +0x130 from the RTTI base list (mdisp 0x130) and the +0x130 vtable stores of every ctor.
// Field offsets from Clothing ctor 005d5700 / dtor 0048fa50, ShirtGraphic ctor 005d5510, Skin ctor 005d58c0.
namespace RBX {
struct NativeClothingLayout {
    static int clothingOutfit1() { return offsetof(Clothing, outfit1); }         // 0x134
    static int clothingOutfit2() { return offsetof(Clothing, outfit2); }         // 0x154
    static int shirtGraphicGraphic() { return offsetof(ShirtGraphic, graphic); } // 0x134
    static int skinColor() { return offsetof(Skin, skinColor); }                // 0x134
};
typedef char InstanceSize[sizeof(Instance) == 0x130 ? 1 : -1];
typedef char TextureIdSize[sizeof(TextureId) == 0x20 ? 1 : -1];
typedef char AppearanceSize[sizeof(CharacterAppearance) == 0x134 ? 1 : -1];
typedef char ClothingSize[sizeof(Clothing) == 0x174 ? 1 : -1];
typedef char ShirtSize[sizeof(Shirt) == 0x174 ? 1 : -1];
typedef char PantsSize[sizeof(Pants) == 0x174 ? 1 : -1];
typedef char ShirtGraphicSize[sizeof(ShirtGraphic) == 0x154 ? 1 : -1];
typedef char SkinSize[sizeof(Skin) == 0x138 ? 1 : -1];
}
int clothingOutfit1() { return RBX::NativeClothingLayout::clothingOutfit1(); }
int clothingOutfit2() { return RBX::NativeClothingLayout::clothingOutfit2(); }
int shirtGraphicGraphic() { return RBX::NativeClothingLayout::shirtGraphicGraphic(); }
int skinColor() { return RBX::NativeClothingLayout::skinColor(); }
// The IModelModifier subobject sits at +0x130 (non-null pointer adjust).
RBX::IModelModifier* clothingModifier(RBX::Clothing* c) { return c; }
