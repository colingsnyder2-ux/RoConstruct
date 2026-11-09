// from server: 100% by auto
// roc 2009-12 006ada00  unit: RBX::Accoutrement  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006ada00
//
// 006ada00  53                   push ebx
// 006ada01  56                   push esi
// 006ada02  57                   push edi
// 006ada03  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 006ada07  807f2d00             cmp byte ptr [edi + 0x2d], 0
// 006ada0b  8bd9                 mov ebx, ecx
// 006ada0d  8bf7                 mov esi, edi
// 006ada0f  7527                 jne 0x6ada38
// 006ada11  8b4608               mov eax, dword ptr [esi + 8]
// 006ada14  50                   push eax
// 006ada15  8bcb                 mov ecx, ebx
// 006ada17  e8e4ffffff           call 0x6ada00
// 006ada1c  8b36                 mov esi, dword ptr [esi]
// 006ada1e  8d4f10               lea ecx, [edi + 0x10]
// 006ada21  ff15e4b69800         call dword ptr [0x98b6e4]
// 006ada27  57                   push edi
// 006ada28  e82d5e1400           call 0x7f385a
// 006ada2d  83c404               add esp, 4
// 006ada30  807e2d00             cmp byte ptr [esi + 0x2d], 0
// 006ada34  8bfe                 mov edi, esi
// 006ada36  74d9                 je 0x6ada11
// 006ada38  5f                   pop edi
// 006ada39  5e                   pop esi
// 006ada3a  5b                   pop ebx
// 006ada3b  c20400               ret 4
// standard library map_int<string> (function ?_Erase@?$_Tree@V?$_Tmap_traits@HV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$0A@@std@@@2@@Z)

// stl: map_int<string>
#include <string>
typedef std::string E;
#include <map>
template class std::map<int, E>;
