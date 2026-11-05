// from server: 100% by auto
// roc 2012-06 00511240  unit: Ogre::RbxSpatialHashedSceneNode  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00511240
//
// 00511240  8b442404             mov eax, dword ptr [esp + 4]
// 00511244  8b542408             mov edx, dword ptr [esp + 8]
// 00511248  3bc2                 cmp eax, edx
// 0051124a  7429                 je 0x511275
// 0051124c  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00511250  56                   push esi
// 00511251  8b31                 mov esi, dword ptr [ecx]
// 00511253  8930                 mov dword ptr [eax], esi
// 00511255  8b7104               mov esi, dword ptr [ecx + 4]
// 00511258  897004               mov dword ptr [eax + 4], esi
// 0051125b  8b7108               mov esi, dword ptr [ecx + 8]
// 0051125e  897008               mov dword ptr [eax + 8], esi
// 00511261  8b710c               mov esi, dword ptr [ecx + 0xc]
// 00511264  89700c               mov dword ptr [eax + 0xc], esi
// 00511267  8b7110               mov esi, dword ptr [ecx + 0x10]
// 0051126a  897010               mov dword ptr [eax + 0x10], esi
// 0051126d  83c014               add eax, 0x14
// 00511270  3bc2                 cmp eax, edx
// 00511272  75dd                 jne 0x511251
// 00511274  5e                   pop esi
// 00511275  c3                   ret 
// standard library vector<pod20> (function ??$_Fill@PAUE@@U1@@std@@YAXPAUE@@0ABU1@@Z)

// stl: vector<pod20>
struct E { int v[5]; };
#include <vector>
template class std::vector<E>;
