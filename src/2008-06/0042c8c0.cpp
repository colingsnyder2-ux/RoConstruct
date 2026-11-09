// from server: 100% by EspClaude
// from server: 88% by king_originala
// roc 2008-06 0042c8c0  unit: CLuaHtmlView::Binder  size: 1026 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0042c8c0
//
// 0042c8c0  6aff                 push -1
// 0042c8c2  68bef77b00           push 0x7bf7be
// 0042c8c7  64a100000000         mov eax, dword ptr fs:[0]
// 0042c8cd  50                   push eax
// 0042c8ce  64892500000000       mov dword ptr fs:[0], esp
// 0042c8d5  83ec68               sub esp, 0x68
// 0042c8d8  53                   push ebx
// 0042c8d9  55                   push ebp
// 0042c8da  56                   push esi
// 0042c8db  57                   push edi
// 0042c8dc  894c2420             mov dword ptr [esp + 0x20], ecx
// 0042c8e0  33f6                 xor esi, esi
// 0042c8e2  89b42480000000       mov dword ptr [esp + 0x80], esi
// 0042c8e9  e892462700           call 0x6a0f80
// 0042c8ee  33c9                 xor ecx, ecx
// 0042c8f0  894c241c             mov dword ptr [esp + 0x1c], ecx
// 0042c8f4  3bc6                 cmp eax, esi
// 0042c8f6  7415                 je 0x42c90d
// 0042c8f8  8b08                 mov ecx, dword ptr [eax]
// 0042c8fa  8d54241c             lea edx, [esp + 0x1c]
// 0042c8fe  52                   push edx
// 0042c8ff  686c058100           push 0x81056c
// 0042c904  50                   push eax
// 0042c905  8b01                 mov eax, dword ptr [ecx]
// 0042c907  ffd0                 call eax
// 0042c909  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0042c90d  c684248000000001     mov byte ptr [esp + 0x80], 1
// 0042c915  3bce                 cmp ecx, esi
// 0042c917  7534                 jne 0x42c94d
// 0042c919  68e0058100           push 0x8105e0
// 0042c91e  8d4c2438             lea ecx, [esp + 0x38]
// 0042c922  ff1558248000         call dword ptr [0x802458]
// 0042c928  8d4c2434             lea ecx, [esp + 0x34]
// 0042c92c  51                   push ecx
// 0042c92d  8d4c2454             lea ecx, [esp + 0x54]
// 0042c931  c684248400000002     mov byte ptr [esp + 0x84], 2
// 0042c939  e812d4fdff           call 0x409d50
// 0042c93e  68c81b8d00           push 0x8d1bc8
// 0042c943  8d542454             lea edx, [esp + 0x54]
// 0042c947  52                   push edx
// 0042c948  e83f4c2700           call 0x6a158c
// 0042c94d  89742418             mov dword ptr [esp + 0x18], esi
// 0042c951  8b01                 mov eax, dword ptr [ecx]
// 0042c953  8b4020               mov eax, dword ptr [eax + 0x20]
// 0042c956  8d542418             lea edx, [esp + 0x18]
// 0042c95a  52                   push edx
// 0042c95b  51                   push ecx
// 0042c95c  c684248800000003     mov byte ptr [esp + 0x88], 3
// 0042c964  ffd0                 call eax
// 0042c966  89742414             mov dword ptr [esp + 0x14], esi
// 0042c96a  8d4c2424             lea ecx, [esp + 0x24]
// 0042c96e  51                   push ecx
// 0042c96f  ff15f4288000         call dword ptr [0x8028f4]
// 0042c975  8b842494000000       mov eax, dword ptr [esp + 0x94]
// 0042c97c  8b742424             mov esi, dword ptr [esp + 0x24]
// 0042c980  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 0042c984  8b6c242c             mov ebp, dword ptr [esp + 0x2c]
// 0042c988  8b5c2430             mov ebx, dword ptr [esp + 0x30]
// 0042c98c  33d2                 xor edx, edx
// 0042c98e  50                   push eax
// 0042c98f  8d4c2438             lea ecx, [esp + 0x38]
// 0042c993  c684248400000005     mov byte ptr [esp + 0x84], 5
// 0042c99b  6689542438           mov word ptr [esp + 0x38], dx
// 0042c9a0  e8cb93feff           call 0x415d70
// 0042c9a5  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0042c9a9  8b11                 mov edx, dword ptr [ecx]
// 0042c9ab  8d442414             lea eax, [esp + 0x14]
// 0042c9af  50                   push eax
// 0042c9b0  83ec10               sub esp, 0x10
// 0042c9b3  8bc4                 mov eax, esp
// 0042c9b5  8930                 mov dword ptr [eax], esi
// 0042c9b7  8b742448             mov esi, dword ptr [esp + 0x48]
// 0042c9bb  897804               mov dword ptr [eax + 4], edi
// 0042c9be  896808               mov dword ptr [eax + 8], ebp
// 0042c9c1  89580c               mov dword ptr [eax + 0xc], ebx
// 0042c9c4  83ec10               sub esp, 0x10
// 0042c9c7  8bc4                 mov eax, esp
// 0042c9c9  8930                 mov dword ptr [eax], esi
// 0042c9cb  8b74245c             mov esi, dword ptr [esp + 0x5c]
// 0042c9cf  897004               mov dword ptr [eax + 4], esi
// 0042c9d2  8b742460             mov esi, dword ptr [esp + 0x60]
// 0042c9d6  897008               mov dword ptr [eax + 8], esi
// 0042c9d9  8b742464             mov esi, dword ptr [esp + 0x64]
// 0042c9dd  51                   push ecx
// 0042c9de  8b4a2c               mov ecx, dword ptr [edx + 0x2c]
// 0042c9e1  c68424a800000006     mov byte ptr [esp + 0xa8], 6
// 0042c9e9  89700c               mov dword ptr [eax + 0xc], esi
// 0042c9ec  ffd1                 call ecx
// 0042c9ee  8b351c298000         mov esi, dword ptr [0x80291c]
// 0042c9f4  8d542434             lea edx, [esp + 0x34]
// 0042c9f8  52                   push edx
// 0042c9f9  ffd6                 call esi
// 0042c9fb  8d442424             lea eax, [esp + 0x24]
// 0042c9ff  50                   push eax
// 0042ca00  c684248400000004     mov byte ptr [esp + 0x84], 4
// 0042ca08  ffd6                 call esi
// 0042ca0a  8b442414             mov eax, dword ptr [esp + 0x14]
// 0042ca0e  85c0                 test eax, eax
// 0042ca10  753b                 jne 0x42ca4d
// 0042ca12  8b8c2494000000       mov ecx, dword ptr [esp + 0x94]
// 0042ca19  51                   push ecx
// 0042ca1a  8d542438             lea edx, [esp + 0x38]
// 0042ca1e  687c068100           push 0x81067c
// 0042ca23  52                   push edx
// 0042ca24  e8e7d00d00           call 0x509b10
// 0042ca29  83c40c               add esp, 0xc
// 0042ca2c  50                   push eax
// 0042ca2d  8d4c2454             lea ecx, [esp + 0x54]
// 0042ca31  c684248400000007     mov byte ptr [esp + 0x84], 7
// 0042ca39  e812d3fdff           call 0x409d50
// 0042ca3e  68c81b8d00           push 0x8d1bc8
// 0042ca43  8d442454             lea eax, [esp + 0x54]
// 0042ca47  50                   push eax
// 0042ca48  e83f4b2700           call 0x6a158c
// 0042ca4d  8d542410             lea edx, [esp + 0x10]
// 0042ca51  52                   push edx
// 0042ca52  c744241400000000     mov dword ptr [esp + 0x14], 0
// 0042ca5a  8b08                 mov ecx, dword ptr [eax]
// 0042ca5c  687c058100           push 0x81057c
// 0042ca61  50                   push eax
// 0042ca62  8b01                 mov eax, dword ptr [ecx]
// 0042ca64  ffd0                 call eax
// 0042ca66  837c241000           cmp dword ptr [esp + 0x10], 0
// 0042ca6b  c684248000000008     mov byte ptr [esp + 0x80], 8
// 0042ca73  753b                 jne 0x42cab0
// 0042ca75  8b8c2494000000       mov ecx, dword ptr [esp + 0x94]
// 0042ca7c  51                   push ecx
// 0042ca7d  8d542438             lea edx, [esp + 0x38]
// 0042ca81  6860068100           push 0x810660
// 0042ca86  52                   push edx
// 0042ca87  e884d00d00           call 0x509b10
// 0042ca8c  83c40c               add esp, 0xc
// 0042ca8f  50                   push eax
// 0042ca90  8d4c2454             lea ecx, [esp + 0x54]
// 0042ca94  c684248400000009     mov byte ptr [esp + 0x84], 9
// 0042ca9c  e8afd2fdff           call 0x409d50
// 0042caa1  68c81b8d00           push 0x8d1bc8
// 0042caa6  8d442454             lea eax, [esp + 0x54]
// 0042caaa  50                   push eax
// 0042caab  e8dc4a2700           call 0x6a158c
// 0042cab0  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 0042cab4  8b8524010000         mov eax, dword ptr [ebp + 0x124]
// 0042caba  8bbd10010000         mov edi, dword ptr [ebp + 0x110]
// 0042cac0  8b30                 mov esi, dword ptr [eax]
// 0042cac2  8b1d90288000         mov ebx, dword ptr [0x802890]
// 0042cac8  81c510010000         add ebp, 0x110
// 0042cace  8bc8                 mov ecx, eax
// 0042cad0  8bd7                 mov edx, edi
// 0042cad2  89742428             mov dword ptr [esp + 0x28], esi
// 0042cad6  897c2424             mov dword ptr [esp + 0x24], edi
// 0042cada  894c2438             mov dword ptr [esp + 0x38], ecx
// 0042cade  89542434             mov dword ptr [esp + 0x34], edx
// 0042cae2  85ff                 test edi, edi
// 0042cae4  7406                 je 0x42caec
// 0042cae6  3b7c2434             cmp edi, dword ptr [esp + 0x34]
// 0042caea  7402                 je 0x42caee
// 0042caec  ffd3                 call ebx
// 0042caee  3b742438             cmp esi, dword ptr [esp + 0x38]
// 0042caf2  745b                 je 0x42cb4f
// 0042caf4  85ff                 test edi, edi
// 0042caf6  7536                 jne 0x42cb2e
// 0042caf8  ffd3                 call ebx
// 0042cafa  33c0                 xor eax, eax
// 0042cafc  3b7014               cmp esi, dword ptr [eax + 0x14]
// 0042caff  7502                 jne 0x42cb03
// 0042cb01  ffd3                 call ebx
// 0042cb03  8b4608               mov eax, dword ptr [esi + 8]
// 0042cb06  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0042cb0a  8b5030               mov edx, dword ptr [eax + 0x30]
// 0042cb0d  51                   push ecx
// 0042cb0e  52                   push edx
// 0042cb0f  e81cdeffff           call 0x42a930
// 0042cb14  83c408               add esp, 8
// 0042cb17  84c0                 test al, al
// 0042cb19  751b                 jne 0x42cb36
// 0042cb1b  85ff                 test edi, edi
// 0042cb1d  7513                 jne 0x42cb32
// 0042cb1f  ffd3                 call ebx
// 0042cb21  33c0                 xor eax, eax
// 0042cb23  3b7014               cmp esi, dword ptr [eax + 0x14]
// 0042cb26  7502                 jne 0x42cb2a
// 0042cb28  ffd3                 call ebx
// 0042cb2a  8b36                 mov esi, dword ptr [esi]
// 0042cb2c  ebb4                 jmp 0x42cae2
// 0042cb2e  8b07                 mov eax, dword ptr [edi]
// 0042cb30  ebca                 jmp 0x42cafc
// 0042cb32  8b07                 mov eax, dword ptr [edi]
// 0042cb34  ebed                 jmp 0x42cb23
// 0042cb36  8d4c2424             lea ecx, [esp + 0x24]
// 0042cb3a  89742428             mov dword ptr [esp + 0x28], esi
// 0042cb3e  e8adddffff           call 0x42a8f0
// 0042cb43  8b30                 mov esi, dword ptr [eax]
// 0042cb45  85f6                 test esi, esi
// 0042cb47  0f85a4000000         jne 0x42cbf1
// 0042cb4d  eb04                 jmp 0x42cb53
// 0042cb4f  89742428             mov dword ptr [esp + 0x28], esi
// 0042cb53  8b442420             mov eax, dword ptr [esp + 0x20]
// 0042cb57  83ec08               sub esp, 8
// 0042cb5a  0500010000           add eax, 0x100
// 0042cb5f  8bcc                 mov ecx, esp
// 0042cb61  89a4249c000000       mov dword ptr [esp + 0x9c], esp
// 0042cb68  50                   push eax
// 0042cb69  e8824bfeff           call 0x4116f0
// 0042cb6e  8d4c242c             lea ecx, [esp + 0x2c]
// 0042cb72  e8c94ffeff           call 0x411b40
// 0042cb77  b30a                 mov bl, 0xa
// 0042cb79  6a34                 push 0x34
// 0042cb7b  889c2484000000       mov byte ptr [esp + 0x84], bl
// 0042cb82  e8993d2700           call 0x6a0920
// 0042cb87  83c404               add esp, 4
// 0042cb8a  89842494000000       mov dword ptr [esp + 0x94], eax
// 0042cb91  c68424800000000b     mov byte ptr [esp + 0x80], 0xb
// 0042cb99  85c0                 test eax, eax
// 0042cb9b  740e                 je 0x42cbab
// 0042cb9d  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0042cba1  51                   push ecx
// 0042cba2  8bc8                 mov ecx, eax
// 0042cba4  e827f5ffff           call 0x42c0d0
// 0042cba9  eb02                 jmp 0x42cbad
// 0042cbab  33c0                 xor eax, eax
// 0042cbad  50                   push eax
// 0042cbae  8d4c2438             lea ecx, [esp + 0x38]
// 0042cbb2  889c2484000000       mov byte ptr [esp + 0x84], bl
// 0042cbb9  8bf0                 mov esi, eax
// 0042cbbb  e830dfffff           call 0x42aaf0
// 0042cbc0  50                   push eax
// 0042cbc1  8bcd                 mov ecx, ebp
// 0042cbc3  c68424840000000c     mov byte ptr [esp + 0x84], 0xc
// 0042cbcb  e8b0240800           call 0x4af080
// 0042cbd0  8d4c2434             lea ecx, [esp + 0x34]
// 0042cbd4  889c2480000000       mov byte ptr [esp + 0x80], bl
// 0042cbdb  e8803a1d00           call 0x600660
// 0042cbe0  8d4c2424             lea ecx, [esp + 0x24]
// 0042cbe4  c684248000000008     mov byte ptr [esp + 0x80], 8
// 0042cbec  e8cfa71400           call 0x5773c0
// 0042cbf1  8b942490000000       mov edx, dword ptr [esp + 0x90]
// 0042cbf8  8b8c2488000000       mov ecx, dword ptr [esp + 0x88]
// 0042cbff  52                   push edx
// 0042cc00  83ec08               sub esp, 8
// 0042cc03  8bc4                 mov eax, esp
// 0042cc05  8908                 mov dword ptr [eax], ecx
// 0042cc07  8b942498000000       mov edx, dword ptr [esp + 0x98]
// 0042cc0e  895004               mov dword ptr [eax + 4], edx
// 0042cc11  8b842498000000       mov eax, dword ptr [esp + 0x98]
// 0042cc18  89a424a0000000       mov dword ptr [esp + 0xa0], esp
// 0042cc1f  85c0                 test eax, eax
// 0042cc21  740c                 je 0x42cc2f
// 0042cc23  83c004               add eax, 4
// 0042cc26  b901000000           mov ecx, 1
// 0042cc2b  f00fc108             lock xadd dword ptr [eax], ecx
// 0042cc2f  8bce                 mov ecx, esi
// 0042cc31  e82afbffff           call 0x42c760
// 0042cc36  8b442410             mov eax, dword ptr [esp + 0x10]
// 0042cc3a  c684248000000004     mov byte ptr [esp + 0x80], 4
// 0042cc42  85c0                 test eax, eax
// 0042cc44  7408                 je 0x42cc4e
// 0042cc46  8b10                 mov edx, dword ptr [eax]
// 0042cc48  50                   push eax
// 0042cc49  8b4208               mov eax, dword ptr [edx + 8]
// 0042cc4c  ffd0                 call eax
// 0042cc4e  8b442414             mov eax, dword ptr [esp + 0x14]
// 0042cc52  c684248000000003     mov byte ptr [esp + 0x80], 3
// 0042cc5a  85c0                 test eax, eax
// 0042cc5c  7408                 je 0x42cc66
// 0042cc5e  8b08                 mov ecx, dword ptr [eax]
// 0042cc60  8b5108               mov edx, dword ptr [ecx + 8]
// 0042cc63  50                   push eax
// 0042cc64  ffd2                 call edx
// 0042cc66  8b442418             mov eax, dword ptr [esp + 0x18]
// 0042cc6a  c684248000000001     mov byte ptr [esp + 0x80], 1
// 0042cc72  85c0                 test eax, eax
// 0042cc74  7408                 je 0x42cc7e
// 0042cc76  8b08                 mov ecx, dword ptr [eax]
// 0042cc78  8b5108               mov edx, dword ptr [ecx + 8]
// 0042cc7b  50                   push eax
// 0042cc7c  ffd2                 call edx
// 0042cc7e  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0042cc82  c684248000000000     mov byte ptr [esp + 0x80], 0
// 0042cc8a  85c0                 test eax, eax
// 0042cc8c  7408                 je 0x42cc96
// 0042cc8e  8b08                 mov ecx, dword ptr [eax]
// 0042cc90  8b5108               mov edx, dword ptr [ecx + 8]
// 0042cc93  50                   push eax
// 0042cc94  ffd2                 call edx
// 0042cc96  8d8c2488000000       lea ecx, [esp + 0x88]
// 0042cc9d  c7842480000000ffffffff mov dword ptr [esp + 0x80], 0xffffffff
// 0042cca8  e8b3391d00           call 0x600660
// 0042ccad  8b4c2478             mov ecx, dword ptr [esp + 0x78]
// 0042ccb1  5f                   pop edi
// 0042ccb2  5e                   pop esi
// 0042ccb3  5d                   pop ebp
// 0042ccb4  64890d00000000       mov dword ptr fs:[0], ecx
// 0042ccbb  5b                   pop ebx
// 0042ccbc  83c474               add esp, 0x74
// 0042ccbf  c21000               ret 0x10

// from server: 87% by colin
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <intrin.h>
#include <string>
#include <stdexcept>
#include <list>

typedef long HRESULT;
typedef unsigned short VARTYPE;
typedef struct _GUID { unsigned long Data1; unsigned short Data2, Data3; unsigned char Data4[8]; } GUID;
typedef GUID IID;
struct tagVARIANT { VARTYPE vt; unsigned short r1, r2, r3; union { long lVal; void* p; double d; }; };
typedef tagVARIANT VARIANT;
extern "C" __declspec(dllimport) void __stdcall VariantInit(VARIANT*);
extern "C" __declspec(dllimport) HRESULT __stdcall VariantClear(VARIANT*);

struct __declspec(uuid("00000000-0000-0000-C000-000000000046")) IUnknown {
    virtual HRESULT __stdcall QueryInterface(const IID& riid, void** ppv) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
};
struct __declspec(uuid("00020400-0000-0000-C000-000000000046")) IDispatch : IUnknown {
    virtual HRESULT __stdcall GetTypeInfoCount(unsigned int*) = 0;
    virtual HRESULT __stdcall GetTypeInfo(unsigned int, unsigned long, void**) = 0;
    virtual HRESULT __stdcall GetIDsOfNames(const IID&, wchar_t**, unsigned int, unsigned long, long*) = 0;
    virtual HRESULT __stdcall Invoke(long, const IID&, unsigned long, unsigned short, void*, VARIANT*, void*, unsigned int*) = 0;
};
struct __declspec(uuid("3050f21f-98b5-11cf-bb82-00aa00bdce0b")) IHTMLElementCollection : IDispatch {
    virtual HRESULT __stdcall toString(void*) = 0;
    virtual HRESULT __stdcall put_length(long) = 0;
    virtual HRESULT __stdcall get_length(long*) = 0;
    virtual HRESULT __stdcall get__newEnum(IUnknown**) = 0;
    virtual HRESULT __stdcall item(VARIANT name, VARIANT index, IDispatch** pdisp) = 0;
};
struct __declspec(uuid("332c4425-26cb-11d0-b483-00c04fd90119")) IHTMLDocument2 : IDispatch {
    virtual HRESULT __stdcall get_Script(IDispatch**) = 0;
    virtual HRESULT __stdcall get_all(IHTMLElementCollection** p) = 0;
};
struct __declspec(uuid("3050f5d2-98b5-11cf-bb82-00aa00bdce0b")) IHTMLInputElement : IDispatch {};

template<class T> class CComPtr {
public:
    CComPtr() throw() { p = 0; }
    ~CComPtr() throw() { if (p) p->Release(); }
    operator T*() const throw() { return p; }
    T* operator->() const throw() { return p; }
    T** operator&() throw() { return &p; }
    bool operator!() const throw() { return p == 0; }
    T* p;
};
template<class T> class CComQIPtr : public CComPtr<T> {
public:
    CComQIPtr(IUnknown* lp) throw() { if (lp != 0) lp->QueryInterface(__uuidof(T), (void**)&this->p); }
};
class CComVariant : public tagVARIANT {
public:
    CComVariant() throw() { ::VariantInit(this); }
    CComVariant(const char* lpszSrc) { vt = 0; *this = lpszSrc; }
    ~CComVariant() throw() { Clear(); }
    CComVariant& operator=(const char* lpszSrc);
    HRESULT Clear() { return ::VariantClear(this); }
};

namespace boost {
namespace detail {
struct sp_counted_base {
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    long use_count_;
    long weak_count_;
};
struct shared_count {
    sp_counted_base* pi_;
    shared_count(const shared_count& r) : pi_(r.pi_) { if (pi_ != 0) _InterlockedIncrement(&pi_->use_count_); }
    ~shared_count();
};
}
template<class T> class shared_ptr {
public:
    explicit shared_ptr(T* p);
    ~shared_ptr();
    T* px;
    detail::shared_count pn;
    T* operator->() const { return px; }
    T* get() const { return px; }
};
}
template<class T> class dm_ptr {
public:
    dm_ptr(const dm_ptr& r);
    ~dm_ptr();
    T* px; void* pn;
};

namespace G3D { std::string __cdecl format(const char* fmt, ...); }
namespace RBX {
class DataModel;
class ReadRequest {
public:
    ReadRequest(dm_ptr<DataModel> dm);
    ~ReadRequest();
    void* a; void* b; void* c;
};
class Instance;
}

class CHtmlView {
public:
    virtual ~CHtmlView();
    IDispatch* GetHtmlDocument() const;
};

bool __cdecl isSameElement(IHTMLInputElement* a, IHTMLInputElement* b);

class CLuaHtmlView : public CHtmlView {
public:
    class Binder {
    public:
        Binder(IHTMLInputElement* element);
        void bind(boost::shared_ptr<RBX::Instance> instance, int property);
        char pad[0x30];
        IHTMLInputElement* element;
    };
    char pad0[0x100 - 4];
    dm_ptr<RBX::DataModel> dataModel;
    char pad1[0x110 - 0x108];
    typedef std::list<boost::shared_ptr<Binder> > BaseList;
    struct BinderList : public BaseList {
        struct iterator : public BaseList::iterator {
            iterator(const BaseList::iterator& i) : BaseList::iterator(i) {}
            __declspec(noinline) boost::shared_ptr<Binder>& operator*() const { return BaseList::iterator::operator*(); }
        };
        __declspec(noinline) void push_back(const boost::shared_ptr<Binder>& v) { BaseList::push_back(v); }
    };
    BinderList binders;
    void bindElement(boost::shared_ptr<RBX::Instance> instance, int property, const char* elementName);
};

void CLuaHtmlView::bindElement(boost::shared_ptr<RBX::Instance> instance, int property, const char* elementName)
{
    CComQIPtr<IHTMLDocument2> doc(GetHtmlDocument());
    if (!doc)
        throw std::runtime_error("The HtmlDocument is not loaded");
    CComPtr<IHTMLElementCollection> all;
    doc->get_all(&all);
    CComPtr<IDispatch> item;
    {
        CComVariant index;
        all->item(CComVariant(elementName), index, &item);
    }
    if (!item)
        throw std::runtime_error(G3D::format("%s not found", elementName));
    CComQIPtr<IHTMLInputElement> input(item);
    if (!input)
        throw std::runtime_error(G3D::format("%s is not an input element", elementName));
    Binder* binder = 0;
    BaseList::iterator it = binders.begin();
    BaseList::iterator end = binders.end();
    for (; it != end; ++it)
        if (isSameElement((*it)->element, input.p)) {
            binder = (*static_cast<BinderList::iterator&>(it)).get();
            break;
        }
    if (!binder) {
        RBX::ReadRequest request(dataModel);
        binder = new Binder(input);
        binders.push_back(boost::shared_ptr<Binder>(binder));
    }
    binder->bind(instance, property);
}
