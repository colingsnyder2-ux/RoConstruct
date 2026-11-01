// from server: 100% by auto
// roc 2009-12 004c0610  unit: RBX::RbxParticleEmitter  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004c0610
//
// 004c0610  56                   push esi
// 004c0611  8b742408             mov esi, dword ptr [esp + 8]
// 004c0615  57                   push edi
// 004c0616  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 004c061a  3bf7                 cmp esi, edi
// 004c061c  7415                 je 0x4c0633
// 004c061e  53                   push ebx
// 004c061f  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 004c0623  53                   push ebx
// 004c0624  8bce                 mov ecx, esi
// 004c0626  e855b40b00           call 0x57ba80
// 004c062b  83c608               add esi, 8
// 004c062e  3bf7                 cmp esi, edi
// 004c0630  75f1                 jne 0x4c0623
// 004c0632  5b                   pop ebx
// 004c0633  5f                   pop edi
// 004c0634  5e                   pop esi
// 004c0635  c3                   ret 
// library wildmagic-2-core/Geometry\WmlConvexPolygon2.cpp (function ??$_Fill@PAV?$Vector2@M@Wml@@V12@@std@@YAXPAV?$Vector2@M@Wml@@0ABV12@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Geometry/WmlConvexPolygon2.cpp
