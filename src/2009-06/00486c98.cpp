// roc 2009-06 00486c98  unit: Ogre::RbxMeshPartAdapter  size: 232 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00486c98
//
// 00486c98  6a00                 push 0
// 00486c9a  6a00                 push 0
// 00486c9c  e8a92d2900           call 0x719a4a
// 00486ca1  8b450c               mov eax, dword ptr [ebp + 0xc]
// 00486ca4  8bcb                 mov ecx, ebx
// 00486ca6  2bc8                 sub ecx, eax
// 00486ca8  c1f903               sar ecx, 3
// 00486cab  3bcf                 cmp ecx, edi
// 00486cad  7374                 jae 0x486d23
// 00486caf  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 00486cb2  d901                 fld dword ptr [ecx]
// 00486cb4  d95de8               fstp dword ptr [ebp - 0x18]
// 00486cb7  d94104               fld dword ptr [ecx + 4]
// 00486cba  8d0cfd00000000       lea ecx, [edi*8]
// 00486cc1  894d14               mov dword ptr [ebp + 0x14], ecx
// 00486cc4  d95dec               fstp dword ptr [ebp - 0x14]
// 00486cc7  03c8                 add ecx, eax
// 00486cc9  51                   push ecx
// 00486cca  53                   push ebx
// 00486ccb  50                   push eax
// 00486ccc  8bce                 mov ecx, esi
// 00486cce  e84dfbffff           call 0x486820
// 00486cd3  8b4610               mov eax, dword ptr [esi + 0x10]
// 00486cd6  8bc8                 mov ecx, eax
// 00486cd8  2b4d0c               sub ecx, dword ptr [ebp + 0xc]
// 00486cdb  8d55e8               lea edx, [ebp - 0x18]
// 00486cde  c1f903               sar ecx, 3
// 00486ce1  52                   push edx
// 00486ce2  2bf9                 sub edi, ecx
// 00486ce4  57                   push edi
// 00486ce5  50                   push eax
// 00486ce6  8bce                 mov ecx, esi
// 00486ce8  c745fc02000000       mov dword ptr [ebp - 4], 2
// 00486cef  e87cfaffff           call 0x486770
// 00486cf4  8b4514               mov eax, dword ptr [ebp + 0x14]
// 00486cf7  014610               add dword ptr [esi + 0x10], eax
// 00486cfa  8b7610               mov esi, dword ptr [esi + 0x10]
// 00486cfd  8d55e8               lea edx, [ebp - 0x18]
// 00486d00  52                   push edx
// 00486d01  2bf0                 sub esi, eax
// 00486d03  8b450c               mov eax, dword ptr [ebp + 0xc]
// 00486d06  56                   push esi
// 00486d07  50                   push eax
// 00486d08  e8b3f6ffff           call 0x4863c0
// 00486d0d  83c40c               add esp, 0xc
// 00486d10  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00486d13  64890d00000000       mov dword ptr fs:[0], ecx
// 00486d1a  5f                   pop edi
// 00486d1b  5e                   pop esi
// 00486d1c  5b                   pop ebx
// 00486d1d  8be5                 mov esp, ebp
// 00486d1f  5d                   pop ebp
// 00486d20  c21000               ret 0x10
// 00486d23  8b4514               mov eax, dword ptr [ebp + 0x14]
// 00486d26  d900                 fld dword ptr [eax]
// 00486d28  53                   push ebx
// 00486d29  d95de8               fstp dword ptr [ebp - 0x18]
// 00486d2c  53                   push ebx
// 00486d2d  d94004               fld dword ptr [eax + 4]
// 00486d30  8d04fd00000000       lea eax, [edi*8]
// 00486d37  8bfb                 mov edi, ebx
// 00486d39  d95dec               fstp dword ptr [ebp - 0x14]
// 00486d3c  2bf8                 sub edi, eax
// 00486d3e  57                   push edi
// 00486d3f  8bce                 mov ecx, esi
// 00486d41  894514               mov dword ptr [ebp + 0x14], eax
// 00486d44  e8d7faffff           call 0x486820
// 00486d49  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 00486d4c  53                   push ebx
// 00486d4d  57                   push edi
// 00486d4e  51                   push ecx
// 00486d4f  894610               mov dword ptr [esi + 0x10], eax
// 00486d52  e8a9f9ffff           call 0x486700
// 00486d57  8b450c               mov eax, dword ptr [ebp + 0xc]
// 00486d5a  8b4d14               mov ecx, dword ptr [ebp + 0x14]
// 00486d5d  8d55e8               lea edx, [ebp - 0x18]
// 00486d60  52                   push edx
// 00486d61  03c8                 add ecx, eax
// 00486d63  51                   push ecx
// 00486d64  50                   push eax
// 00486d65  e856f6ffff           call 0x4863c0
// 00486d6a  83c418               add esp, 0x18
// 00486d6d  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00486d70  5f                   pop edi
// 00486d71  5e                   pop esi
// 00486d72  64890d00000000       mov dword ptr fs:[0], ecx
// 00486d79  5b                   pop ebx
// 00486d7a  8be5                 mov esp, ebp
// 00486d7c  5d                   pop ebp
// 00486d7d  c21000               ret 0x10
// library ogre-1.4.9/OgreShadowCameraSetupPlaneOptimal.cpp (function __catch$?_Insert_n@?$vector@VVector2@Ogre@@V?$allocator@VVector2@Ogre@@@std@@@std@@IAEXV?$_Vector_const_iterator@VVector2@Ogre@@V?$allocator@VVector2@Ogre@@@std@@@2@IABVVector2@Ogre@@@Z$2)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.4.9 OgreShadowCameraSetupPlaneOptimal.cpp
