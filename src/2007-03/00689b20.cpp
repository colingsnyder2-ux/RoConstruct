// from server: 100% by auto
// roc 2007-03 00689b20  unit: seg_00680000  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00689b20
//
// 00689b20  56                   push esi
// 00689b21  8bf1                 mov esi, ecx
// 00689b23  e8aa4bf9ff           call 0x61e6d2
// 00689b28  837c240800           cmp dword ptr [esp + 8], 0
// 00689b2d  751b                 jne 0x689b4a
// 00689b2f  8bce                 mov ecx, esi
// 00689b31  e82a880700           call 0x702360
// 00689b36  84c0                 test al, al
// 00689b38  7510                 jne 0x689b4a
// 00689b3a  8b4620               mov eax, dword ptr [esi + 0x20]
// 00689b3d  6a00                 push 0
// 00689b3f  6a00                 push 0
// 00689b41  6a10                 push 0x10
// 00689b43  50                   push eax
// 00689b44  ff1548ee7700         call dword ptr [0x77ee48]
// 00689b4a  5e                   pop esi
// 00689b4b  c20c00               ret 0xc
// library xtp-15.2.1/Source\Controls\Popup\XTPColorPopup.cpp (function ?OnActivate@CXTPColorPopup@@IAEXIPAVCWnd@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Popup/XTPColorPopup.cpp
