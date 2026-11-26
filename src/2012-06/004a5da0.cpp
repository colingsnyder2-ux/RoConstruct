// from server: 100% by Xemicl
// roc 2012-06 004a5da0  unit: CInstanceExplorer  size: 98 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004a5da0
//
// 004a5da0  6aff                 push -1
// 004a5da2  689340aa00           push 0xaa4093
// 004a5da7  64a100000000         mov eax, dword ptr fs:[0]
// 004a5dad  50                   push eax
// 004a5dae  64892500000000       mov dword ptr fs:[0], esp
// 004a5db5  51                   push ecx
// 004a5db6  56                   push esi
// 004a5db7  8bf1                 mov esi, ecx
// 004a5db9  89742404             mov dword ptr [esp + 4], esi
// 004a5dbd  c706cc1fb600         mov dword ptr [esi], 0xb61fcc
// 004a5dc3  8d8e90010000         lea ecx, [esi + 0x190]
// 004a5dc9  c744241001000000     mov dword ptr [esp + 0x10], 1
// 004a5dd1  e83a3cf9ff           call 0x439a10
// 004a5dd6  8d4e74               lea ecx, [esi + 0x74]
// 004a5dd9  c644241000           mov byte ptr [esp + 0x10], 0
// 004a5dde  e87def5300           call 0x9e4d60
// 004a5de3  8bce                 mov ecx, esi
// 004a5de5  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 004a5ded  e81ccc4d00           call 0x982a0e
// 004a5df2  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004a5df6  5e                   pop esi
// 004a5df7  64890d00000000       mov dword ptr fs:[0], ecx
// 004a5dfe  83c410               add esp, 0x10
// 004a5e01  c3                   ret 
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