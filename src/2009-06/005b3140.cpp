// from server: 100% by auto
// roc 2009-06 005b3140  unit: RBX::RenderNew::TextureProxy  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005b3140
//
// 005b3140  55                   push ebp
// 005b3141  8bec                 mov ebp, esp
// 005b3143  51                   push ecx
// 005b3144  894dfc               mov dword ptr [ebp - 4], ecx
// 005b3147  8b4508               mov eax, dword ptr [ebp + 8]
// 005b314a  50                   push eax
// 005b314b  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 005b314e  e8cdffffff           call 0x5b3120
// 005b3153  8be5                 mov esp, ebp
// 005b3155  5d                   pop ebp
// 005b3156  c20400               ret 4
// library wildmagic-2-core/Containment\WmlConvexHull2.cpp (function ??8SortedVertex@?$ConvexHull2@M@Wml@@QBE_NABV012@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull2.cpp
