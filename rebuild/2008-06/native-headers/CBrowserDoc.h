#pragma once
// >>> native-status (generated) -- do not edit >>>
// CBrowserDoc | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 68e31841 | roc native-status --write
#include <afxwin.h>

class CBrowserView;

// Declarations only. CNullDoc: CRuntimeClass 00812410 (size 0x54 == CDocument, CreateObject 00433310),
// no members of its own.
class CNullDoc : public CDocument {
    DECLARE_DYNCREATE(CNullDoc)
public:
    CNullDoc();
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
