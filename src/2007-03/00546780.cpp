// from server: 100% by auto
// roc 2007-03 00546780  unit: seg_00540000  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00546780
//
// 00546780  53                   push ebx
// 00546781  56                   push esi
// 00546782  57                   push edi
// 00546783  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00546787  807f2d00             cmp byte ptr [edi + 0x2d], 0
// 0054678b  8bd9                 mov ebx, ecx
// 0054678d  8bf7                 mov esi, edi
// 0054678f  7527                 jne 0x5467b8
// 00546791  8b4608               mov eax, dword ptr [esi + 8]
// 00546794  50                   push eax
// 00546795  8bcb                 mov ecx, ebx
// 00546797  e8e4ffffff           call 0x546780
// 0054679c  8b36                 mov esi, dword ptr [esi]
// 0054679e  8d4f10               lea ecx, [edi + 0x10]
// 005467a1  ff158ce77700         call dword ptr [0x77e78c]
// 005467a7  57                   push edi
// 005467a8  e843790d00           call 0x61e0f0
// 005467ad  83c404               add esp, 4
// 005467b0  807e2d00             cmp byte ptr [esi + 0x2d], 0
// 005467b4  8bfe                 mov edi, esi
// 005467b6  74d9                 je 0x546791
// 005467b8  5f                   pop edi
// 005467b9  5e                   pop esi
// 005467ba  5b                   pop ebx
// 005467bb  c20400               ret 4
// standard library map_int<string> (function ?_Erase@?$_Tree@V?$_Tmap_traits@HV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$0A@@std@@@2@@Z)

// stl: map_int<string>
#include <string>
typedef std::string E;
#include <map>
template class std::map<int, E>;
