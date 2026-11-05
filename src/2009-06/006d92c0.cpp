// from server: 100% by auto
// roc 2009-06 006d92c0  unit: RBX::SleepStage  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006d92c0
//
// 006d92c0  8b442408             mov eax, dword ptr [esp + 8]
// 006d92c4  8b542404             mov edx, dword ptr [esp + 4]
// 006d92c8  2bc2                 sub eax, edx
// 006d92ca  56                   push esi
// 006d92cb  c1f802               sar eax, 2
// 006d92ce  57                   push edi
// 006d92cf  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 006d92d3  8d0c8500000000       lea ecx, [eax*4]
// 006d92da  8d3439               lea esi, [ecx + edi]
// 006d92dd  85c0                 test eax, eax
// 006d92df  760d                 jbe 0x6d92ee
// 006d92e1  51                   push ecx
// 006d92e2  52                   push edx
// 006d92e3  51                   push ecx
// 006d92e4  57                   push edi
// 006d92e5  ff155ce98900         call dword ptr [0x89e95c]
// 006d92eb  83c410               add esp, 0x10
// 006d92ee  5f                   pop edi
// 006d92ef  8bc6                 mov eax, esi
// 006d92f1  5e                   pop esi
// 006d92f2  c20c00               ret 0xc
// standard library vector<ptr> (function ??$_Ucopy@PAPAUT@@@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@IAEPAPAUT@@PAPAU2@00@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
