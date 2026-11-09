// from server: 100% by auto
// roc 2010-06 00968660  unit: Ogre::RbxSceneUpdater  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00968660
//
// 00968660  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00968664  8b542408             mov edx, dword ptr [esp + 8]
// 00968668  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0096866c  3bca                 cmp ecx, edx
// 0096866e  7428                 je 0x968698
// 00968670  56                   push esi
// 00968671  8b31                 mov esi, dword ptr [ecx]
// 00968673  8930                 mov dword ptr [eax], esi
// 00968675  8b7104               mov esi, dword ptr [ecx + 4]
// 00968678  897004               mov dword ptr [eax + 4], esi
// 0096867b  8b7108               mov esi, dword ptr [ecx + 8]
// 0096867e  897008               mov dword ptr [eax + 8], esi
// 00968681  8b710c               mov esi, dword ptr [ecx + 0xc]
// 00968684  89700c               mov dword ptr [eax + 0xc], esi
// 00968687  8b7110               mov esi, dword ptr [ecx + 0x10]
// 0096868a  897010               mov dword ptr [eax + 0x10], esi
// 0096868d  83c114               add ecx, 0x14
// 00968690  83c014               add eax, 0x14
// 00968693  3bca                 cmp ecx, edx
// 00968695  75da                 jne 0x968671
// 00968697  5e                   pop esi
// 00968698  c3                   ret 
// standard library vector<pod20> (function ??$_Copy_opt@PAUE@@PAU1@Uforward_iterator_tag@std@@@std@@YAPAUE@@PAU1@00Uforward_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<pod20>
struct E { int v[5]; };
#include <vector>
template class std::vector<E>;
