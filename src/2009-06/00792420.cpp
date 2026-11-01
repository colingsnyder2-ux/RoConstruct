// from server: 100% by auto
// roc 2009-06 00792420  unit: CXTCaption  size: 84 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00792420
//
// 00792420  53                   push ebx
// 00792421  55                   push ebp
// 00792422  56                   push esi
// 00792423  57                   push edi
// 00792424  8bf9                 mov edi, ecx
// 00792426  8b4730               mov eax, dword ptr [edi + 0x30]
// 00792429  33f6                 xor esi, esi
// 0079242b  85c0                 test eax, eax
// 0079242d  7e2e                 jle 0x79245d
// 0079242f  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 00792433  85f6                 test esi, esi
// 00792435  7c11                 jl 0x792448
// 00792437  3bf0                 cmp esi, eax
// 00792439  7d0d                 jge 0x792448
// 0079243b  3b7730               cmp esi, dword ptr [edi + 0x30]
// 0079243e  7d26                 jge 0x792466
// 00792440  8b472c               mov eax, dword ptr [edi + 0x2c]
// 00792443  8b1cb0               mov ebx, dword ptr [eax + esi*4]
// 00792446  eb02                 jmp 0x79244a
// 00792448  33db                 xor ebx, ebx
// 0079244a  8bcb                 mov ecx, ebx
// 0079244c  e85faafbff           call 0x74ceb0
// 00792451  3bc5                 cmp eax, ebp
// 00792453  7416                 je 0x79246b
// 00792455  8b4730               mov eax, dword ptr [edi + 0x30]
// 00792458  46                   inc esi
// 00792459  3bf0                 cmp esi, eax
// 0079245b  7cd6                 jl 0x792433
// 0079245d  5f                   pop edi
// 0079245e  5e                   pop esi
// 0079245f  5d                   pop ebp
// 00792460  33c0                 xor eax, eax
// 00792462  5b                   pop ebx
// 00792463  c20400               ret 4
// 00792466  e87968f8ff           call 0x718ce4
// 0079246b  5f                   pop edi
// 0079246c  5e                   pop esi
// 0079246d  5d                   pop ebp
// 0079246e  8bc3                 mov eax, ebx
// 00792470  5b                   pop ebx
// 00792471  c20400               ret 4
// library xtp-15.2.1/Source\ReportControl\XTPReportColumns.cpp (function ?Find@CXTPReportColumns@@QBEPAVCXTPReportColumn@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/ReportControl/XTPReportColumns.cpp
