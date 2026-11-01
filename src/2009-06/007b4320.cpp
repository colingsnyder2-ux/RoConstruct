// from server: 100% by auto
// roc 2009-06 007b4320  unit: CXTPShortcutManager  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007b4320
//
// 007b4320  8a442404             mov al, byte ptr [esp + 4]
// 007b4324  8d4c2404             lea ecx, [esp + 4]
// 007b4328  51                   push ecx
// 007b4329  88442408             mov byte ptr [esp + 8], al
// 007b432d  c644240900           mov byte ptr [esp + 9], 0
// 007b4332  ff15d4ec8900         call dword ptr [0x89ecd4]
// 007b4338  8a442404             mov al, byte ptr [esp + 4]
// 007b433c  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPShortcutManager.cpp (function ?ToUpper@CXTPShortcutManager@@SADD@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPShortcutManager.cpp
