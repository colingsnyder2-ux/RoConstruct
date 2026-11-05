// from server: 100% by auto
// roc 2010-06 00556fe0  unit: seg_00550000  size: 103 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00556fe0
//
// 00556fe0  f30f10442404         movss xmm0, dword ptr [esp + 4]
// 00556fe6  8bc1                 mov eax, ecx
// 00556fe8  f30f1100             movss dword ptr [eax], xmm0
// 00556fec  f30f10442408         movss xmm0, dword ptr [esp + 8]
// 00556ff2  f30f114004           movss dword ptr [eax + 4], xmm0
// 00556ff7  f30f1044240c         movss xmm0, dword ptr [esp + 0xc]
// 00556ffd  f30f114008           movss dword ptr [eax + 8], xmm0
// 00557002  f30f10442410         movss xmm0, dword ptr [esp + 0x10]
// 00557008  f30f11400c           movss dword ptr [eax + 0xc], xmm0
// 0055700d  f30f10442414         movss xmm0, dword ptr [esp + 0x14]
// 00557013  f30f114010           movss dword ptr [eax + 0x10], xmm0
// 00557018  f30f10442418         movss xmm0, dword ptr [esp + 0x18]
// 0055701e  f30f114014           movss dword ptr [eax + 0x14], xmm0
// 00557023  f30f1044241c         movss xmm0, dword ptr [esp + 0x1c]
// 00557029  f30f114018           movss dword ptr [eax + 0x18], xmm0
// 0055702e  f30f10442420         movss xmm0, dword ptr [esp + 0x20]
// 00557034  f30f11401c           movss dword ptr [eax + 0x1c], xmm0
// 00557039  f30f10442424         movss xmm0, dword ptr [esp + 0x24]
// 0055703f  f30f114020           movss dword ptr [eax + 0x20], xmm0
// 00557044  c22400               ret 0x24
// library rbx2016-g3d/Matrix3.cpp (function ??0Matrix3@G3D@@QAE@MMMMMMMMM@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Matrix3.cpp
