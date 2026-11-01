// from server: 100% by auto
// roc 2009-12 005f3990  unit: seg_005f0000  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 005f3990
//
// 005f3990  8b542408             mov edx, dword ptr [esp + 8]
// 005f3994  8b442404             mov eax, dword ptr [esp + 4]
// 005f3998  d90491               fld dword ptr [ecx + edx*4]
// 005f399b  d918                 fstp dword ptr [eax]
// 005f399d  d944910c             fld dword ptr [ecx + edx*4 + 0xc]
// 005f39a1  d95804               fstp dword ptr [eax + 4]
// 005f39a4  d9449118             fld dword ptr [ecx + edx*4 + 0x18]
// 005f39a8  d95808               fstp dword ptr [eax + 8]
// 005f39ab  c20800               ret 8
// library ogre-1.6.4/OgreMatrix3.cpp (function ?GetColumn@Matrix3@Ogre@@QBE?AVVector3@2@I@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreMatrix3.cpp
