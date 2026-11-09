// from server: 100% by auto
// roc 2012-06 004a0f10  unit: CScriptDoc  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004a0f10
//
// 004a0f10  53                   push ebx
// 004a0f11  56                   push esi
// 004a0f12  57                   push edi
// 004a0f13  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 004a0f17  807f1500             cmp byte ptr [edi + 0x15], 0
// 004a0f1b  8bd9                 mov ebx, ecx
// 004a0f1d  8bf7                 mov esi, edi
// 004a0f1f  751e                 jne 0x4a0f3f
// 004a0f21  8b4608               mov eax, dword ptr [esi + 8]
// 004a0f24  50                   push eax
// 004a0f25  8bcb                 mov ecx, ebx
// 004a0f27  e8e4ffffff           call 0x4a0f10
// 004a0f2c  8b36                 mov esi, dword ptr [esi]
// 004a0f2e  57                   push edi
// 004a0f2f  e8e0114e00           call 0x982114
// 004a0f34  83c404               add esp, 4
// 004a0f37  807e1500             cmp byte ptr [esi + 0x15], 0
// 004a0f3b  8bfe                 mov edi, esi
// 004a0f3d  74e2                 je 0x4a0f21
// 004a0f3f  5f                   pop edi
// 004a0f40  5e                   pop esi
// 004a0f41  5b                   pop ebx
// 004a0f42  c20400               ret 4
// standard library set<pod8> (function ?_Erase@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@@Z)

// stl: set<pod8>
struct E { int v[2]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
