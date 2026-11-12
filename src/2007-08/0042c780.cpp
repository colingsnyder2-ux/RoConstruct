// from server: 94% by EspClaude
// from server: 47% by colin
// roc 2007-08 0042c780  unit: CLuaHtmlView  size: 319 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0042c780
//
// 0042c780  6aff                 push -1
// 0042c782  6838d37300           push 0x73d338
// 0042c787  64a100000000         mov eax, dword ptr fs:[0]
// 0042c78d  50                   push eax
// 0042c78e  83ec10               sub esp, 0x10
// 0042c791  55                   push ebp
// 0042c792  56                   push esi
// 0042c793  57                   push edi
// 0042c794  a188518b00           mov eax, dword ptr [0x8b5188]
// 0042c799  33c4                 xor eax, esp
// 0042c79b  50                   push eax
// 0042c79c  8d442420             lea eax, [esp + 0x20]
// 0042c7a0  64a300000000         mov dword ptr fs:[0], eax
// 0042c7a6  8bf1                 mov esi, ecx
// 0042c7a8  89742418             mov dword ptr [esp + 0x18], esi
// 0042c7ac  c70690a57800         mov dword ptr [esi], 0x78a590
// 0042c7b2  8b4e1c               mov ecx, dword ptr [esi + 0x1c]
// 0042c7b5  c744242803000000     mov dword ptr [esp + 0x28], 3
// 0042c7bd  e85effffff           call 0x42c720
// 0042c7c2  8b4620               mov eax, dword ptr [esi + 0x20]
// 0042c7c5  85c0                 test eax, eax
// 0042c7c7  c744241400000000     mov dword ptr [esp + 0x14], 0
// 0042c7cf  7411                 je 0x42c7e2
// 0042c7d1  8b08                 mov ecx, dword ptr [eax]
// 0042c7d3  8d542414             lea edx, [esp + 0x14]
// 0042c7d7  52                   push edx
// 0042c7d8  6824a27800           push 0x78a224
// 0042c7dd  50                   push eax
// 0042c7de  8b01                 mov eax, dword ptr [ecx]
// 0042c7e0  ffd0                 call eax
// 0042c7e2  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 0042c7e6  6aff                 push -1
// 0042c7e8  6880a57800           push 0x78a580
// 0042c7ed  c644243004           mov byte ptr [esp + 0x30], 4
// 0042c7f2  e88949fdff           call 0x401180
// 0042c7f7  8bf8                 mov edi, eax
// 0042c7f9  83c408               add esp, 8
// 0042c7fc  85ff                 test edi, edi
// 0042c7fe  897c241c             mov dword ptr [esp + 0x1c], edi
// 0042c802  750a                 jne 0x42c80e
// 0042c804  680e000780           push 0x8007000e
// 0042c809  e8f247fdff           call 0x401000
// 0042c80e  8b461c               mov eax, dword ptr [esi + 0x1c]
// 0042c811  8b4d00               mov ecx, dword ptr [ebp]
// 0042c814  8b910c010000         mov edx, dword ptr [ecx + 0x10c]
// 0042c81a  50                   push eax
// 0042c81b  57                   push edi
// 0042c81c  55                   push ebp
// 0042c81d  c644243405           mov byte ptr [esp + 0x34], 5
// 0042c822  ffd2                 call edx
// 0042c824  57                   push edi
// 0042c825  ff15b0e97700         call dword ptr [0x77e9b0]
// 0042c82b  8b442414             mov eax, dword ptr [esp + 0x14]
// 0042c82f  85c0                 test eax, eax
// 0042c831  c644242803           mov byte ptr [esp + 0x28], 3
// 0042c836  7408                 je 0x42c840
// 0042c838  8b08                 mov ecx, dword ptr [eax]
// 0042c83a  8b5108               mov edx, dword ptr [ecx + 8]
// 0042c83d  50                   push eax
// 0042c83e  ffd2                 call edx
// 0042c840  8b4620               mov eax, dword ptr [esi + 0x20]
// 0042c843  85c0                 test eax, eax
// 0042c845  c644242802           mov byte ptr [esp + 0x28], 2
// 0042c84a  7408                 je 0x42c854
// 0042c84c  8b08                 mov ecx, dword ptr [eax]
// 0042c84e  8b5108               mov edx, dword ptr [ecx + 8]
// 0042c851  50                   push eax
// 0042c852  ffd2                 call edx
// 0042c854  8b461c               mov eax, dword ptr [esi + 0x1c]
// 0042c857  85c0                 test eax, eax
// 0042c859  c644242801           mov byte ptr [esp + 0x28], 1
// 0042c85e  7408                 je 0x42c868
// 0042c860  8b08                 mov ecx, dword ptr [eax]
// 0042c862  8b5108               mov edx, dword ptr [ecx + 8]
// 0042c865  50                   push eax
// 0042c866  ffd2                 call edx
// 0042c868  8d7e0c               lea edi, [esi + 0xc]
// 0042c86b  8bcf                 mov ecx, edi
// 0042c86d  c644242800           mov byte ptr [esp + 0x28], 0
// 0042c872  e859f2ffff           call 0x42bad0
// 0042c877  8b4704               mov eax, dword ptr [edi + 4]
// 0042c87a  50                   push eax
// 0042c87b  e8e2332000           call 0x62fc62
// 0042c880  c7470400000000       mov dword ptr [edi + 4], 0
// 0042c887  8b4e08               mov ecx, dword ptr [esi + 8]
// 0042c88a  83c404               add esp, 4
// 0042c88d  85c9                 test ecx, ecx
// 0042c88f  c7442428ffffffff     mov dword ptr [esp + 0x28], 0xffffffff
// 0042c897  7413                 je 0x42c8ac
// 0042c899  8d4108               lea eax, [ecx + 8]
// 0042c89c  83caff               or edx, 0xffffffff
// 0042c89f  f00fc110             lock xadd dword ptr [eax], edx
// 0042c8a3  7507                 jne 0x42c8ac
// 0042c8a5  8b01                 mov eax, dword ptr [ecx]
// 0042c8a7  8b5008               mov edx, dword ptr [eax + 8]
// 0042c8aa  ffd2                 call edx
// 0042c8ac  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0042c8b0  64890d00000000       mov dword ptr fs:[0], ecx
// 0042c8b7  59                   pop ecx
// 0042c8b8  5f                   pop edi
// 0042c8b9  5e                   pop esi
// 0042c8ba  5d                   pop ebp
// 0042c8bb  83c41c               add esp, 0x1c
// 0042c8be  c3                   ret 

#include <list>

extern "C" long __cdecl _InterlockedDecrement(long volatile*);
#pragma intrinsic(_InterlockedDecrement)

typedef long HRESULT;
typedef unsigned short OLECHAR;
typedef OLECHAR* BSTR;
struct GUID { unsigned long Data1; unsigned short Data2, Data3; unsigned char Data4[8]; };
typedef GUID IID;

extern "C" __declspec(dllimport) void __stdcall SysFreeString(BSTR);
BSTR __cdecl A2WBSTR(const char* lp, int nLen = -1);
__declspec(noreturn) void __stdcall AtlThrowImpl(HRESULT hr);

struct IUnknown {
    virtual HRESULT __stdcall QueryInterface(const IID& riid, void** ppv) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
};

struct IDispatch : IUnknown {
    virtual HRESULT __stdcall GetTypeInfoCount(unsigned int*) = 0;
    virtual HRESULT __stdcall GetTypeInfo(unsigned int, unsigned long, void**) = 0;
    virtual HRESULT __stdcall GetIDsOfNames(const IID&, OLECHAR**, unsigned int, unsigned long, long*) = 0;
    virtual HRESULT __stdcall Invoke(long, const IID&, unsigned long, unsigned short, void*, void*, void*, unsigned int*) = 0;
};

struct IHTMLElement : IDispatch { };

// detachEvent sits in vtable slot 0x10c/4 = 67 (read off the call through [ecx+0x10c]).
struct IHTMLElement2 : IDispatch {
#define PAD(n) virtual HRESULT __stdcall pad##n() = 0;
    PAD(7) PAD(8) PAD(9) PAD(10) PAD(11) PAD(12) PAD(13) PAD(14) PAD(15) PAD(16)
    PAD(17) PAD(18) PAD(19) PAD(20) PAD(21) PAD(22) PAD(23) PAD(24) PAD(25) PAD(26)
    PAD(27) PAD(28) PAD(29) PAD(30) PAD(31) PAD(32) PAD(33) PAD(34) PAD(35) PAD(36)
    PAD(37) PAD(38) PAD(39) PAD(40) PAD(41) PAD(42) PAD(43) PAD(44) PAD(45) PAD(46)
    PAD(47) PAD(48) PAD(49) PAD(50) PAD(51) PAD(52) PAD(53) PAD(54) PAD(55) PAD(56)
    PAD(57) PAD(58) PAD(59) PAD(60) PAD(61) PAD(62) PAD(63) PAD(64) PAD(65) PAD(66)
#undef PAD
    virtual HRESULT __stdcall detachEvent(BSTR event, IDispatch* pDisp) = 0;
};

extern "C" const IID IID_IHTMLElement2;
template<class T> struct uuidof_;
template<> struct uuidof_<IHTMLElement2> { static const IID& get() { return IID_IHTMLElement2; } };

template<class T> class CComPtr {
public:
    T* p;
    CComPtr() throw() : p(0) {}
    ~CComPtr() throw() { if (p) p->Release(); }
    operator T*() const { return p; }
    T* operator->() const { return p; }
};

template<class T> class CComQIPtr : public CComPtr<T> {
public:
    CComQIPtr(IUnknown* lp) throw()
    {
        if (lp != 0)
            lp->QueryInterface(uuidof_<T>::get(), (void**)&this->p);
    }
};

class CComBSTR {
public:
    BSTR m_str;
    CComBSTR(const char* pSrc)
    {
        if (pSrc != 0) {
            m_str = A2WBSTR(pSrc);
            if (m_str == 0)
                AtlThrowImpl(0x8007000eL);
        } else {
            m_str = 0;
        }
    }
    ~CComBSTR() { ::SysFreeString(m_str); }
    operator BSTR() const { return m_str; }
};

class sp_counted_base {
    long use_count_;
    long weak_count_;
public:
    virtual ~sp_counted_base();
    virtual void dispose() = 0;
    virtual void destroy();
    void release()
    {
        if (_InterlockedDecrement(&use_count_) == 0) {
            dispose();
            weak_release();
        }
    }
    void weak_release()
    {
        if (_InterlockedDecrement(&weak_count_) == 0)
            destroy();
    }
};

class weak_count {
    sp_counted_base* pi_;
public:
    ~weak_count() { if (pi_ != 0) pi_->weak_release(); }
};

class shared_count {
    sp_counted_base* pi_;
public:
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};

template<class T> class shared_ptr {
    T* px;
    shared_count pn;
};

template<class T> class weak_ptr {
    T* px;
    weak_count pn;
};

class CLuaHtmlView;

class Binder : public IDispatch {
public:
    void Unhook();
};

class EventSink {
public:
    virtual ~EventSink();
    weak_ptr<CLuaHtmlView> view;
    std::list<shared_ptr<CLuaHtmlView> > items;
    int field_18;
    CComPtr<Binder> binder;
    CComPtr<IHTMLElement> element;
};

EventSink::~EventSink()
{
    binder->Unhook();
    CComQIPtr<IHTMLElement2> el(element);
    el->detachEvent(CComBSTR("onchange"), binder);
}
