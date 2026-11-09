// from server: 100% by auto
// roc 2012-06 0062d3b0  unit: G3D::Sphere  size: 103 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0062d3b0
//
// 0062d3b0  f30f10442404         movss xmm0, dword ptr [esp + 4]
// 0062d3b6  8bc1                 mov eax, ecx
// 0062d3b8  f30f1100             movss dword ptr [eax], xmm0
// 0062d3bc  f30f10442408         movss xmm0, dword ptr [esp + 8]
// 0062d3c2  f30f114004           movss dword ptr [eax + 4], xmm0
// 0062d3c7  f30f1044240c         movss xmm0, dword ptr [esp + 0xc]
// 0062d3cd  f30f114008           movss dword ptr [eax + 8], xmm0
// 0062d3d2  f30f10442410         movss xmm0, dword ptr [esp + 0x10]
// 0062d3d8  f30f11400c           movss dword ptr [eax + 0xc], xmm0
// 0062d3dd  f30f10442414         movss xmm0, dword ptr [esp + 0x14]
// 0062d3e3  f30f114010           movss dword ptr [eax + 0x10], xmm0
// 0062d3e8  f30f10442418         movss xmm0, dword ptr [esp + 0x18]
// 0062d3ee  f30f114014           movss dword ptr [eax + 0x14], xmm0
// 0062d3f3  f30f1044241c         movss xmm0, dword ptr [esp + 0x1c]
// 0062d3f9  f30f114018           movss dword ptr [eax + 0x18], xmm0
// 0062d3fe  f30f10442420         movss xmm0, dword ptr [esp + 0x20]
// 0062d404  f30f11401c           movss dword ptr [eax + 0x1c], xmm0
// 0062d409  f30f10442424         movss xmm0, dword ptr [esp + 0x24]
// 0062d40f  f30f114020           movss dword ptr [eax + 0x20], xmm0
// 0062d414  c22400               ret 0x24
// library rbx2016-g3d/Matrix3.cpp (function ??0Matrix3@G3D@@QAE@MMMMMMMMM@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Matrix3.cpp
