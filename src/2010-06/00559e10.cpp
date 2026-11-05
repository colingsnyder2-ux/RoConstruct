// from server: 100% by auto
// roc 2010-06 00559e10  unit: G3D::BinaryInput  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00559e10
//
// 00559e10  b801000000           mov eax, 1
// 00559e15  840594a0c000         test byte ptr [0xc0a094], al
// 00559e1b  7526                 jne 0x559e43
// 00559e1d  f30f100524f6a100     movss xmm0, dword ptr [0xa1f624]
// 00559e25  090594a0c000         or dword ptr [0xc0a094], eax
// 00559e2b  f30f110588a0c000     movss dword ptr [0xc0a088], xmm0
// 00559e33  f30f11058ca0c000     movss dword ptr [0xc0a08c], xmm0
// 00559e3b  f30f110590a0c000     movss dword ptr [0xc0a090], xmm0
// 00559e43  b888a0c000           mov eax, 0xc0a088
// 00559e48  c3                   ret 
// library rbx2016-g3d/Color3.cpp (function ?one@Color3@G3D@@SAABV12@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Color3.cpp
