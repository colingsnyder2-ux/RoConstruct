// from server: 100% by auto
// roc 2011-06 0092a6a0  unit: ResourceGroupHelper::UpdateMaterialRenderableVisitor  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0092a6a0
//
// 0092a6a0  53                   push ebx
// 0092a6a1  56                   push esi
// 0092a6a2  57                   push edi
// 0092a6a3  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0092a6a7  807f3900             cmp byte ptr [edi + 0x39], 0
// 0092a6ab  8bd9                 mov ebx, ecx
// 0092a6ad  8bf7                 mov esi, edi
// 0092a6af  7527                 jne 0x92a6d8
// 0092a6b1  8b4608               mov eax, dword ptr [esi + 8]
// 0092a6b4  50                   push eax
// 0092a6b5  8bcb                 mov ecx, ebx
// 0092a6b7  e8e4ffffff           call 0x92a6a0
// 0092a6bc  8b36                 mov esi, dword ptr [esi]
// 0092a6be  8d4f10               lea ecx, [edi + 0x10]
// 0092a6c1  ff15d004a400         call dword ptr [0xa404d0]
// 0092a6c7  57                   push edi
// 0092a6c8  e88bf9edff           call 0x80a058
// 0092a6cd  83c404               add esp, 4
// 0092a6d0  807e3900             cmp byte ptr [esi + 0x39], 0
// 0092a6d4  8bfe                 mov edi, esi
// 0092a6d6  74d9                 je 0x92a6b1
// 0092a6d8  5f                   pop edi
// 0092a6d9  5e                   pop esi
// 0092a6da  5b                   pop ebx
// 0092a6db  c20400               ret 4
// standard library map_str<double> (function ?_Erase@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@NU?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@N@std@@@2@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@NU?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@N@std@@@2@$0A@@std@@@2@@Z)

// stl: map_str<double>
typedef double E;
#include <map>
#include <string>
template class std::map<std::string, E>;
