// from server: 100% by auto
// roc 2007-03 007173c0  unit: seg_00710000  size: 71 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 007173c0
//
// 007173c0  8b442404             mov eax, dword ptr [esp + 4]
// 007173c4  83f801               cmp eax, 1
// 007173c7  751a                 jne 0x7173e3
// 007173c9  8b542408             mov edx, dword ptr [esp + 8]
// 007173cd  6a00                 push 0
// 007173cf  52                   push edx
// 007173d0  b835040000           mov eax, 0x435
// 007173d5  50                   push eax
// 007173d6  8b4120               mov eax, dword ptr [ecx + 0x20]
// 007173d9  50                   push eax
// 007173da  ff1550ee7700         call dword ptr [0x77ee50]
// 007173e0  c20800               ret 8
// 007173e3  8b542408             mov edx, dword ptr [esp + 8]
// 007173e7  83e802               sub eax, 2
// 007173ea  f7d8                 neg eax
// 007173ec  1bc0                 sbb eax, eax
// 007173ee  6a00                 push 0
// 007173f0  83e0fa               and eax, 0xfffffffa
// 007173f3  0537040000           add eax, 0x437
// 007173f8  52                   push edx
// 007173f9  50                   push eax
// 007173fa  8b4120               mov eax, dword ptr [ecx + 0x20]
// 007173fd  50                   push eax
// 007173fe  ff1550ee7700         call dword ptr [0x77ee50]
// 00717404  c20800               ret 8
// library xtp-15.2.1/Source\SkinFramework\XTPSkinObjectToolBar.cpp (function ?GetImageList@CXTPSkinObjectToolBar@@IAEPAU_IMAGELIST@@HH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/SkinFramework/XTPSkinObjectToolBar.cpp
