#include "v8datamodel/Feature.h"
namespace RBX {
extern const char sFeature[] = "Feature";
extern const char sHole[] = "Hole";
extern const char sMotorFeature[] = "MotorFeature";
Feature::Feature() : faceId(NORM_X), topBottom(CENTER_TB), leftRight(CENTER_LR), inOut(CENTER_IO) { setName("Feature"); }
Feature::~Feature() {}
Hole::Hole() { setName("Hole"); }
Hole::~Hole() {}
MotorFeature::MotorFeature() { setName("MotorFeature"); }
MotorFeature::~MotorFeature() {}
}
