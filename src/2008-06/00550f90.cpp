// from server: 100% by auto
// roc 2008-06 00550f90  unit: seg_00550000  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00550f90
//
// 00550f90  55                   push ebp
// 00550f91  8bec                 mov ebp, esp
// 00550f93  51                   push ecx
// 00550f94  894dfc               mov dword ptr [ebp - 4], ecx
// 00550f97  8b4508               mov eax, dword ptr [ebp + 8]
// 00550f9a  50                   push eax
// 00550f9b  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 00550f9e  e80d000000           call 0x550fb0
// 00550fa3  8b45fc               mov eax, dword ptr [ebp - 4]
// 00550fa6  8be5                 mov esp, ebp
// 00550fa8  5d                   pop ebp
// 00550fa9  c20400               ret 4
// library wildmagic-2-core/Geometry\WmlConvexClipper.cpp (function ??0?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@QAE@ABV01@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Geometry/WmlConvexClipper.cpp
