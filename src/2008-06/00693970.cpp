// from server: 100% by auto
// roc 2008-06 00693970  unit: Ogre::RbxSceneManager  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00693970
//
// 00693970  53                   push ebx
// 00693971  56                   push esi
// 00693972  57                   push edi
// 00693973  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00693977  807f2d00             cmp byte ptr [edi + 0x2d], 0
// 0069397b  8bd9                 mov ebx, ecx
// 0069397d  8bf7                 mov esi, edi
// 0069397f  7527                 jne 0x6939a8
// 00693981  8b4608               mov eax, dword ptr [esi + 8]
// 00693984  50                   push eax
// 00693985  8bcb                 mov ecx, ebx
// 00693987  e8e4ffffff           call 0x693970
// 0069398c  8b36                 mov esi, dword ptr [esi]
// 0069398e  8d4f0c               lea ecx, [edi + 0xc]
// 00693991  ff1568248000         call dword ptr [0x802468]
// 00693997  57                   push edi
// 00693998  e8ddcc0000           call 0x6a067a
// 0069399d  83c404               add esp, 4
// 006939a0  807e2d00             cmp byte ptr [esi + 0x2d], 0
// 006939a4  8bfe                 mov edi, esi
// 006939a6  74d9                 je 0x693981
// 006939a8  5f                   pop edi
// 006939a9  5e                   pop esi
// 006939aa  5b                   pop ebx
// 006939ab  c20400               ret 4
// standard library map_str<ptr> (function ?_Erase@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@std@@@2@$0A@@std@@@std@@IAEXPAU_Node@?$_Tree_nod@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@std@@@2@$0A@@std@@@2@@Z)

// stl: map_str<ptr>
struct T; typedef T* E;
#include <map>
#include <string>
template class std::map<std::string, E>;
