// from server: 100% by auto
// roc 2011-06 005417a0  unit: G3D::Sphere  size: 158 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 005417a0
//
// 005417a0  8b442408             mov eax, dword ptr [esp + 8]
// 005417a4  f30f104804           movss xmm1, dword ptr [eax + 4]
// 005417a9  f30f5c4928           subss xmm1, dword ptr [ecx + 0x28]
// 005417ae  f30f105008           movss xmm2, dword ptr [eax + 8]
// 005417b3  f30f5c512c           subss xmm2, dword ptr [ecx + 0x2c]
// 005417b8  f30f105918           movss xmm3, dword ptr [ecx + 0x18]
// 005417bd  f30f10610c           movss xmm4, dword ptr [ecx + 0xc]
// 005417c2  f30f1000             movss xmm0, dword ptr [eax]
// 005417c6  f30f5c4124           subss xmm0, dword ptr [ecx + 0x24]
// 005417cb  8b442404             mov eax, dword ptr [esp + 4]
// 005417cf  f30f59da             mulss xmm3, xmm2
// 005417d3  f30f59e1             mulss xmm4, xmm1
// 005417d7  f30f58dc             addss xmm3, xmm4
// 005417db  f30f1021             movss xmm4, dword ptr [ecx]
// 005417df  f30f59e0             mulss xmm4, xmm0
// 005417e3  f30f58dc             addss xmm3, xmm4
// 005417e7  f30f106110           movss xmm4, dword ptr [ecx + 0x10]
// 005417ec  f30f1118             movss dword ptr [eax], xmm3
// 005417f0  f30f10591c           movss xmm3, dword ptr [ecx + 0x1c]
// 005417f5  f30f59da             mulss xmm3, xmm2
// 005417f9  f30f59e1             mulss xmm4, xmm1
// 005417fd  f30f58dc             addss xmm3, xmm4
// 00541801  f30f106104           movss xmm4, dword ptr [ecx + 4]
// 00541806  f30f59e0             mulss xmm4, xmm0
// 0054180a  f30f58dc             addss xmm3, xmm4
// 0054180e  f30f115804           movss dword ptr [eax + 4], xmm3
// 00541813  f30f105920           movss xmm3, dword ptr [ecx + 0x20]
// 00541818  f30f59da             mulss xmm3, xmm2
// 0054181c  f30f105114           movss xmm2, dword ptr [ecx + 0x14]
// 00541821  f30f59d1             mulss xmm2, xmm1
// 00541825  f30f104908           movss xmm1, dword ptr [ecx + 8]
// 0054182a  f30f58da             addss xmm3, xmm2
// 0054182e  f30f59c8             mulss xmm1, xmm0
// 00541832  f30f58d9             addss xmm3, xmm1
// 00541836  f30f115808           movss dword ptr [eax + 8], xmm3
// 0054183b  c20800               ret 8
// library rbx2016-g3d/CollisionDetection.cpp (function ?pointToObjectSpace@CoordinateFrame@G3D@@QBE?AVVector3@2@ABV32@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d CollisionDetection.cpp
