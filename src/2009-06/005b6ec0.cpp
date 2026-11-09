// from server: 100% by auto
// roc 2009-06 005b6ec0  unit: seg_005b0000  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005b6ec0
//
// 005b6ec0  55                   push ebp
// 005b6ec1  8bec                 mov ebp, esp
// 005b6ec3  51                   push ecx
// 005b6ec4  894dfc               mov dword ptr [ebp - 4], ecx
// 005b6ec7  8b4508               mov eax, dword ptr [ebp + 8]
// 005b6eca  50                   push eax
// 005b6ecb  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 005b6ece  e84d000000           call 0x5b6f20
// 005b6ed3  0fb6c0               movzx eax, al
// 005b6ed6  f7d8                 neg eax
// 005b6ed8  1bc0                 sbb eax, eax
// 005b6eda  83c001               add eax, 1
// 005b6edd  8be5                 mov esp, ebp
// 005b6edf  5d                   pop ebp
// 005b6ee0  c20400               ret 4
// library wildmagic-2-core/Containment\WmlConvexHull2.cpp (function ??9SortedVertex@?$ConvexHull2@M@Wml@@QBE_NABV012@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull2.cpp
