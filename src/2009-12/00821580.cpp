// from server: 100% by auto
// roc 2009-12 00821580  unit: CXTPReportControl  size: 24 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00821580
//
// 00821580  8b442404             mov eax, dword ptr [esp + 4]
// 00821584  56                   push esi
// 00821585  50                   push eax
// 00821586  8bf1                 mov esi, ecx
// 00821588  e80131fdff           call 0x7f468e
// 0082158d  8bce                 mov ecx, esi
// 0082158f  e8ecdeffff           call 0x81f480
// 00821594  5e                   pop esi
// 00821595  c20400               ret 4
// library wildmagic-2-core/Geometry\WmlConvexPolygon2.cpp (function ?Create@?$ConvexPolygon2@M@Wml@@QAEXABV?$vector@V?$Vector2@M@Wml@@V?$allocator@V?$Vector2@M@Wml@@@std@@@std@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Geometry/WmlConvexPolygon2.cpp
