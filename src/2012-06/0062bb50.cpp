// from server: 100% by auto
// roc 2012-06 0062bb50  unit: G3D::Sphere  size: 60 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0062bb50
//
// 0062bb50  b801000000           mov eax, 1
// 0062bb55  8405a085e200         test byte ptr [0xe285a0], al
// 0062bb5b  7529                 jne 0x62bb86
// 0062bb5d  f30f100540c4b400     movss xmm0, dword ptr [0xb4c440]
// 0062bb65  0905a085e200         or dword ptr [0xe285a0], eax
// 0062bb6b  f30f11059485e200     movss dword ptr [0xe28594], xmm0
// 0062bb73  f30f11059885e200     movss dword ptr [0xe28598], xmm0
// 0062bb7b  0f57c0               xorps xmm0, xmm0
// 0062bb7e  f30f11059c85e200     movss dword ptr [0xe2859c], xmm0
// 0062bb86  b89485e200           mov eax, 0xe28594
// 0062bb8b  c3                   ret 
// library rbx2016-g3d/Color3.cpp (function ?yellow@Color3@G3D@@SAABV12@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Color3.cpp
