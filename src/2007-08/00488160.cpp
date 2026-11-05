// from server: 100% by auto
// roc 2007-08 00488160  unit: P8CRenderSettings::?$GetSetImpl  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00488160
//
// 00488160  6a10                 push 0x10
// 00488162  e88f7d1a00           call 0x62fef6
// 00488167  83c404               add esp, 4
// 0048816a  85c0                 test eax, eax
// 0048816c  7406                 je 0x488174
// 0048816e  c70000000000         mov dword ptr [eax], 0
// 00488174  8d4804               lea ecx, [eax + 4]
// 00488177  85c9                 test ecx, ecx
// 00488179  7406                 je 0x488181
// 0048817b  c70100000000         mov dword ptr [ecx], 0
// 00488181  8d4808               lea ecx, [eax + 8]
// 00488184  85c9                 test ecx, ecx
// 00488186  7406                 je 0x48818e
// 00488188  c70100000000         mov dword ptr [ecx], 0
// 0048818e  c6400d01             mov byte ptr [eax + 0xd], 1
// 00488192  c6400e00             mov byte ptr [eax + 0xe], 0
// 00488196  c3                   ret 
// standard library set<char> (function ?_Buynode@?$_Tree@V?$_Tset_traits@DU?$less@D@std@@V?$allocator@D@2@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tset_traits@DU?$less@D@std@@V?$allocator@D@2@$0A@@std@@@2@XZ)

// stl: set<char>
typedef char E;
#include <set>
template class std::set<E>;
