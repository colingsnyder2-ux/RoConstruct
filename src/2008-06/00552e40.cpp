// from server: 100% by auto
// roc 2008-06 00552e40  unit: RBX::RenderBase::AggregateChunk  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00552e40
//
// 00552e40  55                   push ebp
// 00552e41  8bec                 mov ebp, esp
// 00552e43  51                   push ecx
// 00552e44  894dfc               mov dword ptr [ebp - 4], ecx
// 00552e47  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 00552e4a  e8c184f0ff           call 0x45b310
// 00552e4f  8be5                 mov esp, ebp
// 00552e51  5d                   pop ebp
// 00552e52  c3                   ret 
// library wildmagic-2-core/Containment\WmlConvexHull3.cpp (function ??1Triangle@?$ConvexHull3@M@Wml@@UAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull3.cpp
