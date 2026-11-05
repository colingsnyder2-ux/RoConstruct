// from server: 100% by auto
// roc 2008-06 00540e60  unit: RBX::RenderBase::AggregatingSceneManager::Bucket  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00540e60
//
// 00540e60  55                   push ebp
// 00540e61  8bec                 mov ebp, esp
// 00540e63  51                   push ecx
// 00540e64  894dfc               mov dword ptr [ebp - 4], ecx
// 00540e67  8b4508               mov eax, dword ptr [ebp + 8]
// 00540e6a  50                   push eax
// 00540e6b  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 00540e6e  e87d170000           call 0x5425f0
// 00540e73  8b45fc               mov eax, dword ptr [ebp - 4]
// 00540e76  8be5                 mov esp, ebp
// 00540e78  5d                   pop ebp
// 00540e79  c20400               ret 4
// library wildmagic-2-core/Geometry\WmlConvexClipper.cpp (function ??0?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@QAE@ABV01@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Geometry/WmlConvexClipper.cpp
