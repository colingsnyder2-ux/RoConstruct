// from server: 100% by auto
// roc 2010-06 008818f0  unit: CXTPPropertyGridInplaceList  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008818f0
//
// 008818f0  56                   push esi
// 008818f1  8bf1                 mov esi, ecx
// 008818f3  e89069f2ff           call 0x7a8288
// 008818f8  c70654e7a600         mov dword ptr [esi], 0xa6e754
// 008818fe  c7465400000000       mov dword ptr [esi + 0x54], 0
// 00881905  8bc6                 mov eax, esi
// 00881907  5e                   pop esi
// 00881908  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\ctlcore.cpp (function ??0CReflectorWnd@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/ctlcore.cpp
