// from server: 100% by auto
// roc 2011-06 005413e0  unit: G3D::MemoryManager  size: 100 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 005413e0
//
// 005413e0  b801000000           mov eax, 1
// 005413e5  8405d0a2cb00         test byte ptr [0xcba2d0], al
// 005413eb  7551                 jne 0x54143e
// 005413ed  0f57c0               xorps xmm0, xmm0
// 005413f0  0905d0a2cb00         or dword ptr [0xcba2d0], eax
// 005413f6  f30f1105aca2cb00     movss dword ptr [0xcba2ac], xmm0
// 005413fe  f30f1105b0a2cb00     movss dword ptr [0xcba2b0], xmm0
// 00541406  f30f1105b4a2cb00     movss dword ptr [0xcba2b4], xmm0
// 0054140e  f30f1105b8a2cb00     movss dword ptr [0xcba2b8], xmm0
// 00541416  f30f1105bca2cb00     movss dword ptr [0xcba2bc], xmm0
// 0054141e  f30f1105c0a2cb00     movss dword ptr [0xcba2c0], xmm0
// 00541426  f30f1105c4a2cb00     movss dword ptr [0xcba2c4], xmm0
// 0054142e  f30f1105c8a2cb00     movss dword ptr [0xcba2c8], xmm0
// 00541436  f30f1105cca2cb00     movss dword ptr [0xcba2cc], xmm0
// 0054143e  b8aca2cb00           mov eax, 0xcba2ac
// 00541443  c3                   ret 
// library rbx2016-g3d/Matrix3.cpp (function ?zero@Matrix3@G3D@@SAABV12@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Matrix3.cpp
