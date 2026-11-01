// from server: 100% by auto
// roc 2009-12 008a8350  unit: CXTPDockingPaneBase  size: 59 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008a8350
//
// 008a8350  8b5108               mov edx, dword ptr [ecx + 8]
// 008a8353  85d2                 test edx, edx
// 008a8355  7505                 jne 0x8a835c
// 008a8357  e8b0b7f4ff           call 0x7f3b0c
// 008a835c  8b4204               mov eax, dword ptr [edx + 4]
// 008a835f  56                   push esi
// 008a8360  8b7208               mov esi, dword ptr [edx + 8]
// 008a8363  894108               mov dword ptr [ecx + 8], eax
// 008a8366  85c0                 test eax, eax
// 008a8368  7410                 je 0x8a837a
// 008a836a  52                   push edx
// 008a836b  c70000000000         mov dword ptr [eax], 0
// 008a8371  e80afcffff           call 0x8a7f80
// 008a8376  8bc6                 mov eax, esi
// 008a8378  5e                   pop esi
// 008a8379  c3                   ret 
// 008a837a  52                   push edx
// 008a837b  c7410400000000       mov dword ptr [ecx + 4], 0
// 008a8382  e8f9fbffff           call 0x8a7f80
// 008a8387  8bc6                 mov eax, esi
// 008a8389  5e                   pop esi
// 008a838a  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPImageEditor.cpp (function ?RemoveTail@?$CList@PAVCAlphaBitmap@CXTPImageEditorPicture@@PAV12@@@QAEPAVCAlphaBitmap@CXTPImageEditorPicture@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPImageEditor.cpp
