// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/std-noinline-string
#include "CRobloxReportView.h"
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Stats.h"

// Original 004566f0 (118 B): CValueItem::~CValueItem, byte-folded with CNameItem (both vtable 008184a4 /
// 008185f4 slot 1 deleting destructor 00456fc0 call it). Calls the CXTPReportRecordItem base destructor
// 006c6c60 first, then releases the MutexRef boost::shared_ptr at +0x7c: strong count at control+4, dispose at
// vtable+4, weak count at control+8, destroy at vtable+8. The release is inlined, so MutexRef has no out-of-line
// destructor.
CRobloxReportView::CStatsItemRecord::CValueItem::~CValueItem()
{
}

// Stats::Item::getStringValue is declared (not defined) by the read-only v8datamodel/Stats.h. The original header
// carried the donor body (openrbx tools/openrbx/Client/App/include/v8datamodel/Stats.h): update() then return
// sValue. 00456770 inlines it (virtual update at vtable+0x40, sValue at +0x138), so restore that body here.
namespace RBX { namespace Stats {
const std::string& Item::getStringValue()
{
    update();
    return sValue;
}
}}

// Original 00456770 (173 B): GetCaption. Locks the DataModel held by the MutexRef base (+0x7c), then returns the
// item's string value as a CString. The target inlines getStringValue (update at vtable+0x40, sValue at +0x138)
// and constructs the result through mfc90!#310; std::string::c_str is the imported MSVCP90 function.
CString CRobloxReportView::CStatsItemRecord::CValueItem::GetCaption(CXTPReportColumn*)
{
    RBX::DataModel::Lock lock(dataModel);
    return CString(item->getStringValue().c_str());
}
