// from server: 100% by auto
// roc 2009-06 005bfcd0  unit: RBX::AggregatingSceneManager::Bucket  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005bfcd0
//
// 005bfcd0  55                   push ebp
// 005bfcd1  8bec                 mov ebp, esp
// 005bfcd3  51                   push ecx
// 005bfcd4  894dfc               mov dword ptr [ebp - 4], ecx
// 005bfcd7  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 005bfcda  e8f1befeff           call 0x5abbd0
// 005bfcdf  8be5                 mov esp, ebp
// 005bfce1  5d                   pop ebp
// 005bfce2  c3                   ret 
// library wildmagic-2-core/Containment\WmlConvexHull3.cpp (function ??1Triangle@?$ConvexHull3@M@Wml@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull3.cpp
