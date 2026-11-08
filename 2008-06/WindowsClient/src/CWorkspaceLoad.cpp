// >>> native-status (generated) -- do not edit >>>
// CWorkspaceLoad | 2008-06 | inactive
// 0/1 exact by name (0%) | 0/1 exact bodies | no strings | verified 2026-11-07| by king_originala (chatgpt:gpt-6.1-sol)
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
