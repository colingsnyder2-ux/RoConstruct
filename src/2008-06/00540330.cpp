// from server: 100% by auto
// roc 2008-06 00540330  unit: RBX::RenderBase::AggregatingSceneManager  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00540330
//
// 00540330  55                   push ebp
// 00540331  8bec                 mov ebp, esp
// 00540333  51                   push ecx
// 00540334  894dfc               mov dword ptr [ebp - 4], ecx
// 00540337  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 0054033a  e811060000           call 0x540950
// 0054033f  8be5                 mov esp, ebp
// 00540341  5d                   pop ebp
// 00540342  c3                   ret 
// library wildmagic-2-core/Containment\WmlConvexHull3.cpp (function ??1Triangle@?$ConvexHull3@M@Wml@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull3.cpp
