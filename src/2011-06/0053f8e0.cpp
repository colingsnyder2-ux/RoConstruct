// from server: 100% by auto
// roc 2011-06 0053f8e0  unit: G3D::MemoryManager  size: 60 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0053f8e0
//
// 0053f8e0  b801000000           mov eax, 1
// 0053f8e5  8405c0a1cb00         test byte ptr [0xcba1c0], al
// 0053f8eb  7529                 jne 0x53f916
// 0053f8ed  0f57c0               xorps xmm0, xmm0
// 0053f8f0  0905c0a1cb00         or dword ptr [0xcba1c0], eax
// 0053f8f6  f30f1105b4a1cb00     movss dword ptr [0xcba1b4], xmm0
// 0053f8fe  f30f1105b8a1cb00     movss dword ptr [0xcba1b8], xmm0
// 0053f906  f30f1005143ba600     movss xmm0, dword ptr [0xa63b14]
// 0053f90e  f30f1105bca1cb00     movss dword ptr [0xcba1bc], xmm0
// 0053f916  b8b4a1cb00           mov eax, 0xcba1b4
// 0053f91b  c3                   ret 
// library rbx2016-g3d/Box.cpp (function ?unitZ@Vector3@G3D@@SAABV12@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Box.cpp
