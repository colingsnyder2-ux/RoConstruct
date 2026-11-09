// roc 2012-06 0092a030  unit: RBX::EdgeEdgePair  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0092a030
//
// 0092a030  55                   push ebp
// 0092a031  8bec                 mov ebp, esp
// 0092a033  51                   push ecx
// 0092a034  894dfc               mov dword ptr [ebp - 4], ecx
// 0092a037  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 0092a03a  e8b1ffffff           call 0x929ff0
// 0092a03f  8b4508               mov eax, dword ptr [ebp + 8]
// 0092a042  83e001               and eax, 1
// 0092a045  740c                 je 0x92a053
// 0092a047  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 0092a04a  51                   push ecx
// 0092a04b  e8c4800500           call 0x982114
// 0092a050  83c404               add esp, 4
// 0092a053  8b45fc               mov eax, dword ptr [ebp - 4]
// 0092a056  8be5                 mov esp, ebp
// 0092a058  5d                   pop ebp
// 0092a059  c20400               ret 4
// library wildmagic-2-core/Containment\WmlConvexHull3.cpp (function ??_GTriangle@?$ConvexHull3@M@Wml@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull3.cpp
