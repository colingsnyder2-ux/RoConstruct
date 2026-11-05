// from server: 100% by auto
// roc 2009-06 00515740  unit: seg_00510000  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00515740
//
// 00515740  6a28                 push 0x28
// 00515742  e8f1322000           call 0x718a38
// 00515747  83c404               add esp, 4
// 0051574a  85c0                 test eax, eax
// 0051574c  7406                 je 0x515754
// 0051574e  c70000000000         mov dword ptr [eax], 0
// 00515754  8d4804               lea ecx, [eax + 4]
// 00515757  85c9                 test ecx, ecx
// 00515759  7406                 je 0x515761
// 0051575b  c70100000000         mov dword ptr [ecx], 0
// 00515761  8d4808               lea ecx, [eax + 8]
// 00515764  85c9                 test ecx, ecx
// 00515766  7406                 je 0x51576e
// 00515768  c70100000000         mov dword ptr [ecx], 0
// 0051576e  c6402401             mov byte ptr [eax + 0x24], 1
// 00515772  c6402500             mov byte ptr [eax + 0x25], 0
// 00515776  c3                   ret 
// standard library set<pod24> (function ?_Buynode@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@XZ)

// stl: set<pod24>
struct E { int v[6]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
