// Isolated descriptor ABI fixture, never linked into the player.
#include "v8tree/Instance.h"

const RBX::Reflection::RefPropDescriptor<RBX::Instance, RBX::Instance> RBX::Instance::propParent(
    "Parent", "Data", &RBX::Instance::getParent, &RBX::Instance::setParent,
    RBX::Reflection::PropertyDescriptor::UI);
