// from server: 100% by auto
// roc 2010-06 007f0310  unit: CPatchedControlComboBox  size: 68 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007f0310
//
// 007f0310  56                   push esi
// 007f0311  57                   push edi
// 007f0312  8bf9                 mov edi, ecx
// 007f0314  8b470c               mov eax, dword ptr [edi + 0xc]
// 007f0317  85c0                 test eax, eax
// 007f0319  7423                 je 0x7f033e
// 007f031b  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007f031f  8b5104               mov edx, dword ptr [ecx + 4]
// 007f0322  8b09                 mov ecx, dword ptr [ecx]
// 007f0324  6a00                 push 0
// 007f0326  52                   push edx
// 007f0327  51                   push ecx
// 007f0328  ffd0                 call eax
// 007f032a  8b74240c             mov esi, dword ptr [esp + 0xc]
// 007f032e  50                   push eax
// 007f032f  56                   push esi
// 007f0330  8bcf                 mov ecx, edi
// 007f0332  e8f9feffff           call 0x7f0230
// 007f0337  5f                   pop edi
// 007f0338  8bc6                 mov eax, esi
// 007f033a  5e                   pop esi
// 007f033b  c20800               ret 8
// 007f033e  8b74240c             mov esi, dword ptr [esp + 0xc]
// 007f0342  33c0                 xor eax, eax
// 007f0344  50                   push eax
// 007f0345  56                   push esi
// 007f0346  8bcf                 mov ecx, edi
// 007f0348  e8e3feffff           call 0x7f0230
// 007f034d  5f                   pop edi
// 007f034e  8bc6                 mov eax, esi
// 007f0350  5e                   pop esi
// 007f0351  c20800               ret 8
// library xtp-13.2.1/Source\Common\XTPSystemHelpers.cpp (function ?GetScreenArea@CXTPMultiMonitor@@QAE?AVCRect@@ABUtagPOINT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPSystemHelpers.cpp
