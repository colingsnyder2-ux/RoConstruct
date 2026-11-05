// from server: 100% by auto
// roc 2009-06 005bfc50  unit: RBX::AggregatingSceneManager::Bucket  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005bfc50
//
// 005bfc50  55                   push ebp
// 005bfc51  8bec                 mov ebp, esp
// 005bfc53  51                   push ecx
// 005bfc54  894dfc               mov dword ptr [ebp - 4], ecx
// 005bfc57  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 005bfc5a  e851150000           call 0x5c11b0
// 005bfc5f  8be5                 mov esp, ebp
// 005bfc61  5d                   pop ebp
// 005bfc62  c3                   ret 
// library wildmagic-2-core/Containment\WmlConvexHull3.cpp (function ??1Triangle@?$ConvexHull3@M@Wml@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull3.cpp
