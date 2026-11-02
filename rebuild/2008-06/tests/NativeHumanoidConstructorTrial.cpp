#include "humanoid/roc_Humanoid_2008.h"
namespace RBX {
Humanoid::Humanoid() : health(100.0f), maxHealth(100.0f), walkMode(DIRECTION_MOVE), walkTimer(0), walkRotationalVelocity(0.0f), jump(false), imDead(false), hadHeadJoint(false), sit(false), strafe(false), world(NULL) { setName("Humanoid"); }
}
