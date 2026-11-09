// from server: 100% by auto
// roc 2007-08 00584700  unit: RBX::VHat::?$FactoryProduct  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00584700
//
// 00584700  53                   push ebx
// 00584701  56                   push esi
// 00584702  57                   push edi
// 00584703  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00584707  807f2d00             cmp byte ptr [edi + 0x2d], 0
// 0058470b  8bd9                 mov ebx, ecx
// 0058470d  8bf7                 mov esi, edi
// 0058470f  7527                 jne 0x584738
// 00584711  8b4608               mov eax, dword ptr [esi + 8]
// 00584714  50                   push eax
// 00584715  8bcb                 mov ecx, ebx
// 00584717  e8e4ffffff           call 0x584700
// 0058471c  8b36                 mov esi, dword ptr [esi]
// 0058471e  8d4f10               lea ecx, [edi + 0x10]
// 00584721  ff15ace67700         call dword ptr [0x77e6ac]
// 00584727  57                   push edi
// 00584728  e835b50a00           call 0x62fc62
// 0058472d  83c404               add esp, 4
// 00584730  807e2d00             cmp byte ptr [esi + 0x2d], 0
// 00584734  8bfe                 mov edi, esi
// 00584736  74d9                 je 0x584711
// 00584738  5f                   pop edi
// 00584739  5e                   pop esi
// 0058473a  5b                   pop ebx
// 0058473b  c20400               ret 4
// standard library map_int<string> (function ?_Erase@?$_Tree@V?$_Tmap_traits@HV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$0A@@std@@@2@@Z)

// stl: map_int<string>
#include <string>
typedef std::string E;
#include <map>
template class std::map<int, E>;
