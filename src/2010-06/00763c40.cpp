// from server: 100% by auto
// roc 2010-06 00763c40  unit: RBX::Assembly  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00763c40
//
// 00763c40  56                   push esi
// 00763c41  8b742408             mov esi, dword ptr [esp + 8]
// 00763c45  57                   push edi
// 00763c46  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00763c4a  3bf7                 cmp esi, edi
// 00763c4c  7415                 je 0x763c63
// 00763c4e  53                   push ebx
// 00763c4f  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 00763c53  53                   push ebx
// 00763c54  8bce                 mov ecx, esi
// 00763c56  e8e50ef8ff           call 0x6e4b40
// 00763c5b  83c618               add esi, 0x18
// 00763c5e  3bf7                 cmp esi, edi
// 00763c60  75f1                 jne 0x763c53
// 00763c62  5b                   pop ebx
// 00763c63  5f                   pop edi
// 00763c64  5e                   pop esi
// 00763c65  c3                   ret 
// library wildmagic-2-core/Geometry\WmlConvexClipper.cpp (function ??$_Fill@PAV?$Vector3@N@Wml@@V12@@std@@YAXPAV?$Vector3@N@Wml@@0ABV12@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Geometry/WmlConvexClipper.cpp
