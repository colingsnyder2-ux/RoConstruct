// from server: 100% by auto
// roc 2011-06 008511f0  unit: CXTPToolBar::CControlButtonExpand  size: 59 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008511f0
//
// 008511f0  56                   push esi
// 008511f1  8bf1                 mov esi, ecx
// 008511f3  8b4608               mov eax, dword ptr [esi + 8]
// 008511f6  57                   push edi
// 008511f7  bf01000000           mov edi, 1
// 008511fc  85c0                 test eax, eax
// 008511fe  740f                 je 0x85120f
// 00851200  837e0c02             cmp dword ptr [esi + 0xc], 2
// 00851204  7509                 jne 0x85120f
// 00851206  50                   push eax
// 00851207  ff15b803a400         call dword ptr [0xa403b8]
// 0085120d  8bf8                 mov edi, eax
// 0085120f  8d4e04               lea ecx, [esi + 4]
// 00851212  c7460800000000       mov dword ptr [esi + 8], 0
// 00851219  c7460c00000000       mov dword ptr [esi + 0xc], 0
// 00851220  ff155c27a400         call dword ptr [0xa4275c]
// 00851226  8bc7                 mov eax, edi
// 00851228  5f                   pop edi
// 00851229  5e                   pop esi
// 0085122a  c3                   ret 
// library xtp-15.2.1-shared-mfc/Source\Common\XTPSystemHelpers.cpp (function ?FreeLibrary@CXTPModuleHandle@@QAEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/Common/XTPSystemHelpers.cpp
