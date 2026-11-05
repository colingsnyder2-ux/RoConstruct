// from server: 100% by auto
// roc 2011-06 009c53d0  unit: seg_009c0000  size: 60 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 009c53d0
//
// 009c53d0  b801000000           mov eax, 1
// 009c53d5  8405b8f9d100         test byte ptr [0xd1f9b8], al
// 009c53db  7529                 jne 0x9c5406
// 009c53dd  0f57c0               xorps xmm0, xmm0
// 009c53e0  0905b8f9d100         or dword ptr [0xd1f9b8], eax
// 009c53e6  f30f1105a8f9d100     movss dword ptr [0xd1f9a8], xmm0
// 009c53ee  f30f1105acf9d100     movss dword ptr [0xd1f9ac], xmm0
// 009c53f6  f30f1105b0f9d100     movss dword ptr [0xd1f9b0], xmm0
// 009c53fe  f30f1105b4f9d100     movss dword ptr [0xd1f9b4], xmm0
// 009c5406  b8a8f9d100           mov eax, 0xd1f9a8
// 009c540b  c3                   ret 
// library rbx2016-g3d/Color4.cpp (function ?zero@Color4@G3D@@SAABV12@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Color4.cpp
