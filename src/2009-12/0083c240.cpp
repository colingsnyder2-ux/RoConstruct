// from server: 100% by auto
// roc 2009-12 0083c240  unit: CXTPAccessible  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0083c240
//
// 0083c240  56                   push esi
// 0083c241  8bf1                 mov esi, ecx
// 0083c243  8b4604               mov eax, dword ptr [esi + 4]
// 0083c246  57                   push edi
// 0083c247  85c0                 test eax, eax
// 0083c249  741d                 je 0x83c268
// 0083c24b  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0083c24f  6a00                 push 0
// 0083c251  51                   push ecx
// 0083c252  ffd0                 call eax
// 0083c254  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0083c258  50                   push eax
// 0083c259  57                   push edi
// 0083c25a  8bce                 mov ecx, esi
// 0083c25c  e80ffeffff           call 0x83c070
// 0083c261  8bc7                 mov eax, edi
// 0083c263  5f                   pop edi
// 0083c264  5e                   pop esi
// 0083c265  c20800               ret 8
// 0083c268  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0083c26c  33c0                 xor eax, eax
// 0083c26e  50                   push eax
// 0083c26f  57                   push edi
// 0083c270  8bce                 mov ecx, esi
// 0083c272  e8f9fdffff           call 0x83c070
// 0083c277  8bc7                 mov eax, edi
// 0083c279  5f                   pop edi
// 0083c27a  5e                   pop esi
// 0083c27b  c20800               ret 8
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ?GetScreenArea@CXTPMultiMonitor@@QAE?AVCRect@@PAUHWND__@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
