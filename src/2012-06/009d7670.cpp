// from server: 100% by auto
// roc 2012-06 009d7670  unit: XTP_PRINT_STATE  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009d7670
//
// 009d7670  f644240401           test byte ptr [esp + 4], 1
// 009d7675  56                   push esi
// 009d7676  8bf1                 mov esi, ecx
// 009d7678  7406                 je 0x9d7680
// 009d767a  56                   push esi
// 009d767b  e8e61e0c00           call 0xa99566
// 009d7680  8bc6                 mov eax, esi
// 009d7682  5e                   pop esi
// 009d7683  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxtls.cpp (function ??_GCThreadData@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxtls.cpp
