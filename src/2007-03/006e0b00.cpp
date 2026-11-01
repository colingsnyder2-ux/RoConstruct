// from server: 100% by auto
// roc 2007-03 006e0b00  unit: seg_006e0000  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006e0b00
//
// 006e0b00  56                   push esi
// 006e0b01  8bf1                 mov esi, ecx
// 006e0b03  c786c000000000000000 mov dword ptr [esi + 0xc0], 0
// 006e0b0d  ff150ced7700         call dword ptr [0x77ed0c]
// 006e0b13  8bce                 mov ecx, esi
// 006e0b15  e8b8dbf3ff           call 0x61e6d2
// 006e0b1a  5e                   pop esi
// 006e0b1b  c20c00               ret 0xc
// library xtp-15.2.1/Source\CommandBars\XTPImageEditor.cpp (function ?OnLButtonUp@CXTPImageEditorPicture@@IAEXIVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPImageEditor.cpp
