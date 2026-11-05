// roc 2010-06 0053d765  unit: RBX::ImmediateMeshGenAdapter  size: 265 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0053d765
//
// 0053d765  6a00                 push 0
// 0053d767  6a00                 push 0
// 0053d769  e844b22600           call 0x7a89b2
// 0053d76e  2b5d0c               sub ebx, dword ptr [ebp + 0xc]
// 0053d771  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0053d776  f7eb                 imul ebx
// 0053d778  c1fa02               sar edx, 2
// 0053d77b  8bc2                 mov eax, edx
// 0053d77d  c1e81f               shr eax, 0x1f
// 0053d780  03c2                 add eax, edx
// 0053d782  3bc7                 cmp eax, edi
// 0053d784  0f8384000000         jae 0x53d80e
// 0053d78a  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 0053d78d  51                   push ecx
// 0053d78e  8d4dd4               lea ecx, [ebp - 0x2c]
// 0053d791  e8daf8ffff           call 0x53d070
// 0053d796  8b450c               mov eax, dword ptr [ebp + 0xc]
// 0053d799  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 0053d79c  8d1c7f               lea ebx, [edi + edi*2]
// 0053d79f  03db                 add ebx, ebx
// 0053d7a1  03db                 add ebx, ebx
// 0053d7a3  03db                 add ebx, ebx
// 0053d7a5  8d1403               lea edx, [ebx + eax]
// 0053d7a8  52                   push edx
// 0053d7a9  51                   push ecx
// 0053d7aa  50                   push eax
// 0053d7ab  8bce                 mov ecx, esi
// 0053d7ad  e8befcffff           call 0x53d470
// 0053d7b2  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 0053d7b5  2b4d0c               sub ecx, dword ptr [ebp + 0xc]
// 0053d7b8  8d55d4               lea edx, [ebp - 0x2c]
// 0053d7bb  52                   push edx
// 0053d7bc  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0053d7c1  f7e9                 imul ecx
// 0053d7c3  c1fa02               sar edx, 2
// 0053d7c6  8bc2                 mov eax, edx
// 0053d7c8  c1e81f               shr eax, 0x1f
// 0053d7cb  03c2                 add eax, edx
// 0053d7cd  2bf8                 sub edi, eax
// 0053d7cf  8b4610               mov eax, dword ptr [esi + 0x10]
// 0053d7d2  57                   push edi
// 0053d7d3  50                   push eax
// 0053d7d4  8bce                 mov ecx, esi
// 0053d7d6  c745fc02000000       mov dword ptr [ebp - 4], 2
// 0053d7dd  e84efcffff           call 0x53d430
// 0053d7e2  015e10               add dword ptr [esi + 0x10], ebx
// 0053d7e5  8b7610               mov esi, dword ptr [esi + 0x10]
// 0053d7e8  8b550c               mov edx, dword ptr [ebp + 0xc]
// 0053d7eb  8d4dd4               lea ecx, [ebp - 0x2c]
// 0053d7ee  51                   push ecx
// 0053d7ef  2bf3                 sub esi, ebx
// 0053d7f1  56                   push esi
// 0053d7f2  52                   push edx
// 0053d7f3  e8b8faffff           call 0x53d2b0
// 0053d7f8  83c40c               add esp, 0xc
// 0053d7fb  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0053d7fe  64890d00000000       mov dword ptr fs:[0], ecx
// 0053d805  5f                   pop edi
// 0053d806  5e                   pop esi
// 0053d807  5b                   pop ebx
// 0053d808  8be5                 mov esp, ebp
// 0053d80a  5d                   pop ebp
// 0053d80b  c21000               ret 0x10
// 0053d80e  8b4514               mov eax, dword ptr [ebp + 0x14]
// 0053d811  50                   push eax
// 0053d812  8d4dd4               lea ecx, [ebp - 0x2c]
// 0053d815  e856f8ffff           call 0x53d070
// 0053d81a  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 0053d81d  8d3c7f               lea edi, [edi + edi*2]
// 0053d820  03ff                 add edi, edi
// 0053d822  03ff                 add edi, edi
// 0053d824  53                   push ebx
// 0053d825  03ff                 add edi, edi
// 0053d827  8bc3                 mov eax, ebx
// 0053d829  2bc7                 sub eax, edi
// 0053d82b  53                   push ebx
// 0053d82c  50                   push eax
// 0053d82d  8bce                 mov ecx, esi
// 0053d82f  894514               mov dword ptr [ebp + 0x14], eax
// 0053d832  e839fcffff           call 0x53d470
// 0053d837  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 0053d83a  8b550c               mov edx, dword ptr [ebp + 0xc]
// 0053d83d  53                   push ebx
// 0053d83e  51                   push ecx
// 0053d83f  52                   push edx
// 0053d840  894610               mov dword ptr [esi + 0x10], eax
// 0053d843  e8b8fbffff           call 0x53d400
// 0053d848  8d45d4               lea eax, [ebp - 0x2c]
// 0053d84b  50                   push eax
// 0053d84c  8b450c               mov eax, dword ptr [ebp + 0xc]
// 0053d84f  03f8                 add edi, eax
// 0053d851  57                   push edi
// 0053d852  50                   push eax
// 0053d853  e858faffff           call 0x53d2b0
// 0053d858  83c418               add esp, 0x18
// 0053d85b  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0053d85e  5f                   pop edi
// 0053d85f  5e                   pop esi
// 0053d860  64890d00000000       mov dword ptr fs:[0], ecx
// 0053d867  5b                   pop ebx
// 0053d868  8be5                 mov esp, ebp
// 0053d86a  5d                   pop ebp
// 0053d86b  c21000               ret 0x10
// library ogre-1.4.9/OgreSceneManager.cpp (function __catch$?_Insert_n@?$vector@ULightInfo@SceneManager@Ogre@@V?$allocator@ULightInfo@SceneManager@Ogre@@@std@@@std@@IAEXV?$_Vector_const_iterator@ULightInfo@SceneManager@Ogre@@V?$allocator@ULightInfo@SceneManager@Ogre@@@std@@@2@IABULightInfo@SceneManager@Ogre@@@Z$2)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.4.9 OgreSceneManager.cpp
