// from server: 100% by auto
// roc 2010-06 007df850  unit: CXTPReportRecordItemVariant  size: 99 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007df850
//
// 007df850  8b442404             mov eax, dword ptr [esp + 4]
// 007df854  83ec10               sub esp, 0x10
// 007df857  66833807             cmp word ptr [eax], 7
// 007df85b  56                   push esi
// 007df85c  8bf1                 mov esi, ecx
// 007df85e  743e                 je 0x7df89e
// 007df860  6a07                 push 7
// 007df862  33c9                 xor ecx, ecx
// 007df864  51                   push ecx
// 007df865  50                   push eax
// 007df866  8d542410             lea edx, [esp + 0x10]
// 007df86a  52                   push edx
// 007df86b  66894c2414           mov word ptr [esp + 0x14], cx
// 007df870  ff1514aa9e00         call dword ptr [0x9eaa14]
// 007df876  85c0                 test eax, eax
// 007df878  8bc6                 mov eax, esi
// 007df87a  7c14                 jl 0x7df890
// 007df87c  dd44240c             fld qword ptr [esp + 0xc]
// 007df880  c7460800000000       mov dword ptr [esi + 8], 0
// 007df887  dd1e                 fstp qword ptr [esi]
// 007df889  5e                   pop esi
// 007df88a  83c410               add esp, 0x10
// 007df88d  c20400               ret 4
// 007df890  c7460801000000       mov dword ptr [esi + 8], 1
// 007df897  5e                   pop esi
// 007df898  83c410               add esp, 0x10
// 007df89b  c20400               ret 4
// 007df89e  dd4008               fld qword ptr [eax + 8]
// 007df8a1  8bc6                 mov eax, esi
// 007df8a3  dd1e                 fstp qword ptr [esi]
// 007df8a5  c7460800000000       mov dword ptr [esi + 8], 0
// 007df8ac  5e                   pop esi
// 007df8ad  83c410               add esp, 0x10
// 007df8b0  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\daocore.cpp (function ??4COleDateTime@ATL@@QAEAAV01@ABUtagVARIANT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/daocore.cpp
