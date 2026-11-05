// from server: 100% by auto
// roc 2008-06 00651830  unit: RBX::ScoreHud  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00651830
//
// 00651830  56                   push esi
// 00651831  8b742408             mov esi, dword ptr [esp + 8]
// 00651835  57                   push edi
// 00651836  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0065183a  3bf7                 cmp esi, edi
// 0065183c  7415                 je 0x651853
// 0065183e  53                   push ebx
// 0065183f  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 00651843  53                   push ebx
// 00651844  8bce                 mov ecx, esi
// 00651846  e805c0e3ff           call 0x48d850
// 0065184b  83c618               add esi, 0x18
// 0065184e  3bf7                 cmp esi, edi
// 00651850  75f1                 jne 0x651843
// 00651852  5b                   pop ebx
// 00651853  5f                   pop edi
// 00651854  5e                   pop esi
// 00651855  c3                   ret 
// library wildmagic-2-core/Geometry\WmlConvexClipper.cpp (function ??$_Fill@PAV?$Vector3@N@Wml@@V12@@std@@YAXPAV?$Vector3@N@Wml@@0ABV12@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Geometry/WmlConvexClipper.cpp
