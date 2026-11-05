// from server: 100% by auto
// roc 2010-06 00559bf0  unit: G3D::BinaryInput  size: 60 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00559bf0
//
// 00559bf0  b801000000           mov eax, 1
// 00559bf5  840514a0c000         test byte ptr [0xc0a014], al
// 00559bfb  7529                 jne 0x559c26
// 00559bfd  f30f100524f6a100     movss xmm0, dword ptr [0xa1f624]
// 00559c05  090514a0c000         or dword ptr [0xc0a014], eax
// 00559c0b  f30f110508a0c000     movss dword ptr [0xc0a008], xmm0
// 00559c13  0f57c0               xorps xmm0, xmm0
// 00559c16  f30f11050ca0c000     movss dword ptr [0xc0a00c], xmm0
// 00559c1e  f30f110510a0c000     movss dword ptr [0xc0a010], xmm0
// 00559c26  b808a0c000           mov eax, 0xc0a008
// 00559c2b  c3                   ret 
// library rbx2016-g3d/Box.cpp (function ?unitX@Vector3@G3D@@SAABV12@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Box.cpp
