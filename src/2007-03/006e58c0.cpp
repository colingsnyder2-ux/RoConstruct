// from server: 100% by auto
// roc 2007-03 006e58c0  unit: seg_006e0000  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006e58c0
//
// 006e58c0  8b442404             mov eax, dword ptr [esp + 4]
// 006e58c4  8b405c               mov eax, dword ptr [eax + 0x5c]
// 006e58c7  8d88000000ff         lea ecx, [eax - 0x1000000]
// 006e58cd  83f907               cmp ecx, 7
// 006e58d0  7709                 ja 0x6e58db
// 006e58d2  50                   push eax
// 006e58d3  e808230000           call 0x6e7be0
// 006e58d8  83c404               add esp, 4
// 006e58db  c20400               ret 4
// library xtp-15.2.1/Source\TabManager\XTPTabManager.cpp (function ?GetItemColor@CXTPTabManager@@UBEKPBVCXTPTabManagerItem@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/TabManager/XTPTabManager.cpp
