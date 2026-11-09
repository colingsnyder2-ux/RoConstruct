// from server: 100% by auto
// roc 2011-06 0078a1e0  unit: RBX::Block  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0078a1e0
//
// 0078a1e0  8b4104               mov eax, dword ptr [ecx + 4]
// 0078a1e3  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0078a1e7  8d0488               lea eax, [eax + ecx*4]
// 0078a1ea  c20400               ret 4
// library wildmagic-2-core/Math\WmlGVector.cpp (function ??A?$GVector@M@Wml@@QAEAAMH@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Math/WmlGVector.cpp
