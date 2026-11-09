// from server: 100% by auto
// roc 2010-06 007c8460  unit: CXTPCommandBar  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007c8460
//
// 007c8460  56                   push esi
// 007c8461  8bf1                 mov esi, ecx
// 007c8463  e86801ffff           call 0x7b85d0
// 007c8468  85c0                 test eax, eax
// 007c846a  740c                 je 0x7c8478
// 007c846c  397040               cmp dword ptr [eax + 0x40], esi
// 007c846f  7507                 jne 0x7c8478
// 007c8471  8b4044               mov eax, dword ptr [eax + 0x44]
// 007c8474  85c0                 test eax, eax
// 007c8476  7f02                 jg 0x7c847a
// 007c8478  33c0                 xor eax, eax
// 007c847a  5e                   pop esi
// 007c847b  c3                   ret 
// library xtp-13.2.1/Source\CommandBars\XTPCommandBars.cpp (function ?IsKeyboardTipsVisible@CXTPCommandBar@@QBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPCommandBars.cpp
