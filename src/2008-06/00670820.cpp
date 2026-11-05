// from server: 100% by auto
// roc 2008-06 00670820  unit: Ogre::VRbxFont::?$SharedPtr  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00670820
//
// 00670820  8b442404             mov eax, dword ptr [esp + 4]
// 00670824  8b542408             mov edx, dword ptr [esp + 8]
// 00670828  3bc2                 cmp eax, edx
// 0067082a  7417                 je 0x670843
// 0067082c  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00670830  56                   push esi
// 00670831  8b31                 mov esi, dword ptr [ecx]
// 00670833  8930                 mov dword ptr [eax], esi
// 00670835  8b7104               mov esi, dword ptr [ecx + 4]
// 00670838  897004               mov dword ptr [eax + 4], esi
// 0067083b  83c008               add eax, 8
// 0067083e  3bc2                 cmp eax, edx
// 00670840  75ef                 jne 0x670831
// 00670842  5e                   pop esi
// 00670843  c3                   ret 
// standard library vector<i64> (function ??$_Fill@PA_J_J@std@@YAXPA_J0AB_J@Z)

// stl: vector<i64>
typedef __int64 E;
#include <vector>
template class std::vector<E>;
