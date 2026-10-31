// from server: 100% by EspClaude
// roc 2009-06 00467b30  unit: CSettingsExplorer  size: 98 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00467b30
//
// 00467b30  6aff                 push -1
// 00467b32  68632f8500           push 0x852f63
// 00467b37  64a100000000         mov eax, dword ptr fs:[0]
// 00467b3d  50                   push eax
// 00467b3e  64892500000000       mov dword ptr fs:[0], esp
// 00467b45  51                   push ecx
// 00467b46  56                   push esi
// 00467b47  8bf1                 mov esi, ecx
// 00467b49  89742404             mov dword ptr [esp + 4], esi
// 00467b4d  c70664c88b00         mov dword ptr [esi], 0x8bc864
// 00467b53  8d8e90010000         lea ecx, [esi + 0x190]
// 00467b59  c744241001000000     mov dword ptr [esp + 0x10], 1
// 00467b61  e88a1cfcff           call 0x4297f0
// 00467b66  8d4e74               lea ecx, [esi + 0x74]
// 00467b69  c644241000           mov byte ptr [esp + 0x10], 0
// 00467b6e  e85dac3100           call 0x7827d0
// 00467b73  8bce                 mov ecx, esi
// 00467b75  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 00467b7d  e8e6172b00           call 0x719368
// 00467b82  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00467b86  5e                   pop esi
// 00467b87  64890d00000000       mov dword ptr fs:[0], ecx
// 00467b8e  83c410               add esp, 0x10
// 00467b91  c3                   ret 
// copied from an identical function in another client (function ??1CSettingsExplorer@ns_ROCX000000@@UAE@XZ)

namespace ns_ROCX000000 {
struct Base
{
    virtual ~Base();
    char padding[0x70];
};

struct Splitter
{
    char storage[0x11c];
    ~Splitter();
};

struct Member
{
    ~Member();
};

struct CSettingsExplorer : Base
{
    Splitter splitter;
    Member member;
    virtual ~CSettingsExplorer();
};

CSettingsExplorer::~CSettingsExplorer()
{
}
}
