// from server: 100% by auto
// roc 2012-06 0062e900  unit: G3D::Line  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0062e900
//
// 0062e900  b801000000           mov eax, 1
// 0062e905  84052087e200         test byte ptr [0xe28720], al
// 0062e90b  7526                 jne 0x62e933
// 0062e90d  f30f10052833b800     movss xmm0, dword ptr [0xb83328]
// 0062e915  09052087e200         or dword ptr [0xe28720], eax
// 0062e91b  f30f11051487e200     movss dword ptr [0xe28714], xmm0
// 0062e923  f30f11051887e200     movss dword ptr [0xe28718], xmm0
// 0062e92b  f30f11051c87e200     movss dword ptr [0xe2871c], xmm0
// 0062e933  b81487e200           mov eax, 0xe28714
// 0062e938  c3                   ret 
// library rbx2016-g3d/AABox.cpp (function ?minFinite@Vector3@G3D@@SAABV12@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d AABox.cpp
