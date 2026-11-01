// from server: 100% by auto
// roc 2007-03 0071bf90  unit: seg_00710000  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0071bf90
//
// 0071bf90  8b442408             mov eax, dword ptr [esp + 8]
// 0071bf94  85c0                 test eax, eax
// 0071bf96  742c                 je 0x71bfc4
// 0071bf98  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0071bf9c  0fb7542410           movzx edx, word ptr [esp + 0x10]
// 0071bfa1  51                   push ecx
// 0071bfa2  0fb74c2410           movzx ecx, word ptr [esp + 0x10]
// 0071bfa7  c1e210               shl edx, 0x10
// 0071bfaa  0bd1                 or edx, ecx
// 0071bfac  52                   push edx
// 0071bfad  33d2                 xor edx, edx
// 0071bfaf  3954241c             cmp dword ptr [esp + 0x1c], edx
// 0071bfb3  0f95c2               setne dl
// 0071bfb6  81c214010000         add edx, 0x114
// 0071bfbc  52                   push edx
// 0071bfbd  50                   push eax
// 0071bfbe  ff1550ee7700         call dword ptr [0x77ee50]
// 0071bfc4  c21400               ret 0x14
// library xtp-15.2.1/Source\SkinFramework\XTPSkinObjectScrollBar.cpp (function ?DoScroll@CXTPSkinObjectFrame@@IAEXPAUHWND__@@0HHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/SkinFramework/XTPSkinObjectScrollBar.cpp
