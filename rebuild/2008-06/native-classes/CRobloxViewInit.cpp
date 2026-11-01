#include "../native-headers/CRobloxView.h"
#include "../native-headers/CRobloxDoc.h"
#include "../native-headers/CWorkspace.h"
#include "../native-headers/ToggleToolboxVerb.h"
#include "../native-headers/v8datamodel/DataModel.h"

// Scaffolding, not recovered declarations: DataModel+0x150 and +0x170 are Notifier
// bases the native DataModel.h does not declare yet; 004218a0 is their addListener.
struct ListenerSite { void addListener(void*); };
inline ListenerSite* notifierAt(RBX::DataModel* model, unsigned offset) {
    return reinterpret_cast<ListenerSite*>(reinterpret_cast<char*>(model) + offset);
}

// 0045a4a0, first section through the toolbox verb. Remaining verbs unwritten.
void CRobloxView::OnInitialUpdate() {
    detachDataModel();                       // 0045a2f0
    window.setDataModel(0);                  // 0045f7b0
    owner_170.reset();                       // 00456e80
    CView::OnInitialUpdate();                // 006a0cc2
    CRobloxDoc* document = static_cast<CRobloxDoc*>(GetDocument());   // View+0x54
    window.setDataModel(document->workspace);
    owner_170 = document->workspace->getDataModel();                  // 0046a940, 004025b0
    RBX::DataModel::Lock lock(boost::const_pointer_cast<const RBX::DataModel>(owner_170)); // 00411b40
    RBX::DataModel* model = static_cast<RBX::DataModel*>(owner_170.get());
    if (model) notifierAt(model, 0x150)->addListener(static_cast<RBX::Listener<RBX::ServiceProvider, RBX::ServiceAdded>*>(this));
    if (model) notifierAt(model, 0x170)->addListener(static_cast<RBX::Listener<RBX::ServiceProvider, RBX::ServiceRemoving>*>(this));
    setVerbParent(model ? reinterpret_cast<RBX::VerbContainer*>(reinterpret_cast<char*>(model->getWorkspace()) + 0x2ec) : 0); // 00583210
    slot_1e0.assign(new ToggleToolboxVerb(this, model));
}
