// from server: 100% by auto
// roc 2011-06 00542980  unit: G3D::Sphere  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00542980
//
// 00542980  b801000000           mov eax, 1
// 00542985  840578a3cb00         test byte ptr [0xcba378], al
// 0054298b  7526                 jne 0x5429b3
// 0054298d  f30f1005a8f5a700     movss xmm0, dword ptr [0xa7f5a8]
// 00542995  090578a3cb00         or dword ptr [0xcba378], eax
// 0054299b  f30f11056ca3cb00     movss dword ptr [0xcba36c], xmm0
// 005429a3  f30f110570a3cb00     movss dword ptr [0xcba370], xmm0
// 005429ab  f30f110574a3cb00     movss dword ptr [0xcba374], xmm0
// 005429b3  b86ca3cb00           mov eax, 0xcba36c
// 005429b8  c3                   ret 
// library rbx2016-g3d/AABox.cpp (function ?maxFinite@Vector3@G3D@@SAABV12@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d AABox.cpp
