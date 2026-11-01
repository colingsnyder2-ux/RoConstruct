// from server: 100% by auto
// roc 2009-06 007e7cf0  unit: CXTPImageEditorDlg  size: 40 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007e7cf0
//
// 007e7cf0  56                   push esi
// 007e7cf1  57                   push edi
// 007e7cf2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 007e7cf6  8bf1                 mov esi, ecx
// 007e7cf8  8d4674               lea eax, [esi + 0x74]
// 007e7cfb  50                   push eax
// 007e7cfc  6a67                 push 0x67
// 007e7cfe  57                   push edi
// 007e7cff  e88216f3ff           call 0x719386
// 007e7d04  81c6c8000000         add esi, 0xc8
// 007e7d0a  56                   push esi
// 007e7d0b  6a68                 push 0x68
// 007e7d0d  57                   push edi
// 007e7d0e  e87316f3ff           call 0x719386
// 007e7d13  5f                   pop edi
// 007e7d14  5e                   pop esi
// 007e7d15  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPImageEditor.cpp (function ?DoDataExchange@CXTPImageEditorDlg@@MAEXPAVCDataExchange@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPImageEditor.cpp
