// from server: 100% by auto
// roc 2009-06 00483f00  unit: Ogre::RbxSpatialHashedSceneNode::?1??_findVisibleObjects::NodeVisiter  size: 169 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00483f00
//
// 00483f00  83ec18               sub esp, 0x18
// 00483f03  53                   push ebx
// 00483f04  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 00483f08  56                   push esi
// 00483f09  8bf1                 mov esi, ecx
// 00483f0b  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 00483f0e  57                   push edi
// 00483f0f  8b7e10               mov edi, dword ptr [esi + 0x10]
// 00483f12  8bc7                 mov eax, edi
// 00483f14  2bc1                 sub eax, ecx
// 00483f16  c1f803               sar eax, 3
// 00483f19  3bd8                 cmp ebx, eax
// 00483f1b  762f                 jbe 0x483f4c
// 00483f1d  3bcf                 cmp ecx, edi
// 00483f1f  7606                 jbe 0x483f27
// 00483f21  ff15ace98900         call dword ptr [0x89e9ac]
// 00483f27  8b5610               mov edx, dword ptr [esi + 0x10]
// 00483f2a  2b560c               sub edx, dword ptr [esi + 0xc]
// 00483f2d  8b06                 mov eax, dword ptr [esi]
// 00483f2f  8d4c242c             lea ecx, [esp + 0x2c]
// 00483f33  51                   push ecx
// 00483f34  c1fa03               sar edx, 3
// 00483f37  2bda                 sub ebx, edx
// 00483f39  53                   push ebx
// 00483f3a  57                   push edi
// 00483f3b  50                   push eax
// 00483f3c  8bce                 mov ecx, esi
// 00483f3e  e84df2ffff           call 0x483190
// 00483f43  5f                   pop edi
// 00483f44  5e                   pop esi
// 00483f45  5b                   pop ebx
// 00483f46  83c418               add esp, 0x18
// 00483f49  c20c00               ret 0xc
// 00483f4c  7352                 jae 0x483fa0
// 00483f4e  3bcf                 cmp ecx, edi
// 00483f50  7606                 jbe 0x483f58
// 00483f52  ff15ace98900         call dword ptr [0x89e9ac]
// 00483f58  8b06                 mov eax, dword ptr [esi]
// 00483f5a  55                   push ebp
// 00483f5b  8b6e0c               mov ebp, dword ptr [esi + 0xc]
// 00483f5e  89442418             mov dword ptr [esp + 0x18], eax
// 00483f62  3b6e10               cmp ebp, dword ptr [esi + 0x10]
// 00483f65  7606                 jbe 0x483f6d
// 00483f67  ff15ace98900         call dword ptr [0x89e9ac]
// 00483f6d  8b0e                 mov ecx, dword ptr [esi]
// 00483f6f  53                   push ebx
// 00483f70  8d542424             lea edx, [esp + 0x24]
// 00483f74  894c2414             mov dword ptr [esp + 0x14], ecx
// 00483f78  52                   push edx
// 00483f79  8d4c2418             lea ecx, [esp + 0x18]
// 00483f7d  896c241c             mov dword ptr [esp + 0x1c], ebp
// 00483f81  e89ac0f8ff           call 0x410020
// 00483f86  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00483f8a  8b5004               mov edx, dword ptr [eax + 4]
// 00483f8d  8b00                 mov eax, dword ptr [eax]
// 00483f8f  57                   push edi
// 00483f90  51                   push ecx
// 00483f91  52                   push edx
// 00483f92  50                   push eax
// 00483f93  8d4c2428             lea ecx, [esp + 0x28]
// 00483f97  51                   push ecx
// 00483f98  8bce                 mov ecx, esi
// 00483f9a  e8f1efffff           call 0x482f90
// 00483f9f  5d                   pop ebp
// 00483fa0  5f                   pop edi
// 00483fa1  5e                   pop esi
// 00483fa2  5b                   pop ebx
// 00483fa3  83c418               add esp, 0x18
// 00483fa6  c20c00               ret 0xc
// standard library vector<pod8> (function ?resize@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXIUE@@@Z)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;
