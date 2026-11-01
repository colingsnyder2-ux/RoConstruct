// from server: 100% by auto
// roc 2009-12 006ec210  unit: RBX::Block  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006ec210
//
// 006ec210  d9442408             fld dword ptr [esp + 8]
// 006ec214  56                   push esi
// 006ec215  8b742408             mov esi, dword ptr [esp + 8]
// 006ec219  51                   push ecx
// 006ec21a  d91c24               fstp dword ptr [esp]
// 006ec21d  56                   push esi
// 006ec21e  e8dd2c0c00           call 0x7aef00
// 006ec223  8bc6                 mov eax, esi
// 006ec225  5e                   pop esi
// 006ec226  c20800               ret 8
// library ogre-1.6.4/OgreAlignedAllocator.cpp (function ??DRay@Ogre@@QBE?AVVector3@1@M@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreAlignedAllocator.cpp
