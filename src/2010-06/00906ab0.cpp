// from server: 100% by auto
// roc 2010-06 00906ab0  unit: RBX::RbxParticleEmitter  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00906ab0
//
// 00906ab0  56                   push esi
// 00906ab1  8b742408             mov esi, dword ptr [esp + 8]
// 00906ab5  57                   push edi
// 00906ab6  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00906aba  3bf7                 cmp esi, edi
// 00906abc  7415                 je 0x906ad3
// 00906abe  53                   push ebx
// 00906abf  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 00906ac3  53                   push ebx
// 00906ac4  8bce                 mov ecx, esi
// 00906ac6  e885a2e1ff           call 0x720d50
// 00906acb  83c608               add esi, 8
// 00906ace  3bf7                 cmp esi, edi
// 00906ad0  75f1                 jne 0x906ac3
// 00906ad2  5b                   pop ebx
// 00906ad3  5f                   pop edi
// 00906ad4  5e                   pop esi
// 00906ad5  c3                   ret 
// library wildmagic-2-core/Geometry\WmlConvexPolygon2.cpp (function ??$_Fill@PAV?$Vector2@M@Wml@@V12@@std@@YAXPAV?$Vector2@M@Wml@@0ABV12@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Geometry/WmlConvexPolygon2.cpp
