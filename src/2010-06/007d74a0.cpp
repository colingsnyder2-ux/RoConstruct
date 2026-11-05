// from server: 100% by auto
// roc 2010-06 007d74a0  unit: CXTPReportControl  size: 107 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007d74a0
//
// 007d74a0  53                   push ebx
// 007d74a1  56                   push esi
// 007d74a2  8bd9                 mov ebx, ecx
// 007d74a4  ff1580ba9e00         call dword ptr [0x9eba80]
// 007d74aa  50                   push eax
// 007d74ab  e8ba07fdff           call 0x7a7c6a
// 007d74b0  8bf0                 mov esi, eax
// 007d74b2  85f6                 test esi, esi
// 007d74b4  7503                 jne 0x7d74b9
// 007d74b6  5e                   pop esi
// 007d74b7  5b                   pop ebx
// 007d74b8  c3                   ret 
// 007d74b9  8b4620               mov eax, dword ptr [esi + 0x20]
// 007d74bc  57                   push edi
// 007d74bd  3b4320               cmp eax, dword ptr [ebx + 0x20]
// 007d74c0  7440                 je 0x7d7502
// 007d74c2  8b3d4cba9e00         mov edi, dword ptr [0x9eba4c]
// 007d74c8  50                   push eax
// 007d74c9  ffd7                 call edi
// 007d74cb  50                   push eax
// 007d74cc  e89907fdff           call 0x7a7c6a
// 007d74d1  85c0                 test eax, eax
// 007d74d3  7403                 je 0x7d74d8
// 007d74d5  8b4020               mov eax, dword ptr [eax + 0x20]
// 007d74d8  3b4320               cmp eax, dword ptr [ebx + 0x20]
// 007d74db  7425                 je 0x7d7502
// 007d74dd  8b4638               mov eax, dword ptr [esi + 0x38]
// 007d74e0  85c0                 test eax, eax
// 007d74e2  7506                 jne 0x7d74ea
// 007d74e4  8b4620               mov eax, dword ptr [esi + 0x20]
// 007d74e7  50                   push eax
// 007d74e8  ffd7                 call edi
// 007d74ea  50                   push eax
// 007d74eb  e87a07fdff           call 0x7a7c6a
// 007d74f0  85c0                 test eax, eax
// 007d74f2  7403                 je 0x7d74f7
// 007d74f4  8b4020               mov eax, dword ptr [eax + 0x20]
// 007d74f7  3b4320               cmp eax, dword ptr [ebx + 0x20]
// 007d74fa  7406                 je 0x7d7502
// 007d74fc  5f                   pop edi
// 007d74fd  5e                   pop esi
// 007d74fe  33c0                 xor eax, eax
// 007d7500  5b                   pop ebx
// 007d7501  c3                   ret 
// 007d7502  5f                   pop edi
// 007d7503  5e                   pop esi
// 007d7504  b801000000           mov eax, 1
// 007d7509  5b                   pop ebx
// 007d750a  c3                   ret 
// library xtp-13.2.1/Source\ReportControl\XTPReportControl.cpp (function ?HasFocus@CXTPReportControl@@QBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportControl.cpp
