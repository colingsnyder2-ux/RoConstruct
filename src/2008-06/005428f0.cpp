// from server: 100% by auto
// roc 2008-06 005428f0  unit: RBX::RenderBase::VChunk::?$WeakReferenceCountedPointer  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005428f0
//
// 005428f0  55                   push ebp
// 005428f1  8bec                 mov ebp, esp
// 005428f3  51                   push ecx
// 005428f4  894dfc               mov dword ptr [ebp - 4], ecx
// 005428f7  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 005428fa  e8d11c0000           call 0x5445d0
// 005428ff  8b45fc               mov eax, dword ptr [ebp - 4]
// 00542902  8be5                 mov esp, ebp
// 00542904  5d                   pop ebp
// 00542905  c3                   ret 
// library wildmagic-2-core/Containment\WmlConvexHull2.cpp (function ??0SortedVertex@?$ConvexHull2@M@Wml@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull2.cpp
