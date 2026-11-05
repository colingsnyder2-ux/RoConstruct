// from server: 100% by auto
// roc 2011-06 00563a20  unit: G3D::Random  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00563a20
//
// 00563a20  8b442404             mov eax, dword ptr [esp + 4]
// 00563a24  d9410c               fld dword ptr [ecx + 0xc]
// 00563a27  d84808               fmul dword ptr [eax + 8]
// 00563a2a  d94108               fld dword ptr [ecx + 8]
// 00563a2d  d84804               fmul dword ptr [eax + 4]
// 00563a30  dec1                 faddp st(1)
// 00563a32  d94104               fld dword ptr [ecx + 4]
// 00563a35  d808                 fmul dword ptr [eax]
// 00563a37  dec1                 faddp st(1)
// 00563a39  d86110               fsub dword ptr [ecx + 0x10]
// 00563a3c  c20400               ret 4
// library rbx2016-g3d/CollisionDetection.cpp (function ?distance@Plane@G3D@@QBEMABVVector3@2@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d CollisionDetection.cpp
