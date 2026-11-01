// from server: 100% by auto
// roc 2007-03 006e2c00  unit: seg_006e0000  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006e2c00
//
// 006e2c00  56                   push esi
// 006e2c01  8bf1                 mov esi, ecx
// 006e2c03  c786c000000000000000 mov dword ptr [esi + 0xc0], 0
// 006e2c0d  e8aefcffff           call 0x6e28c0
// 006e2c12  8bce                 mov ecx, esi
// 006e2c14  e8b9baf3ff           call 0x61e6d2
// 006e2c19  5e                   pop esi
// 006e2c1a  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPImageEditor.cpp (function ?OnCaptureChanged@CXTPImageEditorPicture@@IAEXPAVCWnd@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPImageEditor.cpp
