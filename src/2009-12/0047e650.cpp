// from server: 100% by auto
// roc 2009-12 0047e650  unit: Ogre::VResource::?$SharedPtr  size: 83 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0047e650
//
// 0047e650  6aff                 push -1
// 0047e652  68598c9300           push 0x938c59
// 0047e657  64a100000000         mov eax, dword ptr fs:[0]
// 0047e65d  50                   push eax
// 0047e65e  64892500000000       mov dword ptr fs:[0], esp
// 0047e665  51                   push ecx
// 0047e666  56                   push esi
// 0047e667  57                   push edi
// 0047e668  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 0047e66c  8bf1                 mov esi, ecx
// 0047e66e  57                   push edi
// 0047e66f  8974240c             mov dword ptr [esp + 0xc], esi
// 0047e673  ff15f0b69800         call dword ptr [0x98b6f0]
// 0047e679  83c71c               add edi, 0x1c
// 0047e67c  57                   push edi
// 0047e67d  8d4e1c               lea ecx, [esi + 0x1c]
// 0047e680  c744241800000000     mov dword ptr [esp + 0x18], 0
// 0047e688  ff15f4bc9800         call dword ptr [0x98bcf4]
// 0047e68e  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0047e692  5f                   pop edi
// 0047e693  8bc6                 mov eax, esi
// 0047e695  5e                   pop esi
// 0047e696  64890d00000000       mov dword ptr fs:[0], ecx
// 0047e69d  83c410               add esp, 0x10
// 0047e6a0  c20400               ret 4
// standard library map_str<string> (function ??0?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@QAE@ABU01@@Z)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;
