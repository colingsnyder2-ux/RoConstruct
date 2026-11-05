// from server: 100% by auto
// roc 2011-06 00542880  unit: G3D::Sphere  size: 60 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00542880
//
// 00542880  b801000000           mov eax, 1
// 00542885  840548a3cb00         test byte ptr [0xcba348], al
// 0054288b  7529                 jne 0x5428b6
// 0054288d  0f57c0               xorps xmm0, xmm0
// 00542890  090548a3cb00         or dword ptr [0xcba348], eax
// 00542896  f30f11053ca3cb00     movss dword ptr [0xcba33c], xmm0
// 0054289e  f30f110540a3cb00     movss dword ptr [0xcba340], xmm0
// 005428a6  f30f1005143ba600     movss xmm0, dword ptr [0xa63b14]
// 005428ae  f30f110544a3cb00     movss dword ptr [0xcba344], xmm0
// 005428b6  b83ca3cb00           mov eax, 0xcba33c
// 005428bb  c3                   ret 
// library rbx2016-g3d/Box.cpp (function ?unitZ@Vector3@G3D@@SAABV12@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Box.cpp
