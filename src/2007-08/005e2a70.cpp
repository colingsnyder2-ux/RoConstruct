// from server: 100% by auto
// roc 2007-08 005e2a70  unit: seg_005e0000  size: 59 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005e2a70
//
// 005e2a70  83ec08               sub esp, 8
// 005e2a73  56                   push esi
// 005e2a74  8d7104               lea esi, [ecx + 4]
// 005e2a77  c70130cf7b00         mov dword ptr [ecx], 0x7bcf30
// 005e2a7d  8b4604               mov eax, dword ptr [esi + 4]
// 005e2a80  8b08                 mov ecx, dword ptr [eax]
// 005e2a82  50                   push eax
// 005e2a83  56                   push esi
// 005e2a84  51                   push ecx
// 005e2a85  56                   push esi
// 005e2a86  8d442414             lea eax, [esp + 0x14]
// 005e2a8a  50                   push eax
// 005e2a8b  8bce                 mov ecx, esi
// 005e2a8d  e8ce0ffdff           call 0x5b3a60
// 005e2a92  8b4e04               mov ecx, dword ptr [esi + 4]
// 005e2a95  51                   push ecx
// 005e2a96  e8c7d10400           call 0x62fc62
// 005e2a9b  83c404               add esp, 4
// 005e2a9e  33c0                 xor eax, eax
// 005e2aa0  894604               mov dword ptr [esi + 4], eax
// 005e2aa3  894608               mov dword ptr [esi + 8], eax
// 005e2aa6  5e                   pop esi
// 005e2aa7  83c408               add esp, 8
// 005e2aaa  c3                   ret 
// library ogre-1.4.9/OgreAlignedAllocator.cpp (function ??1Renderable@Ogre@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.4.9 OgreAlignedAllocator.cpp
