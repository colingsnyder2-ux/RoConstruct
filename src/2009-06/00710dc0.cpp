// from server: 100% by auto
// roc 2009-06 00710dc0  unit: boost::iostreams::zlib_error  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00710dc0
//
// 00710dc0  53                   push ebx
// 00710dc1  56                   push esi
// 00710dc2  57                   push edi
// 00710dc3  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00710dc7  807f1500             cmp byte ptr [edi + 0x15], 0
// 00710dcb  8bd9                 mov ebx, ecx
// 00710dcd  8bf7                 mov esi, edi
// 00710dcf  751e                 jne 0x710def
// 00710dd1  8b4608               mov eax, dword ptr [esi + 8]
// 00710dd4  50                   push eax
// 00710dd5  8bcb                 mov ecx, ebx
// 00710dd7  e8e4ffffff           call 0x710dc0
// 00710ddc  8b36                 mov esi, dword ptr [esi]
// 00710dde  57                   push edi
// 00710ddf  e84e7c0000           call 0x718a32
// 00710de4  83c404               add esp, 4
// 00710de7  807e1500             cmp byte ptr [esi + 0x15], 0
// 00710deb  8bfe                 mov edi, esi
// 00710ded  74e2                 je 0x710dd1
// 00710def  5f                   pop edi
// 00710df0  5e                   pop esi
// 00710df1  5b                   pop ebx
// 00710df2  c20400               ret 4
// standard library set<pod8> (function ?_Erase@?$_Tree@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@UE@@U?$less@UE@@@std@@V?$allocator@UE@@@3@$0A@@std@@@2@@Z)

// stl: set<pod8>
struct E { int v[2]; };
#include <set>
bool operator<(const E&, const E&);
template class std::set<E>;
