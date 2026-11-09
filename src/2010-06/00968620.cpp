// from server: 100% by auto
// roc 2010-06 00968620  unit: Ogre::RbxSceneUpdater  size: 60 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00968620
//
// 00968620  8b442404             mov eax, dword ptr [esp + 4]
// 00968624  8b542408             mov edx, dword ptr [esp + 8]
// 00968628  3bc2                 cmp eax, edx
// 0096862a  742f                 je 0x96865b
// 0096862c  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00968630  56                   push esi
// 00968631  8b31                 mov esi, dword ptr [ecx]
// 00968633  8930                 mov dword ptr [eax], esi
// 00968635  8b7104               mov esi, dword ptr [ecx + 4]
// 00968638  897004               mov dword ptr [eax + 4], esi
// 0096863b  8b7108               mov esi, dword ptr [ecx + 8]
// 0096863e  897008               mov dword ptr [eax + 8], esi
// 00968641  8b710c               mov esi, dword ptr [ecx + 0xc]
// 00968644  89700c               mov dword ptr [eax + 0xc], esi
// 00968647  8b7110               mov esi, dword ptr [ecx + 0x10]
// 0096864a  897010               mov dword ptr [eax + 0x10], esi
// 0096864d  8b7114               mov esi, dword ptr [ecx + 0x14]
// 00968650  897014               mov dword ptr [eax + 0x14], esi
// 00968653  83c018               add eax, 0x18
// 00968656  3bc2                 cmp eax, edx
// 00968658  75d7                 jne 0x968631
// 0096865a  5e                   pop esi
// 0096865b  c3                   ret 
// standard library vector<pod24> (function ??$_Fill@PAUE@@U1@@std@@YAXPAUE@@0ABU1@@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
