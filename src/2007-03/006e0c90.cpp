// from server: 100% by auto
// roc 2007-03 006e0c90  unit: seg_006e0000  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006e0c90
//
// 006e0c90  8b442404             mov eax, dword ptr [esp + 4]
// 006e0c94  894158               mov dword ptr [ecx + 0x58], eax
// 006e0c97  8b4920               mov ecx, dword ptr [ecx + 0x20]
// 006e0c9a  85c9                 test ecx, ecx
// 006e0c9c  740b                 je 0x6e0ca9
// 006e0c9e  6a00                 push 0
// 006e0ca0  6a00                 push 0
// 006e0ca2  51                   push ecx
// 006e0ca3  ff1554ee7700         call dword ptr [0x77ee54]
// 006e0ca9  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPImageEditor.cpp (function ?SetSelected@CXTPImageEditorPicker@@QAEXH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPImageEditor.cpp
