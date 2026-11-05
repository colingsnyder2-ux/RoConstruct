// from server: 100% by EspClaude
// from server: 90% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: atl-9.0-dll-rtm roc_espclaude_43b5b584c2f00b13.cpp

// Candidate translation unit (score above; library headers required).
#ifndef _CPPUNWIND
#define _CPPUNWIND 1
#endif
#ifndef _AFXDLL
#define _AFXDLL
#endif
#ifndef _MBCS
#define _MBCS
#endif
#include <new>
#include <afxwin.h>
#include <stdexcept>
#include <string>
#include <afxpriv.h>

class ExeCString {
public:
    __declspec(dllimport) bool IsEmpty() const throw();
    __declspec(dllimport) operator const char*() const throw();
    char* m_pszData;
};
struct PendingObject { virtual ~PendingObject(); };
template<class T> class scoped_ptr {
    T* ptr;
public:
    explicit scoped_ptr(T* p = 0) : ptr(p) {}
    ~scoped_ptr() { delete ptr; }
    void reset(T* p = 0) { scoped_ptr<T>(p).swap(*this); }
    void swap(scoped_ptr& b) { T* tmp = b.ptr; b.ptr = ptr; ptr = tmp; }
};
extern scoped_ptr<PendingObject> pendingObject;
extern CDocument* activeDocument;
void finishOpen();
void notifyDocument(int, CDocument*);

class CRobloxModule {
public:
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34();
    virtual void attachDocument(CDocument*);
    char pad[0x8c];
    CDocument* document;
    ExeCString errorText;

    CDocument* open(LPCTSTR lpszFileName, BOOL bMakeVisible);
    CDocument* getDocument();
};

CDocument* CRobloxModule::getDocument()
{
    if (document == NULL)
    {
        pendingObject.reset();
        CDocument* doc = open(NULL, TRUE);
        try
        {
            finishOpen();
        }
        catch (...)
        {
            AfxMessageBox(0xf104);
            if (doc)
                doc->OnCloseDocument();
            throw;
        }
        if (doc == NULL)
        {
            if (!errorText.IsEmpty())
                throw std::runtime_error((const char*)errorText);
            throw std::runtime_error("OpenDocumentFile returned NULL");
        }
        document = doc;
        return doc;
    }
    else
    {
        if (!document->SaveModified())
            throw std::runtime_error("User cancelled");
        attachDocument(document);
        if (!document->OnNewDocument())
            throw std::runtime_error("CDocument::OnNewDocument returned FALSE");
        if (activeDocument == document)
            notifyDocument(1, activeDocument);
        POSITION pos = document->GetFirstViewPosition();
        while (pos)
        {
            CView* view = document->GetNextView(pos);
            pendingObject.reset();
            ::SendMessage(view->m_hWnd, WM_INITIALUPDATE, 0, 0);
        }
        return document;
    }
}

