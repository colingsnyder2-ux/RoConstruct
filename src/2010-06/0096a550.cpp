// from server: 100% by auto
// roc 2010-06 0096a550  unit: Ogre::RbxSceneUpdater  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0096a550
//
// 0096a550  8b542408             mov edx, dword ptr [esp + 8]
// 0096a554  85d2                 test edx, edx
// 0096a556  7638                 jbe 0x96a590
// 0096a558  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0096a55c  8b442404             mov eax, dword ptr [esp + 4]
// 0096a560  56                   push esi
// 0096a561  85c0                 test eax, eax
// 0096a563  7422                 je 0x96a587
// 0096a565  8b31                 mov esi, dword ptr [ecx]
// 0096a567  8930                 mov dword ptr [eax], esi
// 0096a569  8b7104               mov esi, dword ptr [ecx + 4]
// 0096a56c  897004               mov dword ptr [eax + 4], esi
// 0096a56f  8b7108               mov esi, dword ptr [ecx + 8]
// 0096a572  897008               mov dword ptr [eax + 8], esi
// 0096a575  8b710c               mov esi, dword ptr [ecx + 0xc]
// 0096a578  89700c               mov dword ptr [eax + 0xc], esi
// 0096a57b  8b7110               mov esi, dword ptr [ecx + 0x10]
// 0096a57e  897010               mov dword ptr [eax + 0x10], esi
// 0096a581  8b7114               mov esi, dword ptr [ecx + 0x14]
// 0096a584  897014               mov dword ptr [eax + 0x14], esi
// 0096a587  4a                   dec edx
// 0096a588  83c018               add eax, 0x18
// 0096a58b  85d2                 test edx, edx
// 0096a58d  77d2                 ja 0x96a561
// 0096a58f  5e                   pop esi
// 0096a590  c3                   ret 
// standard library vector<pod24> (function ??$_Uninit_fill_n@PAUE@@IU1@V?$allocator@UE@@@std@@@std@@YAXPAUE@@IABU1@AAV?$allocator@UE@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<pod24>
struct E { int v[6]; };
#include <vector>
template class std::vector<E>;
