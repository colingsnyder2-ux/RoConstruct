// from server: 100% by auto
// roc 2012-06 0062ba30  unit: G3D::Sphere  size: 60 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0062ba30
//
// 0062ba30  b801000000           mov eax, 1
// 0062ba35  84056085e200         test byte ptr [0xe28560], al
// 0062ba3b  7529                 jne 0x62ba66
// 0062ba3d  0f57c0               xorps xmm0, xmm0
// 0062ba40  f30f100d40c4b400     movss xmm1, dword ptr [0xb4c440]
// 0062ba48  09056085e200         or dword ptr [0xe28560], eax
// 0062ba4e  f30f11055485e200     movss dword ptr [0xe28554], xmm0
// 0062ba56  f30f110d5885e200     movss dword ptr [0xe28558], xmm1
// 0062ba5e  f30f11055c85e200     movss dword ptr [0xe2855c], xmm0
// 0062ba66  b85485e200           mov eax, 0xe28554
// 0062ba6b  c3                   ret 
// library rbx2016-g3d/Box.cpp (function ?unitY@Vector3@G3D@@SAABV12@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Box.cpp
