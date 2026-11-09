// from server: 100% by auto
// roc 2008-06 005445b0  unit: RBX::RenderBase::VChunk::?$WeakReferenceCountedPointer  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005445b0
//
// 005445b0  55                   push ebp
// 005445b1  8bec                 mov ebp, esp
// 005445b3  51                   push ecx
// 005445b4  894dfc               mov dword ptr [ebp - 4], ecx
// 005445b7  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 005445ba  e8e1120000           call 0x5458a0
// 005445bf  8b45fc               mov eax, dword ptr [ebp - 4]
// 005445c2  8be5                 mov esp, ebp
// 005445c4  5d                   pop ebp
// 005445c5  c3                   ret 
// library wildmagic-2-core/Containment\WmlConvexHull2.cpp (function ??0SortedVertex@?$ConvexHull2@M@Wml@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull2.cpp
