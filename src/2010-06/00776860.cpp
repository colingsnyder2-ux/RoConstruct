// from server: 100% by auto
// roc 2010-06 00776860  unit: RBX::EdgeEdgePair  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00776860
//
// 00776860  55                   push ebp
// 00776861  8bec                 mov ebp, esp
// 00776863  51                   push ecx
// 00776864  894dfc               mov dword ptr [ebp - 4], ecx
// 00776867  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 0077686a  e8b1ffffff           call 0x776820
// 0077686f  8b4508               mov eax, dword ptr [ebp + 8]
// 00776872  83e001               and eax, 1
// 00776875  740c                 je 0x776883
// 00776877  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 0077687a  51                   push ecx
// 0077687b  e81a110300           call 0x7a799a
// 00776880  83c404               add esp, 4
// 00776883  8b45fc               mov eax, dword ptr [ebp - 4]
// 00776886  8be5                 mov esp, ebp
// 00776888  5d                   pop ebp
// 00776889  c20400               ret 4
// library wildmagic-2-core/Containment\WmlConvexHull3.cpp (function ??_GTriangle@?$ConvexHull3@M@Wml@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull3.cpp
