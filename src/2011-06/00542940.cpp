// from server: 100% by auto
// roc 2011-06 00542940  unit: G3D::Sphere  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00542940
//
// 00542940  b801000000           mov eax, 1
// 00542945  840568a3cb00         test byte ptr [0xcba368], al
// 0054294b  7526                 jne 0x542973
// 0054294d  f30f1005a4f5a700     movss xmm0, dword ptr [0xa7f5a4]
// 00542955  090568a3cb00         or dword ptr [0xcba368], eax
// 0054295b  f30f11055ca3cb00     movss dword ptr [0xcba35c], xmm0
// 00542963  f30f110560a3cb00     movss dword ptr [0xcba360], xmm0
// 0054296b  f30f110564a3cb00     movss dword ptr [0xcba364], xmm0
// 00542973  b85ca3cb00           mov eax, 0xcba35c
// 00542978  c3                   ret 
// library rbx2016-g3d/AABox.cpp (function ?minFinite@Vector3@G3D@@SAABV12@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d AABox.cpp
