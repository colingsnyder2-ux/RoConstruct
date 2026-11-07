// >>> native-status (generated) -- do not edit >>>
// CWorkspaceLoad | 2008-06 | inactive
// unmapped (no binary link) | by -
// <<< native-status | src 5ed58aae | roc native-status --write
#include "CWorkspace.h"
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Workspace.h"
#include "v8xml/SerializerV2.h"

void CWorkspace::load(std::istream& stream)
{
    RBX::DataModel::Lock lock(dataModel);
    SerializerV2 serializer;
    serializer.load(stream, dataModel.get());
    (dataModel ? dataModel->getWorkspace() : NULL)->joinAllHack();
}
