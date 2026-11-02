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
