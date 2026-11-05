// from server: 100% by auto
// roc 2009-06 0063f2f0  unit: RBX::Accoutrement  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0063f2f0
//
// 0063f2f0  53                   push ebx
// 0063f2f1  56                   push esi
// 0063f2f2  57                   push edi
// 0063f2f3  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0063f2f7  807f2d00             cmp byte ptr [edi + 0x2d], 0
// 0063f2fb  8bd9                 mov ebx, ecx
// 0063f2fd  8bf7                 mov esi, edi
// 0063f2ff  7527                 jne 0x63f328
// 0063f301  8b4608               mov eax, dword ptr [esi + 8]
// 0063f304  50                   push eax
// 0063f305  8bcb                 mov ecx, ebx
// 0063f307  e8e4ffffff           call 0x63f2f0
// 0063f30c  8b36                 mov esi, dword ptr [esi]
// 0063f30e  8d4f10               lea ecx, [edi + 0x10]
// 0063f311  ff15c4e48900         call dword ptr [0x89e4c4]
// 0063f317  57                   push edi
// 0063f318  e815970d00           call 0x718a32
// 0063f31d  83c404               add esp, 4
// 0063f320  807e2d00             cmp byte ptr [esi + 0x2d], 0
// 0063f324  8bfe                 mov edi, esi
// 0063f326  74d9                 je 0x63f301
// 0063f328  5f                   pop edi
// 0063f329  5e                   pop esi
// 0063f32a  5b                   pop ebx
// 0063f32b  c20400               ret 4
// standard library map_int<string> (function ?_Erase@?$_Tree@V?$_Tmap_traits@HV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$0A@@std@@@2@@Z)

// stl: map_int<string>
#include <string>
typedef std::string E;
#include <map>
template class std::map<int, E>;
