// >>> native-status (generated) -- do not edit >>>
// CRobloxReportViewDataModel | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 28fa56a9 | roc native-status --write
#include "CRobloxReportView.h"
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Stats.h"
#include "CRobloxDoc.h"

namespace RBX { class RunService; }

// Original 00458700 (open, 669 vs 700 bytes): every statement aligns; the original emits a separate release of
// the argument for the early return and tail-merges it into the final release, this build jumps to the common one.
void CRobloxReportView::setDataModel(boost::shared_ptr<RBX::DataModel> dataModel)
{
    if (dataModel == this->dataModel)
        return;
    if (this->dataModel) {
        RBX::DataModel::Lock lock(this->dataModel);
        // ServiceProvider::find<RunService>(provider) inline form (null test, member find 00452c80; result unused).
        if (const RBX::ServiceProvider* provider = this->dataModel.get())
            provider->find<RBX::RunService>();
        RBX::Notifier<RBX::Instance, RBX::ChildAdded>::disconnect(stats, static_cast<RBX::Listener<RBX::Instance, RBX::ChildAdded>*>(this));
        RBX::Notifier<RBX::Instance, RBX::ChildRemoved>::disconnect(stats, static_cast<RBX::Listener<RBX::Instance, RBX::ChildRemoved>*>(this));
        RBX::MarshaledListener<RBX::Instance, RBX::ChildAdded>::detach();
        RBX::MarshaledListener<RBX::Instance, RBX::ChildRemoved>::detach();
        GetReportCtrl().GetRecords()->RemoveAll();
    }
    GetReportCtrl().Populate();
    stats.reset();
    this->dataModel = dataModel;
    if (this->dataModel) {
        RBX::DataModel::Lock lock(dataModel);
        stats = RBX::shared_from<RBX::Instance>(RBX::ServiceProvider::create<RBX::Stats::StatsService>(this->dataModel.get()));
        timer = ::SetTimer(m_hWnd, 1, 333, NULL);
        RBX::Notifier<RBX::Instance, RBX::ChildRemoved>::connect(stats, static_cast<RBX::Listener<RBX::Instance, RBX::ChildRemoved>*>(this));
        RBX::Notifier<RBX::Instance, RBX::ChildAdded>::connect(stats, static_cast<RBX::Listener<RBX::Instance, RBX::ChildAdded>*>(this));
        RBX::ServiceProvider::create<RBX::RunService>(this->dataModel.get());
    } else if (m_hWnd) {
        ::KillTimer(m_hWnd, timer);
    }
}

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class RBX::MarshaledListener<RBX::Instance,RBX::ChildAdded,RBX::Instance,RBX::ChildAdded>;
template class RBX::MarshaledListener<RBX::Instance,RBX::ChildRemoved,RBX::Instance,RBX::ChildRemoved>;
template class std::_Vector_const_iterator<RBX::Listener<RBX::Instance,RBX::ChildAdded> *,std::allocator<RBX::Listener<RBX::Instance,RBX::ChildAdded> *> >;
template class std::_Vector_const_iterator<RBX::Listener<RBX::Instance,RBX::ChildRemoved> *,std::allocator<RBX::Listener<RBX::Instance,RBX::ChildRemoved> *> >;
template class std::_Vector_const_iterator<RBX::MarshaledListener<RBX::Instance,RBX::ChildAdded,RBX::Instance,RBX::ChildAdded>::EventData *,std::allocator<RBX::MarshaledListener<RBX::Instance,RBX::ChildAdded,RBX::Instance,RBX::ChildAdded>::EventData *> >;
template class std::_Vector_const_iterator<RBX::MarshaledListener<RBX::Instance,RBX::ChildRemoved,RBX::Instance,RBX::ChildRemoved>::EventData *,std::allocator<RBX::MarshaledListener<RBX::Instance,RBX::ChildRemoved,RBX::Instance,RBX::ChildRemoved>::EventData *> >;
template class std::_Vector_iterator<RBX::Listener<RBX::Instance,RBX::ChildAdded> *,std::allocator<RBX::Listener<RBX::Instance,RBX::ChildAdded> *> >;
template class std::_Vector_iterator<RBX::Listener<RBX::Instance,RBX::ChildRemoved> *,std::allocator<RBX::Listener<RBX::Instance,RBX::ChildRemoved> *> >;
template class std::_Vector_iterator<RBX::MarshaledListener<RBX::Instance,RBX::ChildAdded,RBX::Instance,RBX::ChildAdded>::EventData *,std::allocator<RBX::MarshaledListener<RBX::Instance,RBX::ChildAdded,RBX::Instance,RBX::ChildAdded>::EventData *> >;
template class std::_Vector_iterator<RBX::MarshaledListener<RBX::Instance,RBX::ChildRemoved,RBX::Instance,RBX::ChildRemoved>::EventData *,std::allocator<RBX::MarshaledListener<RBX::Instance,RBX::ChildRemoved,RBX::Instance,RBX::ChildRemoved>::EventData *> >;
template class std::vector<RBX::Listener<RBX::Instance,RBX::ChildAdded> *,std::allocator<RBX::Listener<RBX::Instance,RBX::ChildAdded> *> >;
template class std::vector<RBX::Listener<RBX::Instance,RBX::ChildRemoved> *,std::allocator<RBX::Listener<RBX::Instance,RBX::ChildRemoved> *> >;
template class std::vector<RBX::MarshaledListener<RBX::Instance,RBX::ChildAdded,RBX::Instance,RBX::ChildAdded>::EventData *,std::allocator<RBX::MarshaledListener<RBX::Instance,RBX::ChildAdded,RBX::Instance,RBX::ChildAdded>::EventData *> >;
template class std::vector<RBX::MarshaledListener<RBX::Instance,RBX::ChildRemoved,RBX::Instance,RBX::ChildRemoved>::EventData *,std::allocator<RBX::MarshaledListener<RBX::Instance,RBX::ChildRemoved,RBX::Instance,RBX::ChildRemoved>::EventData *> >;
