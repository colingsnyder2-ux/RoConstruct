// from server: 100% by auto
// roc 2009-06 005b61a0  unit: seg_005b0000  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005b61a0
//
// 005b61a0  55                   push ebp
// 005b61a1  8bec                 mov ebp, esp
// 005b61a3  51                   push ecx
// 005b61a4  894dfc               mov dword ptr [ebp - 4], ecx
// 005b61a7  8b4508               mov eax, dword ptr [ebp + 8]
// 005b61aa  50                   push eax
// 005b61ab  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 005b61ae  e8bd070000           call 0x5b6970
// 005b61b3  8b45fc               mov eax, dword ptr [ebp - 4]
// 005b61b6  8be5                 mov esp, ebp
// 005b61b8  5d                   pop ebp
// 005b61b9  c20400               ret 4
// library wildmagic-2-core/Geometry\WmlConvexClipper.cpp (function ??0?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@QAE@ABV01@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Geometry/WmlConvexClipper.cpp
