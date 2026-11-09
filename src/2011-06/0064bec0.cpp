// from server: 100% by auto
// roc 2011-06 0064bec0  unit: RBX::GameBasicSettings  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0064bec0
//
// 0064bec0  53                   push ebx
// 0064bec1  56                   push esi
// 0064bec2  57                   push edi
// 0064bec3  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0064bec7  807f2100             cmp byte ptr [edi + 0x21], 0
// 0064becb  8bd9                 mov ebx, ecx
// 0064becd  8bf7                 mov esi, edi
// 0064becf  751e                 jne 0x64beef
// 0064bed1  8b4608               mov eax, dword ptr [esi + 8]
// 0064bed4  50                   push eax
// 0064bed5  8bcb                 mov ecx, ebx
// 0064bed7  e8e4ffffff           call 0x64bec0
// 0064bedc  8b36                 mov esi, dword ptr [esi]
// 0064bede  57                   push edi
// 0064bedf  e874e11b00           call 0x80a058
// 0064bee4  83c404               add esp, 4
// 0064bee7  807e2100             cmp byte ptr [esi + 0x21], 0
// 0064beeb  8bfe                 mov edi, esi
// 0064beed  74e2                 je 0x64bed1
// 0064beef  5f                   pop edi
// 0064bef0  5e                   pop esi
// 0064bef1  5b                   pop ebx
// 0064bef2  c20400               ret 4
// standard library set<pod20> (function ?_Erase@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@@Z)

// stl: set<pod20>
struct E { int v[5]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
