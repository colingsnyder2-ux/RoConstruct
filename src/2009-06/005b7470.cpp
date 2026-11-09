// from server: 100% by auto
// roc 2009-06 005b7470  unit: seg_005b0000  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005b7470
//
// 005b7470  55                   push ebp
// 005b7471  8bec                 mov ebp, esp
// 005b7473  51                   push ecx
// 005b7474  894dfc               mov dword ptr [ebp - 4], ecx
// 005b7477  8b4508               mov eax, dword ptr [ebp + 8]
// 005b747a  50                   push eax
// 005b747b  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 005b747e  e86d1d0000           call 0x5b91f0
// 005b7483  8b45fc               mov eax, dword ptr [ebp - 4]
// 005b7486  8be5                 mov esp, ebp
// 005b7488  5d                   pop ebp
// 005b7489  c20400               ret 4
// library wildmagic-2-core/Geometry\WmlConvexClipper.cpp (function ??0?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@QAE@ABV01@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Geometry/WmlConvexClipper.cpp
