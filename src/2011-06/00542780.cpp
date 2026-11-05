// from server: 100% by auto
// roc 2011-06 00542780  unit: G3D::Sphere  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00542780
//
// 00542780  b801000000           mov eax, 1
// 00542785  840508a3cb00         test byte ptr [0xcba308], al
// 0054278b  7521                 jne 0x5427ae
// 0054278d  0f57c0               xorps xmm0, xmm0
// 00542790  090508a3cb00         or dword ptr [0xcba308], eax
// 00542796  f30f1105fca2cb00     movss dword ptr [0xcba2fc], xmm0
// 0054279e  f30f110500a3cb00     movss dword ptr [0xcba300], xmm0
// 005427a6  f30f110504a3cb00     movss dword ptr [0xcba304], xmm0
// 005427ae  b8fca2cb00           mov eax, 0xcba2fc
// 005427b3  c3                   ret 
// library rbx2016-g3d/AABox.cpp (function ?zero@Vector3@G3D@@SAABV12@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d AABox.cpp
