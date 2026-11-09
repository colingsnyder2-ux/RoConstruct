// from server: 100% by tajop
struct IUnk {
    virtual long __stdcall QueryInterface(const void* riid, void** ppv) throw();
    virtual unsigned long __stdcall AddRef() throw();
    virtual unsigned long __stdcall Release() throw();
};

template <class T>
struct ComPtr {
    T* p;
    ~ComPtr() throw() { if (p) p->Release(); }
};

struct CViewBase {
    virtual ~CViewBase();
    char pad[0xf0 - 4];
};

struct CDeclarationView : CViewBase {
    ComPtr<IUnk> m_p0;
    ComPtr<IUnk> m_p1;
    ComPtr<IUnk> m_p2;
    ComPtr<IUnk> m_p3;
    ComPtr<IUnk> m_p4;
    ComPtr<IUnk> m_p5;
    ComPtr<IUnk> m_p6;
    ComPtr<IUnk> m_p7;
    virtual ~CDeclarationView();
};

CDeclarationView::~CDeclarationView()
{
}
