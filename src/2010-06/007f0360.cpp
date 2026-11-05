// from server: 100% by auto
// roc 2010-06 007f0360  unit: CPatchedControlComboBox  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007f0360
//
// 007f0360  56                   push esi
// 007f0361  8bf1                 mov esi, ecx
// 007f0363  8b4608               mov eax, dword ptr [esi + 8]
// 007f0366  57                   push edi
// 007f0367  85c0                 test eax, eax
// 007f0369  741d                 je 0x7f0388
// 007f036b  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007f036f  6a00                 push 0
// 007f0371  51                   push ecx
// 007f0372  ffd0                 call eax
// 007f0374  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 007f0378  50                   push eax
// 007f0379  57                   push edi
// 007f037a  8bce                 mov ecx, esi
// 007f037c  e8affeffff           call 0x7f0230
// 007f0381  8bc7                 mov eax, edi
// 007f0383  5f                   pop edi
// 007f0384  5e                   pop esi
// 007f0385  c20800               ret 8
// 007f0388  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 007f038c  33c0                 xor eax, eax
// 007f038e  50                   push eax
// 007f038f  57                   push edi
// 007f0390  8bce                 mov ecx, esi
// 007f0392  e899feffff           call 0x7f0230
// 007f0397  8bc7                 mov eax, edi
// 007f0399  5f                   pop edi
// 007f039a  5e                   pop esi
// 007f039b  c20800               ret 8
// library xtp-13.2.1/Source\Common\XTPSystemHelpers.cpp (function ?GetScreenArea@CXTPMultiMonitor@@QAE?AVCRect@@PBUtagRECT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPSystemHelpers.cpp
