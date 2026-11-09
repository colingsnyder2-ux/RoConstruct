// from server: 100% by auto
// roc 2009-06 0048b900  unit: Ogre::RbxManualTextureLoader  size: 87 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0048b900
//
// 0048b900  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0048b904  83ec0c               sub esp, 0xc
// 0048b907  85c9                 test ecx, ecx
// 0048b909  7712                 ja 0x48b91d
// 0048b90b  33c9                 xor ecx, ecx
// 0048b90d  c1e106               shl ecx, 6
// 0048b910  51                   push ecx
// 0048b911  e822d12800           call 0x718a38
// 0048b916  83c404               add esp, 4
// 0048b919  83c40c               add esp, 0xc
// 0048b91c  c3                   ret 
// 0048b91d  83c8ff               or eax, 0xffffffff
// 0048b920  33d2                 xor edx, edx
// 0048b922  f7f1                 div ecx
// 0048b924  83f840               cmp eax, 0x40
// 0048b927  73e4                 jae 0x48b90d
// 0048b929  8d442410             lea eax, [esp + 0x10]
// 0048b92d  50                   push eax
// 0048b92e  8d4c2404             lea ecx, [esp + 4]
// 0048b932  c744241400000000     mov dword ptr [esp + 0x14], 0
// 0048b93a  ff15c4e98900         call dword ptr [0x89e9c4]
// 0048b940  6888919700           push 0x979188
// 0048b945  8d4c2404             lea ecx, [esp + 4]
// 0048b949  51                   push ecx
// 0048b94a  c744240838c98a00     mov dword ptr [esp + 8], 0x8ac938
// 0048b952  e8f3e02800           call 0x719a4a
// standard library vector<pod64> (function ??$_Allocate@UE@@@std@@YAPAUE@@IPAU1@@Z)

// stl: vector<pod64>
struct E { int v[16]; };
#include <vector>
template class std::vector<E>;
