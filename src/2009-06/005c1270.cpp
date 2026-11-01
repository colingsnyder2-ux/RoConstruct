// from server: 100% by auto
// roc 2009-06 005c1270  unit: RBX::VChunk::?$WeakReferenceCountedPointer  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005c1270
//
// 005c1270  55                   push ebp
// 005c1271  8bec                 mov ebp, esp
// 005c1273  51                   push ecx
// 005c1274  894dfc               mov dword ptr [ebp - 4], ecx
// 005c1277  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 005c127a  e8111d0000           call 0x5c2f90
// 005c127f  8b45fc               mov eax, dword ptr [ebp - 4]
// 005c1282  8be5                 mov esp, ebp
// 005c1284  5d                   pop ebp
// 005c1285  c3                   ret 
// library wildmagic-2-core/Containment\WmlConvexHull2.cpp (function ??0SortedVertex@?$ConvexHull2@M@Wml@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull2.cpp
