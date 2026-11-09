// from server: 100% by auto
// roc 2009-06 005bfea0  unit: RBX::VChunk::?$WeakReferenceCountedPointer  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005bfea0
//
// 005bfea0  55                   push ebp
// 005bfea1  8bec                 mov ebp, esp
// 005bfea3  51                   push ecx
// 005bfea4  894dfc               mov dword ptr [ebp - 4], ecx
// 005bfea7  8b4508               mov eax, dword ptr [ebp + 8]
// 005bfeaa  50                   push eax
// 005bfeab  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 005bfeae  e8adf9edff           call 0x49f860
// 005bfeb3  8b45fc               mov eax, dword ptr [ebp - 4]
// 005bfeb6  8be5                 mov esp, ebp
// 005bfeb8  5d                   pop ebp
// 005bfeb9  c20400               ret 4
// library wildmagic-2-core/Geometry\WmlConvexClipper.cpp (function ??0?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@QAE@ABV01@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Geometry/WmlConvexClipper.cpp
