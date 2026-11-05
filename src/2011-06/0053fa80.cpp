// from server: 100% by auto
// roc 2011-06 0053fa80  unit: G3D::MemoryManager  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0053fa80
//
// 0053fa80  b801000000           mov eax, 1
// 0053fa85  840530a2cb00         test byte ptr [0xcba230], al
// 0053fa8b  7526                 jne 0x53fab3
// 0053fa8d  f30f10052cfba700     movss xmm0, dword ptr [0xa7fb2c]
// 0053fa95  090530a2cb00         or dword ptr [0xcba230], eax
// 0053fa9b  f30f110524a2cb00     movss dword ptr [0xcba224], xmm0
// 0053faa3  f30f110528a2cb00     movss dword ptr [0xcba228], xmm0
// 0053faab  f30f11052ca2cb00     movss dword ptr [0xcba22c], xmm0
// 0053fab3  b824a2cb00           mov eax, 0xcba224
// 0053fab8  c3                   ret 
// library rbx2016-g3d/Color3.cpp (function ?gray@Color3@G3D@@SAABV12@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Color3.cpp
