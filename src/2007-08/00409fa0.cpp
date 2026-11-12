// from server: 65% by EspClaude
// from server: 47% by colin
// roc 2007-08 00409fa0  unit: VCApp::?$CComObject  size: 228 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00409fa0
//
// 00409fa0  55                   push ebp
// 00409fa1  8bec                 mov ebp, esp
// 00409fa3  6aff                 push -1
// 00409fa5  68b8987300           push 0x7398b8
// 00409faa  64a100000000         mov eax, dword ptr fs:[0]
// 00409fb0  50                   push eax
// 00409fb1  83ec14               sub esp, 0x14
// 00409fb4  a188518b00           mov eax, dword ptr [0x8b5188]
// 00409fb9  33c5                 xor eax, ebp
// 00409fbb  8945ec               mov dword ptr [ebp - 0x14], eax
// 00409fbe  53                   push ebx
// 00409fbf  56                   push esi
// 00409fc0  57                   push edi
// 00409fc1  50                   push eax
// 00409fc2  8d45f4               lea eax, [ebp - 0xc]
// 00409fc5  64a300000000         mov dword ptr fs:[0], eax
// 00409fcb  8965f0               mov dword ptr [ebp - 0x10], esp
// 00409fce  8b450c               mov eax, dword ptr [ebp + 0xc]
// 00409fd1  33ff                 xor edi, edi
// 00409fd3  3bc7                 cmp eax, edi
// 00409fd5  750a                 jne 0x409fe1
// 00409fd7  b803400080           mov eax, 0x80004003
// 00409fdc  e971010000           jmp 0x40a152
// 00409fe1  6a1c                 push 0x1c
// 00409fe3  8938                 mov dword ptr [eax], edi
// 00409fe5  897dfc               mov dword ptr [ebp - 4], edi
// 00409fe8  e8095f2200           call 0x62fef6
// 00409fed  8bf0                 mov esi, eax
// 00409fef  83c404               add esp, 4
// 00409ff2  3bf7                 cmp esi, edi
// 00409ff4  7429                 je 0x40a01f
// 00409ff6  897e04               mov dword ptr [esi + 4], edi
// 00409ff9  897e10               mov dword ptr [esi + 0x10], edi
// 00409ffc  897e0c               mov dword ptr [esi + 0xc], edi
// 00409fff  897e08               mov dword ptr [esi + 8], edi
// 0040a002  897e14               mov dword ptr [esi + 0x14], edi
// 0040a005  897e18               mov dword ptr [esi + 0x18], edi
// 0040a008  c706a84f7800         mov dword ptr [esi], 0x784fa8
// 0040a00e  8b0d44ae8b00         mov ecx, dword ptr [0x8bae44]
// 0040a014  8b01                 mov eax, dword ptr [ecx]
// 0040a016  8b5004               mov edx, dword ptr [eax + 4]
// 0040a019  ffd2                 call edx
// 0040a01b  8bde                 mov ebx, esi
// 0040a01d  eb02                 jmp 0x40a021
// 0040a01f  33db                 xor ebx, ebx
// 0040a021  83ceff               or esi, 0xffffffff
// 0040a024  3bdf                 cmp ebx, edi
// 0040a026  8975fc               mov dword ptr [ebp - 4], esi
// 0040a029  0f8489000000         je 0x40a0b8
// 0040a02f  f60550af8b0001       test byte ptr [0x8baf50], 1
// 0040a036  7517                 jne 0x40a04f
// 0040a038  830d50af8b0001       or dword ptr [0x8baf50], 1
// 0040a03f  c70548af8b0004000000 mov dword ptr [0x8baf48], 4
// 0040a049  89354caf8b00         mov dword ptr [0x8baf4c], esi
// 0040a04f  bf48af8b00           mov edi, 0x8baf48
// 0040a054  c745e800000000       mov dword ptr [ebp - 0x18], 0
// 0040a05b  6a04                 push 4
// 0040a05d  c745fc02000000       mov dword ptr [ebp - 4], 2
// 0040a064  e8578affff           call 0x402ac0
// 0040a069  83c404               add esp, 4
// 0040a06c  84c0                 test al, al
// 0040a06e  7422                 je 0x40a092
// 0040a070  b804000000           mov eax, 4
// 0040a075  e8e66a2200           call 0x630b60
// 0040a07a  8bcc                 mov ecx, esp
// 0040a07c  8965f0               mov dword ptr [ebp - 0x10], esp
// 0040a07f  894de4               mov dword ptr [ebp - 0x1c], ecx
// 0040a082  eb1d                 jmp 0x40a0a1
//
// ATL 8 IConnectionPointContainerImpl<T>::EnumConnectionPoints, written from the
// atlcom.h body. Evidence: new 0x1c = CComObject<CComEnum<IEnumConnectionPoints>>
// (vptr, m_spUnk +4, m_begin/m_end/m_iter +8/+0xc/+0x10, m_dwFlags +0x14,
// m_dwRef +0x18; zero-store order 4,0x10,0xc,8,0x14,0x18 = ctor order);
// _pAtlModule->Lock() vslot 1; guarded static conn map {4, -1};
// _ATL_SAFE_ALLOCA(4) -> 0x402ac0 / _alloca / 0x4035e0 Allocate; 0x401150 manager
// dtor; 0x403e40 CComEnumImpl::Init(begin, end, pUnk, AtlFlagCopy=3);
// virtual dtor vslot 7; QI vslot 0 with IID at 0x784fe0;
// catch(CException*) funclet at 0x40a084 calls 0x62ff2c.

#include <malloc.h>

typedef unsigned long DWORD;
typedef unsigned long DWORD_PTR;
typedef unsigned long ULONG;
typedef long HRESULT;
typedef int INT_PTR;
typedef unsigned int size_t_;
struct IID { unsigned long d1; unsigned short d2, d3; unsigned char d4[8]; };
typedef const IID& REFIID;

#define E_POINTER     ((HRESULT)0x80004003L)
#define E_OUTOFMEMORY ((HRESULT)0x8007000EL)
#define FAILED(hr)    (((HRESULT)(hr)) < 0)

struct CException { void Delete(); };

struct IUnknown {
    virtual HRESULT __stdcall QueryInterface(REFIID riid, void** ppv) = 0;
    virtual ULONG __stdcall AddRef() = 0;
    virtual ULONG __stdcall Release() = 0;
};
struct IConnectionPoint : IUnknown {};
struct IEnumConnectionPoints : IUnknown {
    virtual HRESULT __stdcall Next(ULONG, IConnectionPoint**, ULONG*) = 0;
    virtual HRESULT __stdcall Skip(ULONG) = 0;
    virtual HRESULT __stdcall Reset() = 0;
    virtual HRESULT __stdcall Clone(IEnumConnectionPoints**) = 0;
};
struct IConnectionPointContainer : IUnknown {
    virtual HRESULT __stdcall EnumConnectionPoints(IEnumConnectionPoints** ppEnum) = 0;
    virtual HRESULT __stdcall FindConnectionPoint(REFIID riid, IConnectionPoint** ppCP) = 0;
};
extern const IID IID_IEnumConnectionPoints;   // 0x784fe0
extern const IID IID_Events;

struct CAtlModule {
    virtual void v0();
    virtual long Lock() throw();
};
extern CAtlModule* _pAtlModule;               // 0x8bae44

enum CComEnumFlags { AtlFlagNoCopy = 0, AtlFlagTakeOwnership = 2, AtlFlagCopy = 3 };

template <class T> struct CComPtr {
    T* p;
    CComPtr() throw() { p = 0; }
};

struct CComObjectRootBase {
    long m_dwRef;
    CComObjectRootBase() { m_dwRef = 0L; }
};

template <class Base, const IID* piid, class T>
class __declspec(novtable) CComEnumImpl : public Base {
public:
    CComEnumImpl() { m_begin = m_end = m_iter = 0; m_dwFlags = 0; }
    virtual ~CComEnumImpl();
    HRESULT Init(T* begin, T* end, IUnknown* pUnk, CComEnumFlags flags = AtlFlagNoCopy);
    CComPtr<IUnknown> m_spUnk;
    T* m_begin;
    T* m_end;
    T* m_iter;
    DWORD m_dwFlags;
};

template <class Base, const IID* piid, class T>
class __declspec(novtable) CComEnum : public CComEnumImpl<Base, piid, T>, public CComObjectRootBase {
};

template <class Base>
class CComObject : public Base {
public:
    CComObject(void* = 0) throw() { _pAtlModule->Lock(); }
    virtual ~CComObject() throw();
    HRESULT __stdcall QueryInterface(REFIID iid, void** ppvObject) throw();
    ULONG __stdcall AddRef();
    ULONG __stdcall Release();
    HRESULT __stdcall Next(ULONG, IConnectionPoint**, ULONG*);
    HRESULT __stdcall Skip(ULONG);
    HRESULT __stdcall Reset();
    HRESULT __stdcall Clone(IEnumConnectionPoints**);
};

class CCRTAllocator {
public:
    static void Free(void* p) throw() { free(p); }
};
template <class Allocator>
class CAtlSafeAllocBufferManager {
    struct CAtlSafeAllocBufferNode {
        CAtlSafeAllocBufferNode* m_pNext;
        unsigned char _pad[4];
    };
    CAtlSafeAllocBufferNode* m_pHead;
public:
    CAtlSafeAllocBufferManager() : m_pHead(0) {}
    void* Allocate(size_t_ nRequestedSize);
    ~CAtlSafeAllocBufferManager()
    {
        while (m_pHead != 0) {
            CAtlSafeAllocBufferNode* p = m_pHead;
            m_pHead = m_pHead->m_pNext;
            Allocator::Free(p);
        }
    }
};
bool __cdecl _AtlVerifyStackAvailable(size_t_ Size);

struct _ATL_CONNMAP_ENTRY { DWORD_PTR dwOffset; };

#define _ATL_PACKING 8
#define offsetofclass(base, derived) ((DWORD_PTR)(static_cast<base*>((derived*)_ATL_PACKING))-_ATL_PACKING)

template <class T>
class __declspec(novtable) IConnectionPointContainerImpl : public IConnectionPointContainer {
    typedef CComEnum<IEnumConnectionPoints, &IID_IEnumConnectionPoints, IConnectionPoint*>
        CComEnumConnectionPoints;
public:
    HRESULT __stdcall EnumConnectionPoints(IEnumConnectionPoints** ppEnum)
    {
        if (ppEnum == 0)
            return E_POINTER;
        *ppEnum = 0;
        CComEnumConnectionPoints* pEnum = 0;
        try { pEnum = new CComObject<CComEnumConnectionPoints>; } catch (CException* e) { e->Delete(); }
        if (pEnum == 0)
            return E_OUTOFMEMORY;

        int nCPCount;
        const _ATL_CONNMAP_ENTRY* pEntry = T::GetConnMap(&nCPCount);

        CAtlSafeAllocBufferManager<CCRTAllocator> _AtlSafeAllocaManager;
        if ((nCPCount < 0) || (nCPCount > (0x7fffffff / sizeof(IConnectionPoint*))))
            return E_OUTOFMEMORY;
        size_t_ nBytes = sizeof(IConnectionPoint*) * nCPCount;
        IConnectionPoint** ppCP = (IConnectionPoint**)((nBytes <= 1024 && _AtlVerifyStackAvailable(nBytes)) ?
            _alloca(nBytes) : _AtlSafeAllocaManager.Allocate(nBytes));
        if (ppCP == 0) {
            delete pEnum;
            return E_OUTOFMEMORY;
        }

        int i = 0;
        while (pEntry->dwOffset != (DWORD_PTR)-1) {
            if (pEntry->dwOffset == (DWORD_PTR)-2) {
                pEntry++;
                const _ATL_CONNMAP_ENTRY* (*pFunc)(int*) = (const _ATL_CONNMAP_ENTRY* (*)(int*))(pEntry->dwOffset);
                pEntry = pFunc(0);
                continue;
            }
            ppCP[i++] = (IConnectionPoint*)((INT_PTR)this + pEntry->dwOffset);
            pEntry++;
        }

        HRESULT hRes = pEnum->Init((IConnectionPoint**)&ppCP[0],
            (IConnectionPoint**)&ppCP[nCPCount],
            reinterpret_cast<IConnectionPointContainer*>(this), AtlFlagCopy);
        if (FAILED(hRes)) {
            delete pEnum;
            return hRes;
        }
        hRes = pEnum->QueryInterface(IID_IEnumConnectionPoints, (void**)ppEnum);
        if (FAILED(hRes))
            delete pEnum;
        return hRes;
    }
};

template <const IID* piid>
class __declspec(novtable) _ICPLocator {
public:
    virtual HRESULT __stdcall _LocCPQueryInterface(REFIID riid, void** ppvObject) = 0;
    virtual ULONG __stdcall AddRef() = 0;
    virtual ULONG __stdcall Release() = 0;
};

class App : public IConnectionPointContainerImpl<App>, public _ICPLocator<&IID_Events> {
public:
    typedef App _atl_conn_classtype;
    static const _ATL_CONNMAP_ENTRY* GetConnMap(int* pnEntries)
    {
        static const _ATL_CONNMAP_ENTRY _entries[] = {
            {offsetofclass(_ICPLocator<&IID_Events>, _atl_conn_classtype) -
             offsetofclass(IConnectionPointContainerImpl<_atl_conn_classtype>, _atl_conn_classtype)},
            {(DWORD_PTR)-1}
        };
        if (pnEntries) *pnEntries = sizeof(_entries) / sizeof(_ATL_CONNMAP_ENTRY) - 1;
        return _entries;
    }
};

template class IConnectionPointContainerImpl<App>;
