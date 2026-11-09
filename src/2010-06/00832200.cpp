// from server: 100% by auto
// roc 2010-06 00832200  unit: CXTPRibbonTheme  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00832200
//
// 00832200  8b442404             mov eax, dword ptr [esp + 4]
// 00832204  50                   push eax
// 00832205  e8e6ffffff           call 0x8321f0
// 0083220a  8bc8                 mov ecx, eax
// 0083220c  e87f370600           call 0x895990
// 00832211  c20400               ret 4
// library xtp-13.2.1/Source\SkinFramework\XTPSkinObjectMenu.cpp (function ?PlayEventSound@CXTPSkinPopupMenuState@@QAEXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/SkinFramework/XTPSkinObjectMenu.cpp
