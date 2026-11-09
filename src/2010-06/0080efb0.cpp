// from server: 100% by auto
// roc 2010-06 0080efb0  unit: CXTPStatusBar  size: 72 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0080efb0
//
// 0080efb0  83ec10               sub esp, 0x10
// 0080efb3  56                   push esi
// 0080efb4  8d442404             lea eax, [esp + 4]
// 0080efb8  50                   push eax
// 0080efb9  8bf1                 mov esi, ecx
// 0080efbb  ff15e4ba9e00         call dword ptr [0x9ebae4]
// 0080efc1  6a01                 push 1
// 0080efc3  8d4c2408             lea ecx, [esp + 8]
// 0080efc7  51                   push ecx
// 0080efc8  8bce                 mov ecx, esi
// 0080efca  e855e31600           call 0x97d324
// 0080efcf  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0080efd3  8b542404             mov edx, dword ptr [esp + 4]
// 0080efd7  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0080efdb  0110                 add dword ptr [eax], edx
// 0080efdd  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0080efe1  015008               add dword ptr [eax + 8], edx
// 0080efe4  83c1fe               add ecx, -2
// 0080efe7  014804               add dword ptr [eax + 4], ecx
// 0080efea  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0080efee  01480c               add dword ptr [eax + 0xc], ecx
// 0080eff1  5e                   pop esi
// 0080eff2  83c410               add esp, 0x10
// 0080eff5  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\barstat.cpp (function ?OnNcCalcSize@CStatusBar@@IAEXHPAUtagNCCALCSIZE_PARAMS@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/barstat.cpp
