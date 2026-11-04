// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "v8datamodel/DataModel.h"
#include "v8datamodel/GuiBuilder.h"

namespace RBX {
void DataModel::buildGui(Adorn* adorn)
{
    GuiBuilder builder;
    builder.buildGui(adorn, this, workspace.get());
}
}
