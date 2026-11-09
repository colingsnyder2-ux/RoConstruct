// roc 2012-06 008a8840  unit: RBX::Block  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 008a8840
//
// 008a8840  8b4104               mov eax, dword ptr [ecx + 4]
// 008a8843  8b4c2404             mov ecx, dword ptr [esp + 4]
// 008a8847  8d0488               lea eax, [eax + ecx*4]
// 008a884a  c20400               ret 4
// library wildmagic-2-core/Math\WmlGVector.cpp (function ??A?$GVector@M@Wml@@QAEAAMH@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Math/WmlGVector.cpp
