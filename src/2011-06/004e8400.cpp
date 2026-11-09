// from server: 100% by auto
// roc 2011-06 004e8400  unit: RBX::Network::PhysicsSender::Job  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 004e8400
//
// 004e8400  f30f10442404         movss xmm0, dword ptr [esp + 4]
// 004e8406  f30f1009             movss xmm1, dword ptr [ecx]
// 004e840a  f30f59c8             mulss xmm1, xmm0
// 004e840e  8bc2                 mov eax, edx
// 004e8410  f30f1108             movss dword ptr [eax], xmm1
// 004e8414  f30f104904           movss xmm1, dword ptr [ecx + 4]
// 004e8419  f30f59c8             mulss xmm1, xmm0
// 004e841d  f30f114804           movss dword ptr [eax + 4], xmm1
// 004e8422  f30f104908           movss xmm1, dword ptr [ecx + 8]
// 004e8427  f30f59c8             mulss xmm1, xmm0
// 004e842b  f30f114808           movss dword ptr [eax + 8], xmm1
// 004e8430  c20400               ret 4
// library rbx2016-g3d/AABox.cpp (function ??DVector3@G3D@@QBI?AV01@M@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d AABox.cpp
