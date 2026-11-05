// from server: 100% by auto
// roc 2010-06 007f03e0  unit: CPatchedControlComboBox  size: 68 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007f03e0
//
// 007f03e0  56                   push esi
// 007f03e1  57                   push edi
// 007f03e2  8bf9                 mov edi, ecx
// 007f03e4  8b470c               mov eax, dword ptr [edi + 0xc]
// 007f03e7  85c0                 test eax, eax
// 007f03e9  7423                 je 0x7f040e
// 007f03eb  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007f03ef  8b5104               mov edx, dword ptr [ecx + 4]
// 007f03f2  8b09                 mov ecx, dword ptr [ecx]
// 007f03f4  6a00                 push 0
// 007f03f6  52                   push edx
// 007f03f7  51                   push ecx
// 007f03f8  ffd0                 call eax
// 007f03fa  8b74240c             mov esi, dword ptr [esp + 0xc]
// 007f03fe  50                   push eax
// 007f03ff  56                   push esi
// 007f0400  8bcf                 mov ecx, edi
// 007f0402  e8c9fdffff           call 0x7f01d0
// 007f0407  5f                   pop edi
// 007f0408  8bc6                 mov eax, esi
// 007f040a  5e                   pop esi
// 007f040b  c20800               ret 8
// 007f040e  8b74240c             mov esi, dword ptr [esp + 0xc]
// 007f0412  33c0                 xor eax, eax
// 007f0414  50                   push eax
// 007f0415  56                   push esi
// 007f0416  8bcf                 mov ecx, edi
// 007f0418  e8b3fdffff           call 0x7f01d0
// 007f041d  5f                   pop edi
// 007f041e  8bc6                 mov eax, esi
// 007f0420  5e                   pop esi
// 007f0421  c20800               ret 8
// library xtp-13.2.1/Source\Common\XTPSystemHelpers.cpp (function ?GetScreenArea@CXTPMultiMonitor@@QAE?AVCRect@@ABUtagPOINT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPSystemHelpers.cpp
