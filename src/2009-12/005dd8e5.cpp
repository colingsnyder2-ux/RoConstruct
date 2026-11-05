// roc 2009-12 005dd8e5  unit: RBX::ImmediateMeshGenAdapter  size: 265 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005dd8e5
//
// 005dd8e5  6a00                 push 0
// 005dd8e7  6a00                 push 0
// 005dd8e9  e88a6f2100           call 0x7f4878
// 005dd8ee  2b5d0c               sub ebx, dword ptr [ebp + 0xc]
// 005dd8f1  b8abaaaa2a           mov eax, 0x2aaaaaab
// 005dd8f6  f7eb                 imul ebx
// 005dd8f8  c1fa02               sar edx, 2
// 005dd8fb  8bc2                 mov eax, edx
// 005dd8fd  c1e81f               shr eax, 0x1f
// 005dd900  03c2                 add eax, edx
// 005dd902  3bc7                 cmp eax, edi
// 005dd904  0f8384000000         jae 0x5dd98e
// 005dd90a  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 005dd90d  51                   push ecx
// 005dd90e  8d4dd4               lea ecx, [ebp - 0x2c]
// 005dd911  e89af8ffff           call 0x5dd1b0
// 005dd916  8b450c               mov eax, dword ptr [ebp + 0xc]
// 005dd919  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 005dd91c  8d1c7f               lea ebx, [edi + edi*2]
// 005dd91f  03db                 add ebx, ebx
// 005dd921  03db                 add ebx, ebx
// 005dd923  03db                 add ebx, ebx
// 005dd925  8d1403               lea edx, [ebx + eax]
// 005dd928  52                   push edx
// 005dd929  51                   push ecx
// 005dd92a  50                   push eax
// 005dd92b  8bce                 mov ecx, esi
// 005dd92d  e87efcffff           call 0x5dd5b0
// 005dd932  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 005dd935  2b4d0c               sub ecx, dword ptr [ebp + 0xc]
// 005dd938  8d55d4               lea edx, [ebp - 0x2c]
// 005dd93b  52                   push edx
// 005dd93c  b8abaaaa2a           mov eax, 0x2aaaaaab
// 005dd941  f7e9                 imul ecx
// 005dd943  c1fa02               sar edx, 2
// 005dd946  8bc2                 mov eax, edx
// 005dd948  c1e81f               shr eax, 0x1f
// 005dd94b  03c2                 add eax, edx
// 005dd94d  2bf8                 sub edi, eax
// 005dd94f  8b4610               mov eax, dword ptr [esi + 0x10]
// 005dd952  57                   push edi
// 005dd953  50                   push eax
// 005dd954  8bce                 mov ecx, esi
// 005dd956  c745fc02000000       mov dword ptr [ebp - 4], 2
// 005dd95d  e80efcffff           call 0x5dd570
// 005dd962  015e10               add dword ptr [esi + 0x10], ebx
// 005dd965  8b7610               mov esi, dword ptr [esi + 0x10]
// 005dd968  8b550c               mov edx, dword ptr [ebp + 0xc]
// 005dd96b  8d4dd4               lea ecx, [ebp - 0x2c]
// 005dd96e  51                   push ecx
// 005dd96f  2bf3                 sub esi, ebx
// 005dd971  56                   push esi
// 005dd972  52                   push edx
// 005dd973  e878faffff           call 0x5dd3f0
// 005dd978  83c40c               add esp, 0xc
// 005dd97b  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 005dd97e  64890d00000000       mov dword ptr fs:[0], ecx
// 005dd985  5f                   pop edi
// 005dd986  5e                   pop esi
// 005dd987  5b                   pop ebx
// 005dd988  8be5                 mov esp, ebp
// 005dd98a  5d                   pop ebp
// 005dd98b  c21000               ret 0x10
// 005dd98e  8b4514               mov eax, dword ptr [ebp + 0x14]
// 005dd991  50                   push eax
// 005dd992  8d4dd4               lea ecx, [ebp - 0x2c]
// 005dd995  e816f8ffff           call 0x5dd1b0
// 005dd99a  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 005dd99d  8d3c7f               lea edi, [edi + edi*2]
// 005dd9a0  03ff                 add edi, edi
// 005dd9a2  03ff                 add edi, edi
// 005dd9a4  53                   push ebx
// 005dd9a5  03ff                 add edi, edi
// 005dd9a7  8bc3                 mov eax, ebx
// 005dd9a9  2bc7                 sub eax, edi
// 005dd9ab  53                   push ebx
// 005dd9ac  50                   push eax
// 005dd9ad  8bce                 mov ecx, esi
// 005dd9af  894514               mov dword ptr [ebp + 0x14], eax
// 005dd9b2  e8f9fbffff           call 0x5dd5b0
// 005dd9b7  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 005dd9ba  8b550c               mov edx, dword ptr [ebp + 0xc]
// 005dd9bd  53                   push ebx
// 005dd9be  51                   push ecx
// 005dd9bf  52                   push edx
// 005dd9c0  894610               mov dword ptr [esi + 0x10], eax
// 005dd9c3  e878fbffff           call 0x5dd540
// 005dd9c8  8d45d4               lea eax, [ebp - 0x2c]
// 005dd9cb  50                   push eax
// 005dd9cc  8b450c               mov eax, dword ptr [ebp + 0xc]
// 005dd9cf  03f8                 add edi, eax
// 005dd9d1  57                   push edi
// 005dd9d2  50                   push eax
// 005dd9d3  e818faffff           call 0x5dd3f0
// 005dd9d8  83c418               add esp, 0x18
// 005dd9db  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 005dd9de  5f                   pop edi
// 005dd9df  5e                   pop esi
// 005dd9e0  64890d00000000       mov dword ptr fs:[0], ecx
// 005dd9e7  5b                   pop ebx
// 005dd9e8  8be5                 mov esp, ebp
// 005dd9ea  5d                   pop ebp
// 005dd9eb  c21000               ret 0x10
// library ogre-1.4.9/OgreSceneManager.cpp (function __catch$?_Insert_n@?$vector@ULightInfo@SceneManager@Ogre@@V?$allocator@ULightInfo@SceneManager@Ogre@@@std@@@std@@IAEXV?$_Vector_const_iterator@ULightInfo@SceneManager@Ogre@@V?$allocator@ULightInfo@SceneManager@Ogre@@@std@@@2@IABULightInfo@SceneManager@Ogre@@@Z$2)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.4.9 OgreSceneManager.cpp
