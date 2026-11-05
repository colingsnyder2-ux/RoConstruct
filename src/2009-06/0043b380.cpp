// from server: 100% by EspClaude
// roc 2009-06 0043b380  unit: MVCXTPPropertyGridItem::?$XItem  size: 122 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0043b380
//
// 0043b380  6aff                 push -1
// 0043b382  68a8fc8400           push 0x84fca8
// 0043b387  64a100000000         mov eax, dword ptr fs:[0]
// 0043b38d  50                   push eax
// 0043b38e  64892500000000       mov dword ptr fs:[0], esp
// 0043b395  51                   push ecx
// 0043b396  8b442418             mov eax, dword ptr [esp + 0x18]
// 0043b39a  56                   push esi
// 0043b39b  8bf1                 mov esi, ecx
// 0043b39d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0043b3a1  50                   push eax
// 0043b3a2  51                   push ecx
// 0043b3a3  8bce                 mov ecx, esi
// 0043b3a5  8974240c             mov dword ptr [esp + 0xc], esi
// 0043b3a9  e8f2daffff           call 0x438ea0
// 0043b3ae  51                   push ecx
// 0043b3af  8bcc                 mov ecx, esp
// 0043b3b1  89642420             mov dword ptr [esp + 0x20], esp
// 0043b3b5  68545a8b00           push 0x8b5a54
// 0043b3ba  c744241800000000     mov dword ptr [esp + 0x18], 0
// 0043b3c2  c7065c598b00         mov dword ptr [esi], 0x8b595c
// 0043b3c8  c74620fc588b00       mov dword ptr [esi + 0x20], 0x8b58fc
// 0043b3cf  c7860c010000f0588b00 mov dword ptr [esi + 0x10c], 0x8b58f0
// 0043b3d9  ff1508fd8900         call dword ptr [0x89fd08]
// 0043b3df  8bce                 mov ecx, esi
// 0043b3e1  e8faed3400           call 0x78a1e0
// 0043b3e6  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0043b3ea  8bc6                 mov eax, esi
// 0043b3ec  64890d00000000       mov dword ptr fs:[0], ecx
// 0043b3f3  5e                   pop esi
// 0043b3f4  83c410               add esp, 0x10
// 0043b3f7  c20800               ret 8
// copied from an identical function in another client (function ??0S@ns_ROCX000015@@QAE@HH@Z)

namespace ns_ROCX000015 {
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
