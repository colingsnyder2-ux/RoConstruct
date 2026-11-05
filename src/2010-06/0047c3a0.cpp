// from server: 100% by Yeetserama
// roc 2010-06 0047c3a0  unit: CWebToolbox  size: 87 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0047c3a0
//
// 0047c3a0  56                   push esi
// 0047c3a1  8bf1                 mov esi, ecx
// 0047c3a3  8b8ef8000000         mov ecx, dword ptr [esi + 0xf8]
// 0047c3a9  57                   push edi
// 0047c3aa  85c9                 test ecx, ecx
// 0047c3ac  7405                 je 0x47c3b3
// 0047c3ae  e88fb93200           call 0x7a7d42
// 0047c3b3  8bb6fc000000         mov esi, dword ptr [esi + 0xfc]
// 0047c3b9  85f6                 test esi, esi
// 0047c3bb  7408                 je 0x47c3c5
// 0047c3bd  8b06                 mov eax, dword ptr [esi]
// 0047c3bf  8b4804               mov ecx, dword ptr [eax + 4]
// 0047c3c2  56                   push esi
// 0047c3c3  ffd1                 call ecx
// 0047c3c5  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0047c3c9  85c0                 test eax, eax
// 0047c3cb  7507                 jne 0x47c3d4
// 0047c3cd  bf03400080           mov edi, 0x80004003
// 0047c3d2  eb10                 jmp 0x47c3e4
// 0047c3d4  8930                 mov dword ptr [eax], esi
// 0047c3d6  85f6                 test esi, esi
// 0047c3d8  7408                 je 0x47c3e2
// 0047c3da  8b16                 mov edx, dword ptr [esi]
// 0047c3dc  8b4204               mov eax, dword ptr [edx + 4]
// 0047c3df  56                   push esi
// 0047c3e0  ffd0                 call eax
// 0047c3e2  33ff                 xor edi, edi
// 0047c3e4  85f6                 test esi, esi
// 0047c3e6  7408                 je 0x47c3f0
// 0047c3e8  8b0e                 mov ecx, dword ptr [esi]
// 0047c3ea  8b5108               mov edx, dword ptr [ecx + 8]
// 0047c3ed  56                   push esi
// 0047c3ee  ffd2                 call edx
// 0047c3f0  8bc7                 mov eax, edi
// 0047c3f2  5f                   pop edi
// 0047c3f3  5e                   pop esi
// 0047c3f4  c20400               ret 4
// copied from an identical function in another client (function ?fn_ROCX000003_0046a8e0@CWebToolbox@ns_ROCX000003@@QAEJPAPAUInterface@2@@Z)

namespace ns_ROCX000003 {
// from server: 100% by king_originala
struct Interface {
    virtual void __stdcall slot0() = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
};

struct Helper {
    void sub_6a0a28();
};

struct CWebToolbox {
    char pad[0xf8];
    Helper* field_f8;
    Interface* field_fc;
    long fn_ROCX000003_0046a8e0(Interface** out);
};

long CWebToolbox::fn_ROCX000003_0046a8e0(Interface** out)
{
    if (field_f8)
        field_f8->sub_6a0a28();

    Interface* value = field_fc;
    if (value)
        value->AddRef();

    long result;
    if (!out) {
        result = (long)0x80004003UL;
    } else {
        *out = value;
        if (value)
            value->AddRef();
        result = 0;
    }

    if (value)
        value->Release();

    return result;
}
}
