// from server: 100% by auto
// roc 2012-06 0091a490  unit: RBX::Assembly  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0091a490
//
// 0091a490  8b442404             mov eax, dword ptr [esp + 4]
// 0091a494  8b542408             mov edx, dword ptr [esp + 8]
// 0091a498  3bc2                 cmp eax, edx
// 0091a49a  7419                 je 0x91a4b5
// 0091a49c  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0091a4a0  56                   push esi
// 0091a4a1  8b31                 mov esi, dword ptr [ecx]
// 0091a4a3  8930                 mov dword ptr [eax], esi
// 0091a4a5  668b7104             mov si, word ptr [ecx + 4]
// 0091a4a9  66897004             mov word ptr [eax + 4], si
// 0091a4ad  83c006               add eax, 6
// 0091a4b0  3bc2                 cmp eax, edx
// 0091a4b2  75ed                 jne 0x91a4a1
// 0091a4b4  5e                   pop esi
// 0091a4b5  c3                   ret 
// standard library vector<podc6> (function ??$_Fill@PAUE@@U1@@std@@YAXPAUE@@0ABU1@@Z)

// stl: vector<podc6>
struct E { char v[6]; };
#include <vector>
template class std::vector<E>;
