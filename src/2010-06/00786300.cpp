// from server: 100% by auto
// roc 2010-06 00786300  unit: RBX::HUMAN::GettingUp  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00786300
//
// 00786300  8b442404             mov eax, dword ptr [esp + 4]
// 00786304  8b542408             mov edx, dword ptr [esp + 8]
// 00786308  3bc2                 cmp eax, edx
// 0078630a  7429                 je 0x786335
// 0078630c  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00786310  56                   push esi
// 00786311  8b31                 mov esi, dword ptr [ecx]
// 00786313  8930                 mov dword ptr [eax], esi
// 00786315  8b7104               mov esi, dword ptr [ecx + 4]
// 00786318  897004               mov dword ptr [eax + 4], esi
// 0078631b  8b7108               mov esi, dword ptr [ecx + 8]
// 0078631e  897008               mov dword ptr [eax + 8], esi
// 00786321  8b710c               mov esi, dword ptr [ecx + 0xc]
// 00786324  89700c               mov dword ptr [eax + 0xc], esi
// 00786327  8b7110               mov esi, dword ptr [ecx + 0x10]
// 0078632a  897010               mov dword ptr [eax + 0x10], esi
// 0078632d  83c014               add eax, 0x14
// 00786330  3bc2                 cmp eax, edx
// 00786332  75dd                 jne 0x786311
// 00786334  5e                   pop esi
// 00786335  c3                   ret 
// standard library vector<pod20> (function ??$_Fill@PAUE@@U1@@std@@YAXPAUE@@0ABU1@@Z)

// stl: vector<pod20>
struct E { int v[5]; };
#include <vector>
template class std::vector<E>;
