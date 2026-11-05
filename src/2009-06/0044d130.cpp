// from server: 100% by EspClaude
// roc 2009-06 0044d130  unit: CRobloxDHtmlDialog  size: 58 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0044d130
//
// 0044d130  56                   push esi
// 0044d131  8bf1                 mov esi, ecx
// 0044d133  e8c2c62c00           call 0x7197fa
// 0044d138  83be2801000000       cmp dword ptr [esi + 0x128], 0
// 0044d13f  7422                 je 0x44d163
// 0044d141  6a00                 push 0
// 0044d143  6a00                 push 0
// 0044d145  6a00                 push 0
// 0044d147  6a00                 push 0
// 0044d149  6a00                 push 0
// 0044d14b  8d8e14010000         lea ecx, [esi + 0x114]
// 0044d151  ff15bce48900         call dword ptr [0x89e4bc]
// 0044d157  50                   push eax
// 0044d158  8bce                 mov ecx, esi
// 0044d15a  e895c62c00           call 0x7197f4
// 0044d15f  33c0                 xor eax, eax
// 0044d161  5e                   pop esi
// 0044d162  c3                   ret 
// 0044d163  b801000000           mov eax, 1
// 0044d168  5e                   pop esi
// 0044d169  c3                   ret 
// copied from an identical function in another client (function ?f@S@ns_ROCX000006@@QAEHXZ)

namespace ns_ROCX000006 {
struct S;
typedef const char* (__thiscall *StringAccessor)(const void*);
extern StringAccessor stringAccessor;

struct S
{
    char padding[0x114];
    char text[0x14];
    unsigned int length;

    void prepare();
    void apply(const char*, int, int, int, int, int);
    int f();
};

int S::f()
{
    prepare();
    if (length != 0)
    {
        apply(stringAccessor(text), 0, 0, 0, 0, 0);
        return 0;
    }
    return 1;
}
}
