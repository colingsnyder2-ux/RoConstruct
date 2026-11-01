// from server: 100% by auto
// roc 2009-12 00814380  unit: CXTPCommandBar  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00814380
//
// 00814380  56                   push esi
// 00814381  8bf1                 mov esi, ecx
// 00814383  e84801ffff           call 0x8044d0
// 00814388  85c0                 test eax, eax
// 0081438a  740c                 je 0x814398
// 0081438c  397040               cmp dword ptr [eax + 0x40], esi
// 0081438f  7507                 jne 0x814398
// 00814391  8b4044               mov eax, dword ptr [eax + 0x44]
// 00814394  85c0                 test eax, eax
// 00814396  7f02                 jg 0x81439a
// 00814398  33c0                 xor eax, eax
// 0081439a  5e                   pop esi
// 0081439b  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPCommandBars.cpp (function ?IsKeyboardTipsVisible@CXTPCommandBar@@QBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPCommandBars.cpp
