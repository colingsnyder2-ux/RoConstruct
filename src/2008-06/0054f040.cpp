// from server: 100% by auto
// roc 2008-06 0054f040  unit: seg_00540000  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0054f040
//
// 0054f040  55                   push ebp
// 0054f041  8bec                 mov ebp, esp
// 0054f043  51                   push ecx
// 0054f044  894dfc               mov dword ptr [ebp - 4], ecx
// 0054f047  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 0054f04a  e8210f0000           call 0x54ff70
// 0054f04f  8b45fc               mov eax, dword ptr [ebp - 4]
// 0054f052  8be5                 mov esp, ebp
// 0054f054  5d                   pop ebp
// 0054f055  c3                   ret 
// library wildmagic-2-core/Containment\WmlConvexHull2.cpp (function ??0SortedVertex@?$ConvexHull2@M@Wml@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull2.cpp
