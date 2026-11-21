#pragma once
#include <XTToolkitPro.h>
#include <boost/shared_ptr.hpp>
#include "util/MarshaledListener.h"
#include "v8tree/Instance.h"
#include "v8tree/InstanceEvents.h"

namespace RBX {
class DataModel;
namespace Stats { class Item; }

// Event payloads proven by the listener thunks: onEvent 00457150 forwards an 8-byte by-value event
// (ret 0xc with the source pointer) and copies it with the shared_ptr<Instance> copy constructor
// 004116f0; onMarshaledEvent 00456250 compares the first word with the record's item pointer.
struct ChildRemoved {
    boost::shared_ptr<Instance> child;
    ChildRemoved(const ChildRemoved&);  // out of line: 004116f0 (identical-COMDAT fold)
};
}

// Inactive layout recovery from CRuntimeClass 00818348 (size 0x3d4, abstract: CreateObject 0, base
// getter 00420770 -> CXTPReportView), RTTI of vtable 0081888c (CRobloxReportView : CXTPReportView +0,
// MarshaledListener<Instance,ChildAdded> +0x378, MarshaledListener<Instance,ChildRemoved> +0x39c),
// the constructor 00457a40 (CXTPReportView 006c5070, listener constructors 00457050/004570d0, +0x3c0 = 0,
// +0x3c4..+0x3d0 = 0) and the destructor 00458b70 (setDataModel(empty), shared_ptr releases of +0x3cc
// then +0x3c4, listener destructors 004578f0/004577e0, ~CXTPReportView 006c5150). The subclasses
// CRobloxReportDocView (0x3d4) and CRobloxReportPaneView (0x3d8) allocate through 00458d80/00458df0.
class CRobloxReportView : public CXTPReportView,
                          public RBX::MarshaledListener<RBX::Instance, RBX::ChildAdded>,
                          public RBX::MarshaledListener<RBX::Instance, RBX::ChildRemoved> {
    DECLARE_DYNAMIC(CRobloxReportView)
    DECLARE_MESSAGE_MAP()
public:
    class CStatsItemRecord;

    CRobloxReportView();                                            // 00457a40
    virtual ~CRobloxReportView();                                   // 00458b70
    virtual void OnInitialUpdate();                                 // 004589c0

    void setDataModel(boost::shared_ptr<RBX::DataModel> dataModel); // 00458700; name provisional
    void updateStats();                                             // 00456c30; name provisional
    void logRecords(CXTPReportRecords* records, CString indent);    // 00456820 (thiscall, ret 8); INFERRED name

    int OnCreate(LPCREATESTRUCT cs);                                // 00455fd0
    void OnTimer(UINT_PTR id);                                      // 00456e60

    virtual void onMarshaledEvent(const RBX::Instance* source, RBX::ChildAdded event);   // 004582f0
    virtual void onMarshaledEvent(const RBX::Instance* source, RBX::ChildRemoved event); // 00456250

    UINT_PTR timer;                                  // +0x3c0, SetTimer(m_hWnd, 1, 333, NULL) in 00458700
    boost::shared_ptr<RBX::DataModel> dataModel;     // +0x3c4, DataModel::Lock argument in 00458700
    boost::shared_ptr<RBX::Instance> stats;          // +0x3cc, shared_from(create<StatsService>) in 00458700
};

// onMarshaledEvent(ChildRemoved) 00456250 reads the record's item pointer at +0xa8 through getItem().
// Declarations only for the stats records (RTTI 00818a74: CXTPReportRecord +0, MarshaledListener<Instance,
// ChildAdded> +0x54, MarshaledListener<Instance,ChildRemoved> +0x78, private non-polymorphic MutexRef +0x9c;
// allocation 0xb0 in 004582f0; constructor 00457ca0 stores the item shared_ptr at +0xa8). Only what this
// view uses is declared; the record body is a separate recovery. Its layout is blocked on +0xa4: MutexRef is
// 8 bytes (CNameItem 004564a0: MutexRef +0x7c, Stats::Item* +0x84, size 0x88), so the record has 4 bytes at +0xa4
// that its constructor 00457ca0, destructor 00457ff0 and listeners 00457f30/004581a0 never touch.
// MutexRef: global class named by the RTTI base descriptors of the record (.?AVMutexRef@@ at +0x9c) and of
// CStatsItemRecord::CNameItem (+0x7c). Its constructor 00554810 copies an 8-byte by-value shared_ptr argument.
class MutexRef {
public:
    MutexRef(boost::shared_ptr<RBX::DataModel> dataModel);     // 00554810
    // No user destructor: 004566f0 inlines the boost::shared_ptr release (strong control+4 / weak control+8),
    // so the implicit destructor is the authentic one. CValueItem::GetCaption 00456770 reads +0x7c/+0x80.
    boost::shared_ptr<RBX::DataModel> dataModel;               // INFERRED: member name; 8 bytes copied by 00554810; +0x7c
};

// Base order from the constructor 00457ca0 (CXTPReportRecord 006d7fd0, MutexRef +0x9c, listeners +0x54/+0x78) and
// the RTTI base array; the compiler places the non-polymorphic MutexRef after the polymorphic bases.
class CRobloxReportView::CStatsItemRecord : public CXTPReportRecord,
                                            private MutexRef,
                                            public RBX::MarshaledListener<RBX::Instance, RBX::ChildAdded>,
                                            public RBX::MarshaledListener<RBX::Instance, RBX::ChildRemoved> {
public:
    class CNameItem;                                           // RTTI vtable 008184a4, constructor 004564a0
    class CValueItem;                                          // vtable 008185f4, constructor 00456620

    CStatsItemRecord(boost::shared_ptr<RBX::Stats::Item> item, boost::shared_ptr<RBX::DataModel> dataModel); // 00457ca0
    virtual ~CStatsItemRecord();                               // 00457ff0
    // INFERRED: inline const accessor; 00457f30 and 00456250 read the item as `mov eax,[eax+0xa8]` through it
    // (a direct member read gives `add eax,0xa8; mov eax,[eax]`).
    RBX::Stats::Item* getItem() const { return item.get(); }
    virtual void onMarshaledEvent(const RBX::Instance* source, RBX::ChildAdded event);   // 004581a0, vtable 00818a5c slot 2
    virtual void onMarshaledEvent(const RBX::Instance* source, RBX::ChildRemoved event); // 00457f30, vtable 00818a48 slot 2

private:
    int unused;                                                // INFERRED: +0xa4, size 0xb0 requires 4 bytes the record never touches
    boost::shared_ptr<RBX::Stats::Item> item;                  // +0xa8, stored by 00457ca0
};

// Record items (size 0x88, operator new(0x88) in 00457ca0): MutexRef +0x7c is constructed before the
// CXTPReportRecordItem base 006c7340; the Stats::Item pointer is stored at +0x84.
class CRobloxReportView::CStatsItemRecord::CNameItem : private MutexRef, public CXTPReportRecordItem {
public:
    CNameItem(RBX::Stats::Item* item, boost::shared_ptr<RBX::DataModel> dataModel);      // 004564a0
    virtual CString GetCaption(CXTPReportColumn* column);     // 00456570, vtable 008184a4 slot 27
private:
    RBX::Stats::Item* item;                                    // +0x84
};

class CRobloxReportView::CStatsItemRecord::CValueItem : private MutexRef, public CXTPReportRecordItem {
public:
    CValueItem(RBX::Stats::Item* item, boost::shared_ptr<RBX::DataModel> dataModel);     // 00456620
    virtual ~CValueItem();                                     // 004566f0 (folded with CNameItem)
    virtual CString GetCaption(CXTPReportColumn* column);     // 00456770, vtable 008185f4 slot 27; vftable-slot (exact tier)
private:
    RBX::Stats::Item* item;                                    // +0x84
};
