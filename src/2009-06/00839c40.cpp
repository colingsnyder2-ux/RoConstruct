// from server: 100% by auto
// roc 2009-06 00839c40  unit: Ogre::RbxEntity  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00839c40
//
// 00839c40  8b442404             mov eax, dword ptr [esp + 4]
// 00839c44  8b542408             mov edx, dword ptr [esp + 8]
// 00839c48  3bc2                 cmp eax, edx
// 00839c4a  7417                 je 0x839c63
// 00839c4c  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00839c50  56                   push esi
// 00839c51  8b31                 mov esi, dword ptr [ecx]
// 00839c53  8930                 mov dword ptr [eax], esi
// 00839c55  8b7104               mov esi, dword ptr [ecx + 4]
// 00839c58  897004               mov dword ptr [eax + 4], esi
// 00839c5b  83c008               add eax, 8
// 00839c5e  3bc2                 cmp eax, edx
// 00839c60  75ef                 jne 0x839c51
// 00839c62  5e                   pop esi
// 00839c63  c3                   ret 
// standard library vector<i64> (function ??$_Fill@PA_J_J@std@@YAXPA_J0AB_J@Z)

// stl: vector<i64>
typedef __int64 E;
#include <vector>
template class std::vector<E>;
