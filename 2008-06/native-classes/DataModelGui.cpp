// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// GuiBuilder is the native 2008-06 one (GuiHud2008/GuiBuilder2008.h: 8-byte dataModel/workspace, buildGui 00605c20),
// not the donor v8datamodel/GuiBuilder.h. 005756e0 reads DataModel::workspace at +0x204 and passes it with `this`.
// BLOCKED (core header): native-headers/v8datamodel/DataModel.h does not declare `void buildGui(Adorn*)`
// (?buildGui@DataModel@RBX@@QAEXPAVAdorn@2@@Z, identity registry 005756e0), so this unit fails with C2039 until
// the owner adds it. With that one declaration (plus `class Adorn;`) in a test overlay this body compiled
// byte-exact (prove.py, inactive_exact, 31 bytes).
#include "v8datamodel/DataModel.h"
#include "GuiHud2008/GuiBuilder2008.h"

namespace RBX {
// 005756e0
void DataModel::buildGui(Adorn* adorn)
{
    GuiBuilder builder;
    builder.buildGui(adorn, this, workspace.get());
}
}
