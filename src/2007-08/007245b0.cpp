// from server: 100% by Yeetserama
// roc 2007-08 007245b0  unit: CXTIconHandle  size: 125 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 007245b0
//
// 007245b0  83ec24               sub esp, 0x24
// 007245b3  a188518b00           mov eax, dword ptr [0x8b5188]
// 007245b8  33c4                 xor eax, esp
// 007245ba  89442420             mov dword ptr [esp + 0x20], eax
// 007245be  56                   push esi
// 007245bf  8d742406             lea esi, [esp + 6]
// 007245c3  33c9                 xor ecx, ecx
// 007245c5  b801000000           mov eax, 1
// 007245ca  2bd6                 sub edx, esi
// 007245cc  8d642400             lea esp, [esp]
// 007245d0  8d3442               lea esi, [edx + eax*2]
// 007245d3  668b743404           mov si, word ptr [esp + esi + 4]
// 007245d8  6603f1               add si, cx
// 007245db  6603f6               add si, si
// 007245de  0fb7ce               movzx ecx, si
// 007245e1  66894c4404           mov word ptr [esp + eax*2 + 4], cx
// 007245e6  83c001               add eax, 1
// 007245e9  83f80f               cmp eax, 0xf
// 007245ec  7ee2                 jle 0x7245d0
// 007245ee  33f6                 xor esi, esi
// 007245f0  85db                 test ebx, ebx
// 007245f2  7c29                 jl 0x72461d
// 007245f4  0fb754b702           movzx edx, word ptr [edi + esi*4 + 2]
// 007245f9  85d2                 test edx, edx
// 007245fb  7419                 je 0x724616
// 007245fd  0fb7445404           movzx eax, word ptr [esp + edx*2 + 4]
// 00724602  0fb7c8               movzx ecx, ax
// 00724605  83c001               add eax, 1
// 00724608  6689445404           mov word ptr [esp + edx*2 + 4], ax
// 0072460d  e87efdffff           call 0x724390
// 00724612  668904b7             mov word ptr [edi + esi*4], ax
// 00724616  83c601               add esi, 1
// 00724619  3bf3                 cmp esi, ebx
// 0072461b  7ed7                 jle 0x7245f4
// 0072461d  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00724621  5e                   pop esi
// 00724622  33cc                 xor ecx, esp
// 00724624  e8f5c3f0ff           call 0x630a1e
// 00724629  83c424               add esp, 0x24
// 0072462c  c3                   ret 
// copied from an identical function in another client (function ?buildCodes@@YAXPAUSymbol@@PBGH@Z)

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