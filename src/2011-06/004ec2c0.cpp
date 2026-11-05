// from server: 100% by auto
// roc 2011-06 004ec2c0  unit: RBX::Network::GuidRegistryService  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 004ec2c0
//
// 004ec2c0  53                   push ebx
// 004ec2c1  56                   push esi
// 004ec2c2  57                   push edi
// 004ec2c3  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 004ec2c7  807f1900             cmp byte ptr [edi + 0x19], 0
// 004ec2cb  8bd9                 mov ebx, ecx
// 004ec2cd  8bf7                 mov esi, edi
// 004ec2cf  751e                 jne 0x4ec2ef
// 004ec2d1  8b4608               mov eax, dword ptr [esi + 8]
// 004ec2d4  50                   push eax
// 004ec2d5  8bcb                 mov ecx, ebx
// 004ec2d7  e8e4ffffff           call 0x4ec2c0
// 004ec2dc  8b36                 mov esi, dword ptr [esi]
// 004ec2de  57                   push edi
// 004ec2df  e874dd3100           call 0x80a058
// 004ec2e4  83c404               add esp, 4
// 004ec2e7  807e1900             cmp byte ptr [esi + 0x19], 0
// 004ec2eb  8bfe                 mov edi, esi
// 004ec2ed  74e2                 je 0x4ec2d1
// 004ec2ef  5f                   pop edi
// 004ec2f0  5e                   pop esi
// 004ec2f1  5b                   pop ebx
// 004ec2f2  c20400               ret 4
// standard library set<double> (function ?_Erase@?$_Tree@V?$_Tset_traits@NU?$less@N@std@@V?$allocator@N@2@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tset_traits@NU?$less@N@std@@V?$allocator@N@2@$0A@@std@@@2@@Z)

// stl: set<double>
typedef double E;
#include <set>
template class std::set<E>;
