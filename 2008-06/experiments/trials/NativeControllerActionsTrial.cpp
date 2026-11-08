#include "StandardVerbs.h"
#include "v8datamodel/Workspace.h"
namespace RBX {
inline const Name& Verb::getName() const { return name; }
void recordCameraHistory(const char*, const Instance*);
void PrimaryControllerCommand::doIt(IDataState* state) { applyController(1); recordCameraHistory(getName().c_str(),workspace.get()); state->setDirty(true); }
void SecondaryControllerCommand::doIt(IDataState* state) { applyController(2); recordCameraHistory(getName().c_str(),workspace.get()); state->setDirty(true); }
}
