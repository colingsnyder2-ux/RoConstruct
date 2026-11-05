// from server: 100% by auto
// roc 2011-06 00841430  unit: CXTPReportRecordItemVariant  size: 99 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00841430
//
// 00841430  8b442404             mov eax, dword ptr [esp + 4]
// 00841434  83ec10               sub esp, 0x10
// 00841437  66833807             cmp word ptr [eax], 7
// 0084143b  56                   push esi
// 0084143c  8bf1                 mov esi, ecx
// 0084143e  743e                 je 0x84147e
// 00841440  6a07                 push 7
// 00841442  33c9                 xor ecx, ecx
// 00841444  51                   push ecx
// 00841445  50                   push eax
// 00841446  8d542410             lea edx, [esp + 0x10]
// 0084144a  52                   push edx
// 0084144b  66894c2414           mov word ptr [esp + 0x14], cx
// 00841450  ff15a40aa400         call dword ptr [0xa40aa4]
// 00841456  85c0                 test eax, eax
// 00841458  8bc6                 mov eax, esi
// 0084145a  7c14                 jl 0x841470
// 0084145c  dd44240c             fld qword ptr [esp + 0xc]
// 00841460  c7460800000000       mov dword ptr [esi + 8], 0
// 00841467  dd1e                 fstp qword ptr [esi]
// 00841469  5e                   pop esi
// 0084146a  83c410               add esp, 0x10
// 0084146d  c20400               ret 4
// 00841470  c7460801000000       mov dword ptr [esi + 8], 1
// 00841477  5e                   pop esi
// 00841478  83c410               add esp, 0x10
// 0084147b  c20400               ret 4
// 0084147e  dd4008               fld qword ptr [eax + 8]
// 00841481  8bc6                 mov eax, esi
// 00841483  dd1e                 fstp qword ptr [esi]
// 00841485  c7460800000000       mov dword ptr [esi + 8], 0
// 0084148c  5e                   pop esi
// 0084148d  83c410               add esp, 0x10
// 00841490  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\daocore.cpp (function ??4COleDateTime@ATL@@QAEAAV01@ABUtagVARIANT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/daocore.cpp
