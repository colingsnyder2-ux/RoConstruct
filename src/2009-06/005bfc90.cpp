// from server: 100% by auto
// roc 2009-06 005bfc90  unit: RBX::AggregatingSceneManager::Bucket  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005bfc90
//
// 005bfc90  55                   push ebp
// 005bfc91  8bec                 mov ebp, esp
// 005bfc93  51                   push ecx
// 005bfc94  894dfc               mov dword ptr [ebp - 4], ecx
// 005bfc97  8b4508               mov eax, dword ptr [ebp + 8]
// 005bfc9a  50                   push eax
// 005bfc9b  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 005bfc9e  e87d150000           call 0x5c1220
// 005bfca3  8b45fc               mov eax, dword ptr [ebp - 4]
// 005bfca6  8be5                 mov esp, ebp
// 005bfca8  5d                   pop ebp
// 005bfca9  c20400               ret 4
// library wildmagic-2-core/Geometry\WmlConvexClipper.cpp (function ??0?$set@HU?$less@H@std@@V?$allocator@H@2@@std@@QAE@ABV01@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Geometry/WmlConvexClipper.cpp
