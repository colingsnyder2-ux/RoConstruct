// from server: 100% by auto
// roc 2009-06 005ab4e0  unit: RBX::Mesh  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005ab4e0
//
// 005ab4e0  55                   push ebp
// 005ab4e1  8bec                 mov ebp, esp
// 005ab4e3  51                   push ecx
// 005ab4e4  894dfc               mov dword ptr [ebp - 4], ecx
// 005ab4e7  8b4508               mov eax, dword ptr [ebp + 8]
// 005ab4ea  50                   push eax
// 005ab4eb  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 005ab4ee  e82dffffff           call 0x5ab420
// 005ab4f3  8be5                 mov esp, ebp
// 005ab4f5  5d                   pop ebp
// 005ab4f6  c20400               ret 4
// library wildmagic-2-core/Containment\WmlConvexHull2.cpp (function ??8SortedVertex@?$ConvexHull2@M@Wml@@QBE_NABV012@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
// roc-lib: wildmagic-2-core Containment/WmlConvexHull2.cpp
