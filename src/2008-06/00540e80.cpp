// from server: 100% by auto
// roc 2008-06 00540e80  unit: RBX::RenderBase::AggregatingSceneManager::Bucket  size: 16 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00540e80
//
// 00540e80  55                   push ebp
// 00540e81  8bec                 mov ebp, esp
// 00540e83  51                   push ecx
// 00540e84  894dfc               mov dword ptr [ebp - 4], ecx
// 00540e87  8b45fc               mov eax, dword ptr [ebp - 4]
// 00540e8a  8b00                 mov eax, dword ptr [eax]
// 00540e8c  8be5                 mov esp, ebp
// 00540e8e  5d                   pop ebp
// 00540e8f  c3                   ret 
// library wildmagic-2-core/Geometry\WmlConvexClipper.cpp (function ?GetQuantity@?$UnorderedSet@VMTVertex@Wml@@@Wml@@QBEHXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Geometry/WmlConvexClipper.cpp
