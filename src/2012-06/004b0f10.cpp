// from server: 100% by Xemicl
// roc 2012-06 004b0f10  unit: CWebToolbox  size: 87 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004b0f10
//
// 004b0f10  56                   push esi
// 004b0f11  8bf1                 mov esi, ecx
// 004b0f13  8b8ef8000000         mov ecx, dword ptr [esi + 0xf8]
// 004b0f19  57                   push edi
// 004b0f1a  85c9                 test ecx, ecx
// 004b0f1c  7405                 je 0x4b0f23
// 004b0f1e  e881154d00           call 0x9824a4
// 004b0f23  8bb6fc000000         mov esi, dword ptr [esi + 0xfc]
// 004b0f29  85f6                 test esi, esi
// 004b0f2b  7408                 je 0x4b0f35
// 004b0f2d  8b06                 mov eax, dword ptr [esi]
// 004b0f2f  8b4804               mov ecx, dword ptr [eax + 4]
// 004b0f32  56                   push esi
// 004b0f33  ffd1                 call ecx
// 004b0f35  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004b0f39  85c0                 test eax, eax
// 004b0f3b  7507                 jne 0x4b0f44
// 004b0f3d  bf03400080           mov edi, 0x80004003
// 004b0f42  eb10                 jmp 0x4b0f54
// 004b0f44  8930                 mov dword ptr [eax], esi
// 004b0f46  85f6                 test esi, esi
// 004b0f48  7408                 je 0x4b0f52
// 004b0f4a  8b16                 mov edx, dword ptr [esi]
// 004b0f4c  8b4204               mov eax, dword ptr [edx + 4]
// 004b0f4f  56                   push esi
// 004b0f50  ffd0                 call eax
// 004b0f52  33ff                 xor edi, edi
// 004b0f54  85f6                 test esi, esi
// 004b0f56  7408                 je 0x4b0f60
// 004b0f58  8b0e                 mov ecx, dword ptr [esi]
// 004b0f5a  8b5108               mov edx, dword ptr [ecx + 8]
// 004b0f5d  56                   push esi
// 004b0f5e  ffd2                 call edx
// 004b0f60  8bc7                 mov eax, edi
// 004b0f62  5f                   pop edi
// 004b0f63  5e                   pop esi
// 004b0f64  c20400               ret 4
// copied from an identical function in another client (function ?fn_ROCX00002d_0046a8e0@CWebToolbox@ns_ROCX00002d@@QAEJPAPAUInterface@2@@Z)

namespace ns_ROCX00002d {
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
    long fn_ROCX00002d_0046a8e0(Interface** out);
};

long CWebToolbox::fn_ROCX00002d_0046a8e0(Interface** out)
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