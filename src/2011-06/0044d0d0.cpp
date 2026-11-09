// from server: 100% by Yeetserama
// roc 2011-06 0044d0d0  unit: MVCXTPPropertyGridItem::?$XItem  size: 122 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0044d0d0
//
// 0044d0d0  6aff                 push -1
// 0044d0d2  6828179d00           push 0x9d1728
// 0044d0d7  64a100000000         mov eax, dword ptr fs:[0]
// 0044d0dd  50                   push eax
// 0044d0de  64892500000000       mov dword ptr fs:[0], esp
// 0044d0e5  51                   push ecx
// 0044d0e6  8b442418             mov eax, dword ptr [esp + 0x18]
// 0044d0ea  56                   push esi
// 0044d0eb  8bf1                 mov esi, ecx
// 0044d0ed  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0044d0f1  50                   push eax
// 0044d0f2  51                   push ecx
// 0044d0f3  8bce                 mov ecx, esi
// 0044d0f5  8974240c             mov dword ptr [esp + 0xc], esi
// 0044d0f9  e8b2e4ffff           call 0x44b5b0
// 0044d0fe  51                   push ecx
// 0044d0ff  8bcc                 mov ecx, esp
// 0044d101  89642420             mov dword ptr [esp + 0x20], esp
// 0044d105  6814c4a600           push 0xa6c414
// 0044d10a  c744241800000000     mov dword ptr [esp + 0x18], 0
// 0044d112  c7061cc3a600         mov dword ptr [esi], 0xa6c31c
// 0044d118  c74620bcc2a600       mov dword ptr [esi + 0x20], 0xa6c2bc
// 0044d11f  c7860c010000b0c2a600 mov dword ptr [esi + 0x10c], 0xa6c2b0
// 0044d129  ff15002ea400         call dword ptr [0xa42e00]
// 0044d12f  8bce                 mov ecx, esi
// 0044d131  e89ac84200           call 0x8799d0
// 0044d136  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0044d13a  8bc6                 mov eax, esi
// 0044d13c  64890d00000000       mov dword ptr fs:[0], ecx
// 0044d143  5e                   pop esi
// 0044d144  83c410               add esp, 0x10
// 0044d147  c20800               ret 8
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
