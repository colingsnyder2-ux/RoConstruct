// from server: 100% by auto
// roc 2010-06 007ef9a0  unit: CXTPToolBar::CControlButtonExpand  size: 59 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007ef9a0
//
// 007ef9a0  56                   push esi
// 007ef9a1  8bf1                 mov esi, ecx
// 007ef9a3  8b4608               mov eax, dword ptr [esi + 8]
// 007ef9a6  57                   push edi
// 007ef9a7  bf01000000           mov edi, 1
// 007ef9ac  85c0                 test eax, eax
// 007ef9ae  740f                 je 0x7ef9bf
// 007ef9b0  837e0c02             cmp dword ptr [esi + 0xc], 2
// 007ef9b4  7509                 jne 0x7ef9bf
// 007ef9b6  50                   push eax
// 007ef9b7  ff1568a39e00         call dword ptr [0x9ea368]
// 007ef9bd  8bf8                 mov edi, eax
// 007ef9bf  8d4e04               lea ecx, [esi + 4]
// 007ef9c2  c7460800000000       mov dword ptr [esi + 8], 0
// 007ef9c9  c7460c00000000       mov dword ptr [esi + 0xc], 0
// 007ef9d0  ff1588c69e00         call dword ptr [0x9ec688]
// 007ef9d6  8bc7                 mov eax, edi
// 007ef9d8  5f                   pop edi
// 007ef9d9  5e                   pop esi
// 007ef9da  c3                   ret 
// library xtp-13.2.1-shared-mfc/Source\Common\XTPSystemHelpers.cpp (function ?FreeLibrary@CXTPModuleHandle@@QAEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/Common/XTPSystemHelpers.cpp
