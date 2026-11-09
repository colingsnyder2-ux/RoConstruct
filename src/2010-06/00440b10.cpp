// from server: 100% by Yeetserama
// roc 2010-06 00440b10  unit: ScriptItem  size: 122 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00440b10
//
// 00440b10  6aff                 push -1
// 00440b12  68780d9800           push 0x980d78
// 00440b17  64a100000000         mov eax, dword ptr fs:[0]
// 00440b1d  50                   push eax
// 00440b1e  64892500000000       mov dword ptr fs:[0], esp
// 00440b25  51                   push ecx
// 00440b26  8b442418             mov eax, dword ptr [esp + 0x18]
// 00440b2a  56                   push esi
// 00440b2b  8bf1                 mov esi, ecx
// 00440b2d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00440b31  50                   push eax
// 00440b32  51                   push ecx
// 00440b33  8bce                 mov ecx, esi
// 00440b35  8974240c             mov dword ptr [esp + 0xc], esi
// 00440b39  e882d4ffff           call 0x43dfc0
// 00440b3e  51                   push ecx
// 00440b3f  8bcc                 mov ecx, esp
// 00440b41  89642420             mov dword ptr [esp + 0x20], esp
// 00440b45  685ca9a000           push 0xa0a95c
// 00440b4a  c744241800000000     mov dword ptr [esp + 0x18], 0
// 00440b52  c70664a8a000         mov dword ptr [esi], 0xa0a864
// 00440b58  c7462004a8a000       mov dword ptr [esi + 0x20], 0xa0a804
// 00440b5f  c7860c010000f8a7a000 mov dword ptr [esi + 0x10c], 0xa0a7f8
// 00440b69  ff15e8ce9e00         call dword ptr [0x9ecee8]
// 00440b6f  8bce                 mov ecx, esi
// 00440b71  e83a863d00           call 0x8191b0
// 00440b76  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00440b7a  8bc6                 mov eax, esi
// 00440b7c  64890d00000000       mov dword ptr fs:[0], ecx
// 00440b83  5e                   pop esi
// 00440b84  83c410               add esp, 0x10
// 00440b87  c20800               ret 8
// copied from an identical function in another client (function ??0S@ns_ROCX00000e@@QAE@HH@Z)

namespace ns_ROCX00000e {
// from server: 100% by colin
struct String;

struct String
{
    char* data;
    __declspec(dllimport) __forceinline String(const char*);
    String(const String&);
    ~String();
};



extern const char description[];

struct First
{
    virtual ~First();
    char padding[0x1c];
};

struct Second
{
    virtual ~Second();
    char padding[0xe8];
};

struct Third
{
    virtual ~Third();
};

struct Base : First, Second, Third
{
    Base(int, int);
    virtual ~Base();
    void SetDescription(String);
};

struct S : Base
{
    S(int, int);
    virtual ~S();
};

S::S(int a, int b) : Base(a, b)
{
    SetDescription(String(description));
}
}
