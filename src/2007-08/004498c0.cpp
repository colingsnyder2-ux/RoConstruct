// from server: 56% by EspClaude
// from server: 54% by tester
// roc 2007-08 004498c0  unit: CRobloxModule  size: 247 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004498c0

#include <string>
#include <stdexcept>

extern "C" __declspec(dllimport) long __stdcall SendMessageA(void*, unsigned int, unsigned int, long);
int __stdcall AfxMessageBox(unsigned int nIDPrompt, unsigned int nType = 0, unsigned int nIDHelp = (unsigned int)-1);

struct Deletable {
    virtual ~Deletable();
};
extern Deletable* g_pending;

struct CView {
    char pad[0x20];
    void* m_hWnd;
};

struct CDocument {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void* GetFirstViewPosition();   // +0x68
    virtual CView* GetNextView(void*& pos);  // +0x6c
    virtual void v70();
    virtual void v74();
    virtual int OnNewDocument();             // +0x78
    virtual void v7c();
    virtual void v80();
    virtual void OnCloseDocument();          // +0x84
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual int DoPrompt();                  // +0x98
};

extern CDocument* g_doc;
void sub_4061f0(int, CDocument*);
void sub_448c10();

struct CRobloxModule {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
    virtual void v20();
    virtual void v21();
    virtual CDocument* OpenDocumentFile(const char* name, int bMakeVisible); // +0x88
    virtual void SetDocument(CDocument* doc);                                   // +0x8c
    char pad4[0x8c - 4];
    int m_count;          // +0x8c
    CDocument* m_pDoc;    // +0x90
    CDocument* NewDocument();
};

CDocument* CRobloxModule::NewDocument()
{
    if (m_pDoc == 0) {
        Deletable* p = g_pending;
        g_pending = 0;
        delete p;
        int count = m_count;
        CDocument* doc = OpenDocumentFile(0, 1);
        try {
            sub_448c10();
        } catch (...) {
            AfxMessageBox(0xf104);
            if (doc)
                doc->OnCloseDocument();
            throw;
        }
        if (doc == 0) {
            if (count != m_count)
                throw std::runtime_error("OpenDocumentFile returned NULL - b");
            throw std::runtime_error("OpenDocumentFile returned NULL - a");
        }
        return doc;
    }
    else {
        if (!m_pDoc->DoPrompt())
            throw std::runtime_error("User cancelled");
        SetDocument(m_pDoc);
        if (!m_pDoc->OnNewDocument())
            throw std::runtime_error("CDocument::OnNewDocument returned FALSE");
        if (g_doc == m_pDoc)
            sub_4061f0(1, g_doc);
        void* pos = m_pDoc->GetFirstViewPosition();
        while (pos) {
            CView* v = m_pDoc->GetNextView(pos);
            Deletable* p = g_pending;
            g_pending = 0;
            delete p;
            SendMessageA(v->m_hWnd, 0x364, 0, 0);
        }
    }
    return m_pDoc;
}
