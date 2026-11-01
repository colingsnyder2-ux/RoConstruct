// from server: 100% by auto
// roc 2007-08 006f0fe0  unit: CXTPImageEditorPicker  size: 61 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006f0fe0
//
// 006f0fe0  56                   push esi
// 006f0fe1  8bf1                 mov esi, ecx
// 006f0fe3  8b4620               mov eax, dword ptr [esi + 0x20]
// 006f0fe6  50                   push eax
// 006f0fe7  ff15a0ed7700         call dword ptr [0x77eda0]
// 006f0fed  85c0                 test eax, eax
// 006f0fef  7426                 je 0x6f1017
// 006f0ff1  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 006f0ff4  51                   push ecx
// 006f0ff5  ff15f8eb7700         call dword ptr [0x77ebf8]
// 006f0ffb  50                   push eax
// 006f0ffc  e8bff1f3ff           call 0x6301c0
// 006f1001  85c0                 test eax, eax
// 006f1003  7412                 je 0x6f1017
// 006f1005  8b4c2408             mov ecx, dword ptr [esp + 8]
// 006f1009  8b16                 mov edx, dword ptr [esi]
// 006f100b  8b9244010000         mov edx, dword ptr [edx + 0x144]
// 006f1011  51                   push ecx
// 006f1012  50                   push eax
// 006f1013  8bce                 mov ecx, esi
// 006f1015  ffd2                 call edx
// 006f1017  33c0                 xor eax, eax
// 006f1019  5e                   pop esi
// 006f101a  c20800               ret 8
// library xtp-13.2.1/Source\CommandBars\XTPImageEditor.cpp (function ?OnIdleUpdateCmdUI@CDlgToolBar@CXTPImageEditorDlg@@QAEJIJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPImageEditor.cpp
