// from server: 100% by auto
// roc 2012-06 0062bc60  unit: G3D::Sphere  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0062bc60
//
// 0062bc60  b801000000           mov eax, 1
// 0062bc65  8405e085e200         test byte ptr [0xe285e0], al
// 0062bc6b  7526                 jne 0x62bc93
// 0062bc6d  f30f10054c85b600     movss xmm0, dword ptr [0xb6854c]
// 0062bc75  0905e085e200         or dword ptr [0xe285e0], eax
// 0062bc7b  f30f1105d485e200     movss dword ptr [0xe285d4], xmm0
// 0062bc83  f30f1105d885e200     movss dword ptr [0xe285d8], xmm0
// 0062bc8b  f30f1105dc85e200     movss dword ptr [0xe285dc], xmm0
// 0062bc93  b8d485e200           mov eax, 0xe285d4
// 0062bc98  c3                   ret 
// library rbx2016-g3d/Color3.cpp (function ?gray@Color3@G3D@@SAABV12@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Color3.cpp
