// from server: 100% by king_originala
// roc-flags: /O2 /GS /EHsc /MD
// from server: 75% by king_originala
// roc 2008-06 007a5420  unit: CXTIconHandle  size: 119 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 007a5420
//
// 007a5420  83ec24               sub esp, 0x24
// 007a5423  a1c05c9600           mov eax, dword ptr [0x965cc0]
// 007a5428  33c4                 xor eax, esp
// 007a542a  89442420             mov dword ptr [esp + 0x20], eax
// 007a542e  56                   push esi
// 007a542f  8d742406             lea esi, [esp + 6]
// 007a5433  33c9                 xor ecx, ecx
// 007a5435  b801000000           mov eax, 1
// 007a543a  2bd6                 sub edx, esi
// 007a543c  8d642400             lea esp, [esp]
// 007a5440  8d3442               lea esi, [edx + eax*2]
// 007a5443  668b743404           mov si, word ptr [esp + esi + 4]
// 007a5448  6603f1               add si, cx
// 007a544b  6603f6               add si, si
// 007a544e  0fb7ce               movzx ecx, si
// 007a5451  66894c4404           mov word ptr [esp + eax*2 + 4], cx
// 007a5456  40                   inc eax
// 007a5457  83f80f               cmp eax, 0xf
// 007a545a  7ee4                 jle 0x7a5440
// 007a545c  33f6                 xor esi, esi
// 007a545e  85db                 test ebx, ebx
// 007a5460  7c25                 jl 0x7a5487
// 007a5462  0fb754b702           movzx edx, word ptr [edi + esi*4 + 2]
// 007a5467  85d2                 test edx, edx
// 007a5469  7417                 je 0x7a5482
// 007a546b  0fb7445404           movzx eax, word ptr [esp + edx*2 + 4]
// 007a5470  0fb7c8               movzx ecx, ax
// 007a5473  40                   inc eax
// 007a5474  6689445404           mov word ptr [esp + edx*2 + 4], ax
// 007a5479  e8a2fdffff           call 0x7a5220
// 007a547e  668904b7             mov word ptr [edi + esi*4], ax
// 007a5482  46                   inc esi
// 007a5483  3bf3                 cmp esi, ebx
// 007a5485  7edb                 jle 0x7a5462
// 007a5487  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 007a548b  5e                   pop esi
// 007a548c  33cc                 xor ecx, esp
// 007a548e  e83fc9efff           call 0x6a1dd2
// 007a5493  83c424               add esp, 0x24
// 007a5496  c3                   ret 

typedef unsigned short Word;

struct Symbol
{
    Word code;
    Word length;
};

extern unsigned int __fastcall reverseBits(unsigned int code, unsigned int length);

static __declspec(noinline) void buildCodes(Symbol* symbols, const Word* counts, int last)
{
    Word next[16];
    unsigned int code = 0;

    for (int length = 1; length <= 15; ++length)
    {
        code = (Word)((counts[length - 1] + code) * 2);
        next[length] = (Word)code;
    }

    for (int i = 0; i <= last; ++i)
    {
        unsigned int length = symbols[i].length;
        if (length != 0)
        {
            unsigned int value = next[length]++;
            symbols[i].code = (Word)reverseBits(value, length);
        }
    }
}

void invoke(Symbol* symbols, const Word* counts, int last) { buildCodes(symbols, counts, last); }
