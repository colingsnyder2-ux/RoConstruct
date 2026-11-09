// from server: 100% by auto
// roc 2011-06 0053f9f0  unit: G3D::MemoryManager  size: 68 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0053f9f0
//
// 0053f9f0  b801000000           mov eax, 1
// 0053f9f5  840510a2cb00         test byte ptr [0xcba210], al
// 0053f9fb  7531                 jne 0x53fa2e
// 0053f9fd  f30f1005143ba600     movss xmm0, dword ptr [0xa63b14]
// 0053fa05  090510a2cb00         or dword ptr [0xcba210], eax
// 0053fa0b  f30f110504a2cb00     movss dword ptr [0xcba204], xmm0
// 0053fa13  f30f1005685ba700     movss xmm0, dword ptr [0xa75b68]
// 0053fa1b  f30f110508a2cb00     movss dword ptr [0xcba208], xmm0
// 0053fa23  0f57c0               xorps xmm0, xmm0
// 0053fa26  f30f11050ca2cb00     movss dword ptr [0xcba20c], xmm0
// 0053fa2e  b804a2cb00           mov eax, 0xcba204
// 0053fa33  c3                   ret 
// library rbx2016-g3d/Color3.cpp (function ?orange@Color3@G3D@@SAABV12@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Color3.cpp
