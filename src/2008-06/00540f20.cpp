// from server: 100% by auto
// roc 2008-06 00540f20  unit: RBX::RenderBase::AggregatingSceneManager::Bucket  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00540f20
//
// 00540f20  55                   push ebp
// 00540f21  8bec                 mov ebp, esp
// 00540f23  51                   push ecx
// 00540f24  894dfc               mov dword ptr [ebp - 4], ecx
// 00540f27  8b4508               mov eax, dword ptr [ebp + 8]
// 00540f2a  50                   push eax
// 00540f2b  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 00540f2e  e89dffffff           call 0x540ed0
// 00540f33  0fb6c0               movzx eax, al
// 00540f36  f7d8                 neg eax
// 00540f38  1bc0                 sbb eax, eax
// 00540f3a  83c001               add eax, 1
// 00540f3d  8be5                 mov esp, ebp
// 00540f3f  5d                   pop ebp
// 00540f40  c20400               ret 4
// library wildmagic-2-core/Containment\WmlConvexHull2.cpp (function ??9SortedVertex@?$ConvexHull2@M@Wml@@QBE_NABV012@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull2.cpp
