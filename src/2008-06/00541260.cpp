// from server: 100% by auto
// roc 2008-06 00541260  unit: RBX::RenderBase::VChunk::?$WeakReferenceCountedPointer  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00541260
//
// 00541260  55                   push ebp
// 00541261  8bec                 mov ebp, esp
// 00541263  51                   push ecx
// 00541264  894dfc               mov dword ptr [ebp - 4], ecx
// 00541267  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 0054126a  e8c1fdffff           call 0x541030
// 0054126f  8b4508               mov eax, dword ptr [ebp + 8]
// 00541272  83e001               and eax, 1
// 00541275  740c                 je 0x541283
// 00541277  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 0054127a  51                   push ecx
// 0054127b  e8faf31500           call 0x6a067a
// 00541280  83c404               add esp, 4
// 00541283  8b45fc               mov eax, dword ptr [ebp - 4]
// 00541286  8be5                 mov esp, ebp
// 00541288  5d                   pop ebp
// 00541289  c20400               ret 4
// library wildmagic-2-core/Containment\WmlConvexHull3.cpp (function ??_GTriangle@?$ConvexHull3@M@Wml@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull3.cpp
