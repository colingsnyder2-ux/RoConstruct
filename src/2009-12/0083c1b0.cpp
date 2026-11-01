// from server: 100% by auto
// roc 2009-12 0083c1b0  unit: CXTPAccessible  size: 68 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0083c1b0
//
// 0083c1b0  56                   push esi
// 0083c1b1  57                   push edi
// 0083c1b2  8bf9                 mov edi, ecx
// 0083c1b4  8b470c               mov eax, dword ptr [edi + 0xc]
// 0083c1b7  85c0                 test eax, eax
// 0083c1b9  7423                 je 0x83c1de
// 0083c1bb  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0083c1bf  8b5104               mov edx, dword ptr [ecx + 4]
// 0083c1c2  8b09                 mov ecx, dword ptr [ecx]
// 0083c1c4  6a00                 push 0
// 0083c1c6  52                   push edx
// 0083c1c7  51                   push ecx
// 0083c1c8  ffd0                 call eax
// 0083c1ca  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0083c1ce  50                   push eax
// 0083c1cf  56                   push esi
// 0083c1d0  8bcf                 mov ecx, edi
// 0083c1d2  e8f9feffff           call 0x83c0d0
// 0083c1d7  5f                   pop edi
// 0083c1d8  8bc6                 mov eax, esi
// 0083c1da  5e                   pop esi
// 0083c1db  c20800               ret 8
// 0083c1de  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0083c1e2  33c0                 xor eax, eax
// 0083c1e4  50                   push eax
// 0083c1e5  56                   push esi
// 0083c1e6  8bcf                 mov ecx, edi
// 0083c1e8  e8e3feffff           call 0x83c0d0
// 0083c1ed  5f                   pop edi
// 0083c1ee  8bc6                 mov eax, esi
// 0083c1f0  5e                   pop esi
// 0083c1f1  c20800               ret 8
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ?GetScreenArea@CXTPMultiMonitor@@QAE?AVCRect@@ABUtagPOINT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
