// from server: 100% by auto
// roc 2009-12 0082b810  unit: CXTPReportRecordItemVariant  size: 99 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0082b810
//
// 0082b810  8b442404             mov eax, dword ptr [esp + 4]
// 0082b814  83ec10               sub esp, 0x10
// 0082b817  66833807             cmp word ptr [eax], 7
// 0082b81b  56                   push esi
// 0082b81c  8bf1                 mov esi, ecx
// 0082b81e  743e                 je 0x82b85e
// 0082b820  6a07                 push 7
// 0082b822  33c9                 xor ecx, ecx
// 0082b824  51                   push ecx
// 0082b825  50                   push eax
// 0082b826  8d542410             lea edx, [esp + 0x10]
// 0082b82a  52                   push edx
// 0082b82b  66894c2414           mov word ptr [esp + 0x14], cx
// 0082b830  ff1578ba9800         call dword ptr [0x98ba78]
// 0082b836  85c0                 test eax, eax
// 0082b838  8bc6                 mov eax, esi
// 0082b83a  7c14                 jl 0x82b850
// 0082b83c  dd44240c             fld qword ptr [esp + 0xc]
// 0082b840  c7460800000000       mov dword ptr [esi + 8], 0
// 0082b847  dd1e                 fstp qword ptr [esi]
// 0082b849  5e                   pop esi
// 0082b84a  83c410               add esp, 0x10
// 0082b84d  c20400               ret 4
// 0082b850  c7460801000000       mov dword ptr [esi + 8], 1
// 0082b857  5e                   pop esi
// 0082b858  83c410               add esp, 0x10
// 0082b85b  c20400               ret 4
// 0082b85e  dd4008               fld qword ptr [eax + 8]
// 0082b861  8bc6                 mov eax, esi
// 0082b863  dd1e                 fstp qword ptr [esi]
// 0082b865  c7460800000000       mov dword ptr [esi + 8], 0
// 0082b86c  5e                   pop esi
// 0082b86d  83c410               add esp, 0x10
// 0082b870  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\daocore.cpp (function ??4COleDateTime@ATL@@QAEAAV01@ABUtagVARIANT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/daocore.cpp
