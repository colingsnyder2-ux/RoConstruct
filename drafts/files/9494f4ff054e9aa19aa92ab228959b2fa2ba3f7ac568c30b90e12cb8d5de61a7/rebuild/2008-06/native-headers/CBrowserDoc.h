#pragma once
#include <afxwin.h>

class CBrowserView;

// Inactive CNullDoc recovery: CRuntimeClass 00812410 (size 0x54 == CDocument, CreateObject 00433310),
// no added storage. The factory inlines the CDocument constructor; the deleting destructor 0040e4d0
// calls only ~CDocument and operator delete. RTTI names CDocument as the zero-offset base.
class CNullDoc : public CDocument {
    DECLARE_DYNCREATE(CNullDoc)
public:
    CNullDoc() {}
    // Original vtable slots 24 (00416690) and 38 (007286a0); both are folded constant-return bodies.
    virtual BOOL IsModified() { return FALSE; }
    virtual BOOL SaveModified() { return TRUE; }
protected:
    // Neutral codegen-analog name: the original name is unknown. Message-map signature 0x41
    // and handler 004332f0 prove void(CCmdUI*) and Enable(FALSE), shared by three command IDs.
    afx_msg void OnUpdateDisabledCommand(CCmdUI* command);
    DECLARE_MESSAGE_MAP()
};

// Declarations only. RTTI of vtable 0080d2c4: CBrowserDoc : CNullDoc : CDocument. CRuntimeClass 0080cfac
// (size 0x58, CreateObject 0040e4f0, base getter 0040df90 -> CNullDoc 004332e0), +0x54 = 0 in CreateObject.
// +0x54 is written with the view by CBrowserView::OnInitialUpdate 0040ed50.
class CBrowserDoc : public CNullDoc {
    DECLARE_DYNCREATE(CBrowserDoc)
public:
    CBrowserDoc();
    CBrowserView* view;     // +0x54
};
