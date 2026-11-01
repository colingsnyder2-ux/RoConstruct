// from server: 100% by auto
// roc 2007-03 006630f0  unit: seg_00660000  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006630f0
//
// 006630f0  8b442404             mov eax, dword ptr [esp + 4]
// 006630f4  83f804               cmp eax, 4
// 006630f7  740d                 je 0x663106
// 006630f9  83f803               cmp eax, 3
// 006630fc  7408                 je 0x663106
// 006630fe  83f802               cmp eax, 2
// 00663101  7403                 je 0x663106
// 00663103  33c0                 xor eax, eax
// 00663105  c3                   ret 
// 00663106  b801000000           mov eax, 1
// 0066310b  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPPopupBar.cpp (function ?IsAnimateType@@YAHW4XTPAnimationType@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPPopupBar.cpp
