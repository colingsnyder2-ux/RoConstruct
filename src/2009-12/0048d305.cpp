// roc 2009-12 0048d305  unit: G3D::Shader  size: 265 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0048d305
//
// 0048d305  6a00                 push 0
// 0048d307  6a00                 push 0
// 0048d309  e86a753600           call 0x7f4878
// 0048d30e  2b5d0c               sub ebx, dword ptr [ebp + 0xc]
// 0048d311  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0048d316  f7eb                 imul ebx
// 0048d318  c1fa02               sar edx, 2
// 0048d31b  8bc2                 mov eax, edx
// 0048d31d  c1e81f               shr eax, 0x1f
// 0048d320  03c2                 add eax, edx
// 0048d322  3bc7                 cmp eax, edi
// 0048d324  0f8384000000         jae 0x48d3ae
// 0048d32a  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 0048d32d  51                   push ecx
// 0048d32e  8d4dd4               lea ecx, [ebp - 0x2c]
// 0048d331  e81ae7ffff           call 0x48ba50
// 0048d336  8b450c               mov eax, dword ptr [ebp + 0xc]
// 0048d339  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 0048d33c  8d1c7f               lea ebx, [edi + edi*2]
// 0048d33f  03db                 add ebx, ebx
// 0048d341  03db                 add ebx, ebx
// 0048d343  03db                 add ebx, ebx
// 0048d345  8d1403               lea edx, [ebx + eax]
// 0048d348  52                   push edx
// 0048d349  51                   push ecx
// 0048d34a  50                   push eax
// 0048d34b  8bce                 mov ecx, esi
// 0048d34d  e87efbffff           call 0x48ced0
// 0048d352  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 0048d355  2b4d0c               sub ecx, dword ptr [ebp + 0xc]
// 0048d358  8d55d4               lea edx, [ebp - 0x2c]
// 0048d35b  52                   push edx
// 0048d35c  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0048d361  f7e9                 imul ecx
// 0048d363  c1fa02               sar edx, 2
// 0048d366  8bc2                 mov eax, edx
// 0048d368  c1e81f               shr eax, 0x1f
// 0048d36b  03c2                 add eax, edx
// 0048d36d  2bf8                 sub edi, eax
// 0048d36f  8b4610               mov eax, dword ptr [esi + 0x10]
// 0048d372  57                   push edi
// 0048d373  50                   push eax
// 0048d374  8bce                 mov ecx, esi
// 0048d376  c745fc02000000       mov dword ptr [ebp - 4], 2
// 0048d37d  e8aef7ffff           call 0x48cb30
// 0048d382  015e10               add dword ptr [esi + 0x10], ebx
// 0048d385  8b7610               mov esi, dword ptr [esi + 0x10]
// 0048d388  8b550c               mov edx, dword ptr [ebp + 0xc]
// 0048d38b  8d4dd4               lea ecx, [ebp - 0x2c]
// 0048d38e  51                   push ecx
// 0048d38f  2bf3                 sub esi, ebx
// 0048d391  56                   push esi
// 0048d392  52                   push edx
// 0048d393  e808f1ffff           call 0x48c4a0
// 0048d398  83c40c               add esp, 0xc
// 0048d39b  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0048d39e  64890d00000000       mov dword ptr fs:[0], ecx
// 0048d3a5  5f                   pop edi
// 0048d3a6  5e                   pop esi
// 0048d3a7  5b                   pop ebx
// 0048d3a8  8be5                 mov esp, ebp
// 0048d3aa  5d                   pop ebp
// 0048d3ab  c21000               ret 0x10
// 0048d3ae  8b4514               mov eax, dword ptr [ebp + 0x14]
// 0048d3b1  50                   push eax
// 0048d3b2  8d4dd4               lea ecx, [ebp - 0x2c]
// 0048d3b5  e896e6ffff           call 0x48ba50
// 0048d3ba  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 0048d3bd  8d3c7f               lea edi, [edi + edi*2]
// 0048d3c0  03ff                 add edi, edi
// 0048d3c2  03ff                 add edi, edi
// 0048d3c4  53                   push ebx
// 0048d3c5  03ff                 add edi, edi
// 0048d3c7  8bc3                 mov eax, ebx
// 0048d3c9  2bc7                 sub eax, edi
// 0048d3cb  53                   push ebx
// 0048d3cc  50                   push eax
// 0048d3cd  8bce                 mov ecx, esi
// 0048d3cf  894514               mov dword ptr [ebp + 0x14], eax
// 0048d3d2  e8f9faffff           call 0x48ced0
// 0048d3d7  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 0048d3da  8b550c               mov edx, dword ptr [ebp + 0xc]
// 0048d3dd  53                   push ebx
// 0048d3de  51                   push ecx
// 0048d3df  52                   push edx
// 0048d3e0  894610               mov dword ptr [esi + 0x10], eax
// 0048d3e3  e8d8f6ffff           call 0x48cac0
// 0048d3e8  8d45d4               lea eax, [ebp - 0x2c]
// 0048d3eb  50                   push eax
// 0048d3ec  8b450c               mov eax, dword ptr [ebp + 0xc]
// 0048d3ef  03f8                 add edi, eax
// 0048d3f1  57                   push edi
// 0048d3f2  50                   push eax
// 0048d3f3  e8a8f0ffff           call 0x48c4a0
// 0048d3f8  83c418               add esp, 0x18
// 0048d3fb  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0048d3fe  5f                   pop edi
// 0048d3ff  5e                   pop esi
// 0048d400  64890d00000000       mov dword ptr fs:[0], ecx
// 0048d407  5b                   pop ebx
// 0048d408  8be5                 mov esp, ebp
// 0048d40a  5d                   pop ebp
// 0048d40b  c21000               ret 0x10
// library ogre-1.4.9/OgreSceneManager.cpp (function __catch$?_Insert_n@?$vector@ULightInfo@SceneManager@Ogre@@V?$allocator@ULightInfo@SceneManager@Ogre@@@std@@@std@@IAEXV?$_Vector_const_iterator@ULightInfo@SceneManager@Ogre@@V?$allocator@ULightInfo@SceneManager@Ogre@@@std@@@2@IABULightInfo@SceneManager@Ogre@@@Z$2)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.4.9 OgreSceneManager.cpp
