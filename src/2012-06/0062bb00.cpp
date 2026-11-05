// from server: 100% by auto
// roc 2012-06 0062bb00  unit: G3D::Sphere  size: 68 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0062bb00
//
// 0062bb00  b801000000           mov eax, 1
// 0062bb05  84059085e200         test byte ptr [0xe28590], al
// 0062bb0b  7531                 jne 0x62bb3e
// 0062bb0d  0f57c0               xorps xmm0, xmm0
// 0062bb10  09059085e200         or dword ptr [0xe28590], eax
// 0062bb16  f30f11058485e200     movss dword ptr [0xe28584], xmm0
// 0062bb1e  f30f10054c85b600     movss xmm0, dword ptr [0xb6854c]
// 0062bb26  f30f11058885e200     movss dword ptr [0xe28588], xmm0
// 0062bb2e  f30f100540c4b400     movss xmm0, dword ptr [0xb4c440]
// 0062bb36  f30f11058c85e200     movss dword ptr [0xe2858c], xmm0
// 0062bb3e  b88485e200           mov eax, 0xe28584
// 0062bb43  c3                   ret 
// library rbx2016-g3d/Color3.cpp (function ?cyan@Color3@G3D@@SAABV12@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Color3.cpp
