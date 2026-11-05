#pragma once
// Inactive native 2008-06 recovery: the IDE document templates owned by CIDEDocManager (CRobloxApp.cpp).
#include <afxwin.h>

// CRbxDocTemplate (RTTI of vtable 00816684: CRbxDocTemplate : CMultiDocTemplate : CDocTemplate : CCmdTarget :
// CObject). No CRuntimeClass (no DECLARE_DYNAMIC: slot 0 is CMultiDocTemplate's GetRuntimeClass).
// sizeof 0x90 == sizeof(CMultiDocTemplate): CIDEDocManager::CIDEDocManager(bool) 00449910 news 0x90 three times,
// calls CMultiDocTemplate::CMultiDocTemplate(id, doc, frame, view) and stores only vptr 00816684, so the
// constructor is inline and adds no members. The implicit destructor is inline (??_G 0044a1a0 calls
// ~CMultiDocTemplate directly).
class CRbxDocTemplate : public CMultiDocTemplate
{
public:
    CRbxDocTemplate(UINT nIDResource, CRuntimeClass* pDocClass, CRuntimeClass* pFrameClass,
                    CRuntimeClass* pViewClass)
        : CMultiDocTemplate(nIDResource, pDocClass, pFrameClass, pViewClass)
    {
    }
    // slot 30 (0044a170): makes sure the IDE main frame exists before CDocTemplate::CreateNewFrame.
    virtual CFrameWnd* CreateNewFrame(CDocument* pDoc, CFrameWnd* pOther);
};

// CRbxPlayDocTemplate (RTTI of vtable 0081671c: CRbxPlayDocTemplate : CRbxDocTemplate). sizeof 0x98: 00449910
// news 0x98, calls CMultiDocTemplate::CMultiDocTemplate, stores vptr 0081671c, +0x90 = 0 and constructs a CString
// at +0x94 (mfc90 #316); ??_G 0044a1c0 destroys +0x94 (mfc90 #601) then ~CMultiDocTemplate.
class CRbxPlayDocTemplate : public CRbxDocTemplate
{
public:
    CRbxPlayDocTemplate(UINT nIDResource, CRuntimeClass* pDocClass, CRuntimeClass* pFrameClass,
                        CRuntimeClass* pViewClass)
        : CRbxDocTemplate(nIDResource, pDocClass, pFrameClass, pViewClass), playDocument(0)
    {
    }
    // slot 26 (004496f0): forgets playDocument when that document is removed.
    virtual void RemoveDocument(CDocument* pDoc);
    // 00449720 (non-virtual; called from 0044b9a0): CMultiDocTemplate::OpenDocumentFile that records each failure
    // text in lastError ("" on entry).
    CDocument* openDocumentFile(LPCTSTR lpszPathName, BOOL bMakeVisible);

    CDocument* playDocument;   // +0x90 (compared/cleared by 004496f0; read and set by 0044b9a0)
    CString lastError;         // +0x94 (assigned by 00449720; IsEmpty-tested by 0044b9a0)
};
