// >>> native-status (generated) -- do not edit >>>
// CSelectionCaptionUpdate | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src db87d5fd | roc native-status --write
#include "CSelectionCaption.h"
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Selection.h"

typedef RBX::Notifier<RBX::Selection, RBX::SelectionChanged> SelectionNotifier;

CSelectionCaption::~CSelectionCaption()
{
    RBX::DataModel::Lock lock(dataModel);
    SelectionNotifier::disconnect(selection, this);
}

void CSelectionCaption::update(boost::shared_ptr<RBX::DataModel> model,
                               boost::shared_ptr<RBX::DataModel>)
{
    {
        RBX::DataModel::Lock lock(dataModel);
        SelectionNotifier::disconnect(selection, this);
        selection.reset();
    }
    dataModel.reset();
    if (model) {
        dataModel = model;
        RBX::DataModel::Lock lock(dataModel);
        selection = RBX::shared_from(RBX::ServiceProvider::create<RBX::Selection>(dataModel.get()));
        SelectionNotifier::connect(selection, this);
    }
    if (!selection) updateCaption();
}
