// roc 2010-06 008d3635  unit: Ogre::VisualEngine  size: 265 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008d3635
//
// 008d3635  6a00                 push 0
// 008d3637  6a00                 push 0
// 008d3639  e87453edff           call 0x7a89b2
// 008d363e  2b5d0c               sub ebx, dword ptr [ebp + 0xc]
// 008d3641  b8abaaaa2a           mov eax, 0x2aaaaaab
// 008d3646  f7eb                 imul ebx
// 008d3648  c1fa02               sar edx, 2
// 008d364b  8bc2                 mov eax, edx
// 008d364d  c1e81f               shr eax, 0x1f
// 008d3650  03c2                 add eax, edx
// 008d3652  3bc7                 cmp eax, edi
// 008d3654  0f8384000000         jae 0x8d36de
// 008d365a  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 008d365d  51                   push ecx
// 008d365e  8d4dd4               lea ecx, [ebp - 0x2c]
// 008d3661  e8dae6ffff           call 0x8d1d40
// 008d3666  8b450c               mov eax, dword ptr [ebp + 0xc]
// 008d3669  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 008d366c  8d1c7f               lea ebx, [edi + edi*2]
// 008d366f  03db                 add ebx, ebx
// 008d3671  03db                 add ebx, ebx
// 008d3673  03db                 add ebx, ebx
// 008d3675  8d1403               lea edx, [ebx + eax]
// 008d3678  52                   push edx
// 008d3679  51                   push ecx
// 008d367a  50                   push eax
// 008d367b  8bce                 mov ecx, esi
// 008d367d  e87efbffff           call 0x8d3200
// 008d3682  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 008d3685  2b4d0c               sub ecx, dword ptr [ebp + 0xc]
// 008d3688  8d55d4               lea edx, [ebp - 0x2c]
// 008d368b  52                   push edx
// 008d368c  b8abaaaa2a           mov eax, 0x2aaaaaab
// 008d3691  f7e9                 imul ecx
// 008d3693  c1fa02               sar edx, 2
// 008d3696  8bc2                 mov eax, edx
// 008d3698  c1e81f               shr eax, 0x1f
// 008d369b  03c2                 add eax, edx
// 008d369d  2bf8                 sub edi, eax
// 008d369f  8b4610               mov eax, dword ptr [esi + 0x10]
// 008d36a2  57                   push edi
// 008d36a3  50                   push eax
// 008d36a4  8bce                 mov ecx, esi
// 008d36a6  c745fc02000000       mov dword ptr [ebp - 4], 2
// 008d36ad  e8aef7ffff           call 0x8d2e60
// 008d36b2  015e10               add dword ptr [esi + 0x10], ebx
// 008d36b5  8b7610               mov esi, dword ptr [esi + 0x10]
// 008d36b8  8b550c               mov edx, dword ptr [ebp + 0xc]
// 008d36bb  8d4dd4               lea ecx, [ebp - 0x2c]
// 008d36be  51                   push ecx
// 008d36bf  2bf3                 sub esi, ebx
// 008d36c1  56                   push esi
// 008d36c2  52                   push edx
// 008d36c3  e8c8f0ffff           call 0x8d2790
// 008d36c8  83c40c               add esp, 0xc
// 008d36cb  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 008d36ce  64890d00000000       mov dword ptr fs:[0], ecx
// 008d36d5  5f                   pop edi
// 008d36d6  5e                   pop esi
// 008d36d7  5b                   pop ebx
// 008d36d8  8be5                 mov esp, ebp
// 008d36da  5d                   pop ebp
// 008d36db  c21000               ret 0x10
// 008d36de  8b4514               mov eax, dword ptr [ebp + 0x14]
// 008d36e1  50                   push eax
// 008d36e2  8d4dd4               lea ecx, [ebp - 0x2c]
// 008d36e5  e856e6ffff           call 0x8d1d40
// 008d36ea  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 008d36ed  8d3c7f               lea edi, [edi + edi*2]
// 008d36f0  03ff                 add edi, edi
// 008d36f2  03ff                 add edi, edi
// 008d36f4  53                   push ebx
// 008d36f5  03ff                 add edi, edi
// 008d36f7  8bc3                 mov eax, ebx
// 008d36f9  2bc7                 sub eax, edi
// 008d36fb  53                   push ebx
// 008d36fc  50                   push eax
// 008d36fd  8bce                 mov ecx, esi
// 008d36ff  894514               mov dword ptr [ebp + 0x14], eax
// 008d3702  e8f9faffff           call 0x8d3200
// 008d3707  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 008d370a  8b550c               mov edx, dword ptr [ebp + 0xc]
// 008d370d  53                   push ebx
// 008d370e  51                   push ecx
// 008d370f  52                   push edx
// 008d3710  894610               mov dword ptr [esi + 0x10], eax
// 008d3713  e8d8f6ffff           call 0x8d2df0
// 008d3718  8d45d4               lea eax, [ebp - 0x2c]
// 008d371b  50                   push eax
// 008d371c  8b450c               mov eax, dword ptr [ebp + 0xc]
// 008d371f  03f8                 add edi, eax
// 008d3721  57                   push edi
// 008d3722  50                   push eax
// 008d3723  e868f0ffff           call 0x8d2790
// 008d3728  83c418               add esp, 0x18
// 008d372b  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 008d372e  5f                   pop edi
// 008d372f  5e                   pop esi
// 008d3730  64890d00000000       mov dword ptr fs:[0], ecx
// 008d3737  5b                   pop ebx
// 008d3738  8be5                 mov esp, ebp
// 008d373a  5d                   pop ebp
// 008d373b  c21000               ret 0x10
// library ogre-1.4.9/OgreSceneManager.cpp (function __catch$?_Insert_n@?$vector@ULightInfo@SceneManager@Ogre@@V?$allocator@ULightInfo@SceneManager@Ogre@@@std@@@std@@IAEXV?$_Vector_const_iterator@ULightInfo@SceneManager@Ogre@@V?$allocator@ULightInfo@SceneManager@Ogre@@@std@@@2@IABULightInfo@SceneManager@Ogre@@@Z$2)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.4.9 OgreSceneManager.cpp
