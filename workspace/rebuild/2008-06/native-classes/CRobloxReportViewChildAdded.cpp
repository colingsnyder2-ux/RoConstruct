// >>> native-status (generated) -- do not edit >>>
// CRobloxReportViewChildAdded | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src 8a7f4abf | roc native-status --write
#include "CRobloxReportView.h"
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Stats.h"
#include "CRobloxDoc.h"

namespace RBX { class RunService; }

// Original 004582f0 (open, 388 vs 391 bytes): identical except operator new(0xb0) - sizeof(CStatsItemRecord) needs
// the record layout (see the header).
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
