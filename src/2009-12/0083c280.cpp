// from server: 100% by auto
// roc 2009-12 0083c280  unit: CXTPAccessible  size: 68 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0083c280
//
// 0083c280  56                   push esi
// 0083c281  57                   push edi
// 0083c282  8bf9                 mov edi, ecx
// 0083c284  8b470c               mov eax, dword ptr [edi + 0xc]
// 0083c287  85c0                 test eax, eax
// 0083c289  7423                 je 0x83c2ae
// 0083c28b  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0083c28f  8b5104               mov edx, dword ptr [ecx + 4]
// 0083c292  8b09                 mov ecx, dword ptr [ecx]
// 0083c294  6a00                 push 0
// 0083c296  52                   push edx
// 0083c297  51                   push ecx
// 0083c298  ffd0                 call eax
// 0083c29a  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0083c29e  50                   push eax
// 0083c29f  56                   push esi
// 0083c2a0  8bcf                 mov ecx, edi
// 0083c2a2  e8c9fdffff           call 0x83c070
// 0083c2a7  5f                   pop edi
// 0083c2a8  8bc6                 mov eax, esi
// 0083c2aa  5e                   pop esi
// 0083c2ab  c20800               ret 8
// 0083c2ae  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0083c2b2  33c0                 xor eax, eax
// 0083c2b4  50                   push eax
// 0083c2b5  56                   push esi
// 0083c2b6  8bcf                 mov ecx, edi
// 0083c2b8  e8b3fdffff           call 0x83c070
// 0083c2bd  5f                   pop edi
// 0083c2be  8bc6                 mov eax, esi
// 0083c2c0  5e                   pop esi
// 0083c2c1  c20800               ret 8
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ?GetScreenArea@CXTPMultiMonitor@@QAE?AVCRect@@ABUtagPOINT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
