// from server: 100% by auto
// roc 2010-06 008769d0  unit: CXTPImageEditorDlg  size: 40 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008769d0
//
// 008769d0  56                   push esi
// 008769d1  57                   push edi
// 008769d2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 008769d6  8bf1                 mov esi, ecx
// 008769d8  8d4674               lea eax, [esi + 0x74]
// 008769db  50                   push eax
// 008769dc  6a67                 push 0x67
// 008769de  57                   push edi
// 008769df  e80a19f3ff           call 0x7a82ee
// 008769e4  81c6c8000000         add esi, 0xc8
// 008769ea  56                   push esi
// 008769eb  6a68                 push 0x68
// 008769ed  57                   push edi
// 008769ee  e8fb18f3ff           call 0x7a82ee
// 008769f3  5f                   pop edi
// 008769f4  5e                   pop esi
// 008769f5  c20400               ret 4
// library xtp-13.2.1/Source\CommandBars\XTPImageEditor.cpp (function ?DoDataExchange@CXTPImageEditorDlg@@MAEXPAVCDataExchange@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPImageEditor.cpp
