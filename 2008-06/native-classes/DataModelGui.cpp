// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// >>> native-status (generated) -- do not edit >>>
// DataModelGui | 2008-06 | inactive
// unmapped (no binary link) | by -
// <<< native-status | src 0d3d645c | roc native-status --write
#include "v8datamodel/DataModel.h"
#include "v8datamodel/GuiBuilder.h"

namespace RBX {
void DataModel::buildGui(Adorn* adorn)
{
    GuiBuilder builder;
    builder.buildGui(adorn, this, workspace.get());
}
}
