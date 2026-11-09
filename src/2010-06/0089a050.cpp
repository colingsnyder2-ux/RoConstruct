// from server: 100% by auto
// roc 2010-06 0089a050  unit: CXTCaptionButton  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0089a050
//
// 0089a050  56                   push esi
// 0089a051  8bf1                 mov esi, ecx
// 0089a053  83bea800000000       cmp dword ptr [esi + 0xa8], 0
// 0089a05a  741c                 je 0x89a078
// 0089a05c  ff1580ba9e00         call dword ptr [0x9eba80]
// 0089a062  50                   push eax
// 0089a063  e802dcf0ff           call 0x7a7c6a
// 0089a068  2bc6                 sub eax, esi
// 0089a06a  f7d8                 neg eax
// 0089a06c  1bc0                 sbb eax, eax
// 0089a06e  83e0f0               and eax, 0xfffffff0
// 0089a071  0510200000           add eax, 0x2010
// 0089a076  5e                   pop esi
// 0089a077  c3                   ret 
// 0089a078  5e                   pop esi
// 0089a079  e9f2def0ff           jmp 0x7a7f70
// library xtp-13.2.1/Source\Controls\XTButton.cpp (function ?OnGetDlgCode@CXTButton@@IAEIXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTButton.cpp
