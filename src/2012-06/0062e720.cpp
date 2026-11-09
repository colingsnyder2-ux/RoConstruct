// from server: 100% by auto
// roc 2012-06 0062e720  unit: G3D::Line  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0062e720
//
// 0062e720  f30f10442408         movss xmm0, dword ptr [esp + 8]
// 0062e726  8bc1                 mov eax, ecx
// 0062e728  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0062e72c  d901                 fld dword ptr [ecx]
// 0062e72e  d918                 fstp dword ptr [eax]
// 0062e730  d94104               fld dword ptr [ecx + 4]
// 0062e733  f30f114008           movss dword ptr [eax + 8], xmm0
// 0062e738  d95804               fstp dword ptr [eax + 4]
// 0062e73b  c20800               ret 8
// library rbx2016-g3d/Vector3.cpp (function ??0Vector3@G3D@@QAE@ABVVector2@1@M@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Vector3.cpp
