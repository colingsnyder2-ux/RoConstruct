// from server: 100% by colin
// from server: 90% by king_originala
// roc 2008-06 00406510  unit: VCApp::?$CComObject  size: 123 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00406510
//
// 00406510  53                   push ebx
// 00406511  8b5c2408             mov ebx, dword ptr [esp + 8]
// 00406515  57                   push edi
// 00406516  8bf9                 mov edi, ecx
// 00406518  85db                 test ebx, ebx
// 0040651a  750a                 jne 0x406526
// 0040651c  6805400080           push 0x80004005
// 00406521  e8daaaffff           call 0x401000
// 00406526  803b00               cmp byte ptr [ebx], 0
// 00406529  7410                 je 0x40653b
// 0040652b  80bf2201000000       cmp byte ptr [edi + 0x122], 0
// 00406532  7507                 jne 0x40653b
// 00406534  5f                   pop edi
// 00406535  33c0                 xor eax, eax
// 00406537  5b                   pop ebx
// 00406538  c20400               ret 4
// 0040653b  56                   push esi
// 0040653c  6881000000           push 0x81
// 00406541  53                   push ebx
// 00406542  ff1570288000         call dword ptr [0x802870]
// 00406548  8bf0                 mov esi, eax
// 0040654a  83c408               add esp, 8
// 0040654d  81fe80000000         cmp esi, 0x80
// 00406553  7608                 jbe 0x40655d
// 00406555  5e                   pop esi
// 00406556  5f                   pop edi
// 00406557  33c0                 xor eax, eax
// 00406559  5b                   pop ebx
// 0040655a  c20400               ret 4
// 0040655d  56                   push esi
// 0040655e  53                   push ebx
// 0040655f  8d87a3010000         lea eax, [edi + 0x1a3]
// 00406565  6881000000           push 0x81
// 0040656a  50                   push eax
// 0040656b  ff15b8288000         call dword ptr [0x8028b8]
// 00406571  50                   push eax
// 00406572  e809b1ffff           call 0x401680
// 00406577  83c414               add esp, 0x14
// 0040657a  89b738120000         mov dword ptr [edi + 0x1238], esi
// 00406580  5e                   pop esi
// 00406581  5f                   pop edi
// 00406582  b801000000           mov eax, 1
// 00406587  5b                   pop ebx
// 00406588  c20400               ret 4

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
