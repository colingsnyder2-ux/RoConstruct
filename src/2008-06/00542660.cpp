// from server: 100% by auto
// roc 2008-06 00542660  unit: RBX::RenderBase::VChunk::?$WeakReferenceCountedPointer  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00542660
//
// 00542660  55                   push ebp
// 00542661  8bec                 mov ebp, esp
// 00542663  51                   push ecx
// 00542664  894dfc               mov dword ptr [ebp - 4], ecx
// 00542667  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 0054266a  e8511d0000           call 0x5443c0
// 0054266f  8b45fc               mov eax, dword ptr [ebp - 4]
// 00542672  8be5                 mov esp, ebp
// 00542674  5d                   pop ebp
// 00542675  c3                   ret 
// library wildmagic-2-core/Containment\WmlConvexHull2.cpp (function ??0SortedVertex@?$ConvexHull2@M@Wml@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull2.cpp
