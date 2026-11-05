// from server: 100% by auto
// roc 2008-06 005443a0  unit: RBX::RenderBase::VChunk::?$WeakReferenceCountedPointer  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005443a0
//
// 005443a0  55                   push ebp
// 005443a1  8bec                 mov ebp, esp
// 005443a3  51                   push ecx
// 005443a4  894dfc               mov dword ptr [ebp - 4], ecx
// 005443a7  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 005443aa  e8c1130000           call 0x545770
// 005443af  8b45fc               mov eax, dword ptr [ebp - 4]
// 005443b2  8be5                 mov esp, ebp
// 005443b4  5d                   pop ebp
// 005443b5  c3                   ret 
// library wildmagic-2-core/Containment\WmlConvexHull2.cpp (function ??0SortedVertex@?$ConvexHull2@M@Wml@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull2.cpp
