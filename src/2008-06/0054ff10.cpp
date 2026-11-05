// from server: 100% by auto
// roc 2008-06 0054ff10  unit: seg_00540000  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0054ff10
//
// 0054ff10  55                   push ebp
// 0054ff11  8bec                 mov ebp, esp
// 0054ff13  51                   push ecx
// 0054ff14  894dfc               mov dword ptr [ebp - 4], ecx
// 0054ff17  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 0054ff1a  e821f1ffff           call 0x54f040
// 0054ff1f  8b45fc               mov eax, dword ptr [ebp - 4]
// 0054ff22  8be5                 mov esp, ebp
// 0054ff24  5d                   pop ebp
// 0054ff25  c3                   ret 
// library wildmagic-2-core/Containment\WmlConvexHull2.cpp (function ??0SortedVertex@?$ConvexHull2@M@Wml@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull2.cpp
