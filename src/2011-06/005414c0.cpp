// from server: 100% by auto
// roc 2011-06 005414c0  unit: G3D::MemoryManager  size: 45 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 005414c0
//
// 005414c0  f30f1005dc5ca700     movss xmm0, dword ptr [0xa75cdc]
// 005414c8  8bc2                 mov eax, edx
// 005414ca  0f28c8               movaps xmm1, xmm0
// 005414cd  f30f5c09             subss xmm1, dword ptr [ecx]
// 005414d1  f30f1108             movss dword ptr [eax], xmm1
// 005414d5  0f28c8               movaps xmm1, xmm0
// 005414d8  f30f5c4904           subss xmm1, dword ptr [ecx + 4]
// 005414dd  f30f5c4108           subss xmm0, dword ptr [ecx + 8]
// 005414e2  f30f114804           movss dword ptr [eax + 4], xmm1
// 005414e7  f30f114008           movss dword ptr [eax + 8], xmm0
// 005414ec  c3                   ret 
// library rbx2016-g3d/AABox.cpp (function ??GVector3@G3D@@QBI?AV01@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d AABox.cpp
