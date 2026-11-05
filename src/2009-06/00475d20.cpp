// from server: 100% by auto
// roc 2009-06 00475d20  unit: Ogre::RbxSceneManagerFactory  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00475d20
//
// 00475d20  6aff                 push -1
// 00475d22  68991c8700           push 0x871c99
// 00475d27  64a100000000         mov eax, dword ptr fs:[0]
// 00475d2d  50                   push eax
// 00475d2e  64892500000000       mov dword ptr fs:[0], esp
// 00475d35  51                   push ecx
// 00475d36  8b442414             mov eax, dword ptr [esp + 0x14]
// 00475d3a  56                   push esi
// 00475d3b  8bf1                 mov esi, ecx
// 00475d3d  50                   push eax
// 00475d3e  89742408             mov dword ptr [esp + 8], esi
// 00475d42  ff15b8e48900         call dword ptr [0x89e4b8]
// 00475d48  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00475d4c  51                   push ecx
// 00475d4d  8d4e1c               lea ecx, [esi + 0x1c]
// 00475d50  c744241400000000     mov dword ptr [esp + 0x14], 0
// 00475d58  ff15b8e48900         call dword ptr [0x89e4b8]
// 00475d5e  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00475d62  8bc6                 mov eax, esi
// 00475d64  5e                   pop esi
// 00475d65  64890d00000000       mov dword ptr fs:[0], ecx
// 00475d6c  83c410               add esp, 0x10
// 00475d6f  c20800               ret 8
// standard library map_str<string> (function ??0?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@0@Z)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;
