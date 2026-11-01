#pragma once
#include "VerbBinder.h"
#include "v8tree/VerbContainer.h"
#include "util/Events.h"
#include "util/IMetric.h"
#include "util/RunStateOwner.h"
#include <afxcmn.h>
#include <boost/shared_ptr.hpp>

namespace RBX {
class ServiceProvider;
struct ServiceAdded;
struct ServiceRemoving;
namespace Network { class Players; struct SuperSafeChanged; }
}

// Original RTTI (0081933c complete object locator) and constructor 00459eb0 prove
// the bases and member offsets below. Names for members the constructor only
// zeroes stay offset-based until their readers are recovered; no padding.
// Inactive: not used by the shell. Native size 0x1f0. Size and offsets are checked by
// tests/NativeViewLayout.cpp; see work/2008-06/shared-layouts/view-compile.json.
// Unrecovered: CRobloxWnd bytes 0x8c-0x97 and 0xbc-0xbf are never written by the
// constructor, and whether CRobloxWnd has 8-byte alignment (which would explain
// the 4-byte gap before the window at View+0xb0). Fill from readers, not padding.

// 0045c730 constructs this at View+0xb0. RTTI: CWnd at 0, IRunView at +0x54,
// IMetric at +0x58. Only offsets the constructor writes are named.
// 8-byte aligned: the original places it at View+0xb0 with View+0xac never written.
__declspec(align(8)) class CRobloxWnd : public CWnd, public RBX::IRunView, public RBX::IMetric {
public:
    int mode_5c;          // 0045cbf0 selects renderer mode here (3 = RbxGfx)
    int retries_60;       // incremented once after a renderer failure
    void* slots_64_7c[7]; // zeroed by the constructor (0x64 through 0x7c)
    bool flag_80;         // set to 1
    void* slot_84;
    bool flags_88_8b[4];  // 0x88 depends on startup context, 0x8b set to 1
    unsigned unaccessed_8c[3]; // no constructor write and no read in 53 mined CRobloxWnd methods; size from CRuntimeClass 0xc0
    void* source_98;      // 005c43a0 result
    bool flag_9c;
    void* slots_a0_a4[2];
    bool flag_a8;
    void* slots_ac_b8[4];
    unsigned unaccessed_bc;    // same evidence as unaccessed_8c
    explicit CRobloxWnd(int);
    virtual ~CRobloxWnd(); // 0045fbe0, called out of line from 00459ba0
    // Interface overrides; bodies not recovered here. IRunView vtable 008199e8, IMetric 008199dc.
    virtual void InvalidateRunView();
    virtual void AdjustThrottle(double);
    virtual std::string getMetric(const std::string&) const;
};

// 00432e30 constructs this at View+0x180: one CWnd-derived member, field at +0x54.
class CReflectorWnd : public CWnd {
public:
    void* target_54;
    CReflectorWnd();
};

// Pointee of the five owning slots. 00459ba0 deletes each through vtable slot 1
// (offset 4), so the pointee has one virtual before its destructor. Real type unrecovered.
struct OwnedPolymorphic {
    virtual void unrecovered_0();
    virtual ~OwnedPolymorphic();
};
struct OwnedSlot {
    OwnedPolymorphic* value;
    OwnedSlot() : value(0) {}
    ~OwnedSlot() { delete value; }
};

class CRobloxView : public VerbBinder<CRobloxView, CView>,
                    public RBX::VerbContainer,
                    public RBX::Listener<RBX::ServiceProvider, RBX::ServiceAdded>,
                    public RBX::Listener<RBX::ServiceProvider, RBX::ServiceRemoving>,
                    public RBX::Listener<RBX::Network::Players, RBX::Network::SuperSafeChanged> {
    DECLARE_DYNCREATE(CRobloxView)
public:
    CRobloxWnd window;        // +0xb0
    boost::shared_ptr<void> owner_170;  // pointer and control block, zeroed by its constructor
    CMenu popupMenu;          // +0x178, menu resource 0x67 loaded at construction
    CReflectorWnd reflector;  // +0x180
    void* slot_1d8;           // not destroyed by 00459ba0, so not owned
    OwnedSlot slot_1dc;       // states 5-9 in 00459ba0, destroyed in reverse order
    OwnedSlot slot_1e0;
    OwnedSlot slot_1e4;
    OwnedSlot slot_1e8;
    OwnedSlot slot_1ec;

    CRobloxView();
    virtual ~CRobloxView(); // 00459ba0, scalar deleting wrapper 00459fb0
    DECLARE_MESSAGE_MAP()
};
