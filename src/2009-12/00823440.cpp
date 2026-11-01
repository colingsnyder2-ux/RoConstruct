// from server: 100% by auto
// roc 2009-12 00823440  unit: CXTPReportControl  size: 107 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00823440
//
// 00823440  53                   push ebx
// 00823441  56                   push esi
// 00823442  8bd9                 mov ebx, ecx
// 00823444  ff15eccb9800         call dword ptr [0x98cbec]
// 0082344a  50                   push eax
// 0082344b  e8da06fdff           call 0x7f3b2a
// 00823450  8bf0                 mov esi, eax
// 00823452  85f6                 test esi, esi
// 00823454  7503                 jne 0x823459
// 00823456  5e                   pop esi
// 00823457  5b                   pop ebx
// 00823458  c3                   ret 
// 00823459  8b4620               mov eax, dword ptr [esi + 0x20]
// 0082345c  57                   push edi
// 0082345d  3b4320               cmp eax, dword ptr [ebx + 0x20]
// 00823460  7440                 je 0x8234a2
// 00823462  8b3dbccb9800         mov edi, dword ptr [0x98cbbc]
// 00823468  50                   push eax
// 00823469  ffd7                 call edi
// 0082346b  50                   push eax
// 0082346c  e8b906fdff           call 0x7f3b2a
// 00823471  85c0                 test eax, eax
// 00823473  7403                 je 0x823478
// 00823475  8b4020               mov eax, dword ptr [eax + 0x20]
// 00823478  3b4320               cmp eax, dword ptr [ebx + 0x20]
// 0082347b  7425                 je 0x8234a2
// 0082347d  8b4638               mov eax, dword ptr [esi + 0x38]
// 00823480  85c0                 test eax, eax
// 00823482  7506                 jne 0x82348a
// 00823484  8b4620               mov eax, dword ptr [esi + 0x20]
// 00823487  50                   push eax
// 00823488  ffd7                 call edi
// 0082348a  50                   push eax
// 0082348b  e89a06fdff           call 0x7f3b2a
// 00823490  85c0                 test eax, eax
// 00823492  7403                 je 0x823497
// 00823494  8b4020               mov eax, dword ptr [eax + 0x20]
// 00823497  3b4320               cmp eax, dword ptr [ebx + 0x20]
// 0082349a  7406                 je 0x8234a2
// 0082349c  5f                   pop edi
// 0082349d  5e                   pop esi
// 0082349e  33c0                 xor eax, eax
// 008234a0  5b                   pop ebx
// 008234a1  c3                   ret 
// 008234a2  5f                   pop edi
// 008234a3  5e                   pop esi
// 008234a4  b801000000           mov eax, 1
// 008234a9  5b                   pop ebx
// 008234aa  c3                   ret 
// library xtp-15.2.1/Source\ReportControl\XTPReportControl.cpp (function ?HasFocus@CXTPReportControl@@QBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/ReportControl/XTPReportControl.cpp
