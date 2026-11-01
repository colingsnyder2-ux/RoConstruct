// from server: 100% by auto
// roc 2009-06 00734410  unit: CXTPImageManagerResource::CBitmapDC  size: 59 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00734410
//
// 00734410  8b442404             mov eax, dword ptr [esp + 4]
// 00734414  83ec14               sub esp, 0x14
// 00734417  56                   push esi
// 00734418  50                   push eax
// 00734419  6a00                 push 0
// 0073441b  8d4c240c             lea ecx, [esp + 0xc]
// 0073441f  e85cc60300           call 0x770a80
// 00734424  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00734428  8b542420             mov edx, dword ptr [esp + 0x20]
// 0073442c  8b442408             mov eax, dword ptr [esp + 8]
// 00734430  51                   push ecx
// 00734431  52                   push edx
// 00734432  50                   push eax
// 00734433  ff15d8e08900         call dword ptr [0x89e0d8]
// 00734439  8d4c2404             lea ecx, [esp + 4]
// 0073443d  8bf0                 mov esi, eax
// 0073443f  e84cc70300           call 0x770b90
// 00734444  8bc6                 mov eax, esi
// 00734446  5e                   pop esi
// 00734447  83c414               add esp, 0x14
// 0073444a  c3                   ret 
// library xtp-15.2.1/Source\Common\XTPImageManager.cpp (function ?GetBitmapMaskColor@CXTPImageManager@@SAKAAVCBitmap@@VCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPImageManager.cpp
