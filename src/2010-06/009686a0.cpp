// from server: 100% by auto
// roc 2010-06 009686a0  unit: Ogre::RbxSceneUpdater  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 009686a0
//
// 009686a0  8b542404             mov edx, dword ptr [esp + 4]
// 009686a4  8b4c2408             mov ecx, dword ptr [esp + 8]
// 009686a8  8b44240c             mov eax, dword ptr [esp + 0xc]
// 009686ac  3bd1                 cmp edx, ecx
// 009686ae  7430                 je 0x9686e0
// 009686b0  56                   push esi
// 009686b1  8b71e8               mov esi, dword ptr [ecx - 0x18]
// 009686b4  83e918               sub ecx, 0x18
// 009686b7  8970e8               mov dword ptr [eax - 0x18], esi
// 009686ba  8b7104               mov esi, dword ptr [ecx + 4]
// 009686bd  83e818               sub eax, 0x18
// 009686c0  897004               mov dword ptr [eax + 4], esi
// 009686c3  8b7108               mov esi, dword ptr [ecx + 8]
// 009686c6  897008               mov dword ptr [eax + 8], esi
// 009686c9  8b710c               mov esi, dword ptr [ecx + 0xc]
// 009686cc  89700c               mov dword ptr [eax + 0xc], esi
// 009686cf  8b7110               mov esi, dword ptr [ecx + 0x10]
// 009686d2  897010               mov dword ptr [eax + 0x10], esi
// 009686d5  8b7114               mov esi, dword ptr [ecx + 0x14]
// 009686d8  897014               mov dword ptr [eax + 0x14], esi
// 009686db  3bca                 cmp ecx, edx
// 009686dd  75d2                 jne 0x9686b1
// 009686df  5e                   pop esi
// 009686e0  c3                   ret 
// standard library vector<pod24> (function ??$_Copy_backward_opt@PAUE@@PAU1@Uforward_iterator_tag@std@@@std@@YAPAUE@@PAU1@00Uforward_iterator_tag@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
