// from server: 100% by auto
// roc 2008-06 00541100  unit: RBX::RenderBase::VChunk::?$WeakReferenceCountedPointer  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00541100
//
// 00541100  55                   push ebp
// 00541101  8bec                 mov ebp, esp
// 00541103  51                   push ecx
// 00541104  894dfc               mov dword ptr [ebp - 4], ecx
// 00541107  8b4508               mov eax, dword ptr [ebp + 8]
// 0054110a  50                   push eax
// 0054110b  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 0054110e  e88d7e0500           call 0x598fa0
// 00541113  8b45fc               mov eax, dword ptr [ebp - 4]
// 00541116  8be5                 mov esp, ebp
// 00541118  5d                   pop ebp
// 00541119  c20400               ret 4
// library wildmagic-2-core/Geometry\WmlConvexClipper.cpp (function ??0?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@QAE@ABV01@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Geometry/WmlConvexClipper.cpp
