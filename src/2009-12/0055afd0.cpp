// from server: 100% by auto
// roc 2009-12 0055afd0  unit: RBX::Network::ServerReplicator  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0055afd0
//
// 0055afd0  53                   push ebx
// 0055afd1  56                   push esi
// 0055afd2  57                   push edi
// 0055afd3  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0055afd7  807f2500             cmp byte ptr [edi + 0x25], 0
// 0055afdb  8bd9                 mov ebx, ecx
// 0055afdd  8bf7                 mov esi, edi
// 0055afdf  751e                 jne 0x55afff
// 0055afe1  8b4608               mov eax, dword ptr [esi + 8]
// 0055afe4  50                   push eax
// 0055afe5  8bcb                 mov ecx, ebx
// 0055afe7  e8e4ffffff           call 0x55afd0
// 0055afec  8b36                 mov esi, dword ptr [esi]
// 0055afee  57                   push edi
// 0055afef  e866882900           call 0x7f385a
// 0055aff4  83c404               add esp, 4
// 0055aff7  807e2500             cmp byte ptr [esi + 0x25], 0
// 0055affb  8bfe                 mov edi, esi
// 0055affd  74e2                 je 0x55afe1
// 0055afff  5f                   pop edi
// 0055b000  5e                   pop esi
// 0055b001  5b                   pop ebx
// 0055b002  c20400               ret 4
// standard library set<pod24> (function ?_Erase@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@@Z)

// stl: set<pod24>
struct E { int v[6]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
