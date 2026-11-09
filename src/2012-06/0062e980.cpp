// from server: 100% by auto
// roc 2012-06 0062e980  unit: G3D::Line  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0062e980
//
// 0062e980  8bc1                 mov eax, ecx
// 0062e982  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0062e986  0fbf11               movsx edx, word ptr [ecx]
// 0062e989  f30f2ac2             cvtsi2ss xmm0, edx
// 0062e98d  f30f1100             movss dword ptr [eax], xmm0
// 0062e991  0fbf5102             movsx edx, word ptr [ecx + 2]
// 0062e995  f30f2ac2             cvtsi2ss xmm0, edx
// 0062e999  f30f114004           movss dword ptr [eax + 4], xmm0
// 0062e99e  0fbf4904             movsx ecx, word ptr [ecx + 4]
// 0062e9a2  f30f2ac1             cvtsi2ss xmm0, ecx
// 0062e9a6  f30f114008           movss dword ptr [eax + 8], xmm0
// 0062e9ab  c20400               ret 4
// library rbx2016-g3d/Vector3.cpp (function ??0Vector3@G3D@@QAE@ABVVector3int16@1@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Vector3.cpp
