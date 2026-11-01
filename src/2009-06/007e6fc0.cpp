// from server: 100% by auto
// roc 2009-06 007e6fc0  unit: CXTPImageEditorDlg::CDlgToolBar  size: 32 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007e6fc0
//
// 007e6fc0  8b442408             mov eax, dword ptr [esp + 8]
// 007e6fc4  99                   cdq 
// 007e6fc5  f7795c               idiv dword ptr [ecx + 0x5c]
// 007e6fc8  56                   push esi
// 007e6fc9  8b742408             mov esi, dword ptr [esp + 8]
// 007e6fcd  8906                 mov dword ptr [esi], eax
// 007e6fcf  8b442410             mov eax, dword ptr [esp + 0x10]
// 007e6fd3  99                   cdq 
// 007e6fd4  f77960               idiv dword ptr [ecx + 0x60]
// 007e6fd7  894604               mov dword ptr [esi + 4], eax
// 007e6fda  8bc6                 mov eax, esi
// 007e6fdc  5e                   pop esi
// 007e6fdd  c20c00               ret 0xc
// library xtp-15.2.1/Source\CommandBars\XTPImageEditor.cpp (function ?ClientToPicture@CXTPImageEditorPicture@@QAE?AVCPoint@@V2@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPImageEditor.cpp
