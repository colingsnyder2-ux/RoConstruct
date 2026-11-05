// from server: 100% by auto
// roc 2008-06 0070e8b0  unit: CXTPStatusBar  size: 72 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0070e8b0
//
// 0070e8b0  83ec10               sub esp, 0x10
// 0070e8b3  56                   push esi
// 0070e8b4  8d442404             lea eax, [esp + 4]
// 0070e8b8  50                   push eax
// 0070e8b9  8bf1                 mov esi, ecx
// 0070e8bb  ff157c2c8000         call dword ptr [0x802c7c]
// 0070e8c1  6a01                 push 1
// 0070e8c3  8d4c2408             lea ecx, [esp + 8]
// 0070e8c7  51                   push ecx
// 0070e8c8  8bce                 mov ecx, esi
// 0070e8ca  e8f3dc0a00           call 0x7bc5c2
// 0070e8cf  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0070e8d3  8b542404             mov edx, dword ptr [esp + 4]
// 0070e8d7  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0070e8db  0110                 add dword ptr [eax], edx
// 0070e8dd  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0070e8e1  015008               add dword ptr [eax + 8], edx
// 0070e8e4  83c1fe               add ecx, -2
// 0070e8e7  014804               add dword ptr [eax + 4], ecx
// 0070e8ea  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0070e8ee  01480c               add dword ptr [eax + 0xc], ecx
// 0070e8f1  5e                   pop esi
// 0070e8f2  83c410               add esp, 0x10
// 0070e8f5  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\barstat.cpp (function ?OnNcCalcSize@CStatusBar@@IAEXHPAUtagNCCALCSIZE_PARAMS@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/barstat.cpp
