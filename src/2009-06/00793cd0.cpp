// from server: 100% by auto
// roc 2009-06 00793cd0  unit: CXTPKeyboardManager  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00793cd0
//
// 00793cd0  83c8ff               or eax, 0xffffffff
// 00793cd3  0bc8                 or ecx, eax
// 00793cd5  a39826a500           mov dword ptr [0xa52698], eax
// 00793cda  83ec08               sub esp, 8
// 00793cdd  8d0424               lea eax, [esp]
// 00793ce0  50                   push eax
// 00793ce1  890d9c26a500         mov dword ptr [0xa5269c], ecx
// 00793ce7  ff152cee8900         call dword ptr [0x89ee2c]
// 00793ced  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00793cf1  8b1424               mov edx, dword ptr [esp]
// 00793cf4  51                   push ecx
// 00793cf5  52                   push edx
// 00793cf6  ff158ced8900         call dword ptr [0x89ed8c]
// 00793cfc  83c408               add esp, 8
// 00793cff  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPMouseManager.cpp (function ?RefreshCursor@CXTPMouseManager@@SAXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPMouseManager.cpp
