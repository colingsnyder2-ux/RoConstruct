// from server: 100% by auto
// roc 2011-06 0053f8a0  unit: G3D::MemoryManager  size: 60 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0053f8a0
//
// 0053f8a0  b801000000           mov eax, 1
// 0053f8a5  8405b0a1cb00         test byte ptr [0xcba1b0], al
// 0053f8ab  7529                 jne 0x53f8d6
// 0053f8ad  0f57c0               xorps xmm0, xmm0
// 0053f8b0  f30f100d143ba600     movss xmm1, dword ptr [0xa63b14]
// 0053f8b8  0905b0a1cb00         or dword ptr [0xcba1b0], eax
// 0053f8be  f30f1105a4a1cb00     movss dword ptr [0xcba1a4], xmm0
// 0053f8c6  f30f110da8a1cb00     movss dword ptr [0xcba1a8], xmm1
// 0053f8ce  f30f1105aca1cb00     movss dword ptr [0xcba1ac], xmm0
// 0053f8d6  b8a4a1cb00           mov eax, 0xcba1a4
// 0053f8db  c3                   ret 
// library rbx2016-g3d/Box.cpp (function ?unitY@Vector3@G3D@@SAABV12@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Box.cpp
