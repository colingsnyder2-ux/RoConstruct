// from server: 100% by auto
// roc 2009-06 006e2b10  unit: RBX::ScoreHud  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006e2b10
//
// 006e2b10  56                   push esi
// 006e2b11  8b742408             mov esi, dword ptr [esp + 8]
// 006e2b15  57                   push edi
// 006e2b16  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 006e2b1a  3bf7                 cmp esi, edi
// 006e2b1c  7415                 je 0x6e2b33
// 006e2b1e  53                   push ebx
// 006e2b1f  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 006e2b23  53                   push ebx
// 006e2b24  8bce                 mov ecx, esi
// 006e2b26  e8856eddff           call 0x4b99b0
// 006e2b2b  83c618               add esi, 0x18
// 006e2b2e  3bf7                 cmp esi, edi
// 006e2b30  75f1                 jne 0x6e2b23
// 006e2b32  5b                   pop ebx
// 006e2b33  5f                   pop edi
// 006e2b34  5e                   pop esi
// 006e2b35  c3                   ret 
// library wildmagic-2-core/Geometry\WmlConvexClipper.cpp (function ??$_Fill@PAV?$Vector3@N@Wml@@V12@@std@@YAXPAV?$Vector3@N@Wml@@0ABV12@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Geometry/WmlConvexClipper.cpp
