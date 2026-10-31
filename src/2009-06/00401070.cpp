// from server: 100% by EspClaude
// roc 2009-06 00401070  unit: CAboutRobloxDialog  size: 80 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00401070
//
// 00401070  6aff                 push -1
// 00401072  6878c98400           push 0x84c978
// 00401077  64a100000000         mov eax, dword ptr fs:[0]
// 0040107d  50                   push eax
// 0040107e  64892500000000       mov dword ptr fs:[0], esp
// 00401085  51                   push ecx
// 00401086  56                   push esi
// 00401087  8bf1                 mov esi, ecx
// 00401089  89742404             mov dword ptr [esp + 4], esi
// 0040108d  8d8e14010000         lea ecx, [esi + 0x114]
// 00401093  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0040109b  ff15c4e48900         call dword ptr [0x89e4c4]
// 004010a1  8bce                 mov ecx, esi
// 004010a3  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 004010ab  e88e793100           call 0x718a3e
// 004010b0  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004010b4  5e                   pop esi
// 004010b5  64890d00000000       mov dword ptr fs:[0], ecx
// 004010bc  83c410               add esp, 0x10
// 004010bf  c3                   ret 
// copied from an identical function in another client (function ??1S@ns_ROCX000003@@QAE@XZ)

namespace ns_ROCX000003 {
struct String;
extern void (__thiscall *string_destroy)(String *);

struct String
{
    char storage[28];
    ~String();
};

inline String::~String()
{
    string_destroy(this);
}

struct Base
{
    char storage[0x114];
    ~Base();
};

struct S : Base
{
    String value;
    ~S();
};

S::~S()
{
}
}
