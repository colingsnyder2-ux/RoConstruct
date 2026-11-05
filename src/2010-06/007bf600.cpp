// from server: 100% by auto
// roc 2010-06 007bf600  unit: CXTPImageManagerResource::CBitmapDC  size: 59 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007bf600
//
// 007bf600  8b442404             mov eax, dword ptr [esp + 4]
// 007bf604  83ec14               sub esp, 0x14
// 007bf607  56                   push esi
// 007bf608  50                   push eax
// 007bf609  6a00                 push 0
// 007bf60b  8d4c240c             lea ecx, [esp + 0xc]
// 007bf60f  e8ac020400           call 0x7ff8c0
// 007bf614  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 007bf618  8b542420             mov edx, dword ptr [esp + 0x20]
// 007bf61c  8b442408             mov eax, dword ptr [esp + 8]
// 007bf620  51                   push ecx
// 007bf621  52                   push edx
// 007bf622  50                   push eax
// 007bf623  ff1560a19e00         call dword ptr [0x9ea160]
// 007bf629  8d4c2404             lea ecx, [esp + 4]
// 007bf62d  8bf0                 mov esi, eax
// 007bf62f  e89c030400           call 0x7ff9d0
// 007bf634  8bc6                 mov eax, esi
// 007bf636  5e                   pop esi
// 007bf637  83c414               add esp, 0x14
// 007bf63a  c3                   ret 
// library xtp-13.2.1/Source\Common\XTPImageManager.cpp (function ?GetBitmapMaskColor@CXTPImageManager@@SAKAAVCBitmap@@VCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPImageManager.cpp
