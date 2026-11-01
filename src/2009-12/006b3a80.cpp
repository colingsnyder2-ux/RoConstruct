// from server: 100% by auto
// roc 2009-12 006b3a80  unit: RBX::DropperTool  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006b3a80
//
// 006b3a80  8b442408             mov eax, dword ptr [esp + 8]
// 006b3a84  8b4c2404             mov ecx, dword ptr [esp + 4]
// 006b3a88  50                   push eax
// 006b3a89  51                   push ecx
// 006b3a8a  e841dcffff           call 0x6b16d0
// 006b3a8f  83c408               add esp, 8
// 006b3a92  c20800               ret 8
// library mfc-8.0/atlmfc\src\mfc\dlgdhtml.cpp (function ?GetUserDefinedType@CDHtmlControlSink@@QAEGPAUITypeInfo@@K@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/dlgdhtml.cpp
