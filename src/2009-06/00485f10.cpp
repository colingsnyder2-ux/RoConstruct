// from server: 100% by auto
// roc 2009-06 00485f10  unit: Ogre::RbxMeshPartAdapter  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00485f10
//
// 00485f10  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00485f14  8b542408             mov edx, dword ptr [esp + 8]
// 00485f18  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00485f1c  3bca                 cmp ecx, edx
// 00485f1e  741a                 je 0x485f3a
// 00485f20  56                   push esi
// 00485f21  85c0                 test eax, eax
// 00485f23  740a                 je 0x485f2f
// 00485f25  8b31                 mov esi, dword ptr [ecx]
// 00485f27  8930                 mov dword ptr [eax], esi
// 00485f29  8b7104               mov esi, dword ptr [ecx + 4]
// 00485f2c  897004               mov dword ptr [eax + 4], esi
// 00485f2f  83c108               add ecx, 8
// 00485f32  83c008               add eax, 8
// 00485f35  3bca                 cmp ecx, edx
// 00485f37  75e8                 jne 0x485f21
// 00485f39  5e                   pop esi
// 00485f3a  c3                   ret 
// standard library vector<pod8> (function ??$_Uninit_copy@PBUE@@PAU1@V?$allocator@UE@@@std@@@std@@YAPAUE@@PBU1@0PAU1@AAV?$allocator@UE@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;
