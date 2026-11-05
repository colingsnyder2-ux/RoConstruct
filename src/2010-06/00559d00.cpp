// from server: 100% by auto
// roc 2010-06 00559d00  unit: G3D::BinaryInput  size: 60 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00559d00
//
// 00559d00  b801000000           mov eax, 1
// 00559d05  840554a0c000         test byte ptr [0xc0a054], al
// 00559d0b  7529                 jne 0x559d36
// 00559d0d  f30f100524f6a100     movss xmm0, dword ptr [0xa1f624]
// 00559d15  090554a0c000         or dword ptr [0xc0a054], eax
// 00559d1b  f30f110548a0c000     movss dword ptr [0xc0a048], xmm0
// 00559d23  f30f11054ca0c000     movss dword ptr [0xc0a04c], xmm0
// 00559d2b  0f57c0               xorps xmm0, xmm0
// 00559d2e  f30f110550a0c000     movss dword ptr [0xc0a050], xmm0
// 00559d36  b848a0c000           mov eax, 0xc0a048
// 00559d3b  c3                   ret 
// library rbx2016-g3d/Color3.cpp (function ?yellow@Color3@G3D@@SAABV12@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Color3.cpp
