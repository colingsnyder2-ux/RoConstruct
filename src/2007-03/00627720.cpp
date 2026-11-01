// from server: 100% by auto
// roc 2007-03 00627720  unit: seg_00620000  size: 59 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00627720
//
// 00627720  8b442404             mov eax, dword ptr [esp + 4]
// 00627724  83ec14               sub esp, 0x14
// 00627727  56                   push esi
// 00627728  50                   push eax
// 00627729  6a00                 push 0
// 0062772b  8d4c240c             lea ecx, [esp + 0xc]
// 0062772f  e8dc480400           call 0x66c010
// 00627734  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00627738  8b542420             mov edx, dword ptr [esp + 0x20]
// 0062773c  8b442408             mov eax, dword ptr [esp + 8]
// 00627740  51                   push ecx
// 00627741  52                   push edx
// 00627742  50                   push eax
// 00627743  ff1500d17700         call dword ptr [0x77d100]
// 00627749  8d4c2404             lea ecx, [esp + 4]
// 0062774d  8bf0                 mov esi, eax
// 0062774f  e8cc490400           call 0x66c120
// 00627754  8bc6                 mov eax, esi
// 00627756  5e                   pop esi
// 00627757  83c414               add esp, 0x14
// 0062775a  c3                   ret 
// library xtp-15.2.1/Source\Common\XTPImageManager.cpp (function ?GetBitmapMaskColor@CXTPImageManager@@SAKAAVCBitmap@@VCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPImageManager.cpp
