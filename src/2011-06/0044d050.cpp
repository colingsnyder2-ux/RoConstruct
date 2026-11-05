// from server: 100% by Yeetserama
// roc 2011-06 0044d050  unit: MVCXTPPropertyGridItem::?$XItem  size: 122 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0044d050
//
// 0044d050  6aff                 push -1
// 0044d052  6828179d00           push 0x9d1728
// 0044d057  64a100000000         mov eax, dword ptr fs:[0]
// 0044d05d  50                   push eax
// 0044d05e  64892500000000       mov dword ptr fs:[0], esp
// 0044d065  51                   push ecx
// 0044d066  8b442418             mov eax, dword ptr [esp + 0x18]
// 0044d06a  56                   push esi
// 0044d06b  8bf1                 mov esi, ecx
// 0044d06d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0044d071  50                   push eax
// 0044d072  51                   push ecx
// 0044d073  8bce                 mov ecx, esi
// 0044d075  8974240c             mov dword ptr [esp + 0xc], esi
// 0044d079  e832e4ffff           call 0x44b4b0
// 0044d07e  51                   push ecx
// 0044d07f  8bcc                 mov ecx, esp
// 0044d081  89642420             mov dword ptr [esp + 0x20], esp
// 0044d085  68a4c2a600           push 0xa6c2a4
// 0044d08a  c744241800000000     mov dword ptr [esp + 0x18], 0
// 0044d092  c706acc1a600         mov dword ptr [esi], 0xa6c1ac
// 0044d098  c746204cc1a600       mov dword ptr [esi + 0x20], 0xa6c14c
// 0044d09f  c7860c01000040c1a600 mov dword ptr [esi + 0x10c], 0xa6c140
// 0044d0a9  ff15002ea400         call dword ptr [0xa42e00]
// 0044d0af  8bce                 mov ecx, esi
// 0044d0b1  e81ac94200           call 0x8799d0
// 0044d0b6  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0044d0ba  8bc6                 mov eax, esi
// 0044d0bc  64890d00000000       mov dword ptr fs:[0], ecx
// 0044d0c3  5e                   pop esi
// 0044d0c4  83c410               add esp, 0x10
// 0044d0c7  c20800               ret 8
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
