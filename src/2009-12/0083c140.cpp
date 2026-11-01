// from server: 100% by auto
// roc 2009-12 0083c140  unit: CXTPAccessible  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0083c140
//
// 0083c140  56                   push esi
// 0083c141  8bf1                 mov esi, ecx
// 0083c143  8b4604               mov eax, dword ptr [esi + 4]
// 0083c146  57                   push edi
// 0083c147  85c0                 test eax, eax
// 0083c149  741d                 je 0x83c168
// 0083c14b  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0083c14f  6a00                 push 0
// 0083c151  51                   push ecx
// 0083c152  ffd0                 call eax
// 0083c154  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0083c158  50                   push eax
// 0083c159  57                   push edi
// 0083c15a  8bce                 mov ecx, esi
// 0083c15c  e86fffffff           call 0x83c0d0
// 0083c161  8bc7                 mov eax, edi
// 0083c163  5f                   pop edi
// 0083c164  5e                   pop esi
// 0083c165  c20800               ret 8
// 0083c168  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0083c16c  33c0                 xor eax, eax
// 0083c16e  50                   push eax
// 0083c16f  57                   push edi
// 0083c170  8bce                 mov ecx, esi
// 0083c172  e859ffffff           call 0x83c0d0
// 0083c177  8bc7                 mov eax, edi
// 0083c179  5f                   pop edi
// 0083c17a  5e                   pop esi
// 0083c17b  c20800               ret 8
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ?GetScreenArea@CXTPMultiMonitor@@QAE?AVCRect@@PAUHWND__@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
