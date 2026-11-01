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
                               boost::shared_ptr<RBX::Instance>)
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
