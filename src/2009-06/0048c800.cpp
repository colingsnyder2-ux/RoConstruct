// from server: 100% by auto
// roc 2009-06 0048c800  unit: Ogre::VRbxTextureCompositorSceneManager::?$sp_counted_impl_p  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0048c800
//
// 0048c800  51                   push ecx
// 0048c801  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0048c805  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0048c809  c6042400             mov byte ptr [esp], 0
// 0048c80d  8b0424               mov eax, dword ptr [esp]
// 0048c810  50                   push eax
// 0048c811  8b442414             mov eax, dword ptr [esp + 0x14]
// 0048c815  51                   push ecx
// 0048c816  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0048c81a  52                   push edx
// 0048c81b  8b542414             mov edx, dword ptr [esp + 0x14]
// 0048c81f  50                   push eax
// 0048c820  51                   push ecx
// 0048c821  52                   push edx
// 0048c822  e819ffffff           call 0x48c740
// 0048c827  83c41c               add esp, 0x1c
// 0048c82a  c3                   ret 
// standard library vector<string> (function ??$unchecked_copy@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAV12@@stdext@@YAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAV12@00@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
