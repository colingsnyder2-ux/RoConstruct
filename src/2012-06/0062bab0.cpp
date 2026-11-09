// from server: 100% by auto
// roc 2012-06 0062bab0  unit: G3D::Sphere  size: 68 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0062bab0
//
// 0062bab0  b801000000           mov eax, 1
// 0062bab5  84058085e200         test byte ptr [0xe28580], al
// 0062babb  7531                 jne 0x62baee
// 0062babd  f30f10054c85b600     movss xmm0, dword ptr [0xb6854c]
// 0062bac5  09058085e200         or dword ptr [0xe28580], eax
// 0062bacb  f30f11057485e200     movss dword ptr [0xe28574], xmm0
// 0062bad3  0f57c0               xorps xmm0, xmm0
// 0062bad6  f30f11057885e200     movss dword ptr [0xe28578], xmm0
// 0062bade  f30f100540c4b400     movss xmm0, dword ptr [0xb4c440]
// 0062bae6  f30f11057c85e200     movss dword ptr [0xe2857c], xmm0
// 0062baee  b87485e200           mov eax, 0xe28574
// 0062baf3  c3                   ret 
// library rbx2016-g3d/Color3.cpp (function ?purple@Color3@G3D@@SAABV12@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Color3.cpp
