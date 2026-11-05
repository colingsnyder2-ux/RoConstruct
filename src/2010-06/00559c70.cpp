// from server: 100% by auto
// roc 2010-06 00559c70  unit: G3D::BinaryInput  size: 60 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00559c70
//
// 00559c70  b801000000           mov eax, 1
// 00559c75  840534a0c000         test byte ptr [0xc0a034], al
// 00559c7b  7529                 jne 0x559ca6
// 00559c7d  0f57c0               xorps xmm0, xmm0
// 00559c80  090534a0c000         or dword ptr [0xc0a034], eax
// 00559c86  f30f110528a0c000     movss dword ptr [0xc0a028], xmm0
// 00559c8e  f30f11052ca0c000     movss dword ptr [0xc0a02c], xmm0
// 00559c96  f30f100524f6a100     movss xmm0, dword ptr [0xa1f624]
// 00559c9e  f30f110530a0c000     movss dword ptr [0xc0a030], xmm0
// 00559ca6  b828a0c000           mov eax, 0xc0a028
// 00559cab  c3                   ret 
// library rbx2016-g3d/Box.cpp (function ?unitZ@Vector3@G3D@@SAABV12@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Box.cpp
