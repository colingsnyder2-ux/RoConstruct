// from server: 100% by auto
// roc 2009-06 007613e0  unit: ATL::CRegObject  size: 68 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007613e0
//
// 007613e0  56                   push esi
// 007613e1  57                   push edi
// 007613e2  8bf9                 mov edi, ecx
// 007613e4  8b470c               mov eax, dword ptr [edi + 0xc]
// 007613e7  85c0                 test eax, eax
// 007613e9  7423                 je 0x76140e
// 007613eb  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007613ef  8b5104               mov edx, dword ptr [ecx + 4]
// 007613f2  8b09                 mov ecx, dword ptr [ecx]
// 007613f4  6a00                 push 0
// 007613f6  52                   push edx
// 007613f7  51                   push ecx
// 007613f8  ffd0                 call eax
// 007613fa  8b74240c             mov esi, dword ptr [esp + 0xc]
// 007613fe  50                   push eax
// 007613ff  56                   push esi
// 00761400  8bcf                 mov ecx, edi
// 00761402  e8f9feffff           call 0x761300
// 00761407  5f                   pop edi
// 00761408  8bc6                 mov eax, esi
// 0076140a  5e                   pop esi
// 0076140b  c20800               ret 8
// 0076140e  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00761412  33c0                 xor eax, eax
// 00761414  50                   push eax
// 00761415  56                   push esi
// 00761416  8bcf                 mov ecx, edi
// 00761418  e8e3feffff           call 0x761300
// 0076141d  5f                   pop edi
// 0076141e  8bc6                 mov eax, esi
// 00761420  5e                   pop esi
// 00761421  c20800               ret 8
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ?GetScreenArea@CXTPMultiMonitor@@QAE?AVCRect@@ABUtagPOINT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
