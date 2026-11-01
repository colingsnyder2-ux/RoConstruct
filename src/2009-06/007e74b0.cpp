// from server: 100% by auto
// roc 2009-06 007e74b0  unit: CStatic  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007e74b0
//
// 007e74b0  8b442404             mov eax, dword ptr [esp + 4]
// 007e74b4  894158               mov dword ptr [ecx + 0x58], eax
// 007e74b7  8b4920               mov ecx, dword ptr [ecx + 0x20]
// 007e74ba  85c9                 test ecx, ecx
// 007e74bc  740b                 je 0x7e74c9
// 007e74be  6a00                 push 0
// 007e74c0  6a00                 push 0
// 007e74c2  51                   push ecx
// 007e74c3  ff157cee8900         call dword ptr [0x89ee7c]
// 007e74c9  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPImageEditor.cpp (function ?SetSelected@CXTPImageEditorPicker@@QAEXH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPImageEditor.cpp
