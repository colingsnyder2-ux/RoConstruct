// from server: 100% by auto
// roc 2010-06 0058e700  unit: RBX::VTaskSchedulerSettings::?$FactoryProduct  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0058e700
//
// 0058e700  53                   push ebx
// 0058e701  56                   push esi
// 0058e702  57                   push edi
// 0058e703  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0058e707  807f1d00             cmp byte ptr [edi + 0x1d], 0
// 0058e70b  8bd9                 mov ebx, ecx
// 0058e70d  8bf7                 mov esi, edi
// 0058e70f  751e                 jne 0x58e72f
// 0058e711  8b4608               mov eax, dword ptr [esi + 8]
// 0058e714  50                   push eax
// 0058e715  8bcb                 mov ecx, ebx
// 0058e717  e8e4ffffff           call 0x58e700
// 0058e71c  8b36                 mov esi, dword ptr [esi]
// 0058e71e  57                   push edi
// 0058e71f  e876922100           call 0x7a799a
// 0058e724  83c404               add esp, 4
// 0058e727  807e1d00             cmp byte ptr [esi + 0x1d], 0
// 0058e72b  8bfe                 mov edi, esi
// 0058e72d  74e2                 je 0x58e711
// 0058e72f  5f                   pop edi
// 0058e730  5e                   pop esi
// 0058e731  5b                   pop ebx
// 0058e732  c20400               ret 4
// standard library set<pod16> (function ?_Erase@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@@Z)

// stl: set<pod16>
struct E { int v[4]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
