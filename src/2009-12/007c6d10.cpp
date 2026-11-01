// from server: 100% by auto
// roc 2009-12 007c6d10  unit: RBX::ScoreHud  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007c6d10
//
// 007c6d10  56                   push esi
// 007c6d11  8b742408             mov esi, dword ptr [esp + 8]
// 007c6d15  57                   push edi
// 007c6d16  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 007c6d1a  3bf7                 cmp esi, edi
// 007c6d1c  7415                 je 0x7c6d33
// 007c6d1e  53                   push ebx
// 007c6d1f  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 007c6d23  53                   push ebx
// 007c6d24  8bce                 mov ecx, esi
// 007c6d26  e89565d3ff           call 0x4fd2c0
// 007c6d2b  83c618               add esi, 0x18
// 007c6d2e  3bf7                 cmp esi, edi
// 007c6d30  75f1                 jne 0x7c6d23
// 007c6d32  5b                   pop ebx
// 007c6d33  5f                   pop edi
// 007c6d34  5e                   pop esi
// 007c6d35  c3                   ret 
// library wildmagic-2-core/Geometry\WmlConvexClipper.cpp (function ??$_Fill@PAV?$Vector3@N@Wml@@V12@@std@@YAXPAV?$Vector3@N@Wml@@0ABV12@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Geometry/WmlConvexClipper.cpp
