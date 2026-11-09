// from server: 100% by auto
// roc 2010-06 00543d20  unit: RBX::RbxG3D::RenderScene  size: 60 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00543d20
//
// 00543d20  b801000000           mov eax, 1
// 00543d25  84052891c000         test byte ptr [0xc09128], al
// 00543d2b  7529                 jne 0x543d56
// 00543d2d  0f57c0               xorps xmm0, xmm0
// 00543d30  f30f100d24f6a100     movss xmm1, dword ptr [0xa1f624]
// 00543d38  09052891c000         or dword ptr [0xc09128], eax
// 00543d3e  f30f11051c91c000     movss dword ptr [0xc0911c], xmm0
// 00543d46  f30f110d2091c000     movss dword ptr [0xc09120], xmm1
// 00543d4e  f30f11052491c000     movss dword ptr [0xc09124], xmm0
// 00543d56  b81c91c000           mov eax, 0xc0911c
// 00543d5b  c3                   ret 
// library rbx2016-g3d/Box.cpp (function ?unitY@Vector3@G3D@@SAABV12@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Box.cpp
