// from server: 100% by auto
// roc 2010-06 00876cb0  unit: CXTPImageEditorDlg  size: 59 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00876cb0
//
// 00876cb0  8b5108               mov edx, dword ptr [ecx + 8]
// 00876cb3  85d2                 test edx, edx
// 00876cb5  7505                 jne 0x876cbc
// 00876cb7  e8900ff3ff           call 0x7a7c4c
// 00876cbc  8b4204               mov eax, dword ptr [edx + 4]
// 00876cbf  56                   push esi
// 00876cc0  8b7208               mov esi, dword ptr [edx + 8]
// 00876cc3  894108               mov dword ptr [ecx + 8], eax
// 00876cc6  85c0                 test eax, eax
// 00876cc8  7410                 je 0x876cda
// 00876cca  52                   push edx
// 00876ccb  c70000000000         mov dword ptr [eax], 0
// 00876cd1  e82a54feff           call 0x85c100
// 00876cd6  8bc6                 mov eax, esi
// 00876cd8  5e                   pop esi
// 00876cd9  c3                   ret 
// 00876cda  52                   push edx
// 00876cdb  c7410400000000       mov dword ptr [ecx + 4], 0
// 00876ce2  e81954feff           call 0x85c100
// 00876ce7  8bc6                 mov eax, esi
// 00876ce9  5e                   pop esi
// 00876cea  c3                   ret 
// library xtp-13.2.1/Source\CommandBars\XTPImageEditor.cpp (function ?RemoveTail@?$CList@PAVCAlphaBitmap@CXTPImageEditorPicture@@PAV12@@@QAEPAVCAlphaBitmap@CXTPImageEditorPicture@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPImageEditor.cpp
