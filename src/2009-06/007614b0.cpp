// from server: 100% by auto
// roc 2009-06 007614b0  unit: ATL::CRegObject  size: 68 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007614b0
//
// 007614b0  56                   push esi
// 007614b1  57                   push edi
// 007614b2  8bf9                 mov edi, ecx
// 007614b4  8b470c               mov eax, dword ptr [edi + 0xc]
// 007614b7  85c0                 test eax, eax
// 007614b9  7423                 je 0x7614de
// 007614bb  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007614bf  8b5104               mov edx, dword ptr [ecx + 4]
// 007614c2  8b09                 mov ecx, dword ptr [ecx]
// 007614c4  6a00                 push 0
// 007614c6  52                   push edx
// 007614c7  51                   push ecx
// 007614c8  ffd0                 call eax
// 007614ca  8b74240c             mov esi, dword ptr [esp + 0xc]
// 007614ce  50                   push eax
// 007614cf  56                   push esi
// 007614d0  8bcf                 mov ecx, edi
// 007614d2  e8c9fdffff           call 0x7612a0
// 007614d7  5f                   pop edi
// 007614d8  8bc6                 mov eax, esi
// 007614da  5e                   pop esi
// 007614db  c20800               ret 8
// 007614de  8b74240c             mov esi, dword ptr [esp + 0xc]
// 007614e2  33c0                 xor eax, eax
// 007614e4  50                   push eax
// 007614e5  56                   push esi
// 007614e6  8bcf                 mov ecx, edi
// 007614e8  e8b3fdffff           call 0x7612a0
// 007614ed  5f                   pop edi
// 007614ee  8bc6                 mov eax, esi
// 007614f0  5e                   pop esi
// 007614f1  c20800               ret 8
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ?GetScreenArea@CXTPMultiMonitor@@QAE?AVCRect@@ABUtagPOINT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
