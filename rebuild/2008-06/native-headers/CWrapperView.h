#pragma once
#include "CSelectionTreeCtrl.h"

// Explorer pane view (docking pane 0xc2). CRuntimeClass 008107e0 = {"CWrapperView", 0x188, 0xffff,
// CreateObject 00430010, base getter -> CView}. Constructor 0042eb40: CView() (mfc90 #588),
// vptr 00810a9c, CSelectionTreeCtrl (00425c90, 0x130 bytes) at +0x58 = sizeof(CView).
// Implemented in the original CMainFrame translation unit (RUNTIME_CLASS is inlined there).
class CWrapperView : public CView {
    DECLARE_DYNCREATE(CWrapperView)
protected:
    CWrapperView();                 // 0042eb40
    virtual void OnDraw(CDC*);
public:
    CSelectionTreeCtrl tree;        // +0x58
};
