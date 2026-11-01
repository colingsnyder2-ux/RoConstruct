// from server: 100% by auto
// roc 2009-06 0089d210  unit: seg_00890000  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0089d210
//
// 0089d210  a1b043a200           mov eax, dword ptr [0xa243b0]
// 0089d215  c705a843a20044eb8e00 mov dword ptr [0xa243a8], 0x8eeb44
// 0089d21f  85c0                 test eax, eax
// 0089d221  741c                 je 0x89d23f
// 0089d223  ff08                 dec dword ptr [eax]
// 0089d225  a1b043a200           mov eax, dword ptr [0xa243b0]
// 0089d22a  833800               cmp dword ptr [eax], 0
// 0089d22d  7510                 jne 0x89d23f
// 0089d22f  8b15a843a200         mov edx, dword ptr [0xa243a8]
// 0089d235  8b4204               mov eax, dword ptr [edx + 4]
// 0089d238  b9a843a200           mov ecx, 0xa243a8
// 0089d23d  ffe0                 jmp eax
// 0089d23f  c3                   ret 
// library ogre-1.6.4/OgreTextureUnitState.cpp (function ??__FnullTexPtr@?9??_getTexturePtr@TextureUnitState@Ogre@@QBEABVTexturePtr@2@I@Z@YAXXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreTextureUnitState.cpp
