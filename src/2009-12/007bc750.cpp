// from server: 100% by auto
// roc 2009-12 007bc750  unit: RBX::SpatialFilter  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007bc750
//
// 007bc750  56                   push esi
// 007bc751  8b742408             mov esi, dword ptr [esp + 8]
// 007bc755  57                   push edi
// 007bc756  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 007bc75a  3bf7                 cmp esi, edi
// 007bc75c  7415                 je 0x7bc773
// 007bc75e  53                   push ebx
// 007bc75f  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 007bc763  53                   push ebx
// 007bc764  8bce                 mov ecx, esi
// 007bc766  e8c517faff           call 0x75df30
// 007bc76b  83c618               add esi, 0x18
// 007bc76e  3bf7                 cmp esi, edi
// 007bc770  75f1                 jne 0x7bc763
// 007bc772  5b                   pop ebx
// 007bc773  5f                   pop edi
// 007bc774  5e                   pop esi
// 007bc775  c3                   ret 
// library wildmagic-2-core/Geometry\WmlConvexClipper.cpp (function ??$_Fill@PAV?$Vector3@N@Wml@@V12@@std@@YAXPAV?$Vector3@N@Wml@@0ABV12@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Geometry/WmlConvexClipper.cpp
