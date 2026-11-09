// from server: 100% by auto
// roc 2012-06 0062e740  unit: G3D::Line  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0062e740
//
// 0062e740  b801000000           mov eax, 1
// 0062e745  8405c086e200         test byte ptr [0xe286c0], al
// 0062e74b  7521                 jne 0x62e76e
// 0062e74d  0f57c0               xorps xmm0, xmm0
// 0062e750  0905c086e200         or dword ptr [0xe286c0], eax
// 0062e756  f30f1105b486e200     movss dword ptr [0xe286b4], xmm0
// 0062e75e  f30f1105b886e200     movss dword ptr [0xe286b8], xmm0
// 0062e766  f30f1105bc86e200     movss dword ptr [0xe286bc], xmm0
// 0062e76e  b8b486e200           mov eax, 0xe286b4
// 0062e773  c3                   ret 
// library rbx2016-g3d/AABox.cpp (function ?zero@Vector3@G3D@@SAABV12@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d AABox.cpp
