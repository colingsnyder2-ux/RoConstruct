// from server: 100% by auto
// roc 2008-06 00553600  unit: RBX::RenderBase::AggregateChunk  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00553600
//
// 00553600  55                   push ebp
// 00553601  8bec                 mov ebp, esp
// 00553603  51                   push ecx
// 00553604  894dfc               mov dword ptr [ebp - 4], ecx
// 00553607  8b4508               mov eax, dword ptr [ebp + 8]
// 0055360a  50                   push eax
// 0055360b  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 0055360e  e88dfeffff           call 0x5534a0
// 00553613  8b45fc               mov eax, dword ptr [ebp - 4]
// 00553616  8be5                 mov esp, ebp
// 00553618  5d                   pop ebp
// 00553619  c20400               ret 4
// library wildmagic-2-core/Geometry\WmlConvexClipper.cpp (function ??0?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@QAE@ABV01@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Geometry/WmlConvexClipper.cpp
