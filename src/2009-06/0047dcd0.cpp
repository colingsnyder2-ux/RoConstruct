// from server: 100% by auto
// roc 2009-06 0047dcd0  unit: Ogre::RbxPart  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0047dcd0
//
// 0047dcd0  56                   push esi
// 0047dcd1  8b742408             mov esi, dword ptr [esp + 8]
// 0047dcd5  57                   push edi
// 0047dcd6  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0047dcda  3bf7                 cmp esi, edi
// 0047dcdc  7415                 je 0x47dcf3
// 0047dcde  53                   push ebx
// 0047dcdf  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 0047dce3  53                   push ebx
// 0047dce4  8bce                 mov ecx, esi
// 0047dce6  e8a52f1900           call 0x610c90
// 0047dceb  83c608               add esi, 8
// 0047dcee  3bf7                 cmp esi, edi
// 0047dcf0  75f1                 jne 0x47dce3
// 0047dcf2  5b                   pop ebx
// 0047dcf3  5f                   pop edi
// 0047dcf4  5e                   pop esi
// 0047dcf5  c3                   ret 
// library wildmagic-2-core/Geometry\WmlConvexPolygon2.cpp (function ??$_Fill@PAV?$Vector2@M@Wml@@V12@@std@@YAXPAV?$Vector2@M@Wml@@0ABV12@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Geometry/WmlConvexPolygon2.cpp
