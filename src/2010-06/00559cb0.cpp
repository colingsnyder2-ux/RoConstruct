// from server: 100% by auto
// roc 2010-06 00559cb0  unit: G3D::BinaryInput  size: 68 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00559cb0
//
// 00559cb0  b801000000           mov eax, 1
// 00559cb5  840544a0c000         test byte ptr [0xc0a044], al
// 00559cbb  7531                 jne 0x559cee
// 00559cbd  f30f1005ec09a200     movss xmm0, dword ptr [0xa209ec]
// 00559cc5  090544a0c000         or dword ptr [0xc0a044], eax
// 00559ccb  f30f110538a0c000     movss dword ptr [0xc0a038], xmm0
// 00559cd3  0f57c0               xorps xmm0, xmm0
// 00559cd6  f30f11053ca0c000     movss dword ptr [0xc0a03c], xmm0
// 00559cde  f30f100524f6a100     movss xmm0, dword ptr [0xa1f624]
// 00559ce6  f30f110540a0c000     movss dword ptr [0xc0a040], xmm0
// 00559cee  b838a0c000           mov eax, 0xc0a038
// 00559cf3  c3                   ret 
// library rbx2016-g3d/Color3.cpp (function ?purple@Color3@G3D@@SAABV12@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Color3.cpp
