// from server: 100% by auto
// roc 2011-06 00553030  unit: G3D::LineSegment  size: 45 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00553030
//
// 00553030  f30f1002             movss xmm0, dword ptr [edx]
// 00553034  8bc1                 mov eax, ecx
// 00553036  f30f5800             addss xmm0, dword ptr [eax]
// 0055303a  f30f1100             movss dword ptr [eax], xmm0
// 0055303e  f30f104204           movss xmm0, dword ptr [edx + 4]
// 00553043  f30f584004           addss xmm0, dword ptr [eax + 4]
// 00553048  f30f114004           movss dword ptr [eax + 4], xmm0
// 0055304d  f30f104208           movss xmm0, dword ptr [edx + 8]
// 00553052  f30f584008           addss xmm0, dword ptr [eax + 8]
// 00553057  f30f114008           movss dword ptr [eax + 8], xmm0
// 0055305c  c3                   ret 
// library rbx2016-g3d/Box.cpp (function ??YVector3@G3D@@QAIAAV01@ABV01@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Box.cpp
