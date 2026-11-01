// from server: 100% by auto
// roc 2009-06 007cd540  unit: CXTPDockingPaneBase  size: 59 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007cd540
//
// 007cd540  8b5108               mov edx, dword ptr [ecx + 8]
// 007cd543  85d2                 test edx, edx
// 007cd545  7505                 jne 0x7cd54c
// 007cd547  e898b7f4ff           call 0x718ce4
// 007cd54c  8b4204               mov eax, dword ptr [edx + 4]
// 007cd54f  56                   push esi
// 007cd550  8b7208               mov esi, dword ptr [edx + 8]
// 007cd553  894108               mov dword ptr [ecx + 8], eax
// 007cd556  85c0                 test eax, eax
// 007cd558  7410                 je 0x7cd56a
// 007cd55a  52                   push edx
// 007cd55b  c70000000000         mov dword ptr [eax], 0
// 007cd561  e80a410100           call 0x7e1670
// 007cd566  8bc6                 mov eax, esi
// 007cd568  5e                   pop esi
// 007cd569  c3                   ret 
// 007cd56a  52                   push edx
// 007cd56b  c7410400000000       mov dword ptr [ecx + 4], 0
// 007cd572  e8f9400100           call 0x7e1670
// 007cd577  8bc6                 mov eax, esi
// 007cd579  5e                   pop esi
// 007cd57a  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPImageEditor.cpp (function ?RemoveTail@?$CList@PAVCAlphaBitmap@CXTPImageEditorPicture@@PAV12@@@QAEPAVCAlphaBitmap@CXTPImageEditorPicture@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPImageEditor.cpp
