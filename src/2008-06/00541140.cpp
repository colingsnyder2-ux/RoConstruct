// from server: 100% by auto
// roc 2008-06 00541140  unit: RBX::RenderBase::VChunk::?$WeakReferenceCountedPointer  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00541140
//
// 00541140  55                   push ebp
// 00541141  8bec                 mov ebp, esp
// 00541143  51                   push ecx
// 00541144  894dfc               mov dword ptr [ebp - 4], ecx
// 00541147  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 0054114a  e8a1170000           call 0x5428f0
// 0054114f  8b45fc               mov eax, dword ptr [ebp - 4]
// 00541152  8be5                 mov esp, ebp
// 00541154  5d                   pop ebp
// 00541155  c3                   ret 
// library wildmagic-2-core/Containment\WmlConvexHull2.cpp (function ??0SortedVertex@?$ConvexHull2@M@Wml@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull2.cpp
