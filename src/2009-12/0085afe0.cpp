// from server: 100% by auto
// roc 2009-12 0085afe0  unit: CXTPStatusBar  size: 72 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0085afe0
//
// 0085afe0  83ec10               sub esp, 0x10
// 0085afe3  56                   push esi
// 0085afe4  8d442404             lea eax, [esp + 4]
// 0085afe8  50                   push eax
// 0085afe9  8bf1                 mov esi, ecx
// 0085afeb  ff159cca9800         call dword ptr [0x98ca9c]
// 0085aff1  6a01                 push 1
// 0085aff3  8d4c2408             lea ecx, [esp + 8]
// 0085aff7  51                   push ecx
// 0085aff8  8bce                 mov ecx, esi
// 0085affa  e8e3b90c00           call 0x9269e2
// 0085afff  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0085b003  8b542404             mov edx, dword ptr [esp + 4]
// 0085b007  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0085b00b  0110                 add dword ptr [eax], edx
// 0085b00d  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0085b011  015008               add dword ptr [eax + 8], edx
// 0085b014  83c1fe               add ecx, -2
// 0085b017  014804               add dword ptr [eax + 4], ecx
// 0085b01a  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0085b01e  01480c               add dword ptr [eax + 0xc], ecx
// 0085b021  5e                   pop esi
// 0085b022  83c410               add esp, 0x10
// 0085b025  c20800               ret 8
// library mfc-8.0/atlmfc\src\mfc\barstat.cpp (function ?OnNcCalcSize@CStatusBar@@IAEXHPAUtagNCCALCSIZE_PARAMS@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barstat.cpp
