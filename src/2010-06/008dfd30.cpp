// from server: 100% by auto
// roc 2010-06 008dfd30  unit: Ogre::RbxMaterialAdapter  size: 47 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008dfd30
//
// 008dfd30  8b4c2408             mov ecx, dword ptr [esp + 8]
// 008dfd34  85c9                 test ecx, ecx
// 008dfd36  7626                 jbe 0x8dfd5e
// 008dfd38  8b54240c             mov edx, dword ptr [esp + 0xc]
// 008dfd3c  8b442404             mov eax, dword ptr [esp + 4]
// 008dfd40  56                   push esi
// 008dfd41  85c0                 test eax, eax
// 008dfd43  7410                 je 0x8dfd55
// 008dfd45  8b32                 mov esi, dword ptr [edx]
// 008dfd47  8930                 mov dword ptr [eax], esi
// 008dfd49  8b7204               mov esi, dword ptr [edx + 4]
// 008dfd4c  897004               mov dword ptr [eax + 4], esi
// 008dfd4f  8b7208               mov esi, dword ptr [edx + 8]
// 008dfd52  897008               mov dword ptr [eax + 8], esi
// 008dfd55  49                   dec ecx
// 008dfd56  83c00c               add eax, 0xc
// 008dfd59  85c9                 test ecx, ecx
// 008dfd5b  77e4                 ja 0x8dfd41
// 008dfd5d  5e                   pop esi
// 008dfd5e  c3                   ret 
// standard library vector<pod12> (function ??$_Uninit_fill_n@PAUE@@IU1@V?$allocator@UE@@@std@@@std@@YAXPAUE@@IABU1@AAV?$allocator@UE@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
