// from server: 100% by auto
// roc 2009-06 005bfcf0  unit: RBX::AggregatingSceneManager::Bucket  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005bfcf0
//
// 005bfcf0  55                   push ebp
// 005bfcf1  8bec                 mov ebp, esp
// 005bfcf3  51                   push ecx
// 005bfcf4  894dfc               mov dword ptr [ebp - 4], ecx
// 005bfcf7  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 005bfcfa  e821bffeff           call 0x5abc20
// 005bfcff  8b45fc               mov eax, dword ptr [ebp - 4]
// 005bfd02  8be5                 mov esp, ebp
// 005bfd04  5d                   pop ebp
// 005bfd05  c3                   ret 
// library wildmagic-2-core/Containment\WmlConvexHull2.cpp (function ??0SortedVertex@?$ConvexHull2@M@Wml@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull2.cpp
