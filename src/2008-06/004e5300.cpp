// from server: 100% by EspClaude
// from server: 98% by colin
// roc 2008-06 004e5300  unit: seg_004e0000  size: 89 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004e5300
//
// 004e5300  6aff                 push -1
// 004e5302  68f8a37c00           push 0x7ca3f8
// 004e5307  64a100000000         mov eax, dword ptr fs:[0]
// 004e530d  50                   push eax
// 004e530e  64892500000000       mov dword ptr fs:[0], esp
// 004e5315  83ec08               sub esp, 8
// 004e5318  56                   push esi
// 004e5319  8bf1                 mov esi, ecx
// 004e531b  8d442407             lea eax, [esp + 7]
// 004e531f  50                   push eax
// 004e5320  8d4c240b             lea ecx, [esp + 0xb]
// 004e5324  51                   push ecx
// 004e5325  8bce                 mov ecx, esi
// 004e5327  89742410             mov dword ptr [esp + 0x10], esi
// 004e532b  e8b0c71800           call 0x671ae0
// 004e5330  8d4e20               lea ecx, [esi + 0x20]
// 004e5333  c744241400000000     mov dword ptr [esp + 0x14], 0
// 004e533b  e830dd0700           call 0x563070
// 004e5340  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004e5344  c7462c00000000       mov dword ptr [esi + 0x2c], 0
// 004e534b  8bc6                 mov eax, esi
// 004e534d  5e                   pop esi
// 004e534e  64890d00000000       mov dword ptr fs:[0], ecx
// 004e5355  83c414               add esp, 0x14
// 004e5358  c3                   ret 

#include <set>

struct Member {
    void* data;
    bool enabled;
    int count;

    Member();
};

struct S : std::set<int> {
    Member member;
    int flag;

    S();
};

S::S()
    : member(), flag(0)
{
}
