// from server: 100% by auto
// roc 2009-12 008c3f20  unit: CXTPImageEditorPicture  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008c3f20
//
// 008c3f20  56                   push esi
// 008c3f21  8bf1                 mov esi, ecx
// 008c3f23  c786c000000000000000 mov dword ptr [esi + 0xc0], 0
// 008c3f2d  e89efcffff           call 0x8c3bd0
// 008c3f32  8bce                 mov ecx, esi
// 008c3f34  e8f7fef2ff           call 0x7f3e30
// 008c3f39  5e                   pop esi
// 008c3f3a  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPImageEditor.cpp (function ?OnCaptureChanged@CXTPImageEditorPicture@@IAEXPAVCWnd@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPImageEditor.cpp
