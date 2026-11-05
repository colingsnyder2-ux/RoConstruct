// roc 2009-12 004ae230  unit: Ogre::RbxManualTextureLoader  size: 87 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004ae230
//
// 004ae230  8b4c2404             mov ecx, dword ptr [esp + 4]
// 004ae234  83ec0c               sub esp, 0xc
// 004ae237  85c9                 test ecx, ecx
// 004ae239  7712                 ja 0x4ae24d
// 004ae23b  33c9                 xor ecx, ecx
// 004ae23d  c1e106               shl ecx, 6
// 004ae240  51                   push ecx
// 004ae241  e81a563400           call 0x7f3860
// 004ae246  83c404               add esp, 4
// 004ae249  83c40c               add esp, 0xc
// 004ae24c  c3                   ret 
// 004ae24d  83c8ff               or eax, 0xffffffff
// 004ae250  33d2                 xor edx, edx
// 004ae252  f7f1                 div ecx
// 004ae254  83f840               cmp eax, 0x40
// 004ae257  73e4                 jae 0x4ae23d
// 004ae259  8d442410             lea eax, [esp + 0x10]
// 004ae25d  50                   push eax
// 004ae25e  8d4c2404             lea ecx, [esp + 4]
// 004ae262  c744241400000000     mov dword ptr [esp + 0x14], 0
// 004ae26a  ff1548b79800         call dword ptr [0x98b748]
// 004ae270  6838efa800           push 0xa8ef38
// 004ae275  8d4c2404             lea ecx, [esp + 4]
// 004ae279  51                   push ecx
// 004ae27a  c744240878f49900     mov dword ptr [esp + 8], 0x99f478
// 004ae282  e8f1653400           call 0x7f4878
// standard library vector<pod64> (function ??$_Allocate@UE@@@std@@YAPAUE@@IPAU1@@Z)

// stl: vector<pod64>
struct E { int v[16]; };
#include <vector>
template class std::vector<E>;
