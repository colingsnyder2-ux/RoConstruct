// from server: 100% by auto
// roc 2012-06 005e5920  unit: seg_005e0000  size: 45 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005e5920
//
// 005e5920  f30f1002             movss xmm0, dword ptr [edx]
// 005e5924  8bc1                 mov eax, ecx
// 005e5926  f30f5800             addss xmm0, dword ptr [eax]
// 005e592a  f30f1100             movss dword ptr [eax], xmm0
// 005e592e  f30f104204           movss xmm0, dword ptr [edx + 4]
// 005e5933  f30f584004           addss xmm0, dword ptr [eax + 4]
// 005e5938  f30f114004           movss dword ptr [eax + 4], xmm0
// 005e593d  f30f104208           movss xmm0, dword ptr [edx + 8]
// 005e5942  f30f584008           addss xmm0, dword ptr [eax + 8]
// 005e5947  f30f114008           movss dword ptr [eax + 8], xmm0
// 005e594c  c3                   ret 
// library rbx2016-g3d/Box.cpp (function ??YVector3@G3D@@QAIAAV01@ABV01@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Box.cpp
