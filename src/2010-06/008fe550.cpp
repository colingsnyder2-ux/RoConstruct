// from server: 100% by auto
// roc 2010-06 008fe550  unit: Ogre::RbxSceneUpdater::?1??debugCheckFrame::NodeVisiter  size: 90 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008fe550
//
// 008fe550  8b4c2404             mov ecx, dword ptr [esp + 4]
// 008fe554  83ec0c               sub esp, 0xc
// 008fe557  85c9                 test ecx, ecx
// 008fe559  7715                 ja 0x8fe570
// 008fe55b  33c9                 xor ecx, ecx
// 008fe55d  8d1489               lea edx, [ecx + ecx*4]
// 008fe560  c1e204               shl edx, 4
// 008fe563  52                   push edx
// 008fe564  e83794eaff           call 0x7a79a0
// 008fe569  83c404               add esp, 4
// 008fe56c  83c40c               add esp, 0xc
// 008fe56f  c3                   ret 
// 008fe570  83c8ff               or eax, 0xffffffff
// 008fe573  33d2                 xor edx, edx
// 008fe575  f7f1                 div ecx
// 008fe577  83f850               cmp eax, 0x50
// 008fe57a  73e1                 jae 0x8fe55d
// 008fe57c  8d442410             lea eax, [esp + 0x10]
// 008fe580  50                   push eax
// 008fe581  8d4c2404             lea ecx, [esp + 4]
// 008fe585  c744241400000000     mov dword ptr [esp + 0x14], 0
// 008fe58d  ff1524a99e00         call dword ptr [0x9ea924]
// 008fe593  68b41ab000           push 0xb01ab4
// 008fe598  8d4c2404             lea ecx, [esp + 4]
// 008fe59c  51                   push ecx
// 008fe59d  c74424082000a000     mov dword ptr [esp + 8], 0xa00020
// 008fe5a5  e808a4eaff           call 0x7a89b2
// standard library set<pod64> (function ??$_Allocate@U_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@@std@@YAPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@0@IPAU120@@Z)

// stl: set<pod64>
struct E { int v[16]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
