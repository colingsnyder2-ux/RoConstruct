// from server: 100% by auto
// roc 2009-06 004d8dc0  unit: RBX::Network::GuidRegistryService  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004d8dc0
//
// 004d8dc0  53                   push ebx
// 004d8dc1  56                   push esi
// 004d8dc2  57                   push edi
// 004d8dc3  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 004d8dc7  807f1900             cmp byte ptr [edi + 0x19], 0
// 004d8dcb  8bd9                 mov ebx, ecx
// 004d8dcd  8bf7                 mov esi, edi
// 004d8dcf  751e                 jne 0x4d8def
// 004d8dd1  8b4608               mov eax, dword ptr [esi + 8]
// 004d8dd4  50                   push eax
// 004d8dd5  8bcb                 mov ecx, ebx
// 004d8dd7  e8e4ffffff           call 0x4d8dc0
// 004d8ddc  8b36                 mov esi, dword ptr [esi]
// 004d8dde  57                   push edi
// 004d8ddf  e84efc2300           call 0x718a32
// 004d8de4  83c404               add esp, 4
// 004d8de7  807e1900             cmp byte ptr [esi + 0x19], 0
// 004d8deb  8bfe                 mov edi, esi
// 004d8ded  74e2                 je 0x4d8dd1
// 004d8def  5f                   pop edi
// 004d8df0  5e                   pop esi
// 004d8df1  5b                   pop ebx
// 004d8df2  c20400               ret 4
// standard library set<double> (function ?_Erase@?$_Tree@V?$_Tset_traits@NU?$less@N@std@@V?$allocator@N@2@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@NU?$less@N@std@@V?$allocator@N@2@$0A@@std@@@2@@Z)

// stl: set<double>
typedef double E;
#include <set>
template class std::set<E>;
