// from server: 100% by auto
// roc 2010-06 005bd890  unit: RBX::PartInstance  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005bd890
//
// 005bd890  b801000000           mov eax, 1
// 005bd895  8405f081c100         test byte ptr [0xc181f0], al
// 005bd89b  7526                 jne 0x5bd8c3
// 005bd89d  f30f100524f6a100     movss xmm0, dword ptr [0xa1f624]
// 005bd8a5  0905f081c100         or dword ptr [0xc181f0], eax
// 005bd8ab  f30f1105e481c100     movss dword ptr [0xc181e4], xmm0
// 005bd8b3  f30f1105e881c100     movss dword ptr [0xc181e8], xmm0
// 005bd8bb  f30f1105ec81c100     movss dword ptr [0xc181ec], xmm0
// 005bd8c3  b8e481c100           mov eax, 0xc181e4
// 005bd8c8  c3                   ret 
// library rbx2016-g3d/Color3.cpp (function ?one@Color3@G3D@@SAABV12@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Color3.cpp
