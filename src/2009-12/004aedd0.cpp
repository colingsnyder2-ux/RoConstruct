// from server: 100% by auto
// roc 2009-12 004aedd0  unit: Ogre::VRbxTextureCompositorSceneManager::?$sp_counted_impl_p  size: 53 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004aedd0
//
// 004aedd0  8b442408             mov eax, dword ptr [esp + 8]
// 004aedd4  8b542404             mov edx, dword ptr [esp + 4]
// 004aedd8  2bc2                 sub eax, edx
// 004aedda  56                   push esi
// 004aeddb  c1f802               sar eax, 2
// 004aedde  57                   push edi
// 004aeddf  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 004aede3  8d0c8500000000       lea ecx, [eax*4]
// 004aedea  8d3439               lea esi, [ecx + edi]
// 004aeded  85c0                 test eax, eax
// 004aedef  760d                 jbe 0x4aedfe
// 004aedf1  51                   push ecx
// 004aedf2  52                   push edx
// 004aedf3  51                   push ecx
// 004aedf4  57                   push edi
// 004aedf5  ff15c0b79800         call dword ptr [0x98b7c0]
// 004aedfb  83c410               add esp, 0x10
// 004aedfe  5f                   pop edi
// 004aedff  8bc6                 mov eax, esi
// 004aee01  5e                   pop esi
// 004aee02  c20c00               ret 0xc
// standard library vector<ptr> (function ??$_Ucopy@PAPAUT@@@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@IAEPAPAUT@@PAPAU2@00@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
