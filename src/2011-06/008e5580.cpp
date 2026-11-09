// from server: 100% by auto
// roc 2011-06 008e5580  unit: CXTPPropertyGridInplaceList  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008e5580
//
// 008e5580  56                   push esi
// 008e5581  8bf1                 mov esi, ecx
// 008e5583  e8be53f2ff           call 0x80a946
// 008e5588  c7062488ad00         mov dword ptr [esi], 0xad8824
// 008e558e  c7465400000000       mov dword ptr [esi + 0x54], 0
// 008e5595  8bc6                 mov eax, esi
// 008e5597  5e                   pop esi
// 008e5598  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\ctlcore.cpp (function ??0CReflectorWnd@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/ctlcore.cpp
