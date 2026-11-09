// from server: 100% by auto
// roc 2009-06 005c6020  unit: seg_005c0000  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005c6020
//
// 005c6020  55                   push ebp
// 005c6021  8bec                 mov ebp, esp
// 005c6023  51                   push ecx
// 005c6024  894dfc               mov dword ptr [ebp - 4], ecx
// 005c6027  8b4508               mov eax, dword ptr [ebp + 8]
// 005c602a  50                   push eax
// 005c602b  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 005c602e  e8fd060000           call 0x5c6730
// 005c6033  0fb6c0               movzx eax, al
// 005c6036  f7d8                 neg eax
// 005c6038  1bc0                 sbb eax, eax
// 005c603a  83c001               add eax, 1
// 005c603d  8be5                 mov esp, ebp
// 005c603f  5d                   pop ebp
// 005c6040  c20400               ret 4
// library wildmagic-2-core/Containment\WmlConvexHull2.cpp (function ??9SortedVertex@?$ConvexHull2@M@Wml@@QBE_NABV012@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull2.cpp
