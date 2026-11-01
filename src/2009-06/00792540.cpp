// from server: 100% by auto
// roc 2009-06 00792540  unit: CXTCaption  size: 75 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00792540
//
// 00792540  53                   push ebx
// 00792541  56                   push esi
// 00792542  57                   push edi
// 00792543  8bf9                 mov edi, ecx
// 00792545  8b4730               mov eax, dword ptr [edi + 0x30]
// 00792548  33f6                 xor esi, esi
// 0079254a  85c0                 test eax, eax
// 0079254c  7e2c                 jle 0x79257a
// 0079254e  8bff                 mov edi, edi
// 00792550  85f6                 test esi, esi
// 00792552  7c11                 jl 0x792565
// 00792554  3bf0                 cmp esi, eax
// 00792556  7d0d                 jge 0x792565
// 00792558  3b7730               cmp esi, dword ptr [edi + 0x30]
// 0079255b  7d23                 jge 0x792580
// 0079255d  8b472c               mov eax, dword ptr [edi + 0x2c]
// 00792560  8b1cb0               mov ebx, dword ptr [eax + esi*4]
// 00792563  eb02                 jmp 0x792567
// 00792565  33db                 xor ebx, ebx
// 00792567  8bcb                 mov ecx, ebx
// 00792569  e8e2a7fbff           call 0x74cd50
// 0079256e  85c0                 test eax, eax
// 00792570  7513                 jne 0x792585
// 00792572  8b4730               mov eax, dword ptr [edi + 0x30]
// 00792575  46                   inc esi
// 00792576  3bf0                 cmp esi, eax
// 00792578  7cd6                 jl 0x792550
// 0079257a  5f                   pop edi
// 0079257b  5e                   pop esi
// 0079257c  33c0                 xor eax, eax
// 0079257e  5b                   pop ebx
// 0079257f  c3                   ret 
// 00792580  e85f67f8ff           call 0x718ce4
// 00792585  5f                   pop edi
// 00792586  5e                   pop esi
// 00792587  8bc3                 mov eax, ebx
// 00792589  5b                   pop ebx
// 0079258a  c3                   ret 
// library xtp-15.2.1/Source\ReportControl\XTPReportColumns.cpp (function ?GetFirstVisibleColumn@CXTPReportColumns@@QBEPAVCXTPReportColumn@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/ReportControl/XTPReportColumns.cpp
