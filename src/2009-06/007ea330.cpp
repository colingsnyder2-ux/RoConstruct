// from server: 100% by auto
// roc 2009-06 007ea330  unit: CXTPCustomizeToolbarsPageCheckListBox  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007ea330
//
// 007ea330  8b442404             mov eax, dword ptr [esp + 4]
// 007ea334  83f82b               cmp eax, 0x2b
// 007ea337  7512                 jne 0x7ea34b
// 007ea339  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007ea33d  50                   push eax
// 007ea33e  e85dfeffff           call 0x7ea1a0
// 007ea343  b801000000           mov eax, 1
// 007ea348  c21000               ret 0x10
// 007ea34b  89442404             mov dword ptr [esp + 4], eax
// 007ea34f  e9a0240600           jmp 0x84c7f4
// library xtp-15.2.1/Source\CommandBars\XTPCustomizeToolbarsPage.cpp (function ?OnChildNotify@CXTPCustomizeToolbarsPageCheckListBox@@MAEHIIJPAJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPCustomizeToolbarsPage.cpp
