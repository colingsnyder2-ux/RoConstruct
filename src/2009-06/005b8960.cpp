// from server: 100% by auto
// roc 2009-06 005b8960  unit: seg_005b0000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005b8960
//
// 005b8960  55                   push ebp
// 005b8961  8bec                 mov ebp, esp
// 005b8963  51                   push ecx
// 005b8964  894dfc               mov dword ptr [ebp - 4], ecx
// 005b8967  8b4508               mov eax, dword ptr [ebp + 8]
// 005b896a  50                   push eax
// 005b896b  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 005b896e  e85d050000           call 0x5b8ed0
// 005b8973  8be5                 mov esp, ebp
// 005b8975  5d                   pop ebp
// 005b8976  c20400               ret 4
// library wildmagic-2-core/Containment\WmlConvexHull2.cpp (function ??8SortedVertex@?$ConvexHull2@M@Wml@@QBE_NABV012@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull2.cpp
