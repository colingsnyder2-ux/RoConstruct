// from server: 100% by auto
// roc 2012-06 009b9860  unit: CXTPReportRecordItemVariant  size: 99 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009b9860
//
// 009b9860  8b442404             mov eax, dword ptr [esp + 4]
// 009b9864  83ec10               sub esp, 0x10
// 009b9867  66833807             cmp word ptr [eax], 7
// 009b986b  56                   push esi
// 009b986c  8bf1                 mov esi, ecx
// 009b986e  743e                 je 0x9b98ae
// 009b9870  6a07                 push 7
// 009b9872  33c9                 xor ecx, ecx
// 009b9874  51                   push ecx
// 009b9875  50                   push eax
// 009b9876  8d542410             lea edx, [esp + 0x10]
// 009b987a  52                   push edx
// 009b987b  66894c2414           mov word ptr [esp + 0x14], cx
// 009b9880  ff15002bb200         call dword ptr [0xb22b00]
// 009b9886  85c0                 test eax, eax
// 009b9888  8bc6                 mov eax, esi
// 009b988a  7c14                 jl 0x9b98a0
// 009b988c  dd44240c             fld qword ptr [esp + 0xc]
// 009b9890  c7460800000000       mov dword ptr [esi + 8], 0
// 009b9897  dd1e                 fstp qword ptr [esi]
// 009b9899  5e                   pop esi
// 009b989a  83c410               add esp, 0x10
// 009b989d  c20400               ret 4
// 009b98a0  c7460801000000       mov dword ptr [esi + 8], 1
// 009b98a7  5e                   pop esi
// 009b98a8  83c410               add esp, 0x10
// 009b98ab  c20400               ret 4
// 009b98ae  dd4008               fld qword ptr [eax + 8]
// 009b98b1  8bc6                 mov eax, esi
// 009b98b3  dd1e                 fstp qword ptr [esi]
// 009b98b5  c7460800000000       mov dword ptr [esi + 8], 0
// 009b98bc  5e                   pop esi
// 009b98bd  83c410               add esp, 0x10
// 009b98c0  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\daocore.cpp (function ??4COleDateTime@ATL@@QAEAAV01@ABUtagVARIANT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/daocore.cpp
