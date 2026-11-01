// from server: 100% by auto
// roc 2009-06 005ae8c0  unit: RBX::Mesh  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005ae8c0
//
// 005ae8c0  55                   push ebp
// 005ae8c1  8bec                 mov ebp, esp
// 005ae8c3  51                   push ecx
// 005ae8c4  894dfc               mov dword ptr [ebp - 4], ecx
// 005ae8c7  8b4508               mov eax, dword ptr [ebp + 8]
// 005ae8ca  50                   push eax
// 005ae8cb  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 005ae8ce  e80d000000           call 0x5ae8e0
// 005ae8d3  8b45fc               mov eax, dword ptr [ebp - 4]
// 005ae8d6  8be5                 mov esp, ebp
// 005ae8d8  5d                   pop ebp
// 005ae8d9  c20400               ret 4
// library wildmagic-2-core/Geometry\WmlConvexClipper.cpp (function ??0?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@QAE@ABV01@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Geometry/WmlConvexClipper.cpp
