// from server: 100% by auto
// roc 2009-06 005bff00  unit: RBX::VChunk::?$WeakReferenceCountedPointer  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005bff00
//
// 005bff00  55                   push ebp
// 005bff01  8bec                 mov ebp, esp
// 005bff03  51                   push ecx
// 005bff04  894dfc               mov dword ptr [ebp - 4], ecx
// 005bff07  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 005bff0a  e871150000           call 0x5c1480
// 005bff0f  8b45fc               mov eax, dword ptr [ebp - 4]
// 005bff12  8be5                 mov esp, ebp
// 005bff14  5d                   pop ebp
// 005bff15  c3                   ret 
// library wildmagic-2-core/Containment\WmlConvexHull2.cpp (function ??0SortedVertex@?$ConvexHull2@M@Wml@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull2.cpp
