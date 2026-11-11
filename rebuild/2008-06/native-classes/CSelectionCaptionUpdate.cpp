// >>> native-status (generated) -- do not edit >>>
// CSelectionCaptionUpdate | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src fbe0d546 | roc native-status --write
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

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class boost::shared_ptr<RBX::Selection const >;
template class std::_Container_base_aux_alloc_real<std::allocator<RBX::MarshaledListener<RBX::Selection,RBX::SelectionChanged,RBX::Selection,RBX::SelectionChanged>::EventData *> >;
template class std::_Vector_const_iterator<RBX::MarshaledListener<RBX::Selection,RBX::SelectionChanged,RBX::Selection,RBX::SelectionChanged>::EventData *,std::allocator<RBX::MarshaledListener<RBX::Selection,RBX::SelectionChanged,RBX::Selection,RBX::SelectionChanged>::EventData *> >;
template class std::_Vector_iterator<RBX::MarshaledListener<RBX::Selection,RBX::SelectionChanged,RBX::Selection,RBX::SelectionChanged>::EventData *,std::allocator<RBX::MarshaledListener<RBX::Selection,RBX::SelectionChanged,RBX::Selection,RBX::SelectionChanged>::EventData *> >;
template class std::_Vector_val<RBX::MarshaledListener<RBX::Selection,RBX::SelectionChanged,RBX::Selection,RBX::SelectionChanged>::EventData *,std::allocator<RBX::MarshaledListener<RBX::Selection,RBX::SelectionChanged,RBX::Selection,RBX::SelectionChanged>::EventData *> >;
template class std::vector<RBX::MarshaledListener<RBX::Selection,RBX::SelectionChanged,RBX::Selection,RBX::SelectionChanged>::EventData *,std::allocator<RBX::MarshaledListener<RBX::Selection,RBX::SelectionChanged,RBX::Selection,RBX::SelectionChanged>::EventData *> >;
