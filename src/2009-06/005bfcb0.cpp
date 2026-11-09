// from server: 100% by auto
// roc 2009-06 005bfcb0  unit: RBX::AggregatingSceneManager::Bucket  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005bfcb0
//
// 005bfcb0  55                   push ebp
// 005bfcb1  8bec                 mov ebp, esp
// 005bfcb3  51                   push ecx
// 005bfcb4  894dfc               mov dword ptr [ebp - 4], ecx
// 005bfcb7  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 005bfcba  e8b1150000           call 0x5c1270
// 005bfcbf  8b45fc               mov eax, dword ptr [ebp - 4]
// 005bfcc2  8be5                 mov esp, ebp
// 005bfcc4  5d                   pop ebp
// 005bfcc5  c3                   ret 
// library wildmagic-2-core/Containment\WmlConvexHull2.cpp (function ??0SortedVertex@?$ConvexHull2@M@Wml@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull2.cpp
