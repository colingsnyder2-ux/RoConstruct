// from server: 100% by auto
// roc 2008-06 0054c4e0  unit: RBX::RenderBase::Mesh  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0054c4e0
//
// 0054c4e0  55                   push ebp
// 0054c4e1  8bec                 mov ebp, esp
// 0054c4e3  51                   push ecx
// 0054c4e4  894dfc               mov dword ptr [ebp - 4], ecx
// 0054c4e7  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 0054c4ea  e8d14cffff           call 0x5411c0
// 0054c4ef  8be5                 mov esp, ebp
// 0054c4f1  5d                   pop ebp
// 0054c4f2  c3                   ret 
// library wildmagic-2-core/Containment\WmlConvexHull3.cpp (function ??1Triangle@?$ConvexHull3@M@Wml@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull3.cpp
