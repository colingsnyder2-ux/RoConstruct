// from server: 100% by auto
// roc 2011-06 00922350  unit: RBX::AdornRbxGfx  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00922350
//
// 00922350  6aff                 push -1
// 00922352  6829e09e00           push 0x9ee029
// 00922357  64a100000000         mov eax, dword ptr fs:[0]
// 0092235d  50                   push eax
// 0092235e  64892500000000       mov dword ptr fs:[0], esp
// 00922365  51                   push ecx
// 00922366  56                   push esi
// 00922367  8bf1                 mov esi, ecx
// 00922369  89742404             mov dword ptr [esp + 4], esi
// 0092236d  8d4e1c               lea ecx, [esi + 0x1c]
// 00922370  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00922378  ff15c817a400         call dword ptr [0xa417c8]
// 0092237e  8bce                 mov ecx, esi
// 00922380  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 00922388  ff15d004a400         call dword ptr [0xa404d0]
// 0092238e  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00922392  5e                   pop esi
// 00922393  64890d00000000       mov dword ptr fs:[0], ecx
// 0092239a  83c410               add esp, 0x10
// 0092239d  c3                   ret 
// standard library map_str<string> (function ??1?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@QAE@XZ)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;
