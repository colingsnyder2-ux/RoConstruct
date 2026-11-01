// from server: 100% by auto
// roc 2009-12 0080b4b0  unit: CXTPImageManagerResource::CBitmapDC  size: 59 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0080b4b0
//
// 0080b4b0  8b442404             mov eax, dword ptr [esp + 4]
// 0080b4b4  83ec14               sub esp, 0x14
// 0080b4b7  56                   push esi
// 0080b4b8  50                   push eax
// 0080b4b9  6a00                 push 0
// 0080b4bb  8d4c240c             lea ecx, [esp + 0xc]
// 0080b4bf  e8bc030400           call 0x84b880
// 0080b4c4  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0080b4c8  8b542420             mov edx, dword ptr [esp + 0x20]
// 0080b4cc  8b442408             mov eax, dword ptr [esp + 8]
// 0080b4d0  51                   push ecx
// 0080b4d1  52                   push edx
// 0080b4d2  50                   push eax
// 0080b4d3  ff1518b19800         call dword ptr [0x98b118]
// 0080b4d9  8d4c2404             lea ecx, [esp + 4]
// 0080b4dd  8bf0                 mov esi, eax
// 0080b4df  e8ac040400           call 0x84b990
// 0080b4e4  8bc6                 mov eax, esi
// 0080b4e6  5e                   pop esi
// 0080b4e7  83c414               add esp, 0x14
// 0080b4ea  c3                   ret 
// library xtp-15.2.1/Source\Common\XTPImageManager.cpp (function ?GetBitmapMaskColor@CXTPImageManager@@SAKAAVCBitmap@@VCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPImageManager.cpp
