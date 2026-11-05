// from server: 100% by auto
// roc 2010-06 00559dd0  unit: G3D::BinaryInput  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00559dd0
//
// 00559dd0  b801000000           mov eax, 1
// 00559dd5  840584a0c000         test byte ptr [0xc0a084], al
// 00559ddb  7526                 jne 0x559e03
// 00559ddd  f30f1005ec09a200     movss xmm0, dword ptr [0xa209ec]
// 00559de5  090584a0c000         or dword ptr [0xc0a084], eax
// 00559deb  f30f110578a0c000     movss dword ptr [0xc0a078], xmm0
// 00559df3  f30f11057ca0c000     movss dword ptr [0xc0a07c], xmm0
// 00559dfb  f30f110580a0c000     movss dword ptr [0xc0a080], xmm0
// 00559e03  b878a0c000           mov eax, 0xc0a078
// 00559e08  c3                   ret 
// library rbx2016-g3d/Color3.cpp (function ?gray@Color3@G3D@@SAABV12@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Color3.cpp
