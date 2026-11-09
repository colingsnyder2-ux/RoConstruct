// from server: 100% by auto
// roc 2010-06 007d72d0  unit: CXTPReportControl  size: 142 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007d72d0
//
// 007d72d0  83ec0c               sub esp, 0xc
// 007d72d3  53                   push ebx
// 007d72d4  8b1d28bc9e00         mov ebx, dword ptr [0x9ebc28]
// 007d72da  57                   push edi
// 007d72db  8bf9                 mov edi, ecx
// 007d72dd  8b4720               mov eax, dword ptr [edi + 0x20]
// 007d72e0  50                   push eax
// 007d72e1  ffd3                 call ebx
// 007d72e3  85c0                 test eax, eax
// 007d72e5  7508                 jne 0x7d72ef
// 007d72e7  5f                   pop edi
// 007d72e8  5b                   pop ebx
// 007d72e9  83c40c               add esp, 0xc
// 007d72ec  c20800               ret 8
// 007d72ef  56                   push esi
// 007d72f0  8b742420             mov esi, dword ptr [esp + 0x20]
// 007d72f4  85f6                 test esi, esi
// 007d72f6  7504                 jne 0x7d72fc
// 007d72f8  8d74240c             lea esi, [esp + 0xc]
// 007d72fc  8b4f20               mov ecx, dword ptr [edi + 0x20]
// 007d72ff  890e                 mov dword ptr [esi], ecx
// 007d7301  8bcf                 mov ecx, edi
// 007d7303  e8fe5c1a00           call 0x97d006
// 007d7308  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 007d730c  894604               mov dword ptr [esi + 4], eax
// 007d730f  895608               mov dword ptr [esi + 8], edx
// 007d7312  8b4738               mov eax, dword ptr [edi + 0x38]
// 007d7315  85c0                 test eax, eax
// 007d7317  750a                 jne 0x7d7323
// 007d7319  8b4720               mov eax, dword ptr [edi + 0x20]
// 007d731c  50                   push eax
// 007d731d  ff154cba9e00         call dword ptr [0x9eba4c]
// 007d7323  50                   push eax
// 007d7324  e84109fdff           call 0x7a7c6a
// 007d7329  8bf8                 mov edi, eax
// 007d732b  85ff                 test edi, edi
// 007d732d  7424                 je 0x7d7353
// 007d732f  8b4f20               mov ecx, dword ptr [edi + 0x20]
// 007d7332  51                   push ecx
// 007d7333  ffd3                 call ebx
// 007d7335  85c0                 test eax, eax
// 007d7337  741a                 je 0x7d7353
// 007d7339  8b4604               mov eax, dword ptr [esi + 4]
// 007d733c  8b5720               mov edx, dword ptr [edi + 0x20]
// 007d733f  56                   push esi
// 007d7340  50                   push eax
// 007d7341  6a4e                 push 0x4e
// 007d7343  52                   push edx
// 007d7344  ff1554ba9e00         call dword ptr [0x9eba54]
// 007d734a  5e                   pop esi
// 007d734b  5f                   pop edi
// 007d734c  5b                   pop ebx
// 007d734d  83c40c               add esp, 0xc
// 007d7350  c20800               ret 8
// 007d7353  5e                   pop esi
// 007d7354  5f                   pop edi
// 007d7355  33c0                 xor eax, eax
// 007d7357  5b                   pop ebx
// 007d7358  83c40c               add esp, 0xc
// 007d735b  c20800               ret 8
// library xtp-13.2.1/Source\ReportControl\XTPReportControl.cpp (function ?SendNotifyMessageA@CXTPReportControl@@QBEJIPAUtagNMHDR@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportControl.cpp
