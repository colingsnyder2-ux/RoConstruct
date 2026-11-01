// from server: 100% by auto
// roc 2007-03 006e3a90  unit: seg_006e0000  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006e3a90
//
// 006e3a90  8b442404             mov eax, dword ptr [esp + 4]
// 006e3a94  83f82b               cmp eax, 0x2b
// 006e3a97  7512                 jne 0x6e3aab
// 006e3a99  8b44240c             mov eax, dword ptr [esp + 0xc]
// 006e3a9d  50                   push eax
// 006e3a9e  e84dfeffff           call 0x6e38f0
// 006e3aa3  b801000000           mov eax, 1
// 006e3aa8  c21000               ret 0x10
// 006e3aab  89442404             mov dword ptr [esp + 4], eax
// 006e3aaf  e96e790500           jmp 0x73b422
// library xtp-15.2.1/Source\CommandBars\XTPCustomizeToolbarsPage.cpp (function ?OnChildNotify@CXTPCustomizeToolbarsPageCheckListBox@@MAEHIIJPAJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPCustomizeToolbarsPage.cpp
