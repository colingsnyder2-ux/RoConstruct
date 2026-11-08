#include "v8datamodel/BodyColors.h"
#include <stddef.h>
// BodyColors: fields from ctor 005d59c0 (+0x134..+0x148) and the descriptor initializers 007f6150..007f6240.
// Size from Creator<BodyColors>::create 0048ff70: new(0x14c) at 0048ff8f.
namespace RBX {
struct NativeAppearanceLayout {
    static int headColor() { return offsetof(BodyColors, headColor); }         // 0x134
    static int leftArmColor() { return offsetof(BodyColors, leftArmColor); }   // 0x138
    static int rightArmColor() { return offsetof(BodyColors, rightArmColor); } // 0x13c
    static int torsoColor() { return offsetof(BodyColors, torsoColor); }       // 0x140
    static int leftLegColor() { return offsetof(BodyColors, leftLegColor); }   // 0x144
    static int rightLegColor() { return offsetof(BodyColors, rightLegColor); } // 0x148
};
typedef char AppearanceSize[sizeof(CharacterAppearance) == 0x134 ? 1 : -1];
typedef char BodyColorsSize[sizeof(BodyColors) == 0x14c ? 1 : -1];
}
int bodyHeadColor() { return RBX::NativeAppearanceLayout::headColor(); }
int bodyLeftArmColor() { return RBX::NativeAppearanceLayout::leftArmColor(); }
int bodyRightArmColor() { return RBX::NativeAppearanceLayout::rightArmColor(); }
int bodyTorsoColor() { return RBX::NativeAppearanceLayout::torsoColor(); }
int bodyLeftLegColor() { return RBX::NativeAppearanceLayout::leftLegColor(); }
int bodyRightLegColor() { return RBX::NativeAppearanceLayout::rightLegColor(); }
#include "v8datamodel/Accoutrement.h"
// Accoutrement/Hat: new(0x1d8) in Creator::create 00432520 / 00432790; fields from ctor 005b2230.
namespace RBX {
struct NativeAccoutrementLayout {
    static int state() { return offsetof(Accoutrement, backendAccoutrementState); }   // 0x154
    static int attachmentPoint() { return offsetof(Accoutrement, attachmentPoint); }   // 0x158
    static int handleTouched() { return offsetof(Accoutrement, handleTouched); }       // 0x188
    static int childAdded() { return offsetof(Accoutrement, characterChildAdded); }    // 0x19c
    static int childRemoved() { return offsetof(Accoutrement, characterChildRemoved); }// 0x1b0
};
typedef char AccoutrementSize[sizeof(Accoutrement) == 0x1d8 ? 1 : -1];
typedef char HatSize[sizeof(Hat) == 0x1d8 ? 1 : -1];
}
int accState() { return RBX::NativeAccoutrementLayout::state(); }
int accAttachmentPoint() { return RBX::NativeAccoutrementLayout::attachmentPoint(); }
int accHandleTouched() { return RBX::NativeAccoutrementLayout::handleTouched(); }
int accChildAdded() { return RBX::NativeAccoutrementLayout::childAdded(); }
int accChildRemoved() { return RBX::NativeAccoutrementLayout::childRemoved(); }
RBX::IEquipable* accEquipable(RBX::Accoutrement* a) { return a; }     // +0x130
RBX::IRenderable* accRenderable(RBX::Accoutrement* a) { return a; }   // +0x140
