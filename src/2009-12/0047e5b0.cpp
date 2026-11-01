// from server: 100% by auto
// roc 2009-12 0047e5b0  unit: Ogre::VResource::?$SharedPtr  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0047e5b0
//
// 0047e5b0  6aff                 push -1
// 0047e5b2  68598c9300           push 0x938c59
// 0047e5b7  64a100000000         mov eax, dword ptr fs:[0]
// 0047e5bd  50                   push eax
// 0047e5be  64892500000000       mov dword ptr fs:[0], esp
// 0047e5c5  51                   push ecx
// 0047e5c6  8b442414             mov eax, dword ptr [esp + 0x14]
// 0047e5ca  56                   push esi
// 0047e5cb  8bf1                 mov esi, ecx
// 0047e5cd  50                   push eax
// 0047e5ce  89742408             mov dword ptr [esp + 8], esi
// 0047e5d2  ff15f0b69800         call dword ptr [0x98b6f0]
// 0047e5d8  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0047e5dc  51                   push ecx
// 0047e5dd  8d4e1c               lea ecx, [esi + 0x1c]
// 0047e5e0  c744241400000000     mov dword ptr [esp + 0x14], 0
// 0047e5e8  ff15f4bc9800         call dword ptr [0x98bcf4]
// 0047e5ee  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0047e5f2  8bc6                 mov eax, esi
// 0047e5f4  5e                   pop esi
// 0047e5f5  64890d00000000       mov dword ptr fs:[0], ecx
// 0047e5fc  83c410               add esp, 0x10
// 0047e5ff  c20800               ret 8
// standard library map_str<string> (function ??0?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@0@Z)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;
