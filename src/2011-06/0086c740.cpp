// from server: 100% by auto
// roc 2011-06 0086c740  unit: CXTPStatusBar  size: 72 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0086c740
//
// 0086c740  83ec10               sub esp, 0x10
// 0086c743  56                   push esi
// 0086c744  8d442404             lea eax, [esp + 4]
// 0086c748  50                   push eax
// 0086c749  8bf1                 mov esi, ecx
// 0086c74b  ff15ac19a400         call dword ptr [0xa419ac]
// 0086c751  6a01                 push 1
// 0086c753  8d4c2408             lea ecx, [esp + 8]
// 0086c757  51                   push ecx
// 0086c758  8bce                 mov ecx, esi
// 0086c75a  e8eb021600           call 0x9cca4a
// 0086c75f  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0086c763  8b542404             mov edx, dword ptr [esp + 4]
// 0086c767  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0086c76b  0110                 add dword ptr [eax], edx
// 0086c76d  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0086c771  015008               add dword ptr [eax + 8], edx
// 0086c774  83c1fe               add ecx, -2
// 0086c777  014804               add dword ptr [eax + 4], ecx
// 0086c77a  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0086c77e  01480c               add dword ptr [eax + 0xc], ecx
// 0086c781  5e                   pop esi
// 0086c782  83c410               add esp, 0x10
// 0086c785  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\barstat.cpp (function ?OnNcCalcSize@CStatusBar@@IAEXHPAUtagNCCALCSIZE_PARAMS@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/barstat.cpp
