// from server: 100% by auto
// roc 2009-12 0088e340  unit: CXTPShortcutManager  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0088e340
//
// 0088e340  8a442404             mov al, byte ptr [esp + 4]
// 0088e344  8d4c2404             lea ecx, [esp + 4]
// 0088e348  51                   push ecx
// 0088e349  88442408             mov byte ptr [esp + 8], al
// 0088e34d  c644240900           mov byte ptr [esp + 9], 0
// 0088e352  ff1598cb9800         call dword ptr [0x98cb98]
// 0088e358  8a442404             mov al, byte ptr [esp + 4]
// 0088e35c  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPShortcutManager.cpp (function ?ToUpper@CXTPShortcutManager@@SADD@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPShortcutManager.cpp
