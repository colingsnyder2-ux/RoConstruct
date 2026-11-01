// from server: 100% by auto
// roc 2007-03 0064e4d0  unit: seg_00640000  size: 100 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0064e4d0
//
// 0064e4d0  8b442404             mov eax, dword ptr [esp + 4]
// 0064e4d4  83ec10               sub esp, 0x10
// 0064e4d7  66833807             cmp word ptr [eax], 7
// 0064e4db  56                   push esi
// 0064e4dc  8bf1                 mov esi, ecx
// 0064e4de  743f                 je 0x64e51f
// 0064e4e0  6a07                 push 7
// 0064e4e2  6a00                 push 0
// 0064e4e4  50                   push eax
// 0064e4e5  8d442410             lea eax, [esp + 0x10]
// 0064e4e9  50                   push eax
// 0064e4ea  66c74424140000       mov word ptr [esp + 0x14], 0
// 0064e4f1  ff15f0ea7700         call dword ptr [0x77eaf0]
// 0064e4f7  85c0                 test eax, eax
// 0064e4f9  8bc6                 mov eax, esi
// 0064e4fb  7c14                 jl 0x64e511
// 0064e4fd  dd44240c             fld qword ptr [esp + 0xc]
// 0064e501  c7460800000000       mov dword ptr [esi + 8], 0
// 0064e508  dd1e                 fstp qword ptr [esi]
// 0064e50a  5e                   pop esi
// 0064e50b  83c410               add esp, 0x10
// 0064e50e  c20400               ret 4
// 0064e511  c7460801000000       mov dword ptr [esi + 8], 1
// 0064e518  5e                   pop esi
// 0064e519  83c410               add esp, 0x10
// 0064e51c  c20400               ret 4
// 0064e51f  dd4008               fld qword ptr [eax + 8]
// 0064e522  8bc6                 mov eax, esi
// 0064e524  dd1e                 fstp qword ptr [esi]
// 0064e526  c7460800000000       mov dword ptr [esi + 8], 0
// 0064e52d  5e                   pop esi
// 0064e52e  83c410               add esp, 0x10
// 0064e531  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\daocore.cpp (function ??4COleDateTime@ATL@@QAEAAV01@ABUtagVARIANT@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/daocore.cpp
