// from server: 100% by auto
// roc 2011-06 009692f0  unit: Ogre::RbxSpatialHashedSceneNode::?3??_findVisibleObjects::NodeVisiter  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 009692f0
//
// 009692f0  8b442408             mov eax, dword ptr [esp + 8]
// 009692f4  8b542404             mov edx, dword ptr [esp + 4]
// 009692f8  2bc2                 sub eax, edx
// 009692fa  c1f802               sar eax, 2
// 009692fd  56                   push esi
// 009692fe  8b742410             mov esi, dword ptr [esp + 0x10]
// 00969302  8d0c8500000000       lea ecx, [eax*4]
// 00969309  2bf1                 sub esi, ecx
// 0096930b  85c0                 test eax, eax
// 0096930d  7e0d                 jle 0x96931c
// 0096930f  51                   push ecx
// 00969310  52                   push edx
// 00969311  51                   push ecx
// 00969312  56                   push esi
// 00969313  ff15fc09a400         call dword ptr [0xa409fc]
// 00969319  83c410               add esp, 0x10
// 0096931c  8bc6                 mov eax, esi
// 0096931e  5e                   pop esi
// 0096931f  c3                   ret 
// standard library vector<ptr> (function ??$_Copy_backward_opt@PAPAUT@@PAPAU1@Urandom_access_iterator_tag@std@@@std@@YAPAPAUT@@PAPAU1@00Urandom_access_iterator_tag@0@U_Scalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
