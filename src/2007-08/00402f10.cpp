// from server: 100% by Yeetserama
// roc 2007-08 00402f10  unit: VCWorkspace::?$CComObject  size: 208 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00402f10
//
// 00402f10  83ec18               sub esp, 0x18
// 00402f13  a188518b00           mov eax, dword ptr [0x8b5188]
// 00402f18  33c4                 xor eax, esp
// 00402f1a  89442414             mov dword ptr [esp + 0x14], eax
// 00402f1e  53                   push ebx
// 00402f1f  8b5c2428             mov ebx, dword ptr [esp + 0x28]
// 00402f23  85db                 test ebx, ebx
// 00402f25  56                   push esi
// 00402f26  8b742428             mov esi, dword ptr [esp + 0x28]
// 00402f2a  57                   push edi
// 00402f2b  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 00402f2f  7406                 je 0x402f37
// 00402f31  c70300000000         mov dword ptr [ebx], 0
// 00402f37  85f6                 test esi, esi
// 00402f39  0f8488000000         je 0x402fc7
// 00402f3f  85db                 test ebx, ebx
// 00402f41  0f8480000000         je 0x402fc7
// 00402f47  8b07                 mov eax, dword ptr [edi]
// 00402f49  8b500c               mov edx, dword ptr [eax + 0xc]
// 00402f4c  8d4c2410             lea ecx, [esp + 0x10]
// 00402f50  51                   push ecx
// 00402f51  57                   push edi
// 00402f52  ffd2                 call edx
// 00402f54  8b06                 mov eax, dword ptr [esi]
// 00402f56  8b00                 mov eax, dword ptr [eax]
// 00402f58  8d4c240c             lea ecx, [esp + 0xc]
// 00402f5c  51                   push ecx
// 00402f5d  8d542414             lea edx, [esp + 0x14]
// 00402f61  52                   push edx
// 00402f62  56                   push esi
// 00402f63  ffd0                 call eax
// 00402f65  8bf0                 mov esi, eax
// 00402f67  85f6                 test esi, esi
// 00402f69  7c4d                 jl 0x402fb8
// 00402f6b  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00402f6f  51                   push ecx
// 00402f70  8d4f04               lea ecx, [edi + 4]
// 00402f73  e848f4ffff           call 0x4023c0
// 00402f78  8903                 mov dword ptr [ebx], eax
// 00402f7a  f7d8                 neg eax
// 00402f7c  1bc0                 sbb eax, eax
// 00402f7e  25fffdfb7f           and eax, 0x7ffbfdff
// 00402f83  0501020480           add eax, 0x80040201
// 00402f88  8bf0                 mov esi, eax
// 00402f8a  740c                 je 0x402f98
// 00402f8c  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00402f90  8b10                 mov edx, dword ptr [eax]
// 00402f92  50                   push eax
// 00402f93  8b4208               mov eax, dword ptr [edx + 8]
// 00402f96  ffd0                 call eax
// 00402f98  85f6                 test esi, esi
// 00402f9a  7d06                 jge 0x402fa2
// 00402f9c  c70300000000         mov dword ptr [ebx], 0
// 00402fa2  5f                   pop edi
// 00402fa3  8bc6                 mov eax, esi
// 00402fa5  5e                   pop esi
// 00402fa6  5b                   pop ebx
// 00402fa7  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00402fab  33cc                 xor ecx, esp
// 00402fad  e86cda2200           call 0x630a1e
// 00402fb2  83c418               add esp, 0x18
// 00402fb5  c20c00               ret 0xc
// 00402fb8  81fe02400080         cmp esi, 0x80004002
// 00402fbe  75d8                 jne 0x402f98
// 00402fc0  be02020480           mov esi, 0x80040202
// 00402fc5  ebd5                 jmp 0x402f9c
// 00402fc7  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00402fcb  5f                   pop edi
// 00402fcc  5e                   pop esi
// 00402fcd  5b                   pop ebx
// 00402fce  33cc                 xor ecx, esp
// 00402fd0  b803400080           mov eax, 0x80004003
// 00402fd5  e844da2200           call 0x630a1e
// 00402fda  83c418               add esp, 0x18
// 00402fdd  c20c00               ret 0xc
// copied from an identical function in another client (function ?Advise@S@ns_ROCX00000c@@QAGJPAUUnknown@2@PAK@Z)

namespace ns_ROCX00000c {
// from server: 100% by king_originala
typedef long HRESULT;
typedef unsigned long DWORD;

struct IID {
    unsigned long a;
    unsigned short b;
    unsigned short c;
    unsigned char d[8];
};

struct Unknown {
    virtual HRESULT __stdcall QueryInterface(const IID& iid, Unknown** result) = 0;
    virtual DWORD __stdcall AddRef() = 0;
    virtual DWORD __stdcall Release() = 0;
    virtual HRESULT __stdcall GetConnectionInterface(IID* iid) = 0;
};

struct Entries {
    DWORD Add(Unknown* object);
};

struct S : Unknown {
    Entries entries;
    HRESULT __stdcall Advise(Unknown* sink, DWORD* cookie);
};

HRESULT __stdcall S::Advise(Unknown* sink, DWORD* cookie)
{
    if (cookie)
        *cookie = 0;

    if (!sink || !cookie)
        return (HRESULT)0x80004003UL;

    IID iid;
    GetConnectionInterface(&iid);

    Unknown* object;
    HRESULT result = sink->QueryInterface(iid, &object);

    if (result >= 0) {
        *cookie = entries.Add(object);
        result = *cookie ? 0 : (HRESULT)0x80040201UL;
        if (result != 0)
            object->Release();
    } else if (result == (HRESULT)0x80004002UL) {
        result = (HRESULT)0x80040202UL;
    }

    if (result < 0)
        *cookie = 0;

    return result;
}
}
