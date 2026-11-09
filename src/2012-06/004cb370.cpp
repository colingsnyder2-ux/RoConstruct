// from server: 100% by auto
// roc 2012-06 004cb370  unit: ResourceGroupHelper::UpdateMaterialRenderableVisitor  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004cb370
//
// 004cb370  53                   push ebx
// 004cb371  56                   push esi
// 004cb372  57                   push edi
// 004cb373  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 004cb377  807f3900             cmp byte ptr [edi + 0x39], 0
// 004cb37b  8bd9                 mov ebx, ecx
// 004cb37d  8bf7                 mov esi, edi
// 004cb37f  7527                 jne 0x4cb3a8
// 004cb381  8b4608               mov eax, dword ptr [esi + 8]
// 004cb384  50                   push eax
// 004cb385  8bcb                 mov ecx, ebx
// 004cb387  e8e4ffffff           call 0x4cb370
// 004cb38c  8b36                 mov esi, dword ptr [esi]
// 004cb38e  8d4f10               lea ecx, [edi + 0x10]
// 004cb391  ff153c26b200         call dword ptr [0xb2263c]
// 004cb397  57                   push edi
// 004cb398  e8776d4b00           call 0x982114
// 004cb39d  83c404               add esp, 4
// 004cb3a0  807e3900             cmp byte ptr [esi + 0x39], 0
// 004cb3a4  8bfe                 mov edi, esi
// 004cb3a6  74d9                 je 0x4cb381
// 004cb3a8  5f                   pop edi
// 004cb3a9  5e                   pop esi
// 004cb3aa  5b                   pop ebx
// 004cb3ab  c20400               ret 4
// standard library map_str<double> (function ?_Erase@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@NU?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@N@std@@@2@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@NU?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@N@std@@@2@$0A@@std@@@2@@Z)

// stl: map_str<double>
typedef double E;
#include <map>
#include <string>
template class std::map<std::string, E>;
