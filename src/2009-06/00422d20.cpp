// from server: 100% by auto
// roc 2009-06 00422d20  unit: RobloxCrashReporter  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00422d20
//
// 00422d20  8b442404             mov eax, dword ptr [esp + 4]
// 00422d24  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00422d28  3bc1                 cmp eax, ecx
// 00422d2a  740a                 je 0x422d36
// 00422d2c  8b10                 mov edx, dword ptr [eax]
// 00422d2e  56                   push esi
// 00422d2f  8b31                 mov esi, dword ptr [ecx]
// 00422d31  8930                 mov dword ptr [eax], esi
// 00422d33  8911                 mov dword ptr [ecx], edx
// 00422d35  5e                   pop esi
// 00422d36  c3                   ret 
// standard library vector<ptr> (function ??$swap@PAV_Aux_cont@std@@@std@@YAXAAPAV_Aux_cont@0@0@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
