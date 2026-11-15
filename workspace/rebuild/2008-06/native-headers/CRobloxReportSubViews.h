#pragma once
#include "CRobloxReportView.h"
#include "ActiveDocView.h"

// Inactive layout recovery of the two concrete CRobloxReportView leaves.
//
// CRobloxReportDocView: CRuntimeClass 00818364 (size 0x3d4, schema 0xffff, CreateObject 00458d80, base getter
// 00455d50 = RUNTIME_CLASS(CRobloxReportView)), RTTI of vtable 00818c94 (CRobloxReportDocView : CRobloxReportView +0,
// no further bases). CreateObject 00458d80 allocates 0x3d4 (= sizeof(CRobloxReportView)), calls the base constructor
// 00457a40 and stores only the three vptrs 00818c94/00818c7c/00818c68: no added members, implicit constructor.
// Its vtable keeps the base's message map getter 00457010 (no own message map) and the base's deleting
// destructor 00458d60 (identical-COMDAT fold); the only new body is OnActivateView 00456310 (slot 92).
class CRobloxReportDocView : public CRobloxReportView {
    DECLARE_DYNCREATE(CRobloxReportDocView)
public:
    virtual void OnActivateView(BOOL bActivate, CView* pActivateView, CView* pDeactiveView); // 00456310
};

// CRobloxReportPaneView: CRuntimeClass 00818380 (size 0x3d8, CreateObject 00458df0, base getter 00455d50), RTTI of
// vtable 00818e7c (CRobloxReportView +0, ActiveDocView mdisp 0x3d4). Constructor 00458c80: CRobloxReportView
// 00457a40, ActiveDocView 00405d50 at +0x3d4, vptrs 00818e7c/00818e64/00818e50/00819038; destructor 00458d10:
// ~ActiveDocView 00405d80 (+0x3d4), ~CRobloxReportView 00458b70. 0x3d4 + sizeof(ActiveDocView) 4 = 0x3d8.
// Message map 00818800 (base getter 00457010, no entries).
class CRobloxReportPaneView : public CRobloxReportView, public ActiveDocView {
    DECLARE_DYNCREATE(CRobloxReportPaneView)
    DECLARE_MESSAGE_MAP()
public:
    CRobloxReportPaneView();                       // 00458c80
    // implicit destructor 00458d10 (no vptr restores: ~ActiveDocView 00405d80, then ~CRobloxReportView 00458b70)
    virtual void OnInitialUpdate();                // 00458a00
    // ActiveDocView slot 0 (vtable 00819038), this at +0x3d4.
    virtual void update(boost::shared_ptr<RBX::DataModel> current, boost::shared_ptr<RBX::DataModel> previous); // 00458a90
};
