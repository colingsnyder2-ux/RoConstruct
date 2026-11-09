// from server: 100% by auto
// roc 2008-06 006901e0  unit: Ogre::RbxSceneManagerFactory  size: 42 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006901e0
//
// 006901e0  8b442404             mov eax, dword ptr [esp + 4]
// 006901e4  8b542408             mov edx, dword ptr [esp + 8]
// 006901e8  3bc2                 cmp eax, edx
// 006901ea  741d                 je 0x690209
// 006901ec  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 006901f0  56                   push esi
// 006901f1  8b31                 mov esi, dword ptr [ecx]
// 006901f3  8930                 mov dword ptr [eax], esi
// 006901f5  8b7104               mov esi, dword ptr [ecx + 4]
// 006901f8  897004               mov dword ptr [eax + 4], esi
// 006901fb  8b7108               mov esi, dword ptr [ecx + 8]
// 006901fe  897008               mov dword ptr [eax + 8], esi
// 00690201  83c00c               add eax, 0xc
// 00690204  3bc2                 cmp eax, edx
// 00690206  75e9                 jne 0x6901f1
// 00690208  5e                   pop esi
// 00690209  c3                   ret 
// standard library vector<pod12> (function ??$_Fill@PAUE@@U1@@std@@YAXPAUE@@0ABU1@@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
