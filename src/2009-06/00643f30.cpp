// from server: 100% by auto
// roc 2009-06 00643f30  unit: RBX::Soundscape::SoundChannel  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00643f30
//
// 00643f30  6a38                 push 0x38
// 00643f32  e8014b0d00           call 0x718a38
// 00643f37  83c404               add esp, 4
// 00643f3a  85c0                 test eax, eax
// 00643f3c  7406                 je 0x643f44
// 00643f3e  c70000000000         mov dword ptr [eax], 0
// 00643f44  8d4804               lea ecx, [eax + 4]
// 00643f47  85c9                 test ecx, ecx
// 00643f49  7406                 je 0x643f51
// 00643f4b  c70100000000         mov dword ptr [ecx], 0
// 00643f51  8d4808               lea ecx, [eax + 8]
// 00643f54  85c9                 test ecx, ecx
// 00643f56  7406                 je 0x643f5e
// 00643f58  c70100000000         mov dword ptr [ecx], 0
// 00643f5e  c6403401             mov byte ptr [eax + 0x34], 1
// 00643f62  c6403500             mov byte ptr [eax + 0x35], 0
// 00643f66  c3                   ret 
// standard library set<pod40> (function ?_Buynode@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@XZ)

// stl: set<pod40>
struct E { int v[10]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
