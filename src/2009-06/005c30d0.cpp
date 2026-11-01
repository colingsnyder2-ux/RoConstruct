// from server: 100% by auto
// roc 2009-06 005c30d0  unit: RBX::VChunk::?$WeakReferenceCountedPointer  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005c30d0
//
// 005c30d0  55                   push ebp
// 005c30d1  8bec                 mov ebp, esp
// 005c30d3  51                   push ecx
// 005c30d4  894dfc               mov dword ptr [ebp - 4], ecx
// 005c30d7  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 005c30da  e831140000           call 0x5c4510
// 005c30df  8b45fc               mov eax, dword ptr [ebp - 4]
// 005c30e2  8be5                 mov esp, ebp
// 005c30e4  5d                   pop ebp
// 005c30e5  c3                   ret 
// library wildmagic-2-core/Containment\WmlConvexHull2.cpp (function ??0SortedVertex@?$ConvexHull2@M@Wml@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull2.cpp
