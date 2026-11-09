// from server: 100% by auto
// roc 2012-06 0062bca0  unit: G3D::Sphere  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0062bca0
//
// 0062bca0  b801000000           mov eax, 1
// 0062bca5  8405f085e200         test byte ptr [0xe285f0], al
// 0062bcab  7526                 jne 0x62bcd3
// 0062bcad  f30f100540c4b400     movss xmm0, dword ptr [0xb4c440]
// 0062bcb5  0905f085e200         or dword ptr [0xe285f0], eax
// 0062bcbb  f30f1105e485e200     movss dword ptr [0xe285e4], xmm0
// 0062bcc3  f30f1105e885e200     movss dword ptr [0xe285e8], xmm0
// 0062bccb  f30f1105ec85e200     movss dword ptr [0xe285ec], xmm0
// 0062bcd3  b8e485e200           mov eax, 0xe285e4
// 0062bcd8  c3                   ret 
// library rbx2016-g3d/Color3.cpp (function ?one@Color3@G3D@@SAABV12@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Color3.cpp
