// from server: 100% by auto
// roc 2011-06 0053ff00  unit: G3D::MemoryManager  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0053ff00
//
// 0053ff00  8bc1                 mov eax, ecx
// 0053ff02  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0053ff06  668b11               mov dx, word ptr [ecx]
// 0053ff09  668910               mov word ptr [eax], dx
// 0053ff0c  668b4904             mov cx, word ptr [ecx + 4]
// 0053ff10  66894802             mov word ptr [eax + 2], cx
// 0053ff14  c20400               ret 4
// library rbx2016-g3d/Vector2int16.cpp (function ??0Vector2int16@G3D@@QAE@QAH@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-g3d Vector2int16.cpp
