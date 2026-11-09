// from server: 100% by auto
// roc 2011-06 00737230  unit: RBX::Network::P8Player::?$GetImpl  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00737230
//
// 00737230  6a10                 push 0x10
// 00737232  e8272e0d00           call 0x80a05e
// 00737237  83c404               add esp, 4
// 0073723a  85c0                 test eax, eax
// 0073723c  7406                 je 0x737244
// 0073723e  c70000000000         mov dword ptr [eax], 0
// 00737244  8d4804               lea ecx, [eax + 4]
// 00737247  85c9                 test ecx, ecx
// 00737249  7406                 je 0x737251
// 0073724b  c70100000000         mov dword ptr [ecx], 0
// 00737251  8d4808               lea ecx, [eax + 8]
// 00737254  85c9                 test ecx, ecx
// 00737256  7406                 je 0x73725e
// 00737258  c70100000000         mov dword ptr [ecx], 0
// 0073725e  c6400d01             mov byte ptr [eax + 0xd], 1
// 00737262  c6400e00             mov byte ptr [eax + 0xe], 0
// 00737266  c3                   ret 
// standard library set<char> (function ?_Buynode@?$_Tree@V?$_Tset_traits@DU?$less@D@std@@V?$allocator@D@2@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tset_traits@DU?$less@D@std@@V?$allocator@D@2@$0A@@std@@@2@XZ)

// stl: set<char>
typedef char E;
#include <set>
template class std::set<E>;
