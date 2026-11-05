#pragma once
// Inactive native 2008-06 recovery: the IDE document templates owned by CIDEDocManager (CRobloxApp.cpp).
#include <afxwin.h>
#include <exception>
#include <boost/scoped_ptr.hpp>

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
    // 0044b9a0 (non-virtual; reached through the tail-jump 0044bbf0 via the doc manager's +0x24 template): opens the
    // play document on first use (openDocumentFile(NULL, TRUE)), otherwise reuses playDocument (SaveModified,
    // SetDefaultTitle, OnNewDocument, WM_INITIALUPDATE to each view). Name provisional.
    CDocument* getPlayDocument();

    CDocument* playDocument;   // +0x90 (compared/cleared by 004496f0; read and set by 0044b9a0)
    CString lastError;         // +0x94 (assigned by 00449720; IsEmpty-tested by 0044b9a0)
};

// Global error carried out of the play-document open (0096dcf4): a polymorphic pointer whose slot 0 is the deleting
// destructor (push 1) and slot 1 what() (0044ab30 builds a std::string from it); reset() loads the old pointer,
// stores 0, then deletes (the boost::scoped_ptr swap order); its atexit destructor 007fadf0 is `if (p) delete p`.
// The static initializer 007ef860 registers that destructor. Name provisional.
extern boost::scoped_ptr<std::exception> pendingPlayError;
// 0044aa70 (cdecl): pendingPlayError.reset(new std::runtime_error(e.what())) (operator new(0x28) ==
// sizeof(std::runtime_error)). Name provisional.
void setPendingPlayError(const std::exception& e);
// 0044ab30 (cdecl): if pendingPlayError is set, copy its what() into a std::runtime_error, reset it, throw the copy.
// Name provisional.
void throwPendingPlayError();
