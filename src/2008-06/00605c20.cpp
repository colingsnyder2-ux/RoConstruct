// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lang: cpp
// roc-lib: rbxgs-dll roc_guibuilder_native_assembly_efa31104829b8758.cpp

// Candidate translation unit (score above; library headers required).
#include <v8datamodel/GuiBuilder.h>
namespace RBX {
class DataModelGuiApi {
public:
    // Genuine public DataModel::getGuiRoot()const. Native sharedowner field21c.
    GuiRoot* getGuiRoot() const {
        return ((const boost::shared_ptr<GuiRoot>*)((const char*)this+0x21c))->get();
    }
};
void GuiBuilder::buildGui(Adorn* adorn,DataModel* model,Workspace* world) {
    dataModel=model;
    workspace=world;
    ((DataModelGuiApi*)dataModel)->getGuiRoot()->addGuiItem(buildStatsHud1());
    ((DataModelGuiApi*)dataModel)->getGuiRoot()->addGuiItem(buildStatsHud2());
    ((DataModelGuiApi*)dataModel)->getGuiRoot()->addGuiItem(buildChatHud());
    ((DataModelGuiApi*)dataModel)->getGuiRoot()->addGuiItem(buildChatMenu(adorn));
    ((DataModelGuiApi*)dataModel)->getGuiRoot()->addGuiItem(buildScoreHud());
    ((DataModelGuiApi*)dataModel)->getGuiRoot()->addGuiItem(buildHealthHud());
    ((DataModelGuiApi*)dataModel)->getGuiRoot()->addGuiItem(buildMenu());
    ((DataModelGuiApi*)dataModel)->getGuiRoot()->addGuiItem(buildRightPalette(adorn));
    ((DataModelGuiApi*)dataModel)->getGuiRoot()->addGuiItem(buildControlHud(adorn,20));
}
}
