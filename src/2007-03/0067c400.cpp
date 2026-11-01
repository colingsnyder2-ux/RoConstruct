// from server: 100% by auto
// roc 2007-03 0067c400  unit: seg_00670000  size: 72 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0067c400
//
// 0067c400  83ec10               sub esp, 0x10
// 0067c403  56                   push esi
// 0067c404  8d442404             lea eax, [esp + 4]
// 0067c408  50                   push eax
// 0067c409  8bf1                 mov esi, ecx
// 0067c40b  ff1514ef7700         call dword ptr [0x77ef14]
// 0067c411  6a01                 push 1
// 0067c413  8d4c2408             lea ecx, [esp + 8]
// 0067c417  51                   push ecx
// 0067c418  8bce                 mov ecx, esi
// 0067c41a  e84bea0b00           call 0x73ae6a
// 0067c41f  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0067c423  8b542404             mov edx, dword ptr [esp + 4]
// 0067c427  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0067c42b  0110                 add dword ptr [eax], edx
// 0067c42d  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0067c431  015008               add dword ptr [eax + 8], edx
// 0067c434  83c1fe               add ecx, -2
// 0067c437  014804               add dword ptr [eax + 4], ecx
// 0067c43a  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0067c43e  01480c               add dword ptr [eax + 0xc], ecx
// 0067c441  5e                   pop esi
// 0067c442  83c410               add esp, 0x10
// 0067c445  c20800               ret 8
// library mfc-8.0/atlmfc\src\mfc\barstat.cpp (function ?OnNcCalcSize@CStatusBar@@IAEXHPAUtagNCCALCSIZE_PARAMS@@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/barstat.cpp
