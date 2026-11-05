// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs roc_espeon_aug2007_legacy_appearance_84b8195c3c05050d.cpp

// Candidate translation unit (score above; library headers required).
#pragma include_alias("v8tree/Instance.h", "../roc_espeon_aug2007_instance_header_47f25dc9e4368119.cpp")
#pragma include_alias("v8datamodel/PartInstance.h", "../roc_espeon_aug2007_part_header_7a4c998b489b0ddf.cpp")
#include "roc_espeon_aug2007_instance_header_47f25dc9e4368119.cpp"
#include "v8datamodel/CharacterAppearance.h"
namespace RBX {
Reflection::BoundProp<BrickColor, 1> BodyColors::prop_HeadColor("HeadColor", "Appearance", &BodyColors::headColor, &BodyColors::dataChanged, Reflection::PropertyDescriptor::STANDARD);
Reflection::BoundProp<BrickColor, 1> BodyColors::prop_LeftArmColor("LeftArmColor", "Appearance", &BodyColors::leftArmColor, &BodyColors::dataChanged, Reflection::PropertyDescriptor::STANDARD);
Reflection::BoundProp<BrickColor, 1> BodyColors::prop_RightArmColor("RightArmColor", "Appearance", &BodyColors::rightArmColor, &BodyColors::dataChanged, Reflection::PropertyDescriptor::STANDARD);
Reflection::BoundProp<BrickColor, 1> BodyColors::prop_TorsoColor("TorsoColor", "Appearance", &BodyColors::torsoColor, &BodyColors::dataChanged, Reflection::PropertyDescriptor::STANDARD);
Reflection::BoundProp<BrickColor, 1> BodyColors::prop_LeftLegColor("LeftLegColor", "Appearance", &BodyColors::leftLegColor, &BodyColors::dataChanged, Reflection::PropertyDescriptor::STANDARD);
Reflection::BoundProp<BrickColor, 1> BodyColors::prop_RightLegColor("RightLegColor", "Appearance", &BodyColors::rightLegColor, &BodyColors::dataChanged, Reflection::PropertyDescriptor::STANDARD);
}

namespace RBX {
Reflection::BoundProp<BrickColor, 1> Shirt::prop_leftSleeveColor("LeftSleeveColor", "Appearance", &Shirt::leftSleeveColor, &Shirt::dataChanged, Reflection::PropertyDescriptor::STANDARD);
Reflection::BoundProp<BrickColor, 1> Shirt::prop_rightSleeveColor("RightSleeveColor", "Appearance", &Shirt::rightSleeveColor, &Shirt::dataChanged, Reflection::PropertyDescriptor::STANDARD);
Reflection::BoundProp<BrickColor, 1> Shirt::prop_torsoColor("TorsoColor", "Appearance", &Shirt::torsoColor, &Shirt::dataChanged, Reflection::PropertyDescriptor::STANDARD);
}
