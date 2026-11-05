// from server: 100% by auto
// roc 2012-06 0062e940  unit: G3D::Line  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0062e940
//
// 0062e940  b801000000           mov eax, 1
// 0062e945  84053087e200         test byte ptr [0xe28730], al
// 0062e94b  7526                 jne 0x62e973
// 0062e94d  f30f10052c33b800     movss xmm0, dword ptr [0xb8332c]
// 0062e955  09053087e200         or dword ptr [0xe28730], eax
// 0062e95b  f30f11052487e200     movss dword ptr [0xe28724], xmm0
// 0062e963  f30f11052887e200     movss dword ptr [0xe28728], xmm0
// 0062e96b  f30f11052c87e200     movss dword ptr [0xe2872c], xmm0
// 0062e973  b82487e200           mov eax, 0xe28724
// 0062e978  c3                   ret 
// library rbx2016-g3d/AABox.cpp (function ?maxFinite@Vector3@G3D@@SAABV12@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d AABox.cpp
