// from server: 100% by auto
// roc 2007-03 0071e550  unit: seg_00710000  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0071e550
//
// 0071e550  8b442404             mov eax, dword ptr [esp + 4]
// 0071e554  50                   push eax
// 0071e555  51                   push ecx
// 0071e556  e845e8f4ff           call 0x66cda0
// 0071e55b  83c408               add esp, 8
// 0071e55e  c20400               ret 4
// library ogre-1.6.4/OgreAlignedAllocator.cpp (function ?intersects@Sphere@Ogre@@QBE_NABVAxisAlignedBox@2@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreAlignedAllocator.cpp
