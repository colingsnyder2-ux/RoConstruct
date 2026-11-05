// from server: 100% by auto
// roc 2009-06 005cd360  unit: RBX::Network::VPlayer::?$RefPropDescriptor  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005cd360
//
// 005cd360  53                   push ebx
// 005cd361  56                   push esi
// 005cd362  57                   push edi
// 005cd363  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 005cd367  807f2d00             cmp byte ptr [edi + 0x2d], 0
// 005cd36b  8bd9                 mov ebx, ecx
// 005cd36d  8bf7                 mov esi, edi
// 005cd36f  7527                 jne 0x5cd398
// 005cd371  8b4608               mov eax, dword ptr [esi + 8]
// 005cd374  50                   push eax
// 005cd375  8bcb                 mov ecx, ebx
// 005cd377  e8e4ffffff           call 0x5cd360
// 005cd37c  8b36                 mov esi, dword ptr [esi]
// 005cd37e  8d4f0c               lea ecx, [edi + 0xc]
// 005cd381  ff15c4e48900         call dword ptr [0x89e4c4]
// 005cd387  57                   push edi
// 005cd388  e8a5b61400           call 0x718a32
// 005cd38d  83c404               add esp, 4
// 005cd390  807e2d00             cmp byte ptr [esi + 0x2d], 0
// 005cd394  8bfe                 mov edi, esi
// 005cd396  74d9                 je 0x5cd371
// 005cd398  5f                   pop edi
// 005cd399  5e                   pop esi
// 005cd39a  5b                   pop ebx
// 005cd39b  c20400               ret 4
// standard library map_str<ptr> (function ?_Erase@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@std@@@2@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@std@@@2@$0A@@std@@@2@@Z)

// stl: map_str<ptr>
struct T; typedef T* E;
#include <map>
#include <string>
template class std::map<std::string, E>;
