// from server: 100% by auto
// roc 2010-06 0061b8f0  unit: RBX::Accoutrement  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0061b8f0
//
// 0061b8f0  53                   push ebx
// 0061b8f1  56                   push esi
// 0061b8f2  57                   push edi
// 0061b8f3  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0061b8f7  807f2d00             cmp byte ptr [edi + 0x2d], 0
// 0061b8fb  8bd9                 mov ebx, ecx
// 0061b8fd  8bf7                 mov esi, edi
// 0061b8ff  7527                 jne 0x61b928
// 0061b901  8b4608               mov eax, dword ptr [esi + 8]
// 0061b904  50                   push eax
// 0061b905  8bcb                 mov ecx, ebx
// 0061b907  e8e4ffffff           call 0x61b8f0
// 0061b90c  8b36                 mov esi, dword ptr [esi]
// 0061b90e  8d4f10               lea ecx, [edi + 0x10]
// 0061b911  ff1500a49e00         call dword ptr [0x9ea400]
// 0061b917  57                   push edi
// 0061b918  e87dc01800           call 0x7a799a
// 0061b91d  83c404               add esp, 4
// 0061b920  807e2d00             cmp byte ptr [esi + 0x2d], 0
// 0061b924  8bfe                 mov edi, esi
// 0061b926  74d9                 je 0x61b901
// 0061b928  5f                   pop edi
// 0061b929  5e                   pop esi
// 0061b92a  5b                   pop ebx
// 0061b92b  c20400               ret 4
// standard library map_int<string> (function ?_Erase@?$_Tree@V?$_Tmap_traits@HV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$0A@@std@@@2@@Z)

// stl: map_int<string>
#include <string>
typedef std::string E;
#include <map>
template class std::map<int, E>;
