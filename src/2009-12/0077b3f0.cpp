// from server: 100% by auto
// roc 2009-12 0077b3f0  unit: RBX::BallBallContact  size: 24 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0077b3f0
//
// 0077b3f0  8b442404             mov eax, dword ptr [esp + 4]
// 0077b3f4  56                   push esi
// 0077b3f5  50                   push eax
// 0077b3f6  8bf1                 mov esi, ecx
// 0077b3f8  e8237b0300           call 0x7b2f20
// 0077b3fd  8bce                 mov ecx, esi
// 0077b3ff  e84c4f0000           call 0x780350
// 0077b404  5e                   pop esi
// 0077b405  c20400               ret 4
// library wildmagic-2-core/Geometry\WmlConvexPolygon2.cpp (function ?Create@?$ConvexPolygon2@M@Wml@@QAEXABV?$vector@V?$Vector2@M@Wml@@V?$allocator@V?$Vector2@M@Wml@@@std@@@std@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Geometry/WmlConvexPolygon2.cpp
