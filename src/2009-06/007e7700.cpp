// from server: 100% by auto
// roc 2009-06 007e7700  unit: CStatic  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007e7700
//
// 007e7700  56                   push esi
// 007e7701  8bf1                 mov esi, ecx
// 007e7703  e8181cf3ff           call 0x719320
// 007e7708  c706a4889000         mov dword ptr [esi], 0x9088a4
// 007e770e  c7465400000000       mov dword ptr [esi + 0x54], 0
// 007e7715  8bc6                 mov eax, esi
// 007e7717  5e                   pop esi
// 007e7718  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\ctlcore.cpp (function ??0CReflectorWnd@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/ctlcore.cpp
