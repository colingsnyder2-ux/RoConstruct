// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /GS-
#include "../native-headers/StandardVerbs.h"
#include "../native-headers/v8datamodel/DataModel.h"
#include "../native-headers/gui/Gui.h"

namespace RBX {
bool StatsCommand::isChecked() const
{
    GuiRoot* root = dataModel->getGuiRoot();
    TopMenuBar* menu = dynamic_cast<TopMenuBar*>(root->findFirstChildByName("StatsHud1"));
    return (menu && menu->isVisible()) ? 1 : 0;
}
}

namespace RBX {
StatsCommand::StatsCommand(RBX::DataModel* dm)
    : Verb(static_cast<RBX::VerbContainer*>(dm), std::string("Stats")),
      dataModel(dm)
{
}
}

