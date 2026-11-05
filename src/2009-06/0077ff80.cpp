// from server: 100% by auto
// roc 2009-06 0077ff80  unit: CXTPStatusBar  size: 72 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0077ff80
//
// 0077ff80  83ec10               sub esp, 0x10
// 0077ff83  56                   push esi
// 0077ff84  8d442404             lea eax, [esp + 4]
// 0077ff88  50                   push eax
// 0077ff89  8bf1                 mov esi, ecx
// 0077ff8b  ff15c8ee8900         call dword ptr [0x89eec8]
// 0077ff91  6a01                 push 1
// 0077ff93  8d4c2408             lea ecx, [esp + 8]
// 0077ff97  51                   push ecx
// 0077ff98  8bce                 mov ecx, esi
// 0077ff9a  e8d7c40c00           call 0x84c476
// 0077ff9f  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0077ffa3  8b542404             mov edx, dword ptr [esp + 4]
// 0077ffa7  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0077ffab  0110                 add dword ptr [eax], edx
// 0077ffad  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0077ffb1  015008               add dword ptr [eax + 8], edx
// 0077ffb4  83c1fe               add ecx, -2
// 0077ffb7  014804               add dword ptr [eax + 4], ecx
// 0077ffba  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0077ffbe  01480c               add dword ptr [eax + 0xc], ecx
// 0077ffc1  5e                   pop esi
// 0077ffc2  83c410               add esp, 0x10
// 0077ffc5  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\barstat.cpp (function ?OnNcCalcSize@CStatusBar@@IAEXHPAUtagNCCALCSIZE_PARAMS@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/barstat.cpp
