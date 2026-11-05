// from server: 100% by auto
// roc 2010-06 00822e40  unit: CXTPResourceManager  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00822e40
//
// 00822e40  83c8ff               or eax, 0xffffffff
// 00822e43  0bc8                 or ecx, eax
// 00822e45  a30462c200           mov dword ptr [0xc26204], eax
// 00822e4a  83ec08               sub esp, 8
// 00822e4d  8d0424               lea eax, [esp]
// 00822e50  50                   push eax
// 00822e51  890d0862c200         mov dword ptr [0xc26208], ecx
// 00822e57  ff1574bc9e00         call dword ptr [0x9ebc74]
// 00822e5d  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00822e61  8b1424               mov edx, dword ptr [esp]
// 00822e64  51                   push ecx
// 00822e65  52                   push edx
// 00822e66  ff15b0bb9e00         call dword ptr [0x9ebbb0]
// 00822e6c  83c408               add esp, 8
// 00822e6f  c3                   ret 
// library xtp-13.2.1/Source\CommandBars\XTPMouseManager.cpp (function ?RefreshCursor@CXTPMouseManager@@SAXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPMouseManager.cpp
