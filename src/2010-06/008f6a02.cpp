// roc 2010-06 008f6a02  unit: Ogre::RbxMeshPartAdapter  size: 221 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008f6a02
//
// 008f6a02  6a00                 push 0
// 008f6a04  6a00                 push 0
// 008f6a06  e8a71febff           call 0x7a89b2
// 008f6a0b  2b4d0c               sub ecx, dword ptr [ebp + 0xc]
// 008f6a0e  c1f905               sar ecx, 5
// 008f6a11  3bcf                 cmp ecx, edi
// 008f6a13  8d4dcc               lea ecx, [ebp - 0x34]
// 008f6a16  736e                 jae 0x8f6a86
// 008f6a18  8b4514               mov eax, dword ptr [ebp + 0x14]
// 008f6a1b  50                   push eax
// 008f6a1c  e8afefffff           call 0x8f59d0
// 008f6a21  8b450c               mov eax, dword ptr [ebp + 0xc]
// 008f6a24  8b5610               mov edx, dword ptr [esi + 0x10]
// 008f6a27  8bdf                 mov ebx, edi
// 008f6a29  c1e305               shl ebx, 5
// 008f6a2c  8d0c03               lea ecx, [ebx + eax]
// 008f6a2f  51                   push ecx
// 008f6a30  52                   push edx
// 008f6a31  50                   push eax
// 008f6a32  8bce                 mov ecx, esi
// 008f6a34  e8c712d6ff           call 0x657d00
// 008f6a39  8b4610               mov eax, dword ptr [esi + 0x10]
// 008f6a3c  8bd0                 mov edx, eax
// 008f6a3e  2b550c               sub edx, dword ptr [ebp + 0xc]
// 008f6a41  8d4dcc               lea ecx, [ebp - 0x34]
// 008f6a44  51                   push ecx
// 008f6a45  c1fa05               sar edx, 5
// 008f6a48  2bfa                 sub edi, edx
// 008f6a4a  57                   push edi
// 008f6a4b  50                   push eax
// 008f6a4c  8bce                 mov ecx, esi
// 008f6a4e  c745fc02000000       mov dword ptr [ebp - 4], 2
// 008f6a55  e8d6f0ffff           call 0x8f5b30
// 008f6a5a  015e10               add dword ptr [esi + 0x10], ebx
// 008f6a5d  8b7610               mov esi, dword ptr [esi + 0x10]
// 008f6a60  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 008f6a63  8d45cc               lea eax, [ebp - 0x34]
// 008f6a66  50                   push eax
// 008f6a67  2bf3                 sub esi, ebx
// 008f6a69  56                   push esi
// 008f6a6a  51                   push ecx
// 008f6a6b  e8a005d6ff           call 0x657010
// 008f6a70  83c40c               add esp, 0xc
// 008f6a73  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 008f6a76  64890d00000000       mov dword ptr fs:[0], ecx
// 008f6a7d  5f                   pop edi
// 008f6a7e  5e                   pop esi
// 008f6a7f  5b                   pop ebx
// 008f6a80  8be5                 mov esp, ebp
// 008f6a82  5d                   pop ebp
// 008f6a83  c21000               ret 0x10
// 008f6a86  8b5514               mov edx, dword ptr [ebp + 0x14]
// 008f6a89  52                   push edx
// 008f6a8a  e841efffff           call 0x8f59d0
// 008f6a8f  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 008f6a92  c1e705               shl edi, 5
// 008f6a95  8bc7                 mov eax, edi
// 008f6a97  53                   push ebx
// 008f6a98  8bfb                 mov edi, ebx
// 008f6a9a  2bf8                 sub edi, eax
// 008f6a9c  53                   push ebx
// 008f6a9d  57                   push edi
// 008f6a9e  8bce                 mov ecx, esi
// 008f6aa0  894514               mov dword ptr [ebp + 0x14], eax
// 008f6aa3  e85812d6ff           call 0x657d00
// 008f6aa8  53                   push ebx
// 008f6aa9  894610               mov dword ptr [esi + 0x10], eax
// 008f6aac  8b450c               mov eax, dword ptr [ebp + 0xc]
// 008f6aaf  57                   push edi
// 008f6ab0  50                   push eax
// 008f6ab1  e82af0ffff           call 0x8f5ae0
// 008f6ab6  8b450c               mov eax, dword ptr [ebp + 0xc]
// 008f6ab9  8b5514               mov edx, dword ptr [ebp + 0x14]
// 008f6abc  8d4dcc               lea ecx, [ebp - 0x34]
// 008f6abf  51                   push ecx
// 008f6ac0  03d0                 add edx, eax
// 008f6ac2  52                   push edx
// 008f6ac3  50                   push eax
// 008f6ac4  e84705d6ff           call 0x657010
// 008f6ac9  83c418               add esp, 0x18
// 008f6acc  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 008f6acf  5f                   pop edi
// 008f6ad0  5e                   pop esi
// 008f6ad1  64890d00000000       mov dword ptr fs:[0], ecx
// 008f6ad8  5b                   pop ebx
// 008f6ad9  8be5                 mov esp, ebp
// 008f6adb  5d                   pop ebp
// 008f6adc  c21000               ret 0x10
// library ogre-1.4.9/OgreProgressiveMesh.cpp (function __catch$?_Insert_n@?$vector@VPMTriangle@ProgressiveMesh@Ogre@@V?$allocator@VPMTriangle@ProgressiveMesh@Ogre@@@std@@@std@@IAEXV?$_Vector_const_iterator@VPMTriangle@ProgressiveMesh@Ogre@@V?$allocator@VPMTriangle@ProgressiveMesh@Ogre@@@std@@@2@IABVPMTriangle@ProgressiveMesh@Ogre@@@Z$2)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.4.9 OgreProgressiveMesh.cpp
