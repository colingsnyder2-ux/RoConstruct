// from server: 100% by auto
// roc 2010-06 00556090  unit: seg_00550000  size: 101 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00556090
//
// 00556090  f30f10442404         movss xmm0, dword ptr [esp + 4]
// 00556096  f30f1101             movss dword ptr [ecx], xmm0
// 0055609a  f30f10442408         movss xmm0, dword ptr [esp + 8]
// 005560a0  f30f114104           movss dword ptr [ecx + 4], xmm0
// 005560a5  f30f1044240c         movss xmm0, dword ptr [esp + 0xc]
// 005560ab  f30f114108           movss dword ptr [ecx + 8], xmm0
// 005560b0  f30f10442410         movss xmm0, dword ptr [esp + 0x10]
// 005560b6  f30f11410c           movss dword ptr [ecx + 0xc], xmm0
// 005560bb  f30f10442414         movss xmm0, dword ptr [esp + 0x14]
// 005560c1  f30f114110           movss dword ptr [ecx + 0x10], xmm0
// 005560c6  f30f10442418         movss xmm0, dword ptr [esp + 0x18]
// 005560cc  f30f114114           movss dword ptr [ecx + 0x14], xmm0
// 005560d1  f30f1044241c         movss xmm0, dword ptr [esp + 0x1c]
// 005560d7  f30f114118           movss dword ptr [ecx + 0x18], xmm0
// 005560dc  f30f10442420         movss xmm0, dword ptr [esp + 0x20]
// 005560e2  f30f11411c           movss dword ptr [ecx + 0x1c], xmm0
// 005560e7  f30f10442424         movss xmm0, dword ptr [esp + 0x24]
// 005560ed  f30f114120           movss dword ptr [ecx + 0x20], xmm0
// 005560f2  c22400               ret 0x24
// library rbx2016-g3d/Matrix3.cpp (function ?set@Matrix3@G3D@@QAEXMMMMMMMMM@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Matrix3.cpp
