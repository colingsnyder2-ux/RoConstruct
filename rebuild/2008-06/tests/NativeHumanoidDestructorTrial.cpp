#undef _RELEASEASSERT
#include "humanoid/roc_Humanoid_2008.h"
namespace RBX {
Humanoid::~Humanoid() { RBXASSERT(!world); } }
