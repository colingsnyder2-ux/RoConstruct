// from server: 100% by auto
// roc 2009-12 0086d500  unit: CXTCaption  size: 89 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0086d500
//
// 0086d500  53                   push ebx
// 0086d501  55                   push ebp
// 0086d502  56                   push esi
// 0086d503  57                   push edi
// 0086d504  8bf9                 mov edi, ecx
// 0086d506  8b4730               mov eax, dword ptr [edi + 0x30]
// 0086d509  33f6                 xor esi, esi
// 0086d50b  85c0                 test eax, eax
// 0086d50d  7e33                 jle 0x86d542
// 0086d50f  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 0086d513  85f6                 test esi, esi
// 0086d515  7c11                 jl 0x86d528
// 0086d517  3bf0                 cmp esi, eax
// 0086d519  7d0d                 jge 0x86d528
// 0086d51b  3b7730               cmp esi, dword ptr [edi + 0x30]
// 0086d51e  7d2b                 jge 0x86d54b
// 0086d520  8b472c               mov eax, dword ptr [edi + 0x2c]
// 0086d523  8b1cb0               mov ebx, dword ptr [eax + esi*4]
// 0086d526  eb02                 jmp 0x86d52a
// 0086d528  33db                 xor ebx, ebx
// 0086d52a  8bcb                 mov ecx, ebx
// 0086d52c  e88f650400           call 0x8b3ac0
// 0086d531  85c0                 test eax, eax
// 0086d533  7405                 je 0x86d53a
// 0086d535  85ed                 test ebp, ebp
// 0086d537  7417                 je 0x86d550
// 0086d539  4d                   dec ebp
// 0086d53a  8b4730               mov eax, dword ptr [edi + 0x30]
// 0086d53d  46                   inc esi
// 0086d53e  3bf0                 cmp esi, eax
// 0086d540  7cd1                 jl 0x86d513
// 0086d542  5f                   pop edi
// 0086d543  5e                   pop esi
// 0086d544  5d                   pop ebp
// 0086d545  33c0                 xor eax, eax
// 0086d547  5b                   pop ebx
// 0086d548  c20400               ret 4
// 0086d54b  e8bc65f8ff           call 0x7f3b0c
// 0086d550  5f                   pop edi
// 0086d551  5e                   pop esi
// 0086d552  5d                   pop ebp
// 0086d553  8bc3                 mov eax, ebx
// 0086d555  5b                   pop ebx
// 0086d556  c20400               ret 4
// library xtp-15.2.1/Source\ReportControl\XTPReportColumns.cpp (function ?GetVisibleAt@CXTPReportColumns@@QBEPAVCXTPReportColumn@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/ReportControl/XTPReportColumns.cpp
