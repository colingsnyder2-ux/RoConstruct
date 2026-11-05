// from server: 100% by auto
// roc 2012-06 0062e840  unit: G3D::Line  size: 60 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0062e840
//
// 0062e840  b801000000           mov eax, 1
// 0062e845  84050087e200         test byte ptr [0xe28700], al
// 0062e84b  7529                 jne 0x62e876
// 0062e84d  0f57c0               xorps xmm0, xmm0
// 0062e850  09050087e200         or dword ptr [0xe28700], eax
// 0062e856  f30f1105f486e200     movss dword ptr [0xe286f4], xmm0
// 0062e85e  f30f1105f886e200     movss dword ptr [0xe286f8], xmm0
// 0062e866  f30f100540c4b400     movss xmm0, dword ptr [0xb4c440]
// 0062e86e  f30f1105fc86e200     movss dword ptr [0xe286fc], xmm0
// 0062e876  b8f486e200           mov eax, 0xe286f4
// 0062e87b  c3                   ret 
// library rbx2016-g3d/Box.cpp (function ?unitZ@Vector3@G3D@@SAABV12@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Box.cpp
