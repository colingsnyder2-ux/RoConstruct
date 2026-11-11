#pragma once
// >>> native-status (generated) -- do not edit >>>
// CRbxDocTemplate | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src d415dd43 | roc native-status --write
#include <afxwin.h>

class CRbxDocTemplate : public CMultiDocTemplate {
public:
    CRbxDocTemplate(UINT id, CRuntimeClass* document, CRuntimeClass* frame, CRuntimeClass* view)
        : CMultiDocTemplate(id, document, frame, view) {}
    virtual CFrameWnd* CreateNewFrame(CDocument*, CFrameWnd*);
};

class CRbxPlayDocTemplate : public CRbxDocTemplate {
    CDocument* document;
    CString text;
public:
    CRbxPlayDocTemplate(UINT id, CRuntimeClass* doc, CRuntimeClass* frame, CRuntimeClass* view)
        : CRbxDocTemplate(id, doc, frame, view), document(NULL) {}
    virtual void RemoveDocument(CDocument*);
};
