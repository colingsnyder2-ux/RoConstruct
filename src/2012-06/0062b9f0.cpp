// from server: 100% by auto
// roc 2012-06 0062b9f0  unit: G3D::Sphere  size: 60 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0062b9f0
//
// 0062b9f0  b801000000           mov eax, 1
// 0062b9f5  84055085e200         test byte ptr [0xe28550], al
// 0062b9fb  7529                 jne 0x62ba26
// 0062b9fd  f30f100540c4b400     movss xmm0, dword ptr [0xb4c440]
// 0062ba05  09055085e200         or dword ptr [0xe28550], eax
// 0062ba0b  f30f11054485e200     movss dword ptr [0xe28544], xmm0
// 0062ba13  0f57c0               xorps xmm0, xmm0
// 0062ba16  f30f11054885e200     movss dword ptr [0xe28548], xmm0
// 0062ba1e  f30f11054c85e200     movss dword ptr [0xe2854c], xmm0
// 0062ba26  b84485e200           mov eax, 0xe28544
// 0062ba2b  c3                   ret 
// library rbx2016-g3d/Box.cpp (function ?unitX@Vector3@G3D@@SAABV12@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Box.cpp
