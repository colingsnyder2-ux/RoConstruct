#pragma once
// >>> native-status (generated) -- do not edit >>>
// CRobloxReportView | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src f3f785bd | roc native-status --write
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
    void updateStats();                                             // 00456c30; name provisional, not recovered

    int OnCreate(LPCREATESTRUCT cs);                                // 00455fd0
    void OnTimer(UINT_PTR id);                                      // 00456e60

    virtual void onMarshaledEvent(const RBX::Instance* source, RBX::ChildAdded event);   // 004582f0
    virtual void onMarshaledEvent(const RBX::Instance* source, RBX::ChildRemoved event); // 00456250

    UINT_PTR timer;                                  // +0x3c0, SetTimer(m_hWnd, 1, 333, NULL) in 00458700
    boost::shared_ptr<RBX::DataModel> dataModel;     // +0x3c4, DataModel::Lock argument in 00458700
    boost::shared_ptr<RBX::Instance> stats;          // +0x3cc, shared_from(create<StatsService>) in 00458700
};

// onMarshaledEvent(ChildRemoved) 00456250 reads the record's item pointer at +0xa8 and is not written here.
// Declarations only for the stats records (RTTI 00818a74: CXTPReportRecord +0, MarshaledListener<Instance,
// ChildAdded> +0x54, MarshaledListener<Instance,ChildRemoved> +0x78, private non-polymorphic MutexRef +0x9c;
// allocation 0xb0 in 004582f0; constructor 00457ca0 stores the item shared_ptr at +0xa8). Only what this
// view uses is declared; the record body is a separate recovery. Its layout is blocked on +0xa4: MutexRef is
// 8 bytes (CNameItem 004564a0: MutexRef +0x7c, Stats::Item* +0x84, size 0x88), so the record has 4 bytes at +0xa4
// that its constructor 00457ca0, destructor 00457ff0 and listeners 00457f30/004581a0 never touch.
class CRobloxReportView::CStatsItemRecord : public CXTPReportRecord {
public:
    CStatsItemRecord(boost::shared_ptr<RBX::Stats::Item> item, boost::shared_ptr<RBX::DataModel> dataModel); // 00457ca0
};
