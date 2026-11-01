// from server: 100% by auto
// roc 2009-12 006ec260  unit: RBX::Ball  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006ec260
//
// 006ec260  d9442408             fld dword ptr [esp + 8]
// 006ec264  56                   push esi
// 006ec265  8b742408             mov esi, dword ptr [esp + 8]
// 006ec269  51                   push ecx
// 006ec26a  d91c24               fstp dword ptr [esp]
// 006ec26d  56                   push esi
// 006ec26e  e84d4a0c00           call 0x7b0cc0
// 006ec273  8bc6                 mov eax, esi
// 006ec275  5e                   pop esi
// 006ec276  c20800               ret 8
// library ogre-1.6.4/OgreAlignedAllocator.cpp (function ??DRay@Ogre@@QBE?AVVector3@1@M@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreAlignedAllocator.cpp
