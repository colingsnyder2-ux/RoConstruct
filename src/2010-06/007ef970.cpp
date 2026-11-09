// from server: 100% by auto
// roc 2010-06 007ef970  unit: CXTPToolBar::CControlButtonExpand  size: 45 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007ef970
//
// 007ef970  56                   push esi
// 007ef971  8bf1                 mov esi, ecx
// 007ef973  8d4e04               lea ecx, [esi + 4]
// 007ef976  c70610c6a500         mov dword ptr [esi], 0xa5c610
// 007ef97c  ff15a4ce9e00         call dword ptr [0x9ecea4]
// 007ef982  33c0                 xor eax, eax
// 007ef984  894608               mov dword ptr [esi + 8], eax
// 007ef987  89460c               mov dword ptr [esi + 0xc], eax
// 007ef98a  894610               mov dword ptr [esi + 0x10], eax
// 007ef98d  894614               mov dword ptr [esi + 0x14], eax
// 007ef990  894618               mov dword ptr [esi + 0x18], eax
// 007ef993  89461c               mov dword ptr [esi + 0x1c], eax
// 007ef996  894620               mov dword ptr [esi + 0x20], eax
// 007ef999  8bc6                 mov eax, esi
// 007ef99b  5e                   pop esi
// 007ef99c  c3                   ret 
// library xtp-13.2.1-shared-mfc/Source\Common\XTPSystemHelpers.cpp (function ??0CXTPModuleHandle@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/Common/XTPSystemHelpers.cpp
