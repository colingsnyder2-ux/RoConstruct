// from server: 100% by auto
// roc 2009-06 007924e0  unit: CXTCaption  size: 89 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007924e0
//
// 007924e0  53                   push ebx
// 007924e1  55                   push ebp
// 007924e2  56                   push esi
// 007924e3  57                   push edi
// 007924e4  8bf9                 mov edi, ecx
// 007924e6  8b4730               mov eax, dword ptr [edi + 0x30]
// 007924e9  33f6                 xor esi, esi
// 007924eb  85c0                 test eax, eax
// 007924ed  7e33                 jle 0x792522
// 007924ef  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 007924f3  85f6                 test esi, esi
// 007924f5  7c11                 jl 0x792508
// 007924f7  3bf0                 cmp esi, eax
// 007924f9  7d0d                 jge 0x792508
// 007924fb  3b7730               cmp esi, dword ptr [edi + 0x30]
// 007924fe  7d2b                 jge 0x79252b
// 00792500  8b472c               mov eax, dword ptr [edi + 0x2c]
// 00792503  8b1cb0               mov ebx, dword ptr [eax + esi*4]
// 00792506  eb02                 jmp 0x79250a
// 00792508  33db                 xor ebx, ebx
// 0079250a  8bcb                 mov ecx, ebx
// 0079250c  e83fa8fbff           call 0x74cd50
// 00792511  85c0                 test eax, eax
// 00792513  7405                 je 0x79251a
// 00792515  85ed                 test ebp, ebp
// 00792517  7417                 je 0x792530
// 00792519  4d                   dec ebp
// 0079251a  8b4730               mov eax, dword ptr [edi + 0x30]
// 0079251d  46                   inc esi
// 0079251e  3bf0                 cmp esi, eax
// 00792520  7cd1                 jl 0x7924f3
// 00792522  5f                   pop edi
// 00792523  5e                   pop esi
// 00792524  5d                   pop ebp
// 00792525  33c0                 xor eax, eax
// 00792527  5b                   pop ebx
// 00792528  c20400               ret 4
// 0079252b  e8b467f8ff           call 0x718ce4
// 00792530  5f                   pop edi
// 00792531  5e                   pop esi
// 00792532  5d                   pop ebp
// 00792533  8bc3                 mov eax, ebx
// 00792535  5b                   pop ebx
// 00792536  c20400               ret 4
// library xtp-15.2.1/Source\ReportControl\XTPReportColumns.cpp (function ?GetVisibleAt@CXTPReportColumns@@QBEPAVCXTPReportColumn@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/ReportControl/XTPReportColumns.cpp
