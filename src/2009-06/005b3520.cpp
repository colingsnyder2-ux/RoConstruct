// from server: 100% by auto
// roc 2009-06 005b3520  unit: RBX::RenderNew::TextureProxy  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005b3520
//
// 005b3520  55                   push ebp
// 005b3521  8bec                 mov ebp, esp
// 005b3523  51                   push ecx
// 005b3524  894dfc               mov dword ptr [ebp - 4], ecx
// 005b3527  8b4508               mov eax, dword ptr [ebp + 8]
// 005b352a  50                   push eax
// 005b352b  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 005b352e  e82d0d0000           call 0x5b4260
// 005b3533  8be5                 mov esp, ebp
// 005b3535  5d                   pop ebp
// 005b3536  c20400               ret 4
// library wildmagic-2-core/Containment\WmlConvexHull2.cpp (function ??8SortedVertex@?$ConvexHull2@M@Wml@@QBE_NABV012@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull2.cpp
