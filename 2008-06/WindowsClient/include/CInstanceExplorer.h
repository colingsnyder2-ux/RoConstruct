#pragma once
// >>> native-status (generated) -- do not edit >>>
// CInstanceExplorer | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src 1c0bb087 | roc native-status --write
#include <XTToolkitPro.h>
#include <boost/shared_ptr.hpp>
#include "util/MarshaledListener.h"
#include "v8tree/Instance.h"

namespace RBX {
// Event payloads: the definitions of native-classes/InstanceDescendantEvents.cpp (identical tokens, ODR).
// 16 bytes by value: the listener thunk 004211b0 copies both words pairs with two shared_ptr add-refs and
// returns with ret 0x14 (source pointer + event); destroyed out of line through 00422c60 (identical-COMDAT fold).
// Shared-header note: these belong next to the Notifier<Instance, Descendant*> bases in v8tree/Instance.h.
struct DescendantAdded {
    const boost::shared_ptr<Instance> instance;
    const boost::shared_ptr<Instance> parent;
    DescendantAdded(Instance* value, Instance* owner)
        : instance(shared_from(value)), parent(shared_from(owner)) {}
};
struct DescendantRemoving {
    const boost::shared_ptr<Instance> instance;
    const boost::shared_ptr<Instance> parent;
    DescendantRemoving(const boost::shared_ptr<Instance>& value, const boost::shared_ptr<Instance>& owner)
        : instance(value), parent(owner) {}
};
}

// Inactive layout recovery. CRuntimeClass 0080f638 (DYNCREATE, size 0x3cc, CreateObject 004219f0: operator
// new(0x3cc), base getter 00420770 -> CXTPReportView). RTTI of vtable 0080f8c4: CXTPReportView +0,
// MarshaledListener<Instance,DescendantAdded> +0x378 (vtable 0080f8ac), MarshaledListener<Instance,
// DescendantRemoving> +0x39c (vtable 0080f898). Constructor 00421940 (CXTPReportView 006c5070, listener
// constructors 00421080/00421130, +0x3c0 = +0x3c4 = 0, byte +0x3c8 = 0); destructor 00421bc0 (setRoot(NULL),
// shared_ptr release of +0x3c0/+0x3c4, listener destructors 00421740/00421620, ~CXTPReportView 006c5150).
// The scalar deleting destructor 00421c90 and its thunks 004219d0/004219e0 are shared with CSettingsExplorer.
class CInstanceExplorer : public CXTPReportView,
                          public RBX::MarshaledListener<RBX::Instance, RBX::DescendantAdded>,
                          public RBX::MarshaledListener<RBX::Instance, RBX::DescendantRemoving> {
    DECLARE_DYNCREATE(CInstanceExplorer)
    DECLARE_MESSAGE_MAP()
public:
    CInstanceExplorer();                               // 00421940
    virtual ~CInstanceExplorer();                      // 00421bc0

    // Original 00421a50 (callers 00421c09, 004670f9): replaces the explored root instance.
    void setRoot(RBX::Instance*);

    int OnCreate(LPCREATESTRUCT cs);                   // 00420990
    void OnReportSelChanged(NMHDR* notify, LRESULT* result); // 00421d00 (XTP_NM_REPORT_SELCHANGED, id 100)

    virtual void onMarshaledEvent(const RBX::Instance* source, RBX::DescendantAdded event);    // 00420fb0
    virtual void onMarshaledEvent(const RBX::Instance* source, RBX::DescendantRemoving event); // 00420c20

    // Inline helper (name provisional): 00420fb0/00420c20 address the flag as [adjusted this + 0x3c8] through the
    // same CInstanceExplorer* that calls GetReportCtrl, which an inlined member call reproduces and a direct
    // member read in the listener override (folded to [listener this + 0x50]/[+0x2c]) does not.
    void populate() { if (!populating) GetReportCtrl().Populate(); }

    boost::shared_ptr<RBX::Instance> root;  // +0x3c0: Notifier bases +0x64/+0x84 of it in 00421a50
    bool populating;                        // +0x3c8: set around setRoot's rebuild, suppresses per-event Populate
};

// Records of the explorer. RTTI vtable 0080f7e4; operator new(0x5c) (CXTPHeapObjectT allocator 006c81f0) in
// 00420fb0; constructor 00420db0 (CXTPReportRecord 006d7fd0, shared_ptr at +0x54, two AddItem 006d8070);
// destructor 00420ee0 (release +0x54/+0x58, ~CXTPReportRecord 006d8100). +0x54 is compared with the event
// instance in 00420c20 and read as the selected instance in 00421d00. RTTI names .?AVCInstanceRecord@@ (namespace
// scope) and .?AVCNameItem@CInstanceRecord@@.
class CInstanceRecord : public CXTPReportRecord {
public:
    class CNameItem;
    explicit CInstanceRecord(boost::shared_ptr<RBX::Instance> instance); // 00420db0
    virtual ~CInstanceRecord();                                          // 00420ee0

    boost::shared_ptr<RBX::Instance> instance;  // +0x54
};

// RTTI vtable 0080f65c: every slot equals CXTPReportRecordItem 008532e4 except GetCaption (00420790); size 0x80
// (operator new(0x80) in 00420db0), Instance* at +0x7c stored by the inline constructor (CXTPReportRecordItem 006c7340).
class CInstanceRecord::CNameItem : public CXTPReportRecordItem {
public:
    explicit CNameItem(RBX::Instance* instance) : instance(instance) {}
    virtual CString GetCaption(CXTPReportColumn* column);  // 00420790

    RBX::Instance* instance;  // +0x7c
};
