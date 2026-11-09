// from server: 100% by EspClaude
// roc 2009-06 0043b400  unit: MVCXTPPropertyGridItem::?$XItem  size: 122 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0043b400
//
// 0043b400  6aff                 push -1
// 0043b402  68a8fc8400           push 0x84fca8
// 0043b407  64a100000000         mov eax, dword ptr fs:[0]
// 0043b40d  50                   push eax
// 0043b40e  64892500000000       mov dword ptr fs:[0], esp
// 0043b415  51                   push ecx
// 0043b416  8b442418             mov eax, dword ptr [esp + 0x18]
// 0043b41a  56                   push esi
// 0043b41b  8bf1                 mov esi, ecx
// 0043b41d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0043b421  50                   push eax
// 0043b422  51                   push ecx
// 0043b423  8bce                 mov ecx, esi
// 0043b425  8974240c             mov dword ptr [esp + 0xc], esi
// 0043b429  e872dbffff           call 0x438fa0
// 0043b42e  51                   push ecx
// 0043b42f  8bcc                 mov ecx, esp
// 0043b431  89642420             mov dword ptr [esp + 0x20], esp
// 0043b435  68c45b8b00           push 0x8b5bc4
// 0043b43a  c744241800000000     mov dword ptr [esp + 0x18], 0
// 0043b442  c706cc5a8b00         mov dword ptr [esi], 0x8b5acc
// 0043b448  c746206c5a8b00       mov dword ptr [esi + 0x20], 0x8b5a6c
// 0043b44f  c7860c010000605a8b00 mov dword ptr [esi + 0x10c], 0x8b5a60
// 0043b459  ff1508fd8900         call dword ptr [0x89fd08]
// 0043b45f  8bce                 mov ecx, esi
// 0043b461  e87aed3400           call 0x78a1e0
// 0043b466  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0043b46a  8bc6                 mov eax, esi
// 0043b46c  64890d00000000       mov dword ptr fs:[0], ecx
// 0043b473  5e                   pop esi
// 0043b474  83c410               add esp, 0x10
// 0043b477  c20800               ret 8
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
