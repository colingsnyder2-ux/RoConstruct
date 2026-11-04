#include "v8datamodel/JointsService.h"
namespace RBX {
// Donor body; 004afb30 casts Instance RTTI 0092907c to JointInstance 0093b2e4.
bool JointsService::askAddChild(const Instance* instance) const {
    return dynamic_cast<const JointInstance*>(instance) != NULL;
}
XmlElement* JointsService::write() { return NULL; }
}
