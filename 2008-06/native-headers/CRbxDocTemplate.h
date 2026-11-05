#pragma once
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
