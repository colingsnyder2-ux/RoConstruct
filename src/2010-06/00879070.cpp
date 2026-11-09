// from server: 100% by auto
// roc 2010-06 00879070  unit: CXTPCustomizeToolbarsPageCheckListBox  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00879070
//
// 00879070  8b442404             mov eax, dword ptr [esp + 4]
// 00879074  83f82b               cmp eax, 0x2b
// 00879077  7512                 jne 0x87908b
// 00879079  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0087907d  50                   push eax
// 0087907e  e85dfeffff           call 0x878ee0
// 00879083  b801000000           mov eax, 1
// 00879088  c21000               ret 0x10
// 0087908b  89442404             mov dword ptr [esp + 4], eax
// 0087908f  e90e461000           jmp 0x97d6a2
// library xtp-13.2.1/Source\CommandBars\XTPCustomizeToolbarsPage.cpp (function ?OnChildNotify@CXTPCustomizeToolbarsPageCheckListBox@@MAEHIIJPAJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPCustomizeToolbarsPage.cpp
