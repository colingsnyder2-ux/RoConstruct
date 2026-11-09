// from server: 100% by auto
// roc 2011-06 007b5590  unit: RBX::TreeStage  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 007b5590
//
// 007b5590  8b442404             mov eax, dword ptr [esp + 4]
// 007b5594  8b542408             mov edx, dword ptr [esp + 8]
// 007b5598  3bc2                 cmp eax, edx
// 007b559a  7423                 je 0x7b55bf
// 007b559c  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 007b55a0  56                   push esi
// 007b55a1  8b31                 mov esi, dword ptr [ecx]
// 007b55a3  8930                 mov dword ptr [eax], esi
// 007b55a5  8b7104               mov esi, dword ptr [ecx + 4]
// 007b55a8  897004               mov dword ptr [eax + 4], esi
// 007b55ab  8b7108               mov esi, dword ptr [ecx + 8]
// 007b55ae  897008               mov dword ptr [eax + 8], esi
// 007b55b1  8b710c               mov esi, dword ptr [ecx + 0xc]
// 007b55b4  89700c               mov dword ptr [eax + 0xc], esi
// 007b55b7  83c010               add eax, 0x10
// 007b55ba  3bc2                 cmp eax, edx
// 007b55bc  75e3                 jne 0x7b55a1
// 007b55be  5e                   pop esi
// 007b55bf  c3                   ret 
// standard library vector<pod16> (function ??$_Fill@PAUE@@U1@@std@@YAXPAUE@@0ABU1@@Z)

// stl: vector<pod16>
struct E { int v[4]; };
#include <vector>
template class std::vector<E>;
