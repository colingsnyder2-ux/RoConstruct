// from server: 100% by auto
// roc 2009-12 0047e4e0  unit: RBX::AdornRbxGfx  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0047e4e0
//
// 0047e4e0  6aff                 push -1
// 0047e4e2  68598c9300           push 0x938c59
// 0047e4e7  64a100000000         mov eax, dword ptr fs:[0]
// 0047e4ed  50                   push eax
// 0047e4ee  64892500000000       mov dword ptr fs:[0], esp
// 0047e4f5  51                   push ecx
// 0047e4f6  56                   push esi
// 0047e4f7  8bf1                 mov esi, ecx
// 0047e4f9  89742404             mov dword ptr [esp + 4], esi
// 0047e4fd  8d4e1c               lea ecx, [esi + 0x1c]
// 0047e500  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0047e508  ff15ecbc9800         call dword ptr [0x98bcec]
// 0047e50e  8bce                 mov ecx, esi
// 0047e510  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 0047e518  ff15e4b69800         call dword ptr [0x98b6e4]
// 0047e51e  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0047e522  5e                   pop esi
// 0047e523  64890d00000000       mov dword ptr fs:[0], ecx
// 0047e52a  83c410               add esp, 0x10
// 0047e52d  c3                   ret 
// standard library map_str<string> (function ??1?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@QAE@XZ)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;
