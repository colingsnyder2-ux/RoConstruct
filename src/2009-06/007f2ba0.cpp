// from server: 100% by auto
// roc 2009-06 007f2ba0  unit: CXTPPropertyGridInplaceList  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007f2ba0
//
// 007f2ba0  56                   push esi
// 007f2ba1  8bf1                 mov esi, ecx
// 007f2ba3  e87867f2ff           call 0x719320
// 007f2ba8  c706ec9f9000         mov dword ptr [esi], 0x909fec
// 007f2bae  c7465400000000       mov dword ptr [esi + 0x54], 0
// 007f2bb5  8bc6                 mov eax, esi
// 007f2bb7  5e                   pop esi
// 007f2bb8  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\ctlcore.cpp (function ??0CReflectorWnd@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/ctlcore.cpp
