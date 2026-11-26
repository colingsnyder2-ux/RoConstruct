// from server: 100% by Xemicl
// roc 2012-06 00401050  unit: CAboutRobloxDialog  size: 80 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00401050
//
// 00401050  6aff                 push -1
// 00401052  68c89ea900           push 0xa99ec8
// 00401057  64a100000000         mov eax, dword ptr fs:[0]
// 0040105d  50                   push eax
// 0040105e  64892500000000       mov dword ptr fs:[0], esp
// 00401065  51                   push ecx
// 00401066  56                   push esi
// 00401067  8bf1                 mov esi, ecx
// 00401069  89742404             mov dword ptr [esp + 4], esi
// 0040106d  8d8e14010000         lea ecx, [esi + 0x114]
// 00401073  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0040107b  ff153c26b200         call dword ptr [0xb2263c]
// 00401081  8bce                 mov ecx, esi
// 00401083  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 0040108b  e890105800           call 0x982120
// 00401090  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00401094  5e                   pop esi
// 00401095  64890d00000000       mov dword ptr fs:[0], ecx
// 0040109c  83c410               add esp, 0x10
// 0040109f  c3                   ret 
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