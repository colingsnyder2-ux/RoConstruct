// from server: 100% by auto
// roc 2009-06 005bf4f0  unit: RBX::AggregatingSceneManager::Bucket  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005bf4f0
//
// 005bf4f0  55                   push ebp
// 005bf4f1  8bec                 mov ebp, esp
// 005bf4f3  51                   push ecx
// 005bf4f4  894dfc               mov dword ptr [ebp - 4], ecx
// 005bf4f7  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 005bf4fa  e8510a0000           call 0x5bff50
// 005bf4ff  8be5                 mov esp, ebp
// 005bf501  5d                   pop ebp
// 005bf502  c3                   ret 
// library wildmagic-2-core/Containment\WmlConvexHull3.cpp (function ??1Triangle@?$ConvexHull3@M@Wml@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull3.cpp
