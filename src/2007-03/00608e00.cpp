// from server: 100% by auto
// roc 2007-03 00608e00  unit: seg_00600000  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00608e00
//
// 00608e00  56                   push esi
// 00608e01  8b742408             mov esi, dword ptr [esp + 8]
// 00608e05  57                   push edi
// 00608e06  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00608e0a  3bf7                 cmp esi, edi
// 00608e0c  7415                 je 0x608e23
// 00608e0e  53                   push ebx
// 00608e0f  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 00608e13  53                   push ebx
// 00608e14  8bce                 mov ecx, esi
// 00608e16  e885fbffff           call 0x6089a0
// 00608e1b  83c610               add esi, 0x10
// 00608e1e  3bf7                 cmp esi, edi
// 00608e20  75f1                 jne 0x608e13
// 00608e22  5b                   pop ebx
// 00608e23  5f                   pop edi
// 00608e24  5e                   pop esi
// 00608e25  c3                   ret 
// library wildmagic-2-core/Geometry\WmlConvexClipper.cpp (function ??$_Fill@PAV?$Plane3@M@Wml@@V12@@std@@YAXPAV?$Plane3@M@Wml@@0ABV12@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Geometry/WmlConvexClipper.cpp
