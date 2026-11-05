// from server: 100% by auto
// roc 2011-06 00553060  unit: G3D::LineSegment  size: 60 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00553060
//
// 00553060  b801000000           mov eax, 1
// 00553065  8405a4a3cb00         test byte ptr [0xcba3a4], al
// 0055306b  7529                 jne 0x553096
// 0055306d  0f57c0               xorps xmm0, xmm0
// 00553070  0905a4a3cb00         or dword ptr [0xcba3a4], eax
// 00553076  f30f110594a3cb00     movss dword ptr [0xcba394], xmm0
// 0055307e  f30f110598a3cb00     movss dword ptr [0xcba398], xmm0
// 00553086  f30f11059ca3cb00     movss dword ptr [0xcba39c], xmm0
// 0055308e  f30f1105a0a3cb00     movss dword ptr [0xcba3a0], xmm0
// 00553096  b894a3cb00           mov eax, 0xcba394
// 0055309b  c3                   ret 
// library rbx2016-g3d/Color4.cpp (function ?zero@Color4@G3D@@SAABV12@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Color4.cpp
