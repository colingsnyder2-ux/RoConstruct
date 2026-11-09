// from server: 100% by auto
// roc 2008-06 005b3860  unit: RBX::VHat::?$FactoryProduct  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005b3860
//
// 005b3860  53                   push ebx
// 005b3861  56                   push esi
// 005b3862  57                   push edi
// 005b3863  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 005b3867  807f2d00             cmp byte ptr [edi + 0x2d], 0
// 005b386b  8bd9                 mov ebx, ecx
// 005b386d  8bf7                 mov esi, edi
// 005b386f  7527                 jne 0x5b3898
// 005b3871  8b4608               mov eax, dword ptr [esi + 8]
// 005b3874  50                   push eax
// 005b3875  8bcb                 mov ecx, ebx
// 005b3877  e8e4ffffff           call 0x5b3860
// 005b387c  8b36                 mov esi, dword ptr [esi]
// 005b387e  8d4f10               lea ecx, [edi + 0x10]
// 005b3881  ff1568248000         call dword ptr [0x802468]
// 005b3887  57                   push edi
// 005b3888  e8edcd0e00           call 0x6a067a
// 005b388d  83c404               add esp, 4
// 005b3890  807e2d00             cmp byte ptr [esi + 0x2d], 0
// 005b3894  8bfe                 mov edi, esi
// 005b3896  74d9                 je 0x5b3871
// 005b3898  5f                   pop edi
// 005b3899  5e                   pop esi
// 005b389a  5b                   pop ebx
// 005b389b  c20400               ret 4
// standard library map_int<string> (function ?_Erase@?$_Tree@V?$_Tmap_traits@HV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tmap_traits@HV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@@2@$0A@@std@@@2@@Z)

// stl: map_int<string>
#include <string>
typedef std::string E;
#include <map>
template class std::map<int, E>;
