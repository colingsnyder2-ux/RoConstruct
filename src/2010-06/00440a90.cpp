// from server: 100% by Yeetserama
// roc 2010-06 00440a90  unit: ScriptItem  size: 122 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00440a90
//
// 00440a90  6aff                 push -1
// 00440a92  68780d9800           push 0x980d78
// 00440a97  64a100000000         mov eax, dword ptr fs:[0]
// 00440a9d  50                   push eax
// 00440a9e  64892500000000       mov dword ptr fs:[0], esp
// 00440aa5  51                   push ecx
// 00440aa6  8b442418             mov eax, dword ptr [esp + 0x18]
// 00440aaa  56                   push esi
// 00440aab  8bf1                 mov esi, ecx
// 00440aad  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00440ab1  50                   push eax
// 00440ab2  51                   push ecx
// 00440ab3  8bce                 mov ecx, esi
// 00440ab5  8974240c             mov dword ptr [esp + 0xc], esi
// 00440ab9  e872d4ffff           call 0x43df30
// 00440abe  51                   push ecx
// 00440abf  8bcc                 mov ecx, esp
// 00440ac1  89642420             mov dword ptr [esp + 0x20], esp
// 00440ac5  68eca7a000           push 0xa0a7ec
// 00440aca  c744241800000000     mov dword ptr [esp + 0x18], 0
// 00440ad2  c706f4a6a000         mov dword ptr [esi], 0xa0a6f4
// 00440ad8  c7462094a6a000       mov dword ptr [esi + 0x20], 0xa0a694
// 00440adf  c7860c01000088a6a000 mov dword ptr [esi + 0x10c], 0xa0a688
// 00440ae9  ff15e8ce9e00         call dword ptr [0x9ecee8]
// 00440aef  8bce                 mov ecx, esi
// 00440af1  e8ba863d00           call 0x8191b0
// 00440af6  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00440afa  8bc6                 mov eax, esi
// 00440afc  64890d00000000       mov dword ptr fs:[0], ecx
// 00440b03  5e                   pop esi
// 00440b04  83c410               add esp, 0x10
// 00440b07  c20800               ret 8
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
