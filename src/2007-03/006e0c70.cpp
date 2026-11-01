// from server: 100% by auto
// roc 2007-03 006e0c70  unit: seg_006e0000  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006e0c70
//
// 006e0c70  8b442404             mov eax, dword ptr [esp + 4]
// 006e0c74  894154               mov dword ptr [ecx + 0x54], eax
// 006e0c77  8b4920               mov ecx, dword ptr [ecx + 0x20]
// 006e0c7a  85c9                 test ecx, ecx
// 006e0c7c  740b                 je 0x6e0c89
// 006e0c7e  6a00                 push 0
// 006e0c80  6a00                 push 0
// 006e0c82  51                   push ecx
// 006e0c83  ff1554ee7700         call dword ptr [0x77ee54]
// 006e0c89  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPImageEditor.cpp (function ?SetColor@CXTPImageEditorPicker@@QAEXK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPImageEditor.cpp
