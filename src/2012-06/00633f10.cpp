// from server: 100% by auto
// roc 2012-06 00633f10  unit: G3D::Random  size: 60 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00633f10
//
// 00633f10  b801000000           mov eax, 1
// 00633f15  84056487e200         test byte ptr [0xe28764], al
// 00633f1b  7529                 jne 0x633f46
// 00633f1d  0f57c0               xorps xmm0, xmm0
// 00633f20  09056487e200         or dword ptr [0xe28764], eax
// 00633f26  f30f11055487e200     movss dword ptr [0xe28754], xmm0
// 00633f2e  f30f11055887e200     movss dword ptr [0xe28758], xmm0
// 00633f36  f30f11055c87e200     movss dword ptr [0xe2875c], xmm0
// 00633f3e  f30f11056087e200     movss dword ptr [0xe28760], xmm0
// 00633f46  b85487e200           mov eax, 0xe28754
// 00633f4b  c3                   ret 
// library rbx2016-g3d/Color4.cpp (function ?zero@Color4@G3D@@SAABV12@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Color4.cpp
