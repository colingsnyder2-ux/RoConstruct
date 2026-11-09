// from server: 100% by auto
// roc 2011-06 00494920  unit: CTaskSchedulerPaneView  size: 38 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00494920
//
// 00494920  8b542408             mov edx, dword ptr [esp + 8]
// 00494924  8b442404             mov eax, dword ptr [esp + 4]
// 00494928  f30f1001             movss xmm0, dword ptr [ecx]
// 0049492c  f30f5c02             subss xmm0, dword ptr [edx]
// 00494930  f30f1100             movss dword ptr [eax], xmm0
// 00494934  f30f104104           movss xmm0, dword ptr [ecx + 4]
// 00494939  f30f5c4204           subss xmm0, dword ptr [edx + 4]
// 0049493e  f30f114004           movss dword ptr [eax + 4], xmm0
// 00494943  c20800               ret 8
// library rbx2016-g3d/LineSegment.cpp (function ??GVector2@G3D@@QBE?AV01@ABV01@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d LineSegment.cpp
