#include "CRobloxReportView.h"
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Stats.h"

// Original 00457ca0 (621 B): CXTPReportRecord 006d7fd0, MutexRef 00554810 at +0x9c, the two listener bases,
// the item shared_ptr at +0xa8, two record items (operator new(0x88) 006c81f0, AddItem 006d8070) and the
// ChildAdded / ChildRemoved listener registration on the item under a DataModel::Lock (00411b40 / 005773c0).
CRobloxReportView::CStatsItemRecord::CStatsItemRecord(boost::shared_ptr<RBX::Stats::Item> item, boost::shared_ptr<RBX::DataModel> dataModel)
    : MutexRef(dataModel)
    , item(item)
{
    AddItem(new CNameItem(item.get(), dataModel));
    AddItem(new CValueItem(item.get(), dataModel));
    RBX::DataModel::Lock lock(dataModel);
    RBX::Notifier<RBX::Instance, RBX::ChildAdded>::connect(item, static_cast<RBX::Listener<RBX::Instance, RBX::ChildAdded>*>(this));
    RBX::Notifier<RBX::Instance, RBX::ChildRemoved>::connect(item, static_cast<RBX::Listener<RBX::Instance, RBX::ChildRemoved>*>(this));
}
