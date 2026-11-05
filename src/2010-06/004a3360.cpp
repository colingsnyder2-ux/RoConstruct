// from server: 100% by auto
// roc 2010-06 004a3360  unit: RBX::Network::Player  size: 78 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004a3360
//
// 004a3360  6aff                 push -1
// 004a3362  68d8099a00           push 0x9a09d8
// 004a3367  64a100000000         mov eax, dword ptr fs:[0]
// 004a336d  50                   push eax
// 004a336e  64892500000000       mov dword ptr fs:[0], esp
// 004a3375  51                   push ecx
// 004a3376  56                   push esi
// 004a3377  8bf1                 mov esi, ecx
// 004a3379  89742404             mov dword ptr [esp + 4], esi
// 004a337d  8d4e1c               lea ecx, [esi + 0x1c]
// 004a3380  c744241000000000     mov dword ptr [esp + 0x10], 0
// 004a3388  ff1500a49e00         call dword ptr [0x9ea400]
// 004a338e  8bce                 mov ecx, esi
// 004a3390  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 004a3398  ff1500a49e00         call dword ptr [0x9ea400]
// 004a339e  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004a33a2  5e                   pop esi
// 004a33a3  64890d00000000       mov dword ptr fs:[0], ecx
// 004a33aa  83c410               add esp, 0x10
// 004a33ad  c3                   ret 
// standard library map_str<string> (function ??1?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@QAE@XZ)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;
