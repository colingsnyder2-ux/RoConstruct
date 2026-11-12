// from server: 84% by EspClaude
// from server: 52% by colin
// roc 2007-08 004058e0  unit: VCWorkspace::?$CComObject  size: 133 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004058e0
//
// 004058e0  53                   push ebx
// 004058e1  8b5c2408             mov ebx, dword ptr [esp + 8]
// 004058e5  85db                 test ebx, ebx
// 004058e7  56                   push esi
// 004058e8  57                   push edi
// 004058e9  7405                 je 0x4058f0
// 004058eb  8d43e8               lea eax, [ebx - 0x18]
// 004058ee  eb02                 jmp 0x4058f2
// 004058f0  33c0                 xor eax, eax
// 004058f2  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 004058f6  85ff                 test edi, edi
// 004058f8  7460                 je 0x40595a
// 004058fa  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 004058fe  85f6                 test esi, esi
// 00405900  7458                 je 0x40595a
// 00405902  8b08                 mov ecx, dword ptr [eax]
// 00405904  55                   push ebp
// 00405905  8d542414             lea edx, [esp + 0x14]
// 00405909  52                   push edx
// 0040590a  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0040590e  52                   push edx
// 0040590f  50                   push eax
// 00405910  8b01                 mov eax, dword ptr [ecx]
// 00405912  ffd0                 call eax
// 00405914  8be8                 mov ebp, eax
// 00405916  85ed                 test ebp, ebp
// 00405918  7c2b                 jl 0x405945
// 0040591a  8b442414             mov eax, dword ptr [esp + 0x14]
// 0040591e  8b08                 mov ecx, dword ptr [eax]
// 00405920  8b5108               mov edx, dword ptr [ecx + 8]
// 00405923  50                   push eax
// 00405924  ffd2                 call edx
// 00405926  8bcb                 mov ecx, ebx
// 00405928  e893edffff           call 0x4046c0
// 0040592d  85c0                 test eax, eax
// 0040592f  c70701000000         mov dword ptr [edi], 1
// 00405935  7514                 jne 0x40594b
// 00405937  8b4304               mov eax, dword ptr [ebx + 4]
// 0040593a  8906                 mov dword ptr [esi], eax
// 0040593c  8bc5                 mov eax, ebp
// 0040593e  5d                   pop ebp
// 0040593f  5f                   pop edi
// 00405940  5e                   pop esi
// 00405941  5b                   pop ebx
// 00405942  c21000               ret 0x10
// 00405945  c70700000000         mov dword ptr [edi], 0
// 0040594b  8bc5                 mov eax, ebp
// 0040594d  5d                   pop ebp
// 0040594e  5f                   pop edi
// 0040594f  c70600000000         mov dword ptr [esi], 0
// 00405955  5e                   pop esi
// 00405956  5b                   pop ebx
// 00405957  c21000               ret 0x10
// 0040595a  5f                   pop edi
// 0040595b  5e                   pop esi
// 0040595c  b803400080           mov eax, 0x80004003
// 00405961  5b                   pop ebx
// 00405962  c21000               ret 0x10

typedef long HRESULT;
struct GUID_ { unsigned long d1; unsigned short d2, d3; unsigned char d4[8]; };

struct IUnknownLike
{
    virtual HRESULT __stdcall QueryInterface(const GUID_& riid, void** ppv) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
};

struct OuterBase : public IUnknownLike
{
    int reserved[5];
};

template <class T>
struct AdvisorImpl
{
    unsigned long cookie;
    int isEmpty();
    virtual HRESULT __stdcall GetConnection(const GUID_& riid, int* pConnected, unsigned long* pCookie);
};

template <class T>
HRESULT __stdcall AdvisorImpl<T>::GetConnection(const GUID_& riid, int* pConnected, unsigned long* pCookie)
{
    T* pT = static_cast<T*>(this);
    if (pConnected == 0 || pCookie == 0)
        return (HRESULT)0x80004003;

    IUnknownLike* punk;
    HRESULT hr = pT->QueryInterface(riid, (void**)&punk);
    if (hr >= 0) {
        punk->Release();
        int empty = isEmpty();
        *pConnected = 1;
        if (empty == 0) {
            *pCookie = cookie;
            return hr;
        }
        *pCookie = 0;
        return hr;
    }
    *pConnected = 0;
    *pCookie = 0;
    return hr;
}

struct Outer : public OuterBase, public AdvisorImpl<Outer>
{
};

template struct AdvisorImpl<Outer>;
