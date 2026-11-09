// roc 2009-12 004a2ed2  unit: Ogre::RbxMeshPartAdapter  size: 221 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004a2ed2
//
// 004a2ed2  6a00                 push 0
// 004a2ed4  6a00                 push 0
// 004a2ed6  e89d193500           call 0x7f4878
// 004a2edb  2b4d0c               sub ecx, dword ptr [ebp + 0xc]
// 004a2ede  c1f905               sar ecx, 5
// 004a2ee1  3bcf                 cmp ecx, edi
// 004a2ee3  8d4dcc               lea ecx, [ebp - 0x34]
// 004a2ee6  736e                 jae 0x4a2f56
// 004a2ee8  8b4514               mov eax, dword ptr [ebp + 0x14]
// 004a2eeb  50                   push eax
// 004a2eec  e8cfedffff           call 0x4a1cc0
// 004a2ef1  8b450c               mov eax, dword ptr [ebp + 0xc]
// 004a2ef4  8b5610               mov edx, dword ptr [esi + 0x10]
// 004a2ef7  8bdf                 mov ebx, edi
// 004a2ef9  c1e305               shl ebx, 5
// 004a2efc  8d0c03               lea ecx, [ebx + eax]
// 004a2eff  51                   push ecx
// 004a2f00  52                   push edx
// 004a2f01  50                   push eax
// 004a2f02  8bce                 mov ecx, esi
// 004a2f04  e827fdffff           call 0x4a2c30
// 004a2f09  8b4610               mov eax, dword ptr [esi + 0x10]
// 004a2f0c  8bd0                 mov edx, eax
// 004a2f0e  2b550c               sub edx, dword ptr [ebp + 0xc]
// 004a2f11  8d4dcc               lea ecx, [ebp - 0x34]
// 004a2f14  51                   push ecx
// 004a2f15  c1fa05               sar edx, 5
// 004a2f18  2bfa                 sub edi, edx
// 004a2f1a  57                   push edi
// 004a2f1b  50                   push eax
// 004a2f1c  8bce                 mov ecx, esi
// 004a2f1e  c745fc02000000       mov dword ptr [ebp - 4], 2
// 004a2f25  e8a6efffff           call 0x4a1ed0
// 004a2f2a  015e10               add dword ptr [esi + 0x10], ebx
// 004a2f2d  8b7610               mov esi, dword ptr [esi + 0x10]
// 004a2f30  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 004a2f33  8d45cc               lea eax, [ebp - 0x34]
// 004a2f36  50                   push eax
// 004a2f37  2bf3                 sub esi, ebx
// 004a2f39  56                   push esi
// 004a2f3a  51                   push ecx
// 004a2f3b  e830eeffff           call 0x4a1d70
// 004a2f40  83c40c               add esp, 0xc
// 004a2f43  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 004a2f46  64890d00000000       mov dword ptr fs:[0], ecx
// 004a2f4d  5f                   pop edi
// 004a2f4e  5e                   pop esi
// 004a2f4f  5b                   pop ebx
// 004a2f50  8be5                 mov esp, ebp
// 004a2f52  5d                   pop ebp
// 004a2f53  c21000               ret 0x10
// 004a2f56  8b5514               mov edx, dword ptr [ebp + 0x14]
// 004a2f59  52                   push edx
// 004a2f5a  e861edffff           call 0x4a1cc0
// 004a2f5f  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 004a2f62  c1e705               shl edi, 5
// 004a2f65  8bc7                 mov eax, edi
// 004a2f67  53                   push ebx
// 004a2f68  8bfb                 mov edi, ebx
// 004a2f6a  2bf8                 sub edi, eax
// 004a2f6c  53                   push ebx
// 004a2f6d  57                   push edi
// 004a2f6e  8bce                 mov ecx, esi
// 004a2f70  894514               mov dword ptr [ebp + 0x14], eax
// 004a2f73  e8b8fcffff           call 0x4a2c30
// 004a2f78  53                   push ebx
// 004a2f79  894610               mov dword ptr [esi + 0x10], eax
// 004a2f7c  8b450c               mov eax, dword ptr [ebp + 0xc]
// 004a2f7f  57                   push edi
// 004a2f80  50                   push eax
// 004a2f81  e8faeeffff           call 0x4a1e80
// 004a2f86  8b450c               mov eax, dword ptr [ebp + 0xc]
// 004a2f89  8b5514               mov edx, dword ptr [ebp + 0x14]
// 004a2f8c  8d4dcc               lea ecx, [ebp - 0x34]
// 004a2f8f  51                   push ecx
// 004a2f90  03d0                 add edx, eax
// 004a2f92  52                   push edx
// 004a2f93  50                   push eax
// 004a2f94  e8d7edffff           call 0x4a1d70
// 004a2f99  83c418               add esp, 0x18
// 004a2f9c  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 004a2f9f  5f                   pop edi
// 004a2fa0  5e                   pop esi
// 004a2fa1  64890d00000000       mov dword ptr fs:[0], ecx
// 004a2fa8  5b                   pop ebx
// 004a2fa9  8be5                 mov esp, ebp
// 004a2fab  5d                   pop ebp
// 004a2fac  c21000               ret 0x10
// library ogre-1.4.9/OgreProgressiveMesh.cpp (function __catch$?_Insert_n@?$vector@VPMTriangle@ProgressiveMesh@Ogre@@V?$allocator@VPMTriangle@ProgressiveMesh@Ogre@@@std@@@std@@IAEXV?$_Vector_const_iterator@VPMTriangle@ProgressiveMesh@Ogre@@V?$allocator@VPMTriangle@ProgressiveMesh@Ogre@@@std@@@2@IABVPMTriangle@ProgressiveMesh@Ogre@@@Z$2)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.4.9 OgreProgressiveMesh.cpp
