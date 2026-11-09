// from server: 100% by auto
// roc 2008-06 00545710  unit: seg_00540000  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00545710
//
// 00545710  55                   push ebp
// 00545711  8bec                 mov ebp, esp
// 00545713  51                   push ecx
// 00545714  894dfc               mov dword ptr [ebp - 4], ecx
// 00545717  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 0054571a  e881ecffff           call 0x5443a0
// 0054571f  8b45fc               mov eax, dword ptr [ebp - 4]
// 00545722  8be5                 mov esp, ebp
// 00545724  5d                   pop ebp
// 00545725  c3                   ret 
// library wildmagic-2-core/Containment\WmlConvexHull2.cpp (function ??0SortedVertex@?$ConvexHull2@M@Wml@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull2.cpp
