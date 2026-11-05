// from server: 100% by auto
// roc 2010-06 007ef9e0  unit: CXTPToolBar::CControlButtonExpand  size: 49 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007ef9e0
//
// 007ef9e0  8b4108               mov eax, dword ptr [ecx + 8]
// 007ef9e3  85c0                 test eax, eax
// 007ef9e5  7501                 jne 0x7ef9e8
// 007ef9e7  c3                   ret 
// 007ef9e8  56                   push esi
// 007ef9e9  6814c6a500           push 0xa5c614
// 007ef9ee  8d7110               lea esi, [ecx + 0x10]
// 007ef9f1  50                   push eax
// 007ef9f2  c70614000000         mov dword ptr [esi], 0x14
// 007ef9f8  ff1590a39e00         call dword ptr [0x9ea390]
// 007ef9fe  85c0                 test eax, eax
// 007efa00  740b                 je 0x7efa0d
// 007efa02  56                   push esi
// 007efa03  ffd0                 call eax
// 007efa05  f7d8                 neg eax
// 007efa07  1bc0                 sbb eax, eax
// 007efa09  f7d8                 neg eax
// 007efa0b  5e                   pop esi
// 007efa0c  c3                   ret 
// 007efa0d  33c0                 xor eax, eax
// 007efa0f  5e                   pop esi
// 007efa10  c3                   ret 
// library xtp-13.2.1/Source\Common\XTPSystemHelpers.cpp (function ?GetVersionInfo@CXTPModuleHandle@@AAEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPSystemHelpers.cpp
