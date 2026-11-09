// from server: 100% by auto
// roc 2008-06 005467e0  unit: seg_00540000  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005467e0
//
// 005467e0  55                   push ebp
// 005467e1  8bec                 mov ebp, esp
// 005467e3  51                   push ecx
// 005467e4  894dfc               mov dword ptr [ebp - 4], ecx
// 005467e7  8b4508               mov eax, dword ptr [ebp + 8]
// 005467ea  50                   push eax
// 005467eb  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 005467ee  e80d000000           call 0x546800
// 005467f3  8b45fc               mov eax, dword ptr [ebp - 4]
// 005467f6  8be5                 mov esp, ebp
// 005467f8  5d                   pop ebp
// 005467f9  c20400               ret 4
// library wildmagic-2-core/Geometry\WmlConvexClipper.cpp (function ??0?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@QAE@ABV01@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Geometry/WmlConvexClipper.cpp
