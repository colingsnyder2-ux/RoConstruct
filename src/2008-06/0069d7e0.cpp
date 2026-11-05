// from server: 100% by auto
// roc 2008-06 0069d7e0  unit: Ogre::RbxSceneManager  size: 93 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0069d7e0
//
// 0069d7e0  53                   push ebx
// 0069d7e1  55                   push ebp
// 0069d7e2  8b6c240c             mov ebp, dword ptr [esp + 0xc]
// 0069d7e6  56                   push esi
// 0069d7e7  8bf1                 mov esi, ecx
// 0069d7e9  8b96688a0000         mov edx, dword ptr [esi + 0x8a68]
// 0069d7ef  2b96648a0000         sub edx, dword ptr [esi + 0x8a64]
// 0069d7f5  8d8e588a0000         lea ecx, [esi + 0x8a58]
// 0069d7fb  b8abaaaa2a           mov eax, 0x2aaaaaab
// 0069d800  f7ea                 imul edx
// 0069d802  d1fa                 sar edx, 1
// 0069d804  8bc2                 mov eax, edx
// 0069d806  c1e81f               shr eax, 0x1f
// 0069d809  03c2                 add eax, edx
// 0069d80b  57                   push edi
// 0069d80c  3be8                 cmp ebp, eax
// 0069d80e  7426                 je 0x69d836
// 0069d810  83ec0c               sub esp, 0xc
// 0069d813  8bc4                 mov eax, esp
// 0069d815  ba00020000           mov edx, 0x200
// 0069d81a  8bfa                 mov edi, edx
// 0069d81c  8910                 mov dword ptr [eax], edx
// 0069d81e  bb1a000000           mov ebx, 0x1a
// 0069d823  897804               mov dword ptr [eax + 4], edi
// 0069d826  55                   push ebp
// 0069d827  895808               mov dword ptr [eax + 8], ebx
// 0069d82a  e841d8ffff           call 0x69b070
// 0069d82f  c686708a000001       mov byte ptr [esi + 0x8a70], 1
// 0069d836  5f                   pop edi
// 0069d837  5e                   pop esi
// 0069d838  5d                   pop ebp
// 0069d839  5b                   pop ebx
// 0069d83a  c20400               ret 4
// library ogre-1.4.9/OgreSceneManager.cpp (function ?setShadowTextureCount@SceneManager@Ogre@@UAEXI@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.4.9 OgreSceneManager.cpp
