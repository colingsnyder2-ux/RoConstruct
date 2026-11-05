// from server: 100% by auto
// roc 2010-06 00559d40  unit: G3D::BinaryInput  size: 68 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00559d40
//
// 00559d40  b801000000           mov eax, 1
// 00559d45  840564a0c000         test byte ptr [0xc0a064], al
// 00559d4b  7531                 jne 0x559d7e
// 00559d4d  f30f100524f6a100     movss xmm0, dword ptr [0xa1f624]
// 00559d55  090564a0c000         or dword ptr [0xc0a064], eax
// 00559d5b  f30f110558a0c000     movss dword ptr [0xc0a058], xmm0
// 00559d63  f30f1005e026a100     movss xmm0, dword ptr [0xa126e0]
// 00559d6b  f30f11055ca0c000     movss dword ptr [0xc0a05c], xmm0
// 00559d73  0f57c0               xorps xmm0, xmm0
// 00559d76  f30f110560a0c000     movss dword ptr [0xc0a060], xmm0
// 00559d7e  b858a0c000           mov eax, 0xc0a058
// 00559d83  c3                   ret 
// library rbx2016-g3d/Color3.cpp (function ?orange@Color3@G3D@@SAABV12@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Color3.cpp
