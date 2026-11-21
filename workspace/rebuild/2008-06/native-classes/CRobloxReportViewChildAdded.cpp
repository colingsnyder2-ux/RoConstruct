#include "CRobloxReportView.h"
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Stats.h"
#include "CRobloxDoc.h"

namespace RBX { class RunService; }

// Original 004582f0: byte-identical with the record layout from the header (operator new(0xb0)).
void CRobloxReportView::onMarshaledEvent(const RBX::Instance*, RBX::ChildAdded event)
{
    CXTPReportControl& control = GetReportCtrl();
    boost::shared_ptr<RBX::Stats::Item> item = boost::shared_dynamic_cast<RBX::Stats::Item>(event.child);
    if (!item)
        return;
    CStatsItemRecord* record = new CStatsItemRecord(item, dataModel);
    record->SetExpanded(TRUE);
    control.AddRecord(record);
}
