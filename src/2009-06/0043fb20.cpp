// from server: 100% by auto
// roc 2009-06 0043fb20  unit: RBX::Reflection::Metadata::VClass::?$BoundPropGetSet  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0043fb20
//
// 0043fb20  668b542408           mov dx, word ptr [esp + 8]
// 0043fb25  8bc1                 mov eax, ecx
// 0043fb27  668b4c2404           mov cx, word ptr [esp + 4]
// 0043fb2c  668908               mov word ptr [eax], cx
// 0043fb2f  66895002             mov word ptr [eax + 2], dx
// 0043fb33  c20800               ret 8
// library rbx2016-g3d/Vector2int16.cpp (function ??0Vector2int16@G3D@@QAE@FF@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-g3d Vector2int16.cpp
