// from server: 100% by auto
// roc 2009-06 004e8790  unit: RBX::JointsService  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004e8790
//
// 004e8790  6aff                 push -1
// 004e8792  6878ef8600           push 0x86ef78
// 004e8797  64a100000000         mov eax, dword ptr fs:[0]
// 004e879d  50                   push eax
// 004e879e  64892500000000       mov dword ptr fs:[0], esp
// 004e87a5  51                   push ecx
// 004e87a6  56                   push esi
// 004e87a7  8bf1                 mov esi, ecx
// 004e87a9  89742404             mov dword ptr [esp + 4], esi
// 004e87ad  c744241000000000     mov dword ptr [esp + 0x10], 0
// 004e87b5  e86660f3ff           call 0x41e820
// 004e87ba  8b06                 mov eax, dword ptr [esi]
// 004e87bc  50                   push eax
// 004e87bd  e870022300           call 0x718a32
// 004e87c2  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004e87c6  83c404               add esp, 4
// 004e87c9  5e                   pop esi
// 004e87ca  64890d00000000       mov dword ptr fs:[0], ecx
// 004e87d1  83c410               add esp, 0x10
// 004e87d4  c3                   ret 
// standard library vector<string> (function ??1?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE@XZ)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
