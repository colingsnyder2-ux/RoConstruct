// from server: 100% by auto
// roc 2009-06 0048b8a0  unit: Ogre::RbxManualTextureLoader  size: 90 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0048b8a0
//
// 0048b8a0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0048b8a4  83ec0c               sub esp, 0xc
// 0048b8a7  85c9                 test ecx, ecx
// 0048b8a9  7715                 ja 0x48b8c0
// 0048b8ab  33c9                 xor ecx, ecx
// 0048b8ad  8d1489               lea edx, [ecx + ecx*4]
// 0048b8b0  c1e204               shl edx, 4
// 0048b8b3  52                   push edx
// 0048b8b4  e87fd12800           call 0x718a38
// 0048b8b9  83c404               add esp, 4
// 0048b8bc  83c40c               add esp, 0xc
// 0048b8bf  c3                   ret 
// 0048b8c0  83c8ff               or eax, 0xffffffff
// 0048b8c3  33d2                 xor edx, edx
// 0048b8c5  f7f1                 div ecx
// 0048b8c7  83f850               cmp eax, 0x50
// 0048b8ca  73e1                 jae 0x48b8ad
// 0048b8cc  8d442410             lea eax, [esp + 0x10]
// 0048b8d0  50                   push eax
// 0048b8d1  8d4c2404             lea ecx, [esp + 4]
// 0048b8d5  c744241400000000     mov dword ptr [esp + 0x14], 0
// 0048b8dd  ff15c4e98900         call dword ptr [0x89e9c4]
// 0048b8e3  6888919700           push 0x979188
// 0048b8e8  8d4c2404             lea ecx, [esp + 4]
// 0048b8ec  51                   push ecx
// 0048b8ed  c744240838c98a00     mov dword ptr [esp + 8], 0x8ac938
// 0048b8f5  e850e12800           call 0x719a4a
// standard library set<pod64> (function ??$_Allocate@U_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@@std@@YAPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@0@IPAU120@@Z)

// stl: set<pod64>
struct E { int v[16]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
