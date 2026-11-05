// from server: 100% by auto
// roc 2009-06 0047be30  unit: Ogre::VRootManager::?$sp_counted_impl_p  size: 196 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0047be30
//
// 0047be30  83ec18               sub esp, 0x18
// 0047be33  53                   push ebx
// 0047be34  55                   push ebp
// 0047be35  56                   push esi
// 0047be36  8bf1                 mov esi, ecx
// 0047be38  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 0047be3b  8b6e0c               mov ebp, dword ptr [esi + 0xc]
// 0047be3e  8bcb                 mov ecx, ebx
// 0047be40  2bcd                 sub ecx, ebp
// 0047be42  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0047be47  f7e9                 imul ecx
// 0047be49  d1fa                 sar edx, 1
// 0047be4b  8bc2                 mov eax, edx
// 0047be4d  c1e81f               shr eax, 0x1f
// 0047be50  57                   push edi
// 0047be51  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 0047be55  03c2                 add eax, edx
// 0047be57  3bf8                 cmp edi, eax
// 0047be59  763d                 jbe 0x47be98
// 0047be5b  3beb                 cmp ebp, ebx
// 0047be5d  7606                 jbe 0x47be65
// 0047be5f  ff15ace98900         call dword ptr [0x89e9ac]
// 0047be65  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 0047be68  2b4e0c               sub ecx, dword ptr [esi + 0xc]
// 0047be6b  8b2e                 mov ebp, dword ptr [esi]
// 0047be6d  8d442430             lea eax, [esp + 0x30]
// 0047be71  50                   push eax
// 0047be72  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0047be77  f7e9                 imul ecx
// 0047be79  d1fa                 sar edx, 1
// 0047be7b  8bca                 mov ecx, edx
// 0047be7d  c1e91f               shr ecx, 0x1f
// 0047be80  03ca                 add ecx, edx
// 0047be82  2bf9                 sub edi, ecx
// 0047be84  57                   push edi
// 0047be85  53                   push ebx
// 0047be86  55                   push ebp
// 0047be87  8bce                 mov ecx, esi
// 0047be89  e852fbffff           call 0x47b9e0
// 0047be8e  5f                   pop edi
// 0047be8f  5e                   pop esi
// 0047be90  5d                   pop ebp
// 0047be91  5b                   pop ebx
// 0047be92  83c418               add esp, 0x18
// 0047be95  c21000               ret 0x10
// 0047be98  7350                 jae 0x47beea
// 0047be9a  3beb                 cmp ebp, ebx
// 0047be9c  7606                 jbe 0x47bea4
// 0047be9e  ff15ace98900         call dword ptr [0x89e9ac]
// 0047bea4  8b6e0c               mov ebp, dword ptr [esi + 0xc]
// 0047bea7  8b16                 mov edx, dword ptr [esi]
// 0047bea9  89542418             mov dword ptr [esp + 0x18], edx
// 0047bead  3b6e10               cmp ebp, dword ptr [esi + 0x10]
// 0047beb0  7606                 jbe 0x47beb8
// 0047beb2  ff15ace98900         call dword ptr [0x89e9ac]
// 0047beb8  8b06                 mov eax, dword ptr [esi]
// 0047beba  57                   push edi
// 0047bebb  8d4c2424             lea ecx, [esp + 0x24]
// 0047bebf  51                   push ecx
// 0047bec0  8d4c2418             lea ecx, [esp + 0x18]
// 0047bec4  89442418             mov dword ptr [esp + 0x18], eax
// 0047bec8  896c241c             mov dword ptr [esp + 0x1c], ebp
// 0047becc  e8fff6ffff           call 0x47b5d0
// 0047bed1  8b542418             mov edx, dword ptr [esp + 0x18]
// 0047bed5  8b4804               mov ecx, dword ptr [eax + 4]
// 0047bed8  53                   push ebx
// 0047bed9  52                   push edx
// 0047beda  8b10                 mov edx, dword ptr [eax]
// 0047bedc  51                   push ecx
// 0047bedd  52                   push edx
// 0047bede  8d442428             lea eax, [esp + 0x28]
// 0047bee2  50                   push eax
// 0047bee3  8bce                 mov ecx, esi
// 0047bee5  e866faffff           call 0x47b950
// 0047beea  5f                   pop edi
// 0047beeb  5e                   pop esi
// 0047beec  5d                   pop ebp
// 0047beed  5b                   pop ebx
// 0047beee  83c418               add esp, 0x18
// 0047bef1  c21000               ret 0x10
// standard library vector<pod12> (function ?resize@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXIUE@@@Z)

// stl: vector<pod12>
struct E { int v[3]; };
#include <vector>
template class std::vector<E>;
