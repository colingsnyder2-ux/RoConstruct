// from server: 100% by auto
// roc 2012-06 004a7d00  unit: CTaskSchedulerPaneView  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004a7d00
//
// 004a7d00  8b542408             mov edx, dword ptr [esp + 8]
// 004a7d04  8b442404             mov eax, dword ptr [esp + 4]
// 004a7d08  f30f1001             movss xmm0, dword ptr [ecx]
// 004a7d0c  f30f5c02             subss xmm0, dword ptr [edx]
// 004a7d10  f30f1100             movss dword ptr [eax], xmm0
// 004a7d14  f30f104104           movss xmm0, dword ptr [ecx + 4]
// 004a7d19  f30f5c4204           subss xmm0, dword ptr [edx + 4]
// 004a7d1e  f30f114004           movss dword ptr [eax + 4], xmm0
// 004a7d23  c20800               ret 8
// library rbx2016-g3d/LineSegment.cpp (function ??GVector2@G3D@@QBE?AV01@ABV01@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d LineSegment.cpp
