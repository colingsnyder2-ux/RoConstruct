// from server: 100% by auto
// roc 2012-06 0062e7c0  unit: G3D::Line  size: 60 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0062e7c0
//
// 0062e7c0  b801000000           mov eax, 1
// 0062e7c5  8405e086e200         test byte ptr [0xe286e0], al
// 0062e7cb  7529                 jne 0x62e7f6
// 0062e7cd  f30f100540c4b400     movss xmm0, dword ptr [0xb4c440]
// 0062e7d5  0905e086e200         or dword ptr [0xe286e0], eax
// 0062e7db  f30f1105d486e200     movss dword ptr [0xe286d4], xmm0
// 0062e7e3  0f57c0               xorps xmm0, xmm0
// 0062e7e6  f30f1105d886e200     movss dword ptr [0xe286d8], xmm0
// 0062e7ee  f30f1105dc86e200     movss dword ptr [0xe286dc], xmm0
// 0062e7f6  b8d486e200           mov eax, 0xe286d4
// 0062e7fb  c3                   ret 
// library rbx2016-g3d/Box.cpp (function ?unitX@Vector3@G3D@@SAABV12@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Box.cpp
