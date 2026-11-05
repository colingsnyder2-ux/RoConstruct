// from server: 100% by auto
// roc 2008-06 0054ac50  unit: RBX::RenderBase::Mesh  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0054ac50
//
// 0054ac50  55                   push ebp
// 0054ac51  8bec                 mov ebp, esp
// 0054ac53  51                   push ecx
// 0054ac54  894dfc               mov dword ptr [ebp - 4], ecx
// 0054ac57  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 0054ac5a  e861080000           call 0x54b4c0
// 0054ac5f  8be5                 mov esp, ebp
// 0054ac61  5d                   pop ebp
// 0054ac62  c3                   ret 
// library wildmagic-2-core/Containment\WmlConvexHull3.cpp (function ??1Triangle@?$ConvexHull3@M@Wml@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull3.cpp
