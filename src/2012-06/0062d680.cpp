// from server: 100% by auto
// roc 2012-06 0062d680  unit: G3D::Sphere  size: 100 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0062d680
//
// 0062d680  b801000000           mov eax, 1
// 0062d685  84058886e200         test byte ptr [0xe28688], al
// 0062d68b  7551                 jne 0x62d6de
// 0062d68d  0f57c0               xorps xmm0, xmm0
// 0062d690  09058886e200         or dword ptr [0xe28688], eax
// 0062d696  f30f11056486e200     movss dword ptr [0xe28664], xmm0
// 0062d69e  f30f11056886e200     movss dword ptr [0xe28668], xmm0
// 0062d6a6  f30f11056c86e200     movss dword ptr [0xe2866c], xmm0
// 0062d6ae  f30f11057086e200     movss dword ptr [0xe28670], xmm0
// 0062d6b6  f30f11057486e200     movss dword ptr [0xe28674], xmm0
// 0062d6be  f30f11057886e200     movss dword ptr [0xe28678], xmm0
// 0062d6c6  f30f11057c86e200     movss dword ptr [0xe2867c], xmm0
// 0062d6ce  f30f11058086e200     movss dword ptr [0xe28680], xmm0
// 0062d6d6  f30f11058486e200     movss dword ptr [0xe28684], xmm0
// 0062d6de  b86486e200           mov eax, 0xe28664
// 0062d6e3  c3                   ret 
// library rbx2016-g3d/Matrix3.cpp (function ?zero@Matrix3@G3D@@SAABV12@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Matrix3.cpp
