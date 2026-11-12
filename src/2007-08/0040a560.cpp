// from server: 89% by EspClaude
// from server: 41% by Yeetserama
// roc 2007-08 0040a560  unit: VCApp::?$CComAggObject  size: 166 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0040a560
//
// 0040a560  55                   push ebp
// 0040a561  8bec                 mov ebp, esp
// 0040a563  6aff                 push -1
// 0040a565  683b997300           push 0x73993b
// 0040a56a  64a100000000         mov eax, dword ptr fs:[0]
// 0040a570  50                   push eax
// 0040a571  83ec0c               sub esp, 0xc
// 0040a574  53                   push ebx
// 0040a575  56                   push esi
// 0040a576  57                   push edi
// 0040a577  a188518b00           mov eax, dword ptr [0x8b5188]
// 0040a57c  33c5                 xor eax, ebp
// 0040a57e  50                   push eax
// 0040a57f  8d45f4               lea eax, [ebp - 0xc]
// 0040a582  64a300000000         mov dword ptr fs:[0], eax
// 0040a588  8965f0               mov dword ptr [ebp - 0x10], esp
// 0040a58b  8b5d10               mov ebx, dword ptr [ebp + 0x10]
// 0040a58e  33f6                 xor esi, esi
// 0040a590  3bde                 cmp ebx, esi
// 0040a592  7519                 jne 0x40a5ad
// 0040a594  b803400080           mov eax, 0x80004003
// 0040a599  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0040a59c  64890d00000000       mov dword ptr fs:[0], ecx
// 0040a5a3  59                   pop ecx
// 0040a5a4  5f                   pop edi
// 0040a5a5  5e                   pop esi
// 0040a5a6  5b                   pop ebx
// 0040a5a7  8be5                 mov esp, ebp
// 0040a5a9  5d                   pop ebp
// 0040a5aa  c20c00               ret 0xc
// 0040a5ad  bf0e000780           mov edi, 0x8007000e
// 0040a5b2  6a34                 push 0x34
// 0040a5b4  8933                 mov dword ptr [ebx], esi
// 0040a5b6  897d10               mov dword ptr [ebp + 0x10], edi
// 0040a5b9  8975fc               mov dword ptr [ebp - 4], esi
// 0040a5bc  e835592200           call 0x62fef6
// 0040a5c1  8bc8                 mov ecx, eax
// 0040a5c3  83c404               add esp, 4
// 0040a5c6  894dec               mov dword ptr [ebp - 0x14], ecx
// 0040a5c9  3bce                 cmp ecx, esi
// 0040a5cb  c645fc01             mov byte ptr [ebp - 4], 1
// 0040a5cf  740b                 je 0x40a5dc
// 0040a5d1  8b4508               mov eax, dword ptr [ebp + 8]
// 0040a5d4  50                   push eax
// 0040a5d5  e8a6fdffff           call 0x40a380
// 0040a5da  8bf0                 mov esi, eax
// 0040a5dc  85f6                 test esi, esi
// 0040a5de  c745fcffffffff       mov dword ptr [ebp - 4], 0xffffffff
// 0040a5e5  7430                 je 0x40a617
// 0040a5e7  8b550c               mov edx, dword ptr [ebp + 0xc]
// 0040a5ea  8b0e                 mov ecx, dword ptr [esi]
// 0040a5ec  8b01                 mov eax, dword ptr [ecx]
// 0040a5ee  53                   push ebx
// 0040a5ef  52                   push edx
// 0040a5f0  56                   push esi
// 0040a5f1  ffd0                 call eax
// 0040a5f3  8bf8                 mov edi, eax
// 0040a5f5  85ff                 test edi, edi
// 0040a5f7  741e                 je 0x40a617
// 0040a5f9  8b16                 mov edx, dword ptr [esi]
// 0040a5fb  8b420c               mov eax, dword ptr [edx + 0xc]
// 0040a5fe  6a01                 push 1
// 0040a600  8bce                 mov ecx, esi
// 0040a602  ffd0                 call eax
// 0040a604  eb11                 jmp 0x40a617

struct _GUID;

// MFC build: ATLTRYALLOC(x) is try{x;} catch(CException* e){e->Delete();}
class CException { public: void Delete(); };

// ATL CComCreator<CComAggObject<...>>::CreateInstance shape: new(0x34), ctor(pv) at 0x40a380,
// QueryInterface at vtbl slot 0 (stdcall), deleting dtor at vtbl slot 3 (+0xc, push 1).
class VCApp_AggObject
{
public:
    VCApp_AggObject(void* pv);
    virtual long __stdcall QueryInterface(const _GUID& riid, void** ppv);
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();
    virtual ~VCApp_AggObject();
    char pad[0x34 - 4];
};

struct VCApp_CComCreator
{
    static long __stdcall CreateInstance(void* pv, const _GUID& riid, void** ppv);
};

long __stdcall VCApp_CComCreator::CreateInstance(void* pv, const _GUID& riid, void** ppv)
{
    if (ppv == 0)
        return (long)0x80004003;
    *ppv = 0;

    long hRes = (long)0x8007000e;
    VCApp_AggObject* p = 0;
    try { p = new VCApp_AggObject(pv); } catch (CException* e) { e->Delete(); }
    if (p != 0)
    {
        hRes = p->QueryInterface(riid, ppv);
        if (hRes != 0)
            delete p;
    }
    return hRes;
}
