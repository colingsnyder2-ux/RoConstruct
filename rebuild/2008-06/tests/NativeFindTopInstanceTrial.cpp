#include "v8datamodel/Workspace.h"
namespace RBX {
Instance* Workspace::findTopInstance(Instance* instance) {
    Instance* workspace = instance->getParent();
    Instance* data = workspace->getParent();
    while (data->getParent()) {
        workspace = data;
        data = data->getParent();
    }
    while (instance->getParent() != workspace) instance = instance->getParent();
    return instance;
}
}
