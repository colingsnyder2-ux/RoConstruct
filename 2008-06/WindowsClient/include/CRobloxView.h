#pragma once
// >>> native-status (generated) -- do not edit >>>
// CRobloxView | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src d00e7aa6 | roc native-status --write
#include "VerbBinder.h"
#include "CWebToolbox.h"
#include "v8tree/VerbContainer.h"
#include "v8tree/Verb.h"
#include <boost/scoped_ptr.hpp>
#include "util/Events.h"
#include "util/IMetric.h"
#include "util/RunStateOwner.h"
#include <afxcmn.h>
#include "Network/SuperSafeChanged.h"
#include "v8tree/Service.h"
#include <boost/shared_ptr.hpp>

namespace RBX {
class ServiceProvider;
class Name;
class Verb;
class DataModel;
namespace Network { class Players; }
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
    void finishAttach();       // 0045ead0
    void windowCommand();      // 0045bf90
    void setDataModel(void*); // 0045f7b0, argument is compared with +0x6c
    __declspec(noinline) void setActive(bool); // 0070bdf0, shared empty stub (ret 4); called from 004591e0/004593b0
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
    void create(CWnd* parent, const RBX::DataModel* model); // 00432e60
};

class CRobloxView : public VerbBinder<CRobloxView, CView>,
                    public RBX::VerbContainer,
                    public RBX::Listener<RBX::ServiceProvider, RBX::ServiceAdded>,
                    public RBX::Listener<RBX::ServiceProvider, RBX::ServiceRemoving>,
                    public RBX::Listener<RBX::Network::Players, RBX::SuperSafeChanged> {
    DECLARE_DYNCREATE(CRobloxView)
public:
    CRobloxWnd window;        // +0xb0
    boost::shared_ptr<const RBX::DataModel> owner_170;  // pointer and control block, zeroed by its constructor
    CMenu popupMenu;          // +0x178, menu resource 0x67 loaded at construction
    CReflectorWnd reflector;  // +0x180
    CWebToolbox* slot_1d8;    // toolbox pane (RTTI CWebToolbox); not destroyed by 00459ba0, so not owned
    boost::scoped_ptr<RBX::Verb> slot_1dc;       // states 5-9 in 00459ba0, destroyed in reverse order
    boost::scoped_ptr<RBX::Verb> slot_1e0;
    boost::scoped_ptr<RBX::Verb> slot_1e4;
    boost::scoped_ptr<RBX::Verb> slot_1e8;
    boost::scoped_ptr<RBX::Verb> slot_1ec;

    CRobloxView();
    virtual ~CRobloxView(); // 00459ba0, scalar deleting wrapper 00459fb0
    virtual void OnInitialUpdate(); // 0045a4a0
    void bindExisting(UINT, RBX::Verb*);
    void bindName(UINT, const RBX::Name&);
    class CRobloxDoc* RobloxDocument() const { return reinterpret_cast<class CRobloxDoc*>(m_pDocument); }
    void detachDataModel();         // 0045a2f0
    virtual void OnActivateFrame(UINT, CFrameWnd*); // 004591e0
    void OnUpdateToolboxCheck(CCmdUI*);            // 00459250, checked while the toolbox pane exists
    __declspec(noinline) boost::shared_ptr<const RBX::DataModel> getDataModel() const; // 00459270, called out of line
    // Standard view overrides (vtable slots 95-99 of 0081933c): the shared empty bodies at 0070bdf0 and 00458e90.
    virtual void OnDraw(CDC*);                                            // slot 95
    virtual BOOL OnPreparePrinting(CPrintInfo*);                          // 00458e80
    virtual void OnBeginPrinting(CDC*, CPrintInfo*);                      // slot 97
    virtual void OnEndPrinting(CDC*, CPrintInfo*);                        // slot 99
    // Window messages and listener events. Names are descriptive; message-map entries are not recovered yet.
    virtual void OnActivateView(BOOL, CView*, CView*);                  // 004593b0
    afx_msg void OnSetFocus(CWnd*);                                       // 00459210
    afx_msg void OnSize(UINT, int, int);                                  // 00459390
    void layout();                                                        // 004592b0
    void showToolbox(bool show, bool notify);                             // 004596a0
    LRESULT closeToolbox(WPARAM, LPARAM);                                 // 004597c0
    void toggleToolbox();                                                 // 004597f0
    void openToolboxPage();                                               // 00459810
    afx_msg void OnDestroy();                                             // 0045ac20
    afx_msg int OnCreate(LPCREATESTRUCT);                                 // 00459170
    afx_msg BOOL OnEraseBkgnd(CDC*);                                      // 006e8870, shared stub
    afx_msg void OnContextMenu(CWnd*, CPoint);                            // 006ad2a0, shared empty stub
    void OnWindowCommand();                                               // 00459240
    void OnUpdateAlwaysEnable(CCmdUI*);                                   // 0042e550, shared with the other views
    // 0045ac20-style update: reflector visibility follows Players super-safe mode.
    void showHelp();                                                      // 00459570
    void insertFromFile(int);                                             // 00459420
    void OnInsertFromFile();                                              // 00459560
    void OnInsertFromFileAt();                                            // 00459550
    LRESULT updateReflector(WPARAM, LPARAM);                              // 0045a140
    virtual void onEvent(const RBX::Network::Players*, RBX::SuperSafeChanged);        // 00458ea0
    virtual void onEvent(const RBX::ServiceProvider*, RBX::ServiceAdded);                       // 0045a030
    virtual void onEvent(const RBX::ServiceProvider*, RBX::ServiceRemoving);                    // 00459d60
    DECLARE_MESSAGE_MAP()
};
