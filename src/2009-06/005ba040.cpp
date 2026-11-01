// from server: 100% by auto
// roc 2009-06 005ba040  unit: seg_005b0000  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005ba040
//
// 005ba040  55                   push ebp
// 005ba041  8bec                 mov ebp, esp
// 005ba043  51                   push ecx
// 005ba044  894dfc               mov dword ptr [ebp - 4], ecx
// 005ba047  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 005ba04a  e8e19affff           call 0x5b3b30
// 005ba04f  8b45fc               mov eax, dword ptr [ebp - 4]
// 005ba052  8be5                 mov esp, ebp
// 005ba054  5d                   pop ebp
// 005ba055  c3                   ret 
// library wildmagic-2-core/Containment\WmlConvexHull2.cpp (function ??0SortedVertex@?$ConvexHull2@M@Wml@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull2.cpp
