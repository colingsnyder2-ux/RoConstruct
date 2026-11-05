// from server: 100% by auto
// roc 2009-06 005c1510  unit: RBX::VChunk::?$WeakReferenceCountedPointer  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005c1510
//
// 005c1510  55                   push ebp
// 005c1511  8bec                 mov ebp, esp
// 005c1513  51                   push ecx
// 005c1514  894dfc               mov dword ptr [ebp - 4], ecx
// 005c1517  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 005c151a  e8b11b0000           call 0x5c30d0
// 005c151f  8b45fc               mov eax, dword ptr [ebp - 4]
// 005c1522  8be5                 mov esp, ebp
// 005c1524  5d                   pop ebp
// 005c1525  c3                   ret 
// library wildmagic-2-core/Containment\WmlConvexHull2.cpp (function ??0SortedVertex@?$ConvexHull2@M@Wml@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull2.cpp
