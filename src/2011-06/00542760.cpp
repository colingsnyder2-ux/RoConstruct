// from server: 100% by auto
// roc 2011-06 00542760  unit: G3D::Sphere  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00542760
//
// 00542760  f30f10442408         movss xmm0, dword ptr [esp + 8]
// 00542766  8bc1                 mov eax, ecx
// 00542768  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0054276c  d901                 fld dword ptr [ecx]
// 0054276e  d918                 fstp dword ptr [eax]
// 00542770  d94104               fld dword ptr [ecx + 4]
// 00542773  f30f114008           movss dword ptr [eax + 8], xmm0
// 00542778  d95804               fstp dword ptr [eax + 4]
// 0054277b  c20800               ret 8
// library rbx2016-g3d/Vector3.cpp (function ??0Vector3@G3D@@QAE@ABVVector2@1@M@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Vector3.cpp
