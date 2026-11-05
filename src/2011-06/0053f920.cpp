// from server: 100% by auto
// roc 2011-06 0053f920  unit: G3D::MemoryManager  size: 68 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0053f920
//
// 0053f920  b801000000           mov eax, 1
// 0053f925  8405d0a1cb00         test byte ptr [0xcba1d0], al
// 0053f92b  7531                 jne 0x53f95e
// 0053f92d  f30f10052cfba700     movss xmm0, dword ptr [0xa7fb2c]
// 0053f935  0905d0a1cb00         or dword ptr [0xcba1d0], eax
// 0053f93b  f30f1105c4a1cb00     movss dword ptr [0xcba1c4], xmm0
// 0053f943  0f57c0               xorps xmm0, xmm0
// 0053f946  f30f1105c8a1cb00     movss dword ptr [0xcba1c8], xmm0
// 0053f94e  f30f1005143ba600     movss xmm0, dword ptr [0xa63b14]
// 0053f956  f30f1105cca1cb00     movss dword ptr [0xcba1cc], xmm0
// 0053f95e  b8c4a1cb00           mov eax, 0xcba1c4
// 0053f963  c3                   ret 
// library rbx2016-g3d/Color3.cpp (function ?purple@Color3@G3D@@SAABV12@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Color3.cpp
