#include "v8datamodel/JointsService.h"
namespace RBX {
JointsService::JointsService() : world(NULL) { setName("JointsService"); }
void JointsService::onDescendentAdded(Instance* instance) {
    Instance::onDescendentAdded(instance);
    IRenderable* renderable = dynamic_cast<IRenderable*>(instance);
    if (renderable) onAdded(renderable);
}
void JointsService::onDescendentRemoving(const boost::shared_ptr<Instance>& instance) {
    IRenderable* renderable = dynamic_cast<IRenderable*>(instance.get());
    if (renderable) onRemoving(renderable);
    Instance::onDescendentRemoving(instance);
}
// Donor body; 004afb30 casts Instance RTTI 0092907c to JointInstance 0093b2e4.
bool JointsService::askAddChild(const Instance* instance) const {
    return dynamic_cast<const JointInstance*>(instance) != NULL;
}
XmlElement* JointsService::write() { return NULL; }
}
