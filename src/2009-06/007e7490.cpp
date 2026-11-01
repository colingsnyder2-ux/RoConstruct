// from server: 100% by auto
// roc 2009-06 007e7490  unit: CStatic  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007e7490
//
// 007e7490  8b442404             mov eax, dword ptr [esp + 4]
// 007e7494  894154               mov dword ptr [ecx + 0x54], eax
// 007e7497  8b4920               mov ecx, dword ptr [ecx + 0x20]
// 007e749a  85c9                 test ecx, ecx
// 007e749c  740b                 je 0x7e74a9
// 007e749e  6a00                 push 0
// 007e74a0  6a00                 push 0
// 007e74a2  51                   push ecx
// 007e74a3  ff157cee8900         call dword ptr [0x89ee7c]
// 007e74a9  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPImageEditor.cpp (function ?SetColor@CXTPImageEditorPicker@@QAEXK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPImageEditor.cpp
