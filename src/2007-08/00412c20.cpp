// from server: 100% by Yeetserama
// roc 2007-08 00412c20  unit: VCContent::?$CComAggObject  size: 123 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00412c20
//
// 00412c20  53                   push ebx
// 00412c21  8b5c2408             mov ebx, dword ptr [esp + 8]
// 00412c25  85db                 test ebx, ebx
// 00412c27  57                   push edi
// 00412c28  8bf9                 mov edi, ecx
// 00412c2a  750a                 jne 0x412c36
// 00412c2c  6805400080           push 0x80004005
// 00412c31  e8cae3feff           call 0x401000
// 00412c36  803b00               cmp byte ptr [ebx], 0
// 00412c39  7410                 je 0x412c4b
// 00412c3b  80bf2201000000       cmp byte ptr [edi + 0x122], 0
// 00412c42  7507                 jne 0x412c4b
// 00412c44  5f                   pop edi
// 00412c45  33c0                 xor eax, eax
// 00412c47  5b                   pop ebx
// 00412c48  c20400               ret 4
// 00412c4b  56                   push esi
// 00412c4c  6881000000           push 0x81
// 00412c51  53                   push ebx
// 00412c52  ff15a0e97700         call dword ptr [0x77e9a0]
// 00412c58  8bf0                 mov esi, eax
// 00412c5a  83c408               add esp, 8
// 00412c5d  81fe80000000         cmp esi, 0x80
// 00412c63  7608                 jbe 0x412c6d
// 00412c65  5e                   pop esi
// 00412c66  5f                   pop edi
// 00412c67  33c0                 xor eax, eax
// 00412c69  5b                   pop ebx
// 00412c6a  c20400               ret 4
// 00412c6d  56                   push esi
// 00412c6e  53                   push ebx
// 00412c6f  8d87a3010000         lea eax, [edi + 0x1a3]
// 00412c75  6881000000           push 0x81
// 00412c7a  50                   push eax
// 00412c7b  ff15cce67700         call dword ptr [0x77e6cc]
// 00412c81  50                   push eax
// 00412c82  e859eafeff           call 0x4016e0
// 00412c87  83c414               add esp, 0x14
// 00412c8a  89b738120000         mov dword ptr [edi + 0x1238], esi
// 00412c90  5e                   pop esi
// 00412c91  5f                   pop edi
// 00412c92  b801000000           mov eax, 1
// 00412c97  5b                   pop ebx
// 00412c98  c20400               ret 4
// copied from an identical function in another client (function ?f@S@ns_ROCX00000b@@QAEHPBD@Z)

namespace ns_ROCX00000b {
namespace ATL {
    void __stdcall AtlThrowImpl(long hr);
}

extern "C" {
    extern unsigned int (__cdecl *strnlen)(const char *, unsigned int);
    extern int (__cdecl *_mbsnbcpy_s)(
        unsigned char *, unsigned int, const unsigned char *, unsigned int);
}

void __cdecl CheckResult(int result);

struct S {
    char padding0[0x122];
    unsigned char enabled;
    char padding1[0x80];
    unsigned char buffer[0x81];
    char padding2[0x1238 - 0x224];
    unsigned int length;

    int f(const char *text);
};

int S::f(const char *text)
{
    if (!text)
        ATL::AtlThrowImpl((long)0x80004005UL);

    if (*text && !enabled)
        return 0;

    unsigned int count = strnlen(text, 0x81);
    if (count > 0x80)
        return 0;

    int rc = _mbsnbcpy_s(
        buffer, 0x81, (const unsigned char *)text, count);
    CheckResult(rc);

    length = count;
    return 1;
}
}
