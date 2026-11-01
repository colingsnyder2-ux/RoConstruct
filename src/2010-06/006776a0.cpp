// from server: 100% by auto
// roc 2010-06 006776a0  unit: RBX::Geometry  size: 24 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 006776a0
//
// 006776a0  8b442404             mov eax, dword ptr [esp + 4]
// 006776a4  d900                 fld dword ptr [eax]
// 006776a6  d95904               fstp dword ptr [ecx + 4]
// 006776a9  d94004               fld dword ptr [eax + 4]
// 006776ac  d95908               fstp dword ptr [ecx + 8]
// 006776af  d94008               fld dword ptr [eax + 8]
// 006776b2  d9590c               fstp dword ptr [ecx + 0xc]
// 006776b5  c20400               ret 4
// library ogre-1.6.4/OgreAlignedAllocator.cpp (function ?setCenter@Sphere@Ogre@@QAEXABVVector3@2@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
// roc-lib: ogre-1.6.4 OgreAlignedAllocator.cpp
