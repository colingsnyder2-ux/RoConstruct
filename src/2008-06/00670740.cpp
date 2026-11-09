// from server: 100% by auto
// roc 2008-06 00670740  unit: Ogre::VRbxFont::?$SharedPtr  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00670740
//
// 00670740  6a30                 push 0x30
// 00670742  e8d9010300           call 0x6a0920
// 00670747  83c404               add esp, 4
// 0067074a  85c0                 test eax, eax
// 0067074c  7406                 je 0x670754
// 0067074e  c70000000000         mov dword ptr [eax], 0
// 00670754  8d4804               lea ecx, [eax + 4]
// 00670757  85c9                 test ecx, ecx
// 00670759  7406                 je 0x670761
// 0067075b  c70100000000         mov dword ptr [ecx], 0
// 00670761  8d4808               lea ecx, [eax + 8]
// 00670764  85c9                 test ecx, ecx
// 00670766  7406                 je 0x67076e
// 00670768  c70100000000         mov dword ptr [ecx], 0
// 0067076e  c6402c01             mov byte ptr [eax + 0x2c], 1
// 00670772  c6402d00             mov byte ptr [eax + 0x2d], 0
// 00670776  c3                   ret 
// standard library set<pod32> (function ?_Buynode@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@XZ)

// stl: set<pod32>
struct E { int v[8]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
