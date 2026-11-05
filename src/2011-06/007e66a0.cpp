// from server: 100% by auto
// roc 2011-06 007e66a0  unit: RBX::AdvRotateTool  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 007e66a0
//
// 007e66a0  8b442404             mov eax, dword ptr [esp + 4]
// 007e66a4  8b542408             mov edx, dword ptr [esp + 8]
// 007e66a8  3bc2                 cmp eax, edx
// 007e66aa  7429                 je 0x7e66d5
// 007e66ac  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 007e66b0  56                   push esi
// 007e66b1  8b31                 mov esi, dword ptr [ecx]
// 007e66b3  8930                 mov dword ptr [eax], esi
// 007e66b5  8b7104               mov esi, dword ptr [ecx + 4]
// 007e66b8  897004               mov dword ptr [eax + 4], esi
// 007e66bb  8b7108               mov esi, dword ptr [ecx + 8]
// 007e66be  897008               mov dword ptr [eax + 8], esi
// 007e66c1  8b710c               mov esi, dword ptr [ecx + 0xc]
// 007e66c4  89700c               mov dword ptr [eax + 0xc], esi
// 007e66c7  8b7110               mov esi, dword ptr [ecx + 0x10]
// 007e66ca  897010               mov dword ptr [eax + 0x10], esi
// 007e66cd  83c014               add eax, 0x14
// 007e66d0  3bc2                 cmp eax, edx
// 007e66d2  75dd                 jne 0x7e66b1
// 007e66d4  5e                   pop esi
// 007e66d5  c3                   ret 
// standard library vector<pod20> (function ??$_Fill@PAUE@@U1@@std@@YAXPAUE@@0ABU1@@Z)

// stl: vector<pod20>
struct E { int v[5]; };
#include <vector>
template class std::vector<E>;
