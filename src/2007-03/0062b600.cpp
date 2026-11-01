// from server: 100% by auto
// roc 2007-03 0062b600  unit: seg_00620000  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0062b600
//
// 0062b600  56                   push esi
// 0062b601  8bf1                 mov esi, ecx
// 0062b603  e808d70000           call 0x638d10
// 0062b608  85c0                 test eax, eax
// 0062b60a  740c                 je 0x62b618
// 0062b60c  397040               cmp dword ptr [eax + 0x40], esi
// 0062b60f  7507                 jne 0x62b618
// 0062b611  8b4044               mov eax, dword ptr [eax + 0x44]
// 0062b614  85c0                 test eax, eax
// 0062b616  7f02                 jg 0x62b61a
// 0062b618  33c0                 xor eax, eax
// 0062b61a  5e                   pop esi
// 0062b61b  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPCommandBars.cpp (function ?IsKeyboardTipsVisible@CXTPCommandBar@@QBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPCommandBars.cpp
