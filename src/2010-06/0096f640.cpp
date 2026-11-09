// from server: 100% by auto
// roc 2010-06 0096f640  unit: seg_00960000  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0096f640
//
// 0096f640  8b442404             mov eax, dword ptr [esp + 4]
// 0096f644  8b542408             mov edx, dword ptr [esp + 8]
// 0096f648  3bc2                 cmp eax, edx
// 0096f64a  741d                 je 0x96f669
// 0096f64c  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0096f650  56                   push esi
// 0096f651  8b31                 mov esi, dword ptr [ecx]
// 0096f653  8930                 mov dword ptr [eax], esi
// 0096f655  8b7104               mov esi, dword ptr [ecx + 4]
// 0096f658  897004               mov dword ptr [eax + 4], esi
// 0096f65b  8b7108               mov esi, dword ptr [ecx + 8]
// 0096f65e  897008               mov dword ptr [eax + 8], esi
// 0096f661  83c00c               add eax, 0xc
// 0096f664  3bc2                 cmp eax, edx
// 0096f666  75e9                 jne 0x96f651
// 0096f668  5e                   pop esi
// 0096f669  c3                   ret 
// standard library vector<pod12> (function ??$_Fill@PAUE@@U1@@std@@YAXPAUE@@0ABU1@@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
