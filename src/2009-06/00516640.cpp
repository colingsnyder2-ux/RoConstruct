// from server: 100% by auto
// roc 2009-06 00516640  unit: RBX::AggregateChunk  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00516640
//
// 00516640  d9442404             fld dword ptr [esp + 4]
// 00516644  d9590c               fstp dword ptr [ecx + 0xc]
// 00516647  c20400               ret 4
// library rbx2016-g3d/GCamera.cpp (function ?setFarPlaneZ@GCamera@G3D@@QAEXM@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-g3d GCamera.cpp
