// from server: 100% by auto
// roc 2010-06 008425a0  unit: CXTPShortcutManager  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008425a0
//
// 008425a0  8a442404             mov al, byte ptr [esp + 4]
// 008425a4  8d4c2404             lea ecx, [esp + 4]
// 008425a8  51                   push ecx
// 008425a9  88442408             mov byte ptr [esp + 8], al
// 008425ad  c644240900           mov byte ptr [esp + 9], 0
// 008425b2  ff1524bb9e00         call dword ptr [0x9ebb24]
// 008425b8  8a442404             mov al, byte ptr [esp + 4]
// 008425bc  c3                   ret 
// library xtp-13.2.1/Source\CommandBars\XTPShortcutManager.cpp (function ?ToUpper@CXTPShortcutManager@@SADD@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPShortcutManager.cpp
