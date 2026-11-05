// from server: 100% by auto
// roc 2008-06 006fa0b0  unit: XTP_PRINT_STATE  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006fa0b0
//
// 006fa0b0  f644240401           test byte ptr [esp + 4], 1
// 006fa0b5  56                   push esi
// 006fa0b6  8bf1                 mov esi, ecx
// 006fa0b8  7406                 je 0x6fa0c0
// 006fa0ba  56                   push esi
// 006fa0bb  e8de1e0c00           call 0x7bbf9e
// 006fa0c0  8bc6                 mov eax, esi
// 006fa0c2  5e                   pop esi
// 006fa0c3  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxtls.cpp (function ??_GCThreadData@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxtls.cpp
