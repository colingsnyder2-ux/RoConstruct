// from server: 100% by auto
// roc 2010-06 00979de0  unit: seg_00970000  size: 60 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00979de0
//
// 00979de0  b801000000           mov eax, 1
// 00979de5  840578cfc200         test byte ptr [0xc2cf78], al
// 00979deb  7529                 jne 0x979e16
// 00979ded  0f57c0               xorps xmm0, xmm0
// 00979df0  090578cfc200         or dword ptr [0xc2cf78], eax
// 00979df6  f30f110568cfc200     movss dword ptr [0xc2cf68], xmm0
// 00979dfe  f30f11056ccfc200     movss dword ptr [0xc2cf6c], xmm0
// 00979e06  f30f110570cfc200     movss dword ptr [0xc2cf70], xmm0
// 00979e0e  f30f110574cfc200     movss dword ptr [0xc2cf74], xmm0
// 00979e16  b868cfc200           mov eax, 0xc2cf68
// 00979e1b  c3                   ret 
// library rbx2016-g3d/Color4.cpp (function ?zero@Color4@G3D@@SAABV12@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Color4.cpp
