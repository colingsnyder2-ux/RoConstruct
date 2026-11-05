// from server: 100% by auto
// roc 2012-06 0062bb90  unit: G3D::Sphere  size: 60 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0062bb90
//
// 0062bb90  b801000000           mov eax, 1
// 0062bb95  8405b085e200         test byte ptr [0xe285b0], al
// 0062bb9b  7529                 jne 0x62bbc6
// 0062bb9d  f30f10057027b600     movss xmm0, dword ptr [0xb62770]
// 0062bba5  0905b085e200         or dword ptr [0xe285b0], eax
// 0062bbab  f30f1105a485e200     movss dword ptr [0xe285a4], xmm0
// 0062bbb3  f30f1105a885e200     movss dword ptr [0xe285a8], xmm0
// 0062bbbb  0f57c0               xorps xmm0, xmm0
// 0062bbbe  f30f1105ac85e200     movss dword ptr [0xe285ac], xmm0
// 0062bbc6  b8a485e200           mov eax, 0xe285a4
// 0062bbcb  c3                   ret 
// library rbx2016-g3d/Color3.cpp (function ?brown@Color3@G3D@@SAABV12@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Color3.cpp
