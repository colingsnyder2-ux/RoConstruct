// from server: 100% by auto
// roc 2008-06 00432a30  unit: RBX::VHat::?$FactoryProduct::Creator  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00432a30
//
// 00432a30  53                   push ebx
// 00432a31  56                   push esi
// 00432a32  57                   push edi
// 00432a33  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00432a37  807f1500             cmp byte ptr [edi + 0x15], 0
// 00432a3b  8bd9                 mov ebx, ecx
// 00432a3d  8bf7                 mov esi, edi
// 00432a3f  751e                 jne 0x432a5f
// 00432a41  8b4608               mov eax, dword ptr [esi + 8]
// 00432a44  50                   push eax
// 00432a45  8bcb                 mov ecx, ebx
// 00432a47  e8e4ffffff           call 0x432a30
// 00432a4c  8b36                 mov esi, dword ptr [esi]
// 00432a4e  57                   push edi
// 00432a4f  e826dc2600           call 0x6a067a
// 00432a54  83c404               add esp, 4
// 00432a57  807e1500             cmp byte ptr [esi + 0x15], 0
// 00432a5b  8bfe                 mov edi, esi
// 00432a5d  74e2                 je 0x432a41
// 00432a5f  5f                   pop edi
// 00432a60  5e                   pop esi
// 00432a61  5b                   pop ebx
// 00432a62  c20400               ret 4
// standard library set<pod8> (function ?_Erase@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@@Z)

// stl: set<pod8>
struct E { int v[2]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
