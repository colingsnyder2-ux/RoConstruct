// from server: 100% by auto
// roc 2009-06 005c7910  unit: seg_005c0000  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005c7910
//
// 005c7910  55                   push ebp
// 005c7911  8bec                 mov ebp, esp
// 005c7913  51                   push ecx
// 005c7914  894dfc               mov dword ptr [ebp - 4], ecx
// 005c7917  8b4508               mov eax, dword ptr [ebp + 8]
// 005c791a  50                   push eax
// 005c791b  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 005c791e  e8cd020000           call 0x5c7bf0
// 005c7923  8b45fc               mov eax, dword ptr [ebp - 4]
// 005c7926  8be5                 mov esp, ebp
// 005c7928  5d                   pop ebp
// 005c7929  c20400               ret 4
// library wildmagic-2-core/Geometry\WmlConvexClipper.cpp (function ??0?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@QAE@ABV01@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Geometry/WmlConvexClipper.cpp
