// from server: 100% by auto
// roc 2010-06 00829280  unit: CXTPControlComboBoxGalleryPopupBar  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00829280
//
// 00829280  8b442404             mov eax, dword ptr [esp + 4]
// 00829284  50                   push eax
// 00829285  e806b9ffff           call 0x824b90
// 0082928a  8bc8                 mov ecx, eax
// 0082928c  e8aff3ffff           call 0x828640
// 00829291  c20400               ret 4
// library xtp-13.2.1/Source\SkinFramework\XTPSkinObjectMenu.cpp (function ?PlayEventSound@CXTPSkinPopupMenuState@@QAEXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/SkinFramework/XTPSkinObjectMenu.cpp
