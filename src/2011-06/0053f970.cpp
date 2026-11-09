// from server: 100% by auto
// roc 2011-06 0053f970  unit: G3D::MemoryManager  size: 60 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0053f970
//
// 0053f970  b801000000           mov eax, 1
// 0053f975  8405f0a1cb00         test byte ptr [0xcba1f0], al
// 0053f97b  7529                 jne 0x53f9a6
// 0053f97d  f30f1005143ba600     movss xmm0, dword ptr [0xa63b14]
// 0053f985  0905f0a1cb00         or dword ptr [0xcba1f0], eax
// 0053f98b  f30f1105e4a1cb00     movss dword ptr [0xcba1e4], xmm0
// 0053f993  f30f1105e8a1cb00     movss dword ptr [0xcba1e8], xmm0
// 0053f99b  0f57c0               xorps xmm0, xmm0
// 0053f99e  f30f1105eca1cb00     movss dword ptr [0xcba1ec], xmm0
// 0053f9a6  b8e4a1cb00           mov eax, 0xcba1e4
// 0053f9ab  c3                   ret 
// library rbx2016-g3d/Color3.cpp (function ?yellow@Color3@G3D@@SAABV12@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Color3.cpp
