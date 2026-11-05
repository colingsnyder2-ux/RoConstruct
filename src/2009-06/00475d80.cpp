// from server: 100% by auto
// roc 2009-06 00475d80  unit: Ogre::RbxSceneManagerFactory  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00475d80
//
// 00475d80  6aff                 push -1
// 00475d82  68991c8700           push 0x871c99
// 00475d87  64a100000000         mov eax, dword ptr fs:[0]
// 00475d8d  50                   push eax
// 00475d8e  64892500000000       mov dword ptr fs:[0], esp
// 00475d95  51                   push ecx
// 00475d96  56                   push esi
// 00475d97  57                   push edi
// 00475d98  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 00475d9c  8bf1                 mov esi, ecx
// 00475d9e  57                   push edi
// 00475d9f  8974240c             mov dword ptr [esp + 0xc], esi
// 00475da3  ff15b8e48900         call dword ptr [0x89e4b8]
// 00475da9  83c71c               add edi, 0x1c
// 00475dac  57                   push edi
// 00475dad  8d4e1c               lea ecx, [esi + 0x1c]
// 00475db0  c744241800000000     mov dword ptr [esp + 0x18], 0
// 00475db8  ff15b8e48900         call dword ptr [0x89e4b8]
// 00475dbe  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00475dc2  5f                   pop edi
// 00475dc3  8bc6                 mov eax, esi
// 00475dc5  5e                   pop esi
// 00475dc6  64890d00000000       mov dword ptr fs:[0], ecx
// 00475dcd  83c410               add esp, 0x10
// 00475dd0  c20400               ret 4
// standard library map_str<string> (function ??0?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@QAE@ABU01@@Z)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;
