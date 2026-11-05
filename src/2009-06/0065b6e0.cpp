// from server: 100% by auto
// roc 2009-06 0065b6e0  unit: VCRenderSettingsItem::?$EnumPropDescriptor  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0065b6e0
//
// 0065b6e0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0065b6e4  8b542408             mov edx, dword ptr [esp + 8]
// 0065b6e8  50                   push eax
// 0065b6e9  8b442408             mov eax, dword ptr [esp + 8]
// 0065b6ed  52                   push edx
// 0065b6ee  6a00                 push 0
// 0065b6f0  50                   push eax
// 0065b6f1  e88af9ffff           call 0x65b080
// 0065b6f6  c20c00               ret 0xc
// library mfc-9.0/atlmfc\src\mfc\afxribbonbar.cpp (function ?Create@CMFCRibbonBar@@QAEHPAVCWnd@@KI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxribbonbar.cpp
