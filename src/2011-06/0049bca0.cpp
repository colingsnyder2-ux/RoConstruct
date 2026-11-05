// from server: 100% by Yeetserama
// roc 2011-06 0049bca0  unit: CWebToolbox  size: 87 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0049bca0
//
// 0049bca0  56                   push esi
// 0049bca1  8bf1                 mov esi, ecx
// 0049bca3  8b8ef8000000         mov ecx, dword ptr [esi + 0xf8]
// 0049bca9  57                   push edi
// 0049bcaa  85c9                 test ecx, ecx
// 0049bcac  7405                 je 0x49bcb3
// 0049bcae  e84de73600           call 0x80a400
// 0049bcb3  8bb6fc000000         mov esi, dword ptr [esi + 0xfc]
// 0049bcb9  85f6                 test esi, esi
// 0049bcbb  7408                 je 0x49bcc5
// 0049bcbd  8b06                 mov eax, dword ptr [esi]
// 0049bcbf  8b4804               mov ecx, dword ptr [eax + 4]
// 0049bcc2  56                   push esi
// 0049bcc3  ffd1                 call ecx
// 0049bcc5  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0049bcc9  85c0                 test eax, eax
// 0049bccb  7507                 jne 0x49bcd4
// 0049bccd  bf03400080           mov edi, 0x80004003
// 0049bcd2  eb10                 jmp 0x49bce4
// 0049bcd4  8930                 mov dword ptr [eax], esi
// 0049bcd6  85f6                 test esi, esi
// 0049bcd8  7408                 je 0x49bce2
// 0049bcda  8b16                 mov edx, dword ptr [esi]
// 0049bcdc  8b4204               mov eax, dword ptr [edx + 4]
// 0049bcdf  56                   push esi
// 0049bce0  ffd0                 call eax
// 0049bce2  33ff                 xor edi, edi
// 0049bce4  85f6                 test esi, esi
// 0049bce6  7408                 je 0x49bcf0
// 0049bce8  8b0e                 mov ecx, dword ptr [esi]
// 0049bcea  8b5108               mov edx, dword ptr [ecx + 8]
// 0049bced  56                   push esi
// 0049bcee  ffd2                 call edx
// 0049bcf0  8bc7                 mov eax, edi
// 0049bcf2  5f                   pop edi
// 0049bcf3  5e                   pop esi
// 0049bcf4  c20400               ret 4
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
