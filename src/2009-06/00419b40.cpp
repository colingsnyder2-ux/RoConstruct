// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0041faa0  unit: CListCtrl  size: 131 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0041faa0
//
// 0041faa0  56                   push esi
// 0041faa1  8b742408             mov esi, dword ptr [esp + 8]
// 0041faa5  85f6                 test esi, esi
// 0041faa7  7409                 je 0x41fab2
// 0041faa9  e8c2471300           call 0x554270
// 0041faae  3bf0                 cmp esi, eax
// 0041fab0  7530                 jne 0x41fae2
// 0041fab2  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0041fab6  85f6                 test esi, esi
// 0041fab8  7417                 je 0x41fad1
// 0041faba  e8b1471300           call 0x554270
// 0041fabf  3bf0                 cmp esi, eax
// 0041fac1  740e                 je 0x41fad1
// 0041fac3  33c0                 xor eax, eax
// 0041fac5  33c9                 xor ecx, ecx
// 0041fac7  84c0                 test al, al
// 0041fac9  0f95c1               setne cl
// 0041facc  5e                   pop esi
// 0041facd  49                   dec ecx
// 0041face  8bc1                 mov eax, ecx
// 0041fad0  c3                   ret 
// 0041fad1  b801000000           mov eax, 1
// 0041fad6  33c9                 xor ecx, ecx
// 0041fad8  84c0                 test al, al
// 0041fada  0f95c1               setne cl
// 0041fadd  5e                   pop esi
// 0041fade  49                   dec ecx
// 0041fadf  8bc1                 mov eax, ecx
// 0041fae1  c3                   ret 
// 0041fae2  57                   push edi
// 0041fae3  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0041fae7  85ff                 test edi, edi
// 0041fae9  7409                 je 0x41faf4
// 0041faeb  e880471300           call 0x554270
// 0041faf0  3bf8                 cmp edi, eax
// 0041faf2  7516                 jne 0x41fb0a
// 0041faf4  e877471300           call 0x554270
// 0041faf9  33c9                 xor ecx, ecx
// 0041fafb  3bf0                 cmp esi, eax
// 0041fafd  0f94c1               sete cl
// 0041fb00  33c0                 xor eax, eax
// 0041fb02  84c9                 test cl, cl
// 0041fb04  5f                   pop edi
// 0041fb05  0f94c0               sete al
// 0041fb08  5e                   pop esi
// 0041fb09  c3                   ret 
// 0041fb0a  3bf7                 cmp esi, edi
// 0041fb0c  7505                 jne 0x41fb13
// 0041fb0e  5f                   pop edi
// 0041fb0f  33c0                 xor eax, eax
// 0041fb11  5e                   pop esi
// 0041fb12  c3                   ret 
// 0041fb13  83c704               add edi, 4
// 0041fb16  57                   push edi
// 0041fb17  8d4e04               lea ecx, [esi + 4]
// 0041fb1a  ff1524248000         call dword ptr [0x802424]
// 0041fb20  5f                   pop edi
// 0041fb21  5e                   pop esi
// 0041fb22  c3                   ret 

struct String
{
    unsigned char storage[28];
};

typedef int (__thiscall *StringCompare)(const String *, const String &);
extern StringCompare stringCompare;

struct Name
{

    String text;
    static int isLocal(const Name *);
};

extern const Name & __cdecl getLocalScope();

__forceinline int Name::isLocal(const Name *p)
{
    if (!p || p == &getLocalScope())
        return 1;
    return 0;
}

int __cdecl compareNames(const Name *left, const Name *right)
{
    if (Name::isLocal(left))
        return int(bool((unsigned char)Name::isLocal(right))) - 1;

    if (Name::isLocal(right))
        return int(!bool((unsigned char)Name::isLocal(left)));

    if (left == right)
        return 0;

    return stringCompare(&left->text, right->text);
}
