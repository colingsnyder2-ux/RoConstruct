// from server: 100% by auto
// roc 2010-06 0076fdb0  unit: RBX::ScoreHud  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0076fdb0
//
// 0076fdb0  56                   push esi
// 0076fdb1  8b742408             mov esi, dword ptr [esp + 8]
// 0076fdb5  57                   push edi
// 0076fdb6  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0076fdba  3bf7                 cmp esi, edi
// 0076fdbc  7415                 je 0x76fdd3
// 0076fdbe  53                   push ebx
// 0076fdbf  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 0076fdc3  53                   push ebx
// 0076fdc4  8bce                 mov ecx, esi
// 0076fdc6  e835abd3ff           call 0x4aa900
// 0076fdcb  83c618               add esi, 0x18
// 0076fdce  3bf7                 cmp esi, edi
// 0076fdd0  75f1                 jne 0x76fdc3
// 0076fdd2  5b                   pop ebx
// 0076fdd3  5f                   pop edi
// 0076fdd4  5e                   pop esi
// 0076fdd5  c3                   ret 
// library wildmagic-2-core/Geometry\WmlConvexClipper.cpp (function ??$_Fill@PAV?$Vector3@N@Wml@@V12@@std@@YAXPAV?$Vector3@N@Wml@@0ABV12@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Geometry/WmlConvexClipper.cpp
