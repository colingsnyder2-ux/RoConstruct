// from server: 100% by auto
// roc 2011-06 0078ddf0  unit: RBX::UniversalTool  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0078ddf0
//
// 0078ddf0  53                   push ebx
// 0078ddf1  56                   push esi
// 0078ddf2  57                   push edi
// 0078ddf3  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0078ddf7  807f2d00             cmp byte ptr [edi + 0x2d], 0
// 0078ddfb  8bd9                 mov ebx, ecx
// 0078ddfd  8bf7                 mov esi, edi
// 0078ddff  7527                 jne 0x78de28
// 0078de01  8b4608               mov eax, dword ptr [esi + 8]
// 0078de04  50                   push eax
// 0078de05  8bcb                 mov ecx, ebx
// 0078de07  e8e4ffffff           call 0x78ddf0
// 0078de0c  8b36                 mov esi, dword ptr [esi]
// 0078de0e  8d4f0c               lea ecx, [edi + 0xc]
// 0078de11  ff15d004a400         call dword ptr [0xa404d0]
// 0078de17  57                   push edi
// 0078de18  e83bc20700           call 0x80a058
// 0078de1d  83c404               add esp, 4
// 0078de20  807e2d00             cmp byte ptr [esi + 0x2d], 0
// 0078de24  8bfe                 mov edi, esi
// 0078de26  74d9                 je 0x78de01
// 0078de28  5f                   pop edi
// 0078de29  5e                   pop esi
// 0078de2a  5b                   pop ebx
// 0078de2b  c20400               ret 4
// standard library map_str<ptr> (function ?_Erase@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@std@@@2@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@std@@@2@$0A@@std@@@2@@Z)

// stl: map_str<ptr>
struct T; typedef T* E;
#include <map>
#include <string>
template class std::map<std::string, E>;
