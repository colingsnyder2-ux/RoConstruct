// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/std-noinline-string
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

// Original 004564a0 (197 B): CNameItem constructor, operator new(0x88) site in 00457ca0. MutexRef(dataModel)
// 00554810 at +0x7c first, then CXTPReportRecordItem 006c7340, vptr 008184a4 (RTTI
// .?AVCNameItem@CStatsItemRecord@CRobloxReportView@@), item pointer at +0x84; the by-value dataModel argument is
// released at the end.
CRobloxReportView::CStatsItemRecord::CNameItem::CNameItem(RBX::Stats::Item* item, boost::shared_ptr<RBX::DataModel> dataModel)
    : MutexRef(dataModel)
    , item(item)
{
}

// Original 00456620 (197 B): CValueItem constructor, the same shape as CNameItem's with vptr 008185f4.
CRobloxReportView::CStatsItemRecord::CValueItem::CValueItem(RBX::Stats::Item* item, boost::shared_ptr<RBX::DataModel> dataModel)
    : MutexRef(dataModel)
    , item(item)
{
}

// Original 004581a0 (335 B, vtable 00818a5c slot 2, this = the ChildAdded listener base at +0x54): a child Stats
// item added under this record's item gets its own child record (boost::shared_dynamic_cast 00456ee0, operator
// new(0xb0), constructor 00457ca0 with the record's MutexRef DataModel at +0x9c, GetChilds 006d8180, Add 006d7ca0).
void CRobloxReportView::CStatsItemRecord::onMarshaledEvent(const RBX::Instance*, RBX::ChildAdded event)
{
    boost::shared_ptr<RBX::Stats::Item> child = boost::shared_dynamic_cast<RBX::Stats::Item>(event.child);
    if (child)
        GetChilds()->Add(new CStatsItemRecord(child, dataModel));
}

// Original 00457f30 (181 B, vtable 00818a48 slot 2, this = the ChildRemoved listener base at +0x78): removes the
// child record whose item (+0xa8) is the removed instance, scanning GetChilds() (006d8180) from the end
// (GetCount 006da050, GetAt 006d7920, RemoveAt 006d7cd0).
// Open (182 vs 181 B): this build reads the item as `add eax,0xa8; mov eax,[eax]`, the target as `mov eax,[eax+0xa8]`.
// Rejected: `item == event.child` (shared_ptr operator==), a const CStatsItemRecord* cast. Byte-identical with an
// inline const accessor `RBX::Stats::Item* getItem() const { return item.get(); }` in CStatsItemRecord (measured
// against a scratch header copy; proposal for the CRobloxReportView.h owner, which also lets 00456250 drop its
// char* + 0xa8 read).
void CRobloxReportView::CStatsItemRecord::onMarshaledEvent(const RBX::Instance*, RBX::ChildRemoved event)
{
    for (int i = GetChilds()->GetCount() - 1; i >= 0; --i) {
        if (static_cast<CStatsItemRecord*>(GetChilds()->GetAt(i))->item.get() == event.child.get()) {
            GetChilds()->RemoveAt(i);
            break;
        }
    }
}

#ifdef NATIVE_CROBLOXREPORTVIEW_RECORD_DECLS_PENDING
// PENDING: these two bodies need declarations the read-only native-headers/CRobloxReportView.h does not have yet
// (proposal for its owner: `virtual ~CStatsItemRecord();` in CStatsItemRecord and
// `virtual CString GetCaption(CXTPReportColumn* column);` in CNameItem). Measured byte-identical (relocs masked)
// against a scratch copy of the header carrying those declarations; the unit also needs the util/MarshaledListener.h
// stray-brace fix to compile at all.

// Original 00457ff0 (347 B): CStatsItemRecord destructor. Vptr stores 00818a74 / 00818a5c (+0x54) / 00818a48
// (+0x78), then under a DataModel::Lock of the MutexRef base (+0x9c) disconnects both listener bases from the item
// (Notifier disconnect 005e5a80 on item+0x24 / item+0x44); members and bases are destroyed afterwards (item +0xa8,
// ~MarshaledListener 004578f0 / 004577e0, MutexRef +0x9c, ~CXTPReportRecord 006d8100).
CRobloxReportView::CStatsItemRecord::~CStatsItemRecord()
{
    RBX::DataModel::Lock lock(dataModel);
    RBX::Notifier<RBX::Instance, RBX::ChildAdded>::disconnect(item, static_cast<RBX::Listener<RBX::Instance, RBX::ChildAdded>*>(this));
    RBX::Notifier<RBX::Instance, RBX::ChildRemoved>::disconnect(item, static_cast<RBX::Listener<RBX::Instance, RBX::ChildRemoved>*>(this));
}

// Original 00456570 (164 B): CNameItem::GetCaption (vtable 008184a4 slot 27, the CValueItem::GetCaption 00456770
// shape): under a DataModel::Lock of the MutexRef base (+0x7c) returns the item's Instance name (+0x110) as a CString
// (MSVCP90 c_str, mfc90 #310).
CString CRobloxReportView::CStatsItemRecord::CNameItem::GetCaption(CXTPReportColumn*)
{
    RBX::DataModel::Lock lock(dataModel);
    return CString(item->getName().c_str());
}
#endif
