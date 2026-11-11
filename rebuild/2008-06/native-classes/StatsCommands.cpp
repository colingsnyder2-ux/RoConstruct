// Native StatsCommand methods: 0057d9f0, 0057db00, 0057db90.
// >>> native-status (generated) -- do not edit >>>
// StatsCommands | 2008-06 | draft (no current byte proof)
// 0/3 mapped addresses byte-exact | 3 unproved | no mapped strings | by king_originala (+1) (mixed 2)
// <<< native-status | src 43b29c4e | roc native-status --write
#include "v8datamodel/DataModel.h"
#include "StandardVerbs.h"
#include "gui/Gui.h"

namespace RBX {
void StatsCommand::doIt(IDataState*) {
    GuiRoot* root = dataModel->getGuiRoot();
    TopMenuBar* first = dynamic_cast<TopMenuBar*>(root->findFirstChildByName("StatsHud1"));
    if (first) first->setVisible(!first->isVisible());
    TopMenuBar* second = dynamic_cast<TopMenuBar*>(root->findFirstChildByName("StatsHud2"));
    if (second) second->setVisible(!second->isVisible());
}

bool StatsCommand::isEnabled() const {
    GuiRoot* root = dataModel->getGuiRoot();
    return dynamic_cast<TopMenuBar*>(root->findFirstChildByName("StatsHud1")) != 0;
}

bool StatsCommand::isChecked() const {
    GuiRoot* root = dataModel->getGuiRoot();
    const TopMenuBar* menu = dynamic_cast<TopMenuBar*>(root->findFirstChildByName("StatsHud1"));
    return menu && menu->isVisible();
}
}
