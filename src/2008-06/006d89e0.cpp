// from server: 100% by auto
// roc 2008-06 006d89e0  unit: CXTPReportRecordItemVariant  size: 99 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006d89e0
//
// 006d89e0  8b442404             mov eax, dword ptr [esp + 4]
// 006d89e4  83ec10               sub esp, 0x10
// 006d89e7  66833807             cmp word ptr [eax], 7
// 006d89eb  56                   push esi
// 006d89ec  8bf1                 mov esi, ecx
// 006d89ee  743e                 je 0x6d8a2e
// 006d89f0  6a07                 push 7
// 006d89f2  33c9                 xor ecx, ecx
// 006d89f4  51                   push ecx
// 006d89f5  50                   push eax
// 006d89f6  8d542410             lea edx, [esp + 0x10]
// 006d89fa  52                   push edx
// 006d89fb  66894c2414           mov word ptr [esp + 0x14], cx
// 006d8a00  ff15f0288000         call dword ptr [0x8028f0]
// 006d8a06  85c0                 test eax, eax
// 006d8a08  8bc6                 mov eax, esi
// 006d8a0a  7c14                 jl 0x6d8a20
// 006d8a0c  dd44240c             fld qword ptr [esp + 0xc]
// 006d8a10  c7460800000000       mov dword ptr [esi + 8], 0
// 006d8a17  dd1e                 fstp qword ptr [esi]
// 006d8a19  5e                   pop esi
// 006d8a1a  83c410               add esp, 0x10
// 006d8a1d  c20400               ret 4
// 006d8a20  c7460801000000       mov dword ptr [esi + 8], 1
// 006d8a27  5e                   pop esi
// 006d8a28  83c410               add esp, 0x10
// 006d8a2b  c20400               ret 4
// 006d8a2e  dd4008               fld qword ptr [eax + 8]
// 006d8a31  8bc6                 mov eax, esi
// 006d8a33  dd1e                 fstp qword ptr [esi]
// 006d8a35  c7460800000000       mov dword ptr [esi + 8], 0
// 006d8a3c  5e                   pop esi
// 006d8a3d  83c410               add esp, 0x10
// 006d8a40  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\daocore.cpp (function ??4COleDateTime@ATL@@QAEAAV01@ABUtagVARIANT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/daocore.cpp
