// from server: 100% by auto
// roc 2007-08 0046a710  unit: RBX::LDraw2Lua::LDraw2RobloxMapRoot  size: 87 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0046a710
//
// 0046a710  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0046a714  83ec0c               sub esp, 0xc
// 0046a717  85c9                 test ecx, ecx
// 0046a719  7712                 ja 0x46a72d
// 0046a71b  33c9                 xor ecx, ecx
// 0046a71d  c1e106               shl ecx, 6
// 0046a720  51                   push ecx
// 0046a721  e8d0571c00           call 0x62fef6
// 0046a726  83c404               add esp, 4
// 0046a729  83c40c               add esp, 0xc
// 0046a72c  c3                   ret 
// 0046a72d  83c8ff               or eax, 0xffffffff
// 0046a730  33d2                 xor edx, edx
// 0046a732  f7f1                 div ecx
// 0046a734  83f840               cmp eax, 0x40
// 0046a737  73e4                 jae 0x46a71d
// 0046a739  8d442410             lea eax, [esp + 0x10]
// 0046a73d  50                   push eax
// 0046a73e  8d4c2404             lea ecx, [esp + 4]
// 0046a742  c744241400000000     mov dword ptr [esp + 0x14], 0
// 0046a74a  ff15ece67700         call dword ptr [0x77e6ec]
// 0046a750  687cf18300           push 0x83f17c
// 0046a755  8d4c2404             lea ecx, [esp + 4]
// 0046a759  51                   push ecx
// 0046a75a  c7442408544e7800     mov dword ptr [esp + 8], 0x784e54
// 0046a762  e837641c00           call 0x630b9e
// standard library vector<pod64> (function ??$_Allocate@UE@@@std@@YAPAUE@@IPAU1@@Z)

// stl: vector<pod64>
struct E { int v[16]; };
#include <vector>
template class std::vector<E>;
