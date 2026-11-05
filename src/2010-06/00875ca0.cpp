// from server: 100% by auto
// roc 2010-06 00875ca0  unit: CXTPImageEditorDlg::CDlgToolBar  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00875ca0
//
// 00875ca0  8b442408             mov eax, dword ptr [esp + 8]
// 00875ca4  99                   cdq 
// 00875ca5  f7795c               idiv dword ptr [ecx + 0x5c]
// 00875ca8  56                   push esi
// 00875ca9  8b742408             mov esi, dword ptr [esp + 8]
// 00875cad  8906                 mov dword ptr [esi], eax
// 00875caf  8b442410             mov eax, dword ptr [esp + 0x10]
// 00875cb3  99                   cdq 
// 00875cb4  f77960               idiv dword ptr [ecx + 0x60]
// 00875cb7  894604               mov dword ptr [esi + 4], eax
// 00875cba  8bc6                 mov eax, esi
// 00875cbc  5e                   pop esi
// 00875cbd  c20c00               ret 0xc
// library xtp-13.2.1/Source\CommandBars\XTPImageEditor.cpp (function ?ClientToPicture@CXTPImageEditorPicture@@QAE?AVCPoint@@V2@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPImageEditor.cpp
