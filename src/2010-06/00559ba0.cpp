// from server: 100% by auto
// roc 2010-06 00559ba0  unit: G3D::BinaryInput  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00559ba0
//
// 00559ba0  f30f10442408         movss xmm0, dword ptr [esp + 8]
// 00559ba6  8bc1                 mov eax, ecx
// 00559ba8  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00559bac  d901                 fld dword ptr [ecx]
// 00559bae  d918                 fstp dword ptr [eax]
// 00559bb0  d94104               fld dword ptr [ecx + 4]
// 00559bb3  f30f114008           movss dword ptr [eax + 8], xmm0
// 00559bb8  f30f1044240c         movss xmm0, dword ptr [esp + 0xc]
// 00559bbe  d95804               fstp dword ptr [eax + 4]
// 00559bc1  f30f11400c           movss dword ptr [eax + 0xc], xmm0
// 00559bc6  c20c00               ret 0xc
// library rbx2016-g3d/Vector4.cpp (function ??0Vector4@G3D@@QAE@ABVVector2@1@MM@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Vector4.cpp
