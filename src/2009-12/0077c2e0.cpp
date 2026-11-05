// from server: 100% by auto
// roc 2009-12 0077c2e0  unit: RBX::BallBallContact  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0077c2e0
//
// 0077c2e0  8b442404             mov eax, dword ptr [esp + 4]
// 0077c2e4  8b542408             mov edx, dword ptr [esp + 8]
// 0077c2e8  3bc2                 cmp eax, edx
// 0077c2ea  7417                 je 0x77c303
// 0077c2ec  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0077c2f0  56                   push esi
// 0077c2f1  8b31                 mov esi, dword ptr [ecx]
// 0077c2f3  8930                 mov dword ptr [eax], esi
// 0077c2f5  8b7104               mov esi, dword ptr [ecx + 4]
// 0077c2f8  897004               mov dword ptr [eax + 4], esi
// 0077c2fb  83c008               add eax, 8
// 0077c2fe  3bc2                 cmp eax, edx
// 0077c300  75ef                 jne 0x77c2f1
// 0077c302  5e                   pop esi
// 0077c303  c3                   ret 
// standard library vector<i64> (function ??$_Fill@PA_J_J@std@@YAXPA_J0AB_J@Z)

// stl: vector<i64>
typedef __int64 E;
#include <vector>
template class std::vector<E>;
