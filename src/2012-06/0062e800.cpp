// from server: 100% by auto
// roc 2012-06 0062e800  unit: G3D::Line  size: 60 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0062e800
//
// 0062e800  b801000000           mov eax, 1
// 0062e805  8405f086e200         test byte ptr [0xe286f0], al
// 0062e80b  7529                 jne 0x62e836
// 0062e80d  0f57c0               xorps xmm0, xmm0
// 0062e810  f30f100d40c4b400     movss xmm1, dword ptr [0xb4c440]
// 0062e818  0905f086e200         or dword ptr [0xe286f0], eax
// 0062e81e  f30f1105e486e200     movss dword ptr [0xe286e4], xmm0
// 0062e826  f30f110de886e200     movss dword ptr [0xe286e8], xmm1
// 0062e82e  f30f1105ec86e200     movss dword ptr [0xe286ec], xmm0
// 0062e836  b8e486e200           mov eax, 0xe286e4
// 0062e83b  c3                   ret 
// library rbx2016-g3d/Box.cpp (function ?unitY@Vector3@G3D@@SAABV12@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Box.cpp
