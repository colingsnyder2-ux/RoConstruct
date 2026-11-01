// from server: 100% by auto
// roc 2009-12 0087c070  unit: CXTPControlGallery  size: 24 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0087c070
//
// 0087c070  8b442404             mov eax, dword ptr [esp + 4]
// 0087c074  56                   push esi
// 0087c075  50                   push eax
// 0087c076  8bf1                 mov esi, ecx
// 0087c078  e883c0f7ff           call 0x7f8100
// 0087c07d  8bce                 mov ecx, esi
// 0087c07f  e87ce3ffff           call 0x87a400
// 0087c084  5e                   pop esi
// 0087c085  c20400               ret 4
// library wildmagic-2-core/Geometry\WmlConvexPolygon2.cpp (function ?Create@?$ConvexPolygon2@M@Wml@@QAEXABV?$vector@V?$Vector2@M@Wml@@V?$allocator@V?$Vector2@M@Wml@@@std@@@std@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Geometry/WmlConvexPolygon2.cpp
