// from server: 100% by auto
// roc 2009-06 0080b240  unit: CXTCaptionButton  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0080b240
//
// 0080b240  56                   push esi
// 0080b241  8bf1                 mov esi, ecx
// 0080b243  83bea800000000       cmp dword ptr [esi + 0xa8], 0
// 0080b24a  741c                 je 0x80b268
// 0080b24c  ff1578ee8900         call dword ptr [0x89ee78]
// 0080b252  50                   push eax
// 0080b253  e8aadaf0ff           call 0x718d02
// 0080b258  2bc6                 sub eax, esi
// 0080b25a  f7d8                 neg eax
// 0080b25c  1bc0                 sbb eax, eax
// 0080b25e  83e0f0               and eax, 0xfffffff0
// 0080b261  0510200000           add eax, 0x2010
// 0080b266  5e                   pop esi
// 0080b267  c3                   ret 
// 0080b268  5e                   pop esi
// 0080b269  e99addf0ff           jmp 0x719008
// library xtp-15.2.1/Source\Controls\Deprecated\XTButton.cpp (function ?OnGetDlgCode@CXTButton@@IAEIXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Deprecated/XTButton.cpp
