// from server: 100% by auto
// roc 2011-06 005d7420  unit: RBX::PartInstance  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 005d7420
//
// 005d7420  b801000000           mov eax, 1
// 005d7425  840530a2cc00         test byte ptr [0xcca230], al
// 005d742b  7526                 jne 0x5d7453
// 005d742d  f30f1005143ba600     movss xmm0, dword ptr [0xa63b14]
// 005d7435  090530a2cc00         or dword ptr [0xcca230], eax
// 005d743b  f30f110524a2cc00     movss dword ptr [0xcca224], xmm0
// 005d7443  f30f110528a2cc00     movss dword ptr [0xcca228], xmm0
// 005d744b  f30f11052ca2cc00     movss dword ptr [0xcca22c], xmm0
// 005d7453  b824a2cc00           mov eax, 0xcca224
// 005d7458  c3                   ret 
// library rbx2016-g3d/Color3.cpp (function ?one@Color3@G3D@@SAABV12@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Color3.cpp
