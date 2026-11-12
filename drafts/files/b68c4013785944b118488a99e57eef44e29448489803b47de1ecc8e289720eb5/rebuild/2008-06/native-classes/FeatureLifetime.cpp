// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// Feature/Hole/MotorFeature constructors - native 2008-06.
// Constructor addresses from identity registry:
//   Feature::Feature() 0060be60, Hole::Hole() 0060c840, MotorFeature::MotorFeature() 0060c910
// Destructors are compiler-generated (not declared in class), so not defined here.
// >>> native-status (generated) -- do not edit >>>
// FeatureLifetime | 2008-06 | draft (no current byte proof)
// 0/3 mapped addresses byte-exact | 3 unproved | no mapped strings | by colin
// <<< native-status | src 00000000 | roc native-status --write
#include "v8datamodel/Feature.h"
namespace RBX {
extern const char sFeature[] = "Feature";
extern const char sHole[] = "Hole";
extern const char sMotorFeature[] = "MotorFeature";
Feature::Feature() : faceId(NORM_X), topBottom(CENTER_TB), leftRight(CENTER_LR), inOut(CENTER_IO) { setName("Feature"); }
Hole::Hole() { setName("Hole"); }
MotorFeature::MotorFeature() { setName("MotorFeature"); }
}
