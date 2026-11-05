// from server: 100% by auto
// roc 2008-06 00540350  unit: RBX::RenderBase::AggregatingSceneManager  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00540350
//
// 00540350  55                   push ebp
// 00540351  8bec                 mov ebp, esp
// 00540353  51                   push ecx
// 00540354  894dfc               mov dword ptr [ebp - 4], ecx
// 00540357  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 0054035a  e851070000           call 0x540ab0
// 0054035f  8be5                 mov esp, ebp
// 00540361  5d                   pop ebp
// 00540362  c3                   ret 
// library wildmagic-2-core/Containment\WmlConvexHull3.cpp (function ??1Triangle@?$ConvexHull3@M@Wml@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull3.cpp
