// from server: 100% by auto
// roc 2011-06 0085f260  unit: XTP_PRINT_STATE  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0085f260
//
// 0085f260  f644240401           test byte ptr [esp + 4], 1
// 0085f265  56                   push esi
// 0085f266  8bf1                 mov esi, ecx
// 0085f268  7406                 je 0x85f270
// 0085f26a  56                   push esi
// 0085f26b  e83cd31600           call 0x9cc5ac
// 0085f270  8bc6                 mov eax, esi
// 0085f272  5e                   pop esi
// 0085f273  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxtls.cpp (function ??_GCThreadData@@UAEPAXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxtls.cpp
