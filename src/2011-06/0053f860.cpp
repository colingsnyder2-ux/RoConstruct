// from server: 100% by auto
// roc 2011-06 0053f860  unit: G3D::MemoryManager  size: 60 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0053f860
//
// 0053f860  b801000000           mov eax, 1
// 0053f865  8405a0a1cb00         test byte ptr [0xcba1a0], al
// 0053f86b  7529                 jne 0x53f896
// 0053f86d  f30f1005143ba600     movss xmm0, dword ptr [0xa63b14]
// 0053f875  0905a0a1cb00         or dword ptr [0xcba1a0], eax
// 0053f87b  f30f110594a1cb00     movss dword ptr [0xcba194], xmm0
// 0053f883  0f57c0               xorps xmm0, xmm0
// 0053f886  f30f110598a1cb00     movss dword ptr [0xcba198], xmm0
// 0053f88e  f30f11059ca1cb00     movss dword ptr [0xcba19c], xmm0
// 0053f896  b894a1cb00           mov eax, 0xcba194
// 0053f89b  c3                   ret 
// library rbx2016-g3d/Box.cpp (function ?unitX@Vector3@G3D@@SAABV12@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Box.cpp
