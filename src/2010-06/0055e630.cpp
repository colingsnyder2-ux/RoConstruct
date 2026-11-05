// from server: 100% by auto
// roc 2010-06 0055e630  unit: G3D::TextInput::WrongSymbol  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0055e630
//
// 0055e630  f30f10442408         movss xmm0, dword ptr [esp + 8]
// 0055e636  8bc1                 mov eax, ecx
// 0055e638  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0055e63c  d901                 fld dword ptr [ecx]
// 0055e63e  d918                 fstp dword ptr [eax]
// 0055e640  d94104               fld dword ptr [ecx + 4]
// 0055e643  f30f114008           movss dword ptr [eax + 8], xmm0
// 0055e648  d95804               fstp dword ptr [eax + 4]
// 0055e64b  c20800               ret 8
// library rbx2016-g3d/Vector3.cpp (function ??0Vector3@G3D@@QAE@ABVVector2@1@M@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Vector3.cpp
