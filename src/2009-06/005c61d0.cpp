// from server: 100% by auto
// roc 2009-06 005c61d0  unit: seg_005c0000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005c61d0
//
// 005c61d0  55                   push ebp
// 005c61d1  8bec                 mov ebp, esp
// 005c61d3  51                   push ecx
// 005c61d4  894dfc               mov dword ptr [ebp - 4], ecx
// 005c61d7  8b4508               mov eax, dword ptr [ebp + 8]
// 005c61da  50                   push eax
// 005c61db  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 005c61de  e81d080000           call 0x5c6a00
// 005c61e3  8be5                 mov esp, ebp
// 005c61e5  5d                   pop ebp
// 005c61e6  c20400               ret 4
// library wildmagic-2-core/Containment\WmlConvexHull2.cpp (function ??8SortedVertex@?$ConvexHull2@M@Wml@@QBE_NABV012@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull2.cpp
