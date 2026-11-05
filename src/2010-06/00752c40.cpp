// from server: 100% by auto
// roc 2010-06 00752c40  unit: RBX::MotorJoint  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00752c40
//
// 00752c40  8b442404             mov eax, dword ptr [esp + 4]
// 00752c44  d9410c               fld dword ptr [ecx + 0xc]
// 00752c47  d84808               fmul dword ptr [eax + 8]
// 00752c4a  d94108               fld dword ptr [ecx + 8]
// 00752c4d  d84804               fmul dword ptr [eax + 4]
// 00752c50  dec1                 faddp st(1)
// 00752c52  d94104               fld dword ptr [ecx + 4]
// 00752c55  d808                 fmul dword ptr [eax]
// 00752c57  dec1                 faddp st(1)
// 00752c59  d86110               fsub dword ptr [ecx + 0x10]
// 00752c5c  c20400               ret 4
// library rbx2016-g3d/CollisionDetection.cpp (function ?distance@Plane@G3D@@QBEMABVVector3@2@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d CollisionDetection.cpp
