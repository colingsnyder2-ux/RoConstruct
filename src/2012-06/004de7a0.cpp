// from server: 100% by auto
// roc 2012-06 004de7a0  unit: Ogre::VRbxTextureCompositorSceneManager::?$sp_counted_impl_p  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004de7a0
//
// 004de7a0  8b442408             mov eax, dword ptr [esp + 8]
// 004de7a4  8b542404             mov edx, dword ptr [esp + 4]
// 004de7a8  2bc2                 sub eax, edx
// 004de7aa  c1f802               sar eax, 2
// 004de7ad  56                   push esi
// 004de7ae  8b742410             mov esi, dword ptr [esp + 0x10]
// 004de7b2  8d0c8500000000       lea ecx, [eax*4]
// 004de7b9  2bf1                 sub esi, ecx
// 004de7bb  85c0                 test eax, eax
// 004de7bd  7e0d                 jle 0x4de7cc
// 004de7bf  51                   push ecx
// 004de7c0  52                   push edx
// 004de7c1  51                   push ecx
// 004de7c2  56                   push esi
// 004de7c3  ff15c02ab200         call dword ptr [0xb22ac0]
// 004de7c9  83c410               add esp, 0x10
// 004de7cc  8bc6                 mov eax, esi
// 004de7ce  5e                   pop esi
// 004de7cf  c3                   ret 
// standard library vector<ptr> (function ??$_Copy_backward_opt@PAPAUT@@PAPAU1@Urandom_access_iterator_tag@std@@@std@@YAPAPAUT@@PAPAU1@00Urandom_access_iterator_tag@0@U_Scalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
