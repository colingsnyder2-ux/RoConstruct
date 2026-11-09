// from server: 100% by auto
// roc 2009-06 005c6e40  unit: seg_005c0000  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005c6e40
//
// 005c6e40  55                   push ebp
// 005c6e41  8bec                 mov ebp, esp
// 005c6e43  51                   push ecx
// 005c6e44  894dfc               mov dword ptr [ebp - 4], ecx
// 005c6e47  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 005c6e4a  e801c1ffff           call 0x5c2f50
// 005c6e4f  8b45fc               mov eax, dword ptr [ebp - 4]
// 005c6e52  8be5                 mov esp, ebp
// 005c6e54  5d                   pop ebp
// 005c6e55  c3                   ret 
// library wildmagic-2-core/Containment\WmlConvexHull2.cpp (function ??0SortedVertex@?$ConvexHull2@M@Wml@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull2.cpp
