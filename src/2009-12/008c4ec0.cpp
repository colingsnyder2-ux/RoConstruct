// from server: 100% by auto
// roc 2009-12 008c4ec0  unit: CXTPCustomizeToolbarsPageCheckListBox  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008c4ec0
//
// 008c4ec0  8b442404             mov eax, dword ptr [esp + 4]
// 008c4ec4  83f82b               cmp eax, 0x2b
// 008c4ec7  7512                 jne 0x8c4edb
// 008c4ec9  8b44240c             mov eax, dword ptr [esp + 0xc]
// 008c4ecd  50                   push eax
// 008c4ece  e85dfeffff           call 0x8c4d30
// 008c4ed3  b801000000           mov eax, 1
// 008c4ed8  c21000               ret 0x10
// 008c4edb  89442404             mov dword ptr [esp + 4], eax
// 008c4edf  e97c1e0600           jmp 0x926d60
// library xtp-15.2.1/Source\CommandBars\XTPCustomizeToolbarsPage.cpp (function ?OnChildNotify@CXTPCustomizeToolbarsPageCheckListBox@@MAEHIIJPAJ@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPCustomizeToolbarsPage.cpp
