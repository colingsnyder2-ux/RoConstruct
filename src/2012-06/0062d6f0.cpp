// from server: 100% by auto
// roc 2012-06 0062d6f0  unit: G3D::Sphere  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0062d6f0
//
// 0062d6f0  b801000000           mov eax, 1
// 0062d6f5  8405b086e200         test byte ptr [0xe286b0], al
// 0062d6fb  7559                 jne 0x62d756
// 0062d6fd  0f57c0               xorps xmm0, xmm0
// 0062d700  f30f100d40c4b400     movss xmm1, dword ptr [0xb4c440]
// 0062d708  0905b086e200         or dword ptr [0xe286b0], eax
// 0062d70e  f30f110d8c86e200     movss dword ptr [0xe2868c], xmm1
// 0062d716  f30f11059086e200     movss dword ptr [0xe28690], xmm0
// 0062d71e  f30f11059486e200     movss dword ptr [0xe28694], xmm0
// 0062d726  f30f11059886e200     movss dword ptr [0xe28698], xmm0
// 0062d72e  f30f110d9c86e200     movss dword ptr [0xe2869c], xmm1
// 0062d736  f30f1105a086e200     movss dword ptr [0xe286a0], xmm0
// 0062d73e  f30f1105a486e200     movss dword ptr [0xe286a4], xmm0
// 0062d746  f30f1105a886e200     movss dword ptr [0xe286a8], xmm0
// 0062d74e  f30f110dac86e200     movss dword ptr [0xe286ac], xmm1
// 0062d756  b88c86e200           mov eax, 0xe2868c
// 0062d75b  c3                   ret 
// library rbx2016-g3d/Matrix3.cpp (function ?identity@Matrix3@G3D@@SAABV12@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Matrix3.cpp
