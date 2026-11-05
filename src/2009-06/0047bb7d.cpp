// roc 2009-06 0047bb7d  unit: Ogre::VRootManager::?$sp_counted_impl_p  size: 250 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0047bb7d
//
// 0047bb7d  6a00                 push 0
// 0047bb7f  6a00                 push 0
// 0047bb81  e8c4de2900           call 0x719a4a
// 0047bb86  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 0047bb89  8bd3                 mov edx, ebx
// 0047bb8b  2bd1                 sub edx, ecx
// 0047bb8d  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0047bb92  f7ea                 imul edx
// 0047bb94  d1fa                 sar edx, 1
// 0047bb96  8bc2                 mov eax, edx
// 0047bb98  c1e81f               shr eax, 0x1f
// 0047bb9b  03c2                 add eax, edx
// 0047bb9d  3bc7                 cmp eax, edi
// 0047bb9f  8b4514               mov eax, dword ptr [ebp + 0x14]
// 0047bba2  d900                 fld dword ptr [eax]
// 0047bba4  d95de0               fstp dword ptr [ebp - 0x20]
// 0047bba7  d94004               fld dword ptr [eax + 4]
// 0047bbaa  d95de4               fstp dword ptr [ebp - 0x1c]
// 0047bbad  d94008               fld dword ptr [eax + 8]
// 0047bbb0  d95de8               fstp dword ptr [ebp - 0x18]
// 0047bbb3  7373                 jae 0x47bc28
// 0047bbb5  8d047f               lea eax, [edi + edi*2]
// 0047bbb8  03c0                 add eax, eax
// 0047bbba  03c0                 add eax, eax
// 0047bbbc  894514               mov dword ptr [ebp + 0x14], eax
// 0047bbbf  03c1                 add eax, ecx
// 0047bbc1  50                   push eax
// 0047bbc2  53                   push ebx
// 0047bbc3  51                   push ecx
// 0047bbc4  8bce                 mov ecx, esi
// 0047bbc6  e825ac0000           call 0x4867f0
// 0047bbcb  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 0047bbce  8d4de0               lea ecx, [ebp - 0x20]
// 0047bbd1  51                   push ecx
// 0047bbd2  8bcb                 mov ecx, ebx
// 0047bbd4  2b4d0c               sub ecx, dword ptr [ebp + 0xc]
// 0047bbd7  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0047bbdc  f7e9                 imul ecx
// 0047bbde  d1fa                 sar edx, 1
// 0047bbe0  8bc2                 mov eax, edx
// 0047bbe2  c1e81f               shr eax, 0x1f
// 0047bbe5  03c2                 add eax, edx
// 0047bbe7  2bf8                 sub edi, eax
// 0047bbe9  57                   push edi
// 0047bbea  53                   push ebx
// 0047bbeb  8bce                 mov ecx, esi
// 0047bbed  c745fc02000000       mov dword ptr [ebp - 4], 2
// 0047bbf4  e8e7faffff           call 0x47b6e0
// 0047bbf9  8b4514               mov eax, dword ptr [ebp + 0x14]
// 0047bbfc  014610               add dword ptr [esi + 0x10], eax
// 0047bbff  8b7610               mov esi, dword ptr [esi + 0x10]
// 0047bc02  8b550c               mov edx, dword ptr [ebp + 0xc]
// 0047bc05  8d4de0               lea ecx, [ebp - 0x20]
// 0047bc08  51                   push ecx
// 0047bc09  2bf0                 sub esi, eax
// 0047bc0b  56                   push esi
// 0047bc0c  52                   push edx
// 0047bc0d  e80efaffff           call 0x47b620
// 0047bc12  83c40c               add esp, 0xc
// 0047bc15  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0047bc18  64890d00000000       mov dword ptr fs:[0], ecx
// 0047bc1f  5f                   pop edi
// 0047bc20  5e                   pop esi
// 0047bc21  5b                   pop ebx
// 0047bc22  8be5                 mov esp, ebp
// 0047bc24  5d                   pop ebp
// 0047bc25  c21000               ret 0x10
// 0047bc28  8d3c7f               lea edi, [edi + edi*2]
// 0047bc2b  03ff                 add edi, edi
// 0047bc2d  53                   push ebx
// 0047bc2e  03ff                 add edi, edi
// 0047bc30  8bc3                 mov eax, ebx
// 0047bc32  2bc7                 sub eax, edi
// 0047bc34  53                   push ebx
// 0047bc35  50                   push eax
// 0047bc36  8bce                 mov ecx, esi
// 0047bc38  894514               mov dword ptr [ebp + 0x14], eax
// 0047bc3b  e8b0ab0000           call 0x4867f0
// 0047bc40  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 0047bc43  894610               mov dword ptr [esi + 0x10], eax
// 0047bc46  8b4514               mov eax, dword ptr [ebp + 0x14]
// 0047bc49  53                   push ebx
// 0047bc4a  50                   push eax
// 0047bc4b  51                   push ecx
// 0047bc4c  e87faa0000           call 0x4866d0
// 0047bc51  8b450c               mov eax, dword ptr [ebp + 0xc]
// 0047bc54  8d55e0               lea edx, [ebp - 0x20]
// 0047bc57  52                   push edx
// 0047bc58  03f8                 add edi, eax
// 0047bc5a  57                   push edi
// 0047bc5b  50                   push eax
// 0047bc5c  e8bff9ffff           call 0x47b620
// 0047bc61  83c418               add esp, 0x18
// 0047bc64  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0047bc67  5f                   pop edi
// 0047bc68  5e                   pop esi
// 0047bc69  64890d00000000       mov dword ptr fs:[0], ecx
// 0047bc70  5b                   pop ebx
// 0047bc71  8be5                 mov esp, ebp
// 0047bc73  5d                   pop ebp
// 0047bc74  c21000               ret 0x10
// library ogre-1.4.9/OgreMeshSerializerImpl.cpp (function __catch$?_Insert_n@?$vector@VVector3@Ogre@@V?$allocator@VVector3@Ogre@@@std@@@std@@IAEXV?$_Vector_const_iterator@VVector3@Ogre@@V?$allocator@VVector3@Ogre@@@std@@@2@IABVVector3@Ogre@@@Z$2)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.4.9 OgreMeshSerializerImpl.cpp
