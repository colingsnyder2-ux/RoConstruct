// from server: 100% by Yeetserama
// roc 2007-08 00462dc0  unit: CInstanceExplorer  size: 110 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00462dc0
//
// 00462dc0  6aff                 push -1
// 00462dc2  68332d7400           push 0x742d33
// 00462dc7  64a100000000         mov eax, dword ptr fs:[0]
// 00462dcd  50                   push eax
// 00462dce  51                   push ecx
// 00462dcf  56                   push esi
// 00462dd0  a188518b00           mov eax, dword ptr [0x8b5188]
// 00462dd5  33c4                 xor eax, esp
// 00462dd7  50                   push eax
// 00462dd8  8d44240c             lea eax, [esp + 0xc]
// 00462ddc  64a300000000         mov dword ptr fs:[0], eax
// 00462de2  8bf1                 mov esi, ecx
// 00462de4  89742408             mov dword ptr [esp + 8], esi
// 00462de8  c70654577900         mov dword ptr [esi], 0x795754
// 00462dee  8d8e90010000         lea ecx, [esi + 0x190]
// 00462df4  c744241401000000     mov dword ptr [esp + 0x14], 1
// 00462dfc  e8cfdffcff           call 0x430dd0
// 00462e01  8d4e74               lea ecx, [esi + 0x74]
// 00462e04  c644241400           mov byte ptr [esp + 0x14], 0
// 00462e09  e892d42200           call 0x6902a0
// 00462e0e  8bce                 mov ecx, esi
// 00462e10  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 00462e18  e8f5d51c00           call 0x630412
// 00462e1d  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00462e21  64890d00000000       mov dword ptr fs:[0], ecx
// 00462e28  59                   pop ecx
// 00462e29  5e                   pop esi
// 00462e2a  83c410               add esp, 0x10
// 00462e2d  c3                   ret 
// copied from an identical function in another client (function ??1CSettingsExplorer@ns_ROCX000001@@UAE@XZ)

namespace ns_ROCX000001 {
// from server: 100% by king_originala
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
