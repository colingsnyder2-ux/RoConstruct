// from server: 100% by coldek
// from server: 100% by colin
// roc 2008-06 00402750  unit: VCWorkspace::?$CComObject  size: 175 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00402750
//
// 00402750  55                   push ebp
// 00402751  8bec                 mov ebp, esp
// 00402753  6aff                 push -1
// 00402755  6870cb7b00           push 0x7bcb70
// 0040275a  64a100000000         mov eax, dword ptr fs:[0]
// 00402760  50                   push eax
// 00402761  64892500000000       mov dword ptr fs:[0], esp
// 00402768  83ec08               sub esp, 8
// 0040276b  53                   push ebx
// 0040276c  8b5d10               mov ebx, dword ptr [ebp + 0x10]
// 0040276f  56                   push esi
// 00402770  33f6                 xor esi, esi
// 00402772  57                   push edi
// 00402773  8965f0               mov dword ptr [ebp - 0x10], esp
// 00402776  3bde                 cmp ebx, esi
// 00402778  7518                 jne 0x402792
// 0040277a  b803400080           mov eax, 0x80004003
// 0040277f  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00402782  64890d00000000       mov dword ptr fs:[0], ecx
// 00402789  5f                   pop edi
// 0040278a  5e                   pop esi
// 0040278b  5b                   pop ebx
// 0040278c  8be5                 mov esp, ebp
// 0040278e  5d                   pop ebp
// 0040278f  c20c00               ret 0xc
// 00402792  bf0e000780           mov edi, 0x8007000e
// 00402797  6a34                 push 0x34
// 00402799  8933                 mov dword ptr [ebx], esi
// 0040279b  897d10               mov dword ptr [ebp + 0x10], edi
// 0040279e  8975fc               mov dword ptr [ebp - 4], esi
// 004027a1  e87ae12900           call 0x6a0920
// 004027a6  83c404               add esp, 4
// 004027a9  3bc6                 cmp eax, esi
// 004027ab  740d                 je 0x4027ba
// 004027ad  8b4d08               mov ecx, dword ptr [ebp + 8]
// 004027b0  51                   push ecx
// 004027b1  8bc8                 mov ecx, eax
// 004027b3  e858f1ffff           call 0x401910
// 004027b8  8bf0                 mov esi, eax
// 004027ba  c745fcffffffff       mov dword ptr [ebp - 4], 0xffffffff
// 004027c1  85f6                 test esi, esi
// 004027c3  744b                 je 0x402810
// 004027c5  ff4620               inc dword ptr [esi + 0x20]
// 004027c8  8bce                 mov ecx, esi
// 004027ca  e8f18d0600           call 0x46b5c0
// 004027cf  8bf8                 mov edi, eax
// 004027d1  85ff                 test edi, edi
// 004027d3  7c02                 jl 0x4027d7
// 004027d5  33ff                 xor edi, edi
// 004027d7  ff4e20               dec dword ptr [esi + 0x20]
// 004027da  85ff                 test edi, edi
// 004027dc  7512                 jne 0x4027f0
// 004027de  8b450c               mov eax, dword ptr [ebp + 0xc]
// 004027e1  8b16                 mov edx, dword ptr [esi]
// 004027e3  8b0a                 mov ecx, dword ptr [edx]
// 004027e5  53                   push ebx
// 004027e6  50                   push eax
// 004027e7  56                   push esi
// 004027e8  ffd1                 call ecx
// 004027ea  8bf8                 mov edi, eax
// 004027ec  85ff                 test edi, edi
// 004027ee  7420                 je 0x402810
// 004027f0  8b5610               mov edx, dword ptr [esi + 0x10]
// 004027f3  8b4214               mov eax, dword ptr [edx + 0x14]
// 004027f6  8d4e10               lea ecx, [esi + 0x10]
// 004027f9  6a01                 push 1
// 004027fb  ffd0                 call eax
// 004027fd  eb11                 jmp 0x402810

// from server: 93% by king_originala
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD

typedef long HRESULT;
struct IID { unsigned long a; unsigned short b, c; unsigned char d[8]; };

struct QueryInterfaceBase
{
    virtual HRESULT __stdcall QueryInterface(const IID& iid, void** result);
    unsigned char interfaceBytes04[12];
};
struct DeletingInterfaceBase
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual ~DeletingInterfaceBase() throw();
};
struct WorkspaceObject : QueryInterfaceBase, DeletingInterfaceBase
{
    unsigned char interfaceBytes14[12];
    long references;
    unsigned char applicationBytes24[16];
    WorkspaceObject(void* outer) throw();
    virtual ~WorkspaceObject() throw();
    void SetVoid(void*) {}
    void InternalFinalConstructAddRef() { ++references; }
    void InternalFinalConstructRelease() { --references; }
    HRESULT _AtlInitialConstruct() { return 0; }
    HRESULT FinalConstruct();
    HRESULT _AtlFinalConstruct() { return 0; }
};

class CException {
public:
    virtual ~CException();
    void Delete();
};

template <class T1>
struct CComCreator
{
    static HRESULT __stdcall CreateInstance(void* pv, const IID& riid, void** ppv)
    {
        if (ppv == 0)
            return 0x80004003L;
        *ppv = 0;

        HRESULT hRes = 0x8007000EL;
        T1* p = 0;
        try { p = new T1(pv); } catch (CException* e) { e->Delete(); }
        if (p != 0)
        {
            p->SetVoid(pv);
            p->InternalFinalConstructAddRef();
            hRes = p->_AtlInitialConstruct();
            if (hRes >= 0)
                hRes = p->FinalConstruct();
            if (hRes >= 0)
                hRes = p->_AtlFinalConstruct();
            p->InternalFinalConstructRelease();
            if (hRes == 0)
                hRes = p->QueryInterface(riid, ppv);
            if (hRes != 0)
                delete p;
        }
        return hRes;
    }
};

template struct CComCreator<WorkspaceObject>;
