// from server: 100% by auto
// roc 2007-03 006967e0  unit: seg_00690000  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006967e0
//
// 006967e0  8a442404             mov al, byte ptr [esp + 4]
// 006967e4  8d4c2404             lea ecx, [esp + 4]
// 006967e8  51                   push ecx
// 006967e9  88442408             mov byte ptr [esp + 8], al
// 006967ed  c644240900           mov byte ptr [esp + 9], 0
// 006967f2  ff15c4ed7700         call dword ptr [0x77edc4]
// 006967f8  8a442404             mov al, byte ptr [esp + 4]
// 006967fc  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPShortcutManager.cpp (function ?ToUpper@CXTPShortcutManager@@SADD@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPShortcutManager.cpp
