// from server: 100% by EspClaude
// roc 2009-06 0046d980  unit: CWebToolbox  size: 87 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0046d980
//
// 0046d980  56                   push esi
// 0046d981  8bf1                 mov esi, ecx
// 0046d983  8b8ef8000000         mov ecx, dword ptr [esi + 0xf8]
// 0046d989  57                   push edi
// 0046d98a  85c9                 test ecx, ecx
// 0046d98c  7405                 je 0x46d993
// 0046d98e  e847b42a00           call 0x718dda
// 0046d993  8bb6fc000000         mov esi, dword ptr [esi + 0xfc]
// 0046d999  85f6                 test esi, esi
// 0046d99b  7408                 je 0x46d9a5
// 0046d99d  8b06                 mov eax, dword ptr [esi]
// 0046d99f  8b4804               mov ecx, dword ptr [eax + 4]
// 0046d9a2  56                   push esi
// 0046d9a3  ffd1                 call ecx
// 0046d9a5  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0046d9a9  85c0                 test eax, eax
// 0046d9ab  7507                 jne 0x46d9b4
// 0046d9ad  bf03400080           mov edi, 0x80004003
// 0046d9b2  eb10                 jmp 0x46d9c4
// 0046d9b4  8930                 mov dword ptr [eax], esi
// 0046d9b6  85f6                 test esi, esi
// 0046d9b8  7408                 je 0x46d9c2
// 0046d9ba  8b16                 mov edx, dword ptr [esi]
// 0046d9bc  8b4204               mov eax, dword ptr [edx + 4]
// 0046d9bf  56                   push esi
// 0046d9c0  ffd0                 call eax
// 0046d9c2  33ff                 xor edi, edi
// 0046d9c4  85f6                 test esi, esi
// 0046d9c6  7408                 je 0x46d9d0
// 0046d9c8  8b0e                 mov ecx, dword ptr [esi]
// 0046d9ca  8b5108               mov edx, dword ptr [ecx + 8]
// 0046d9cd  56                   push esi
// 0046d9ce  ffd2                 call edx
// 0046d9d0  8bc7                 mov eax, edi
// 0046d9d2  5f                   pop edi
// 0046d9d3  5e                   pop esi
// 0046d9d4  c20400               ret 4
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
