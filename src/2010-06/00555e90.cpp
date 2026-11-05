// from server: 100% by auto
// roc 2010-06 00555e90  unit: seg_00550000  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00555e90
//
// 00555e90  8bc1                 mov eax, ecx
// 00555e92  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00555e96  668b11               mov dx, word ptr [ecx]
// 00555e99  668910               mov word ptr [eax], dx
// 00555e9c  668b4904             mov cx, word ptr [ecx + 4]
// 00555ea0  66894802             mov word ptr [eax + 2], cx
// 00555ea4  c20400               ret 4
// library rbx2016-g3d/Vector2int16.cpp (function ??0Vector2int16@G3D@@QAE@QAH@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-g3d Vector2int16.cpp
