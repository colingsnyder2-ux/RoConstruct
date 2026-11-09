// from server: 100% by auto
// roc 2010-06 008292a0  unit: CXTPControlComboBoxGalleryPopupBar  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008292a0
//
// 008292a0  8b442404             mov eax, dword ptr [esp + 4]
// 008292a4  50                   push eax
// 008292a5  e8e6b8ffff           call 0x824b90
// 008292aa  8bc8                 mov ecx, eax
// 008292ac  e82ff2ffff           call 0x8284e0
// 008292b1  c20400               ret 4
// library xtp-13.2.1/Source\SkinFramework\XTPSkinObjectMenu.cpp (function ?PlayEventSound@CXTPSkinPopupMenuState@@QAEXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/SkinFramework/XTPSkinObjectMenu.cpp
