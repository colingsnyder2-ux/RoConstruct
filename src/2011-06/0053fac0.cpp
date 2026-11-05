// from server: 100% by auto
// roc 2011-06 0053fac0  unit: G3D::MemoryManager  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0053fac0
//
// 0053fac0  b801000000           mov eax, 1
// 0053fac5  840540a2cb00         test byte ptr [0xcba240], al
// 0053facb  7526                 jne 0x53faf3
// 0053facd  f30f1005143ba600     movss xmm0, dword ptr [0xa63b14]
// 0053fad5  090540a2cb00         or dword ptr [0xcba240], eax
// 0053fadb  f30f110534a2cb00     movss dword ptr [0xcba234], xmm0
// 0053fae3  f30f110538a2cb00     movss dword ptr [0xcba238], xmm0
// 0053faeb  f30f11053ca2cb00     movss dword ptr [0xcba23c], xmm0
// 0053faf3  b834a2cb00           mov eax, 0xcba234
// 0053faf8  c3                   ret 
// library rbx2016-g3d/Color3.cpp (function ?one@Color3@G3D@@SAABV12@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Color3.cpp
