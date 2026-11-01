// from server: 100% by auto
// roc 2009-06 005b7d10  unit: seg_005b0000  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005b7d10
//
// 005b7d10  55                   push ebp
// 005b7d11  8bec                 mov ebp, esp
// 005b7d13  51                   push ecx
// 005b7d14  894dfc               mov dword ptr [ebp - 4], ecx
// 005b7d17  8b4508               mov eax, dword ptr [ebp + 8]
// 005b7d1a  50                   push eax
// 005b7d1b  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 005b7d1e  e84d180000           call 0x5b9570
// 005b7d23  8b45fc               mov eax, dword ptr [ebp - 4]
// 005b7d26  8be5                 mov esp, ebp
// 005b7d28  5d                   pop ebp
// 005b7d29  c20400               ret 4
// library wildmagic-2-core/Geometry\WmlConvexClipper.cpp (function ??0?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@QAE@ABV01@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Geometry/WmlConvexClipper.cpp
