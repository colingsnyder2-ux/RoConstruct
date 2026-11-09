// from server: 100% by auto
// roc 2012-06 0062bbd0  unit: G3D::Sphere  size: 68 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0062bbd0
//
// 0062bbd0  b801000000           mov eax, 1
// 0062bbd5  8405c085e200         test byte ptr [0xe285c0], al
// 0062bbdb  7531                 jne 0x62bc0e
// 0062bbdd  f30f100540c4b400     movss xmm0, dword ptr [0xb4c440]
// 0062bbe5  0905c085e200         or dword ptr [0xe285c0], eax
// 0062bbeb  f30f1105b485e200     movss dword ptr [0xe285b4], xmm0
// 0062bbf3  f30f10057027b600     movss xmm0, dword ptr [0xb62770]
// 0062bbfb  f30f1105b885e200     movss dword ptr [0xe285b8], xmm0
// 0062bc03  0f57c0               xorps xmm0, xmm0
// 0062bc06  f30f1105bc85e200     movss dword ptr [0xe285bc], xmm0
// 0062bc0e  b8b485e200           mov eax, 0xe285b4
// 0062bc13  c3                   ret 
// library rbx2016-g3d/Color3.cpp (function ?orange@Color3@G3D@@SAABV12@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Color3.cpp
