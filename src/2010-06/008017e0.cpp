// from server: 100% by auto
// roc 2010-06 008017e0  unit: XTP_PRINT_STATE  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008017e0
//
// 008017e0  f644240401           test byte ptr [esp + 4], 1
// 008017e5  56                   push esi
// 008017e6  8bf1                 mov esi, ecx
// 008017e8  7406                 je 0x8017f0
// 008017ea  56                   push esi
// 008017eb  e870b51700           call 0x97cd60
// 008017f0  8bc6                 mov eax, esi
// 008017f2  5e                   pop esi
// 008017f3  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxtls.cpp (function ??_GCThreadData@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxtls.cpp
