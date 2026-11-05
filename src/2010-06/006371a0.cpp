// from server: 100% by auto
// roc 2010-06 006371a0  unit: RBX::VPVInstance::?$NonFactoryProduct  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 006371a0
//
// 006371a0  b801000000           mov eax, 1
// 006371a5  8405e4b4c100         test byte ptr [0xc1b4e4], al
// 006371ab  7526                 jne 0x6371d3
// 006371ad  f30f100524f6a100     movss xmm0, dword ptr [0xa1f624]
// 006371b5  0905e4b4c100         or dword ptr [0xc1b4e4], eax
// 006371bb  f30f1105d8b4c100     movss dword ptr [0xc1b4d8], xmm0
// 006371c3  f30f1105dcb4c100     movss dword ptr [0xc1b4dc], xmm0
// 006371cb  f30f1105e0b4c100     movss dword ptr [0xc1b4e0], xmm0
// 006371d3  b8d8b4c100           mov eax, 0xc1b4d8
// 006371d8  c3                   ret 
// library rbx2016-g3d/Color3.cpp (function ?one@Color3@G3D@@SAABV12@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Color3.cpp
