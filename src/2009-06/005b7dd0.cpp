// from server: 100% by auto
// roc 2009-06 005b7dd0  unit: seg_005b0000  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005b7dd0
//
// 005b7dd0  55                   push ebp
// 005b7dd1  8bec                 mov ebp, esp
// 005b7dd3  51                   push ecx
// 005b7dd4  894dfc               mov dword ptr [ebp - 4], ecx
// 005b7dd7  8b4508               mov eax, dword ptr [ebp + 8]
// 005b7dda  50                   push eax
// 005b7ddb  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 005b7dde  e8ad180000           call 0x5b9690
// 005b7de3  8b45fc               mov eax, dword ptr [ebp - 4]
// 005b7de6  8be5                 mov esp, ebp
// 005b7de8  5d                   pop ebp
// 005b7de9  c20400               ret 4
// library wildmagic-2-core/Geometry\WmlConvexClipper.cpp (function ??0?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@QAE@ABV01@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Geometry/WmlConvexClipper.cpp
