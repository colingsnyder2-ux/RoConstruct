// from server: 100% by auto
// roc 2012-06 006341d0  unit: G3D::Random  size: 60 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006341d0
//
// 006341d0  b801000000           mov eax, 1
// 006341d5  84057887e200         test byte ptr [0xe28778], al
// 006341db  7529                 jne 0x634206
// 006341dd  0f57c0               xorps xmm0, xmm0
// 006341e0  09057887e200         or dword ptr [0xe28778], eax
// 006341e6  f30f11056887e200     movss dword ptr [0xe28768], xmm0
// 006341ee  f30f11056c87e200     movss dword ptr [0xe2876c], xmm0
// 006341f6  f30f11057087e200     movss dword ptr [0xe28770], xmm0
// 006341fe  f30f11057487e200     movss dword ptr [0xe28774], xmm0
// 00634206  b86887e200           mov eax, 0xe28768
// 0063420b  c3                   ret 
// library rbx2016-g3d/Color4.cpp (function ?zero@Color4@G3D@@SAABV12@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Color4.cpp
