// from server: 100% by auto
// roc 2009-06 005b8980  unit: seg_005b0000  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005b8980
//
// 005b8980  55                   push ebp
// 005b8981  8bec                 mov ebp, esp
// 005b8983  51                   push ecx
// 005b8984  894dfc               mov dword ptr [ebp - 4], ecx
// 005b8987  8b4508               mov eax, dword ptr [ebp + 8]
// 005b898a  50                   push eax
// 005b898b  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 005b898e  e88d050000           call 0x5b8f20
// 005b8993  8b45fc               mov eax, dword ptr [ebp - 4]
// 005b8996  8be5                 mov esp, ebp
// 005b8998  5d                   pop ebp
// 005b8999  c20400               ret 4
// library wildmagic-2-core/Geometry\WmlConvexClipper.cpp (function ??0?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@QAE@ABV01@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Geometry/WmlConvexClipper.cpp
