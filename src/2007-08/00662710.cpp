// from server: 100% by auto
// roc 2007-08 00662710  unit: PluginInterface  size: 100 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00662710
//
// 00662710  8b442404             mov eax, dword ptr [esp + 4]
// 00662714  83ec10               sub esp, 0x10
// 00662717  66833807             cmp word ptr [eax], 7
// 0066271b  56                   push esi
// 0066271c  8bf1                 mov esi, ecx
// 0066271e  743f                 je 0x66275f
// 00662720  6a07                 push 7
// 00662722  6a00                 push 0
// 00662724  50                   push eax
// 00662725  8d442410             lea eax, [esp + 0x10]
// 00662729  50                   push eax
// 0066272a  66c74424140000       mov word ptr [esp + 0x14], 0
// 00662731  ff150cea7700         call dword ptr [0x77ea0c]
// 00662737  85c0                 test eax, eax
// 00662739  8bc6                 mov eax, esi
// 0066273b  7c14                 jl 0x662751
// 0066273d  dd44240c             fld qword ptr [esp + 0xc]
// 00662741  c7460800000000       mov dword ptr [esi + 8], 0
// 00662748  dd1e                 fstp qword ptr [esi]
// 0066274a  5e                   pop esi
// 0066274b  83c410               add esp, 0x10
// 0066274e  c20400               ret 4
// 00662751  c7460801000000       mov dword ptr [esi + 8], 1
// 00662758  5e                   pop esi
// 00662759  83c410               add esp, 0x10
// 0066275c  c20400               ret 4
// 0066275f  dd4008               fld qword ptr [eax + 8]
// 00662762  8bc6                 mov eax, esi
// 00662764  dd1e                 fstp qword ptr [esi]
// 00662766  c7460800000000       mov dword ptr [esi + 8], 0
// 0066276d  5e                   pop esi
// 0066276e  83c410               add esp, 0x10
// 00662771  c20400               ret 4
// library mfc-8.0/atlmfc\src\mfc\daocore.cpp (function ??4COleDateTime@ATL@@QAEAAV01@ABUtagVARIANT@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/daocore.cpp
