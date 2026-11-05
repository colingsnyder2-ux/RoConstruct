// from server: 100% by auto
// roc 2008-06 00542910  unit: RBX::RenderBase::VChunk::?$WeakReferenceCountedPointer  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00542910
//
// 00542910  55                   push ebp
// 00542911  8bec                 mov ebp, esp
// 00542913  51                   push ecx
// 00542914  894dfc               mov dword ptr [ebp - 4], ecx
// 00542917  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 0054291a  e8911c0000           call 0x5445b0
// 0054291f  8b45fc               mov eax, dword ptr [ebp - 4]
// 00542922  8be5                 mov esp, ebp
// 00542924  5d                   pop ebp
// 00542925  c3                   ret 
// library wildmagic-2-core/Containment\WmlConvexHull2.cpp (function ??0SortedVertex@?$ConvexHull2@M@Wml@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull2.cpp
