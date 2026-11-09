// from server: 100% by auto
// roc 2012-06 00634370  unit: G3D::Random  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00634370
//
// 00634370  8b442404             mov eax, dword ptr [esp + 4]
// 00634374  d9410c               fld dword ptr [ecx + 0xc]
// 00634377  d84808               fmul dword ptr [eax + 8]
// 0063437a  d94108               fld dword ptr [ecx + 8]
// 0063437d  d84804               fmul dword ptr [eax + 4]
// 00634380  dec1                 faddp st(1)
// 00634382  d94104               fld dword ptr [ecx + 4]
// 00634385  d808                 fmul dword ptr [eax]
// 00634387  dec1                 faddp st(1)
// 00634389  d86110               fsub dword ptr [ecx + 0x10]
// 0063438c  c20400               ret 4
// library rbx2016-g3d/CollisionDetection.cpp (function ?distance@Plane@G3D@@QBEMABVVector3@2@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d CollisionDetection.cpp
