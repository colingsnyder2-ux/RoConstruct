// from server: 100% by auto
// roc 2009-12 008c1a80  unit: CXTPImageEditorDlg::CDlgToolBar  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008c1a80
//
// 008c1a80  8b442408             mov eax, dword ptr [esp + 8]
// 008c1a84  99                   cdq 
// 008c1a85  f7795c               idiv dword ptr [ecx + 0x5c]
// 008c1a88  56                   push esi
// 008c1a89  8b742408             mov esi, dword ptr [esp + 8]
// 008c1a8d  8906                 mov dword ptr [esi], eax
// 008c1a8f  8b442410             mov eax, dword ptr [esp + 0x10]
// 008c1a93  99                   cdq 
// 008c1a94  f77960               idiv dword ptr [ecx + 0x60]
// 008c1a97  894604               mov dword ptr [esi + 4], eax
// 008c1a9a  8bc6                 mov eax, esi
// 008c1a9c  5e                   pop esi
// 008c1a9d  c20c00               ret 0xc
// library xtp-15.2.1/Source\CommandBars\XTPImageEditor.cpp (function ?ClientToPicture@CXTPImageEditorPicture@@QAE?AVCPoint@@V2@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPImageEditor.cpp
