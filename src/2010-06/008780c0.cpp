// from server: 100% by auto
// roc 2010-06 008780c0  unit: CXTPImageEditorPicture  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008780c0
//
// 008780c0  56                   push esi
// 008780c1  8bf1                 mov esi, ecx
// 008780c3  c786c000000000000000 mov dword ptr [esi + 0xc0], 0
// 008780cd  e89efcffff           call 0x877d70
// 008780d2  8bce                 mov ecx, esi
// 008780d4  e897fef2ff           call 0x7a7f70
// 008780d9  5e                   pop esi
// 008780da  c20400               ret 4
// library xtp-13.2.1/Source\CommandBars\XTPImageEditor.cpp (function ?OnCaptureChanged@CXTPImageEditorPicture@@IAEXPAVCWnd@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPImageEditor.cpp
