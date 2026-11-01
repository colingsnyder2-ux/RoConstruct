// from server: 100% by auto
// roc 2009-06 00723bf0  unit: CXTPPaintManager  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00723bf0
//
// 00723bf0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00723bf4  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00723bf8  83ec08               sub esp, 8
// 00723bfb  56                   push esi
// 00723bfc  8b742410             mov esi, dword ptr [esp + 0x10]
// 00723c00  50                   push eax
// 00723c01  51                   push ecx
// 00723c02  8d54240c             lea edx, [esp + 0xc]
// 00723c06  52                   push edx
// 00723c07  8bce                 mov ecx, esi
// 00723c09  e8005dffff           call 0x71990e
// 00723c0e  8b442420             mov eax, dword ptr [esp + 0x20]
// 00723c12  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00723c16  50                   push eax
// 00723c17  51                   push ecx
// 00723c18  8bce                 mov ecx, esi
// 00723c1a  e8e95cffff           call 0x719908
// 00723c1f  5e                   pop esi
// 00723c20  83c408               add esp, 8
// 00723c23  c21400               ret 0x14
// library xtp-15.2.1/Source\CommandBars\XTPPaintManager.cpp (function ?Line@CXTPPaintManager@@QAEXPAVCDC@@VCPoint@@1@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPPaintManager.cpp
