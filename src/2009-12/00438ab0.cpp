// from server: 100% by auto
// roc 2009-12 00438ab0  unit: RBX::Soundscape::VSoundId::?$XItem  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00438ab0
//
// 00438ab0  8b442408             mov eax, dword ptr [esp + 8]
// 00438ab4  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00438ab8  50                   push eax
// 00438ab9  51                   push ecx
// 00438aba  e8318c2700           call 0x6b16f0
// 00438abf  83c408               add esp, 8
// 00438ac2  c20800               ret 8
// library mfc-8.0/atlmfc\src\mfc\dlgdhtml.cpp (function ?GetUserDefinedType@CDHtmlControlSink@@QAEGPAUITypeInfo@@K@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/dlgdhtml.cpp
