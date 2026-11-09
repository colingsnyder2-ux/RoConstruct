// from server: 100% by auto
// roc 2009-06 00750a50  unit: CXTPReportRecordItemVariant  size: 99 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00750a50
//
// 00750a50  8b442404             mov eax, dword ptr [esp + 4]
// 00750a54  83ec10               sub esp, 0x10
// 00750a57  66833807             cmp word ptr [eax], 7
// 00750a5b  56                   push esi
// 00750a5c  8bf1                 mov esi, ecx
// 00750a5e  743e                 je 0x750a9e
// 00750a60  6a07                 push 7
// 00750a62  33c9                 xor ecx, ecx
// 00750a64  51                   push ecx
// 00750a65  50                   push eax
// 00750a66  8d542410             lea edx, [esp + 0x10]
// 00750a6a  52                   push edx
// 00750a6b  66894c2414           mov word ptr [esp + 0x14], cx
// 00750a70  ff15fce98900         call dword ptr [0x89e9fc]
// 00750a76  85c0                 test eax, eax
// 00750a78  8bc6                 mov eax, esi
// 00750a7a  7c14                 jl 0x750a90
// 00750a7c  dd44240c             fld qword ptr [esp + 0xc]
// 00750a80  c7460800000000       mov dword ptr [esi + 8], 0
// 00750a87  dd1e                 fstp qword ptr [esi]
// 00750a89  5e                   pop esi
// 00750a8a  83c410               add esp, 0x10
// 00750a8d  c20400               ret 4
// 00750a90  c7460801000000       mov dword ptr [esi + 8], 1
// 00750a97  5e                   pop esi
// 00750a98  83c410               add esp, 0x10
// 00750a9b  c20400               ret 4
// 00750a9e  dd4008               fld qword ptr [eax + 8]
// 00750aa1  8bc6                 mov eax, esi
// 00750aa3  dd1e                 fstp qword ptr [esi]
// 00750aa5  c7460800000000       mov dword ptr [esi + 8], 0
// 00750aac  5e                   pop esi
// 00750aad  83c410               add esp, 0x10
// 00750ab0  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\daocore.cpp (function ??4COleDateTime@ATL@@QAEAAV01@ABUtagVARIANT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/daocore.cpp
