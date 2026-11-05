// from server: 100% by auto
// roc 2008-06 005446b0  unit: RBX::RenderBase::VChunk::?$WeakReferenceCountedPointer  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005446b0
//
// 005446b0  55                   push ebp
// 005446b1  8bec                 mov ebp, esp
// 005446b3  51                   push ecx
// 005446b4  894dfc               mov dword ptr [ebp - 4], ecx
// 005446b7  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 005446ba  e811000000           call 0x5446d0
// 005446bf  8b45fc               mov eax, dword ptr [ebp - 4]
// 005446c2  8be5                 mov esp, ebp
// 005446c4  5d                   pop ebp
// 005446c5  c3                   ret 
// library wildmagic-2-core/Containment\WmlConvexHull2.cpp (function ??0SortedVertex@?$ConvexHull2@M@Wml@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull2.cpp
