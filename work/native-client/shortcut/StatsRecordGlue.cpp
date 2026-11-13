// Shortcut glue (owner-authorized): CRobloxReportView::CStatsItemRecord's constructor (exe 00457ca0) was a zero stub, so
// onMarshaledEvent wrote through a null record.  The native header only declares the CXTPReportRecord base (the 2008 record
// adds MutexRef + two MarshaledListeners, openrbx win/RobloxReportView.cpp:126); this builds the base so the Stats view gets an
// empty row instead of crashing.  Real body: openrbx CStatsItemRecord ctor (name/value items + ChildAdded/Removed listeners).
#include "CRobloxReportView.h"

CRobloxReportView::CStatsItemRecord::CStatsItemRecord(boost::shared_ptr<RBX::Stats::Item>, boost::shared_ptr<RBX::DataModel>)
{
}
