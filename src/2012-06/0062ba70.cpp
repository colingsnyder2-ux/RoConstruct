// from server: 100% by auto
// roc 2012-06 0062ba70  unit: G3D::Sphere  size: 60 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0062ba70
//
// 0062ba70  b801000000           mov eax, 1
// 0062ba75  84057085e200         test byte ptr [0xe28570], al
// 0062ba7b  7529                 jne 0x62baa6
// 0062ba7d  0f57c0               xorps xmm0, xmm0
// 0062ba80  09057085e200         or dword ptr [0xe28570], eax
// 0062ba86  f30f11056485e200     movss dword ptr [0xe28564], xmm0
// 0062ba8e  f30f11056885e200     movss dword ptr [0xe28568], xmm0
// 0062ba96  f30f100540c4b400     movss xmm0, dword ptr [0xb4c440]
// 0062ba9e  f30f11056c85e200     movss dword ptr [0xe2856c], xmm0
// 0062baa6  b86485e200           mov eax, 0xe28564
// 0062baab  c3                   ret 
// library rbx2016-g3d/Box.cpp (function ?unitZ@Vector3@G3D@@SAABV12@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Box.cpp
