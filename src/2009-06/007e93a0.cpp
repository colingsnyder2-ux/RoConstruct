// from server: 100% by auto
// roc 2009-06 007e93a0  unit: CXTPImageEditorPicture  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007e93a0
//
// 007e93a0  56                   push esi
// 007e93a1  8bf1                 mov esi, ecx
// 007e93a3  c786c000000000000000 mov dword ptr [esi + 0xc0], 0
// 007e93ad  e89efcffff           call 0x7e9050
// 007e93b2  8bce                 mov ecx, esi
// 007e93b4  e84ffcf2ff           call 0x719008
// 007e93b9  5e                   pop esi
// 007e93ba  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPImageEditor.cpp (function ?OnCaptureChanged@CXTPImageEditorPicture@@IAEXPAVCWnd@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPImageEditor.cpp
