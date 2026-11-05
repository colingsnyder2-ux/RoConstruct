// from server: 100% by auto
// roc 2009-06 00485510  unit: RBX::MeshFileKey  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00485510
//
// 00485510  8b442404             mov eax, dword ptr [esp + 4]
// 00485514  8b542408             mov edx, dword ptr [esp + 8]
// 00485518  3bc2                 cmp eax, edx
// 0048551a  7423                 je 0x48553f
// 0048551c  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00485520  56                   push esi
// 00485521  8b31                 mov esi, dword ptr [ecx]
// 00485523  8930                 mov dword ptr [eax], esi
// 00485525  8b7104               mov esi, dword ptr [ecx + 4]
// 00485528  897004               mov dword ptr [eax + 4], esi
// 0048552b  8b7108               mov esi, dword ptr [ecx + 8]
// 0048552e  897008               mov dword ptr [eax + 8], esi
// 00485531  8b710c               mov esi, dword ptr [ecx + 0xc]
// 00485534  89700c               mov dword ptr [eax + 0xc], esi
// 00485537  83c010               add eax, 0x10
// 0048553a  3bc2                 cmp eax, edx
// 0048553c  75e3                 jne 0x485521
// 0048553e  5e                   pop esi
// 0048553f  c3                   ret 
// standard library vector<pod16> (function ??$_Fill@PAUE@@U1@@std@@YAXPAUE@@0ABU1@@Z)

// stl: vector<pod16>
struct E { int v[4]; };
#include <vector>
template class std::vector<E>;
