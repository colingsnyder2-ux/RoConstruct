#pragma once
#include <afxwin.h>

class CBrowserView;

// Declarations only. CNullDoc: CRuntimeClass 00812410 (size 0x54 == CDocument, CreateObject 00433310),
// no members of its own.
class CNullDoc : public CDocument {
    DECLARE_DYNCREATE(CNullDoc)
public:
    CNullDoc();
protected:
    // INFERRED: name from draft (coldek-fork); 004332f0, protected non-virtual (?...@IAE...) per mangled symbol.
    afx_msg void OnUpdateDisabledCommand(CCmdUI* command);
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
