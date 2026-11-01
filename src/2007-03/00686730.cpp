// from server: 100% by auto
// roc 2007-03 00686730  unit: seg_00680000  size: 68 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00686730
//
// 00686730  56                   push esi
// 00686731  57                   push edi
// 00686732  8bf9                 mov edi, ecx
// 00686734  8b470c               mov eax, dword ptr [edi + 0xc]
// 00686737  85c0                 test eax, eax
// 00686739  7423                 je 0x68675e
// 0068673b  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0068673f  8b5104               mov edx, dword ptr [ecx + 4]
// 00686742  8b09                 mov ecx, dword ptr [ecx]
// 00686744  6a00                 push 0
// 00686746  52                   push edx
// 00686747  51                   push ecx
// 00686748  ffd0                 call eax
// 0068674a  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0068674e  50                   push eax
// 0068674f  56                   push esi
// 00686750  8bcf                 mov ecx, edi
// 00686752  e869ffffff           call 0x6866c0
// 00686757  5f                   pop edi
// 00686758  8bc6                 mov eax, esi
// 0068675a  5e                   pop esi
// 0068675b  c20800               ret 8
// 0068675e  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00686762  33c0                 xor eax, eax
// 00686764  50                   push eax
// 00686765  56                   push esi
// 00686766  8bcf                 mov ecx, edi
// 00686768  e853ffffff           call 0x6866c0
// 0068676d  5f                   pop edi
// 0068676e  8bc6                 mov eax, esi
// 00686770  5e                   pop esi
// 00686771  c20800               ret 8
// library xtp-15.2.1/Source\Common\XTPSystemHelpers.cpp (function ?GetScreenArea@CXTPMultiMonitor@@QAE?AVCRect@@ABUtagPOINT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPSystemHelpers.cpp
