#include "CWorkspace.h"
#include "v8datamodel/DataModel.h"
RBX::Workspace* CWorkspace::getWorkspace()
{
    return dataModel ? dataModel->getWorkspace() : NULL;
}
