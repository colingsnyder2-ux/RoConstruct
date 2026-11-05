// from server: 100% by auto
// roc 2012-06 0062bc20  unit: G3D::Sphere  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0062bc20
//
// 0062bc20  b801000000           mov eax, 1
// 0062bc25  8405d085e200         test byte ptr [0xe285d0], al
// 0062bc2b  7521                 jne 0x62bc4e
// 0062bc2d  0f57c0               xorps xmm0, xmm0
// 0062bc30  0905d085e200         or dword ptr [0xe285d0], eax
// 0062bc36  f30f1105c485e200     movss dword ptr [0xe285c4], xmm0
// 0062bc3e  f30f1105c885e200     movss dword ptr [0xe285c8], xmm0
// 0062bc46  f30f1105cc85e200     movss dword ptr [0xe285cc], xmm0
// 0062bc4e  b8c485e200           mov eax, 0xe285c4
// 0062bc53  c3                   ret 
// library rbx2016-g3d/AABox.cpp (function ?zero@Vector3@G3D@@SAABV12@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d AABox.cpp
