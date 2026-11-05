// from server: 100% by auto
// roc 2010-06 00559c30  unit: G3D::BinaryInput  size: 60 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00559c30
//
// 00559c30  b801000000           mov eax, 1
// 00559c35  840524a0c000         test byte ptr [0xc0a024], al
// 00559c3b  7529                 jne 0x559c66
// 00559c3d  0f57c0               xorps xmm0, xmm0
// 00559c40  f30f100d24f6a100     movss xmm1, dword ptr [0xa1f624]
// 00559c48  090524a0c000         or dword ptr [0xc0a024], eax
// 00559c4e  f30f110518a0c000     movss dword ptr [0xc0a018], xmm0
// 00559c56  f30f110d1ca0c000     movss dword ptr [0xc0a01c], xmm1
// 00559c5e  f30f110520a0c000     movss dword ptr [0xc0a020], xmm0
// 00559c66  b818a0c000           mov eax, 0xc0a018
// 00559c6b  c3                   ret 
// library rbx2016-g3d/Box.cpp (function ?unitY@Vector3@G3D@@SAABV12@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Box.cpp
