// from server: 100% by auto
// roc 2008-06 0053f1e0  unit: RBX::RenderBase::AggregatingSceneManager  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0053f1e0
//
// 0053f1e0  55                   push ebp
// 0053f1e1  8bec                 mov ebp, esp
// 0053f1e3  51                   push ecx
// 0053f1e4  894dfc               mov dword ptr [ebp - 4], ecx
// 0053f1e7  8b4508               mov eax, dword ptr [ebp + 8]
// 0053f1ea  50                   push eax
// 0053f1eb  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 0053f1ee  e8bd8bf9ff           call 0x4d7db0
// 0053f1f3  8be5                 mov esp, ebp
// 0053f1f5  5d                   pop ebp
// 0053f1f6  c20400               ret 4
// library wildmagic-2-core/Containment\WmlConvexHull2.cpp (function ??8SortedVertex@?$ConvexHull2@M@Wml@@QBE_NABV012@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull2.cpp
