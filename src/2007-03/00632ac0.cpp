// from server: 100% by auto
// roc 2007-03 00632ac0  unit: seg_00630000  size: 50 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00632ac0
//
// 00632ac0  8b01                 mov eax, dword ptr [ecx]
// 00632ac2  56                   push esi
// 00632ac3  8b742408             mov esi, dword ptr [esp + 8]
// 00632ac7  8906                 mov dword ptr [esi], eax
// 00632ac9  8b5104               mov edx, dword ptr [ecx + 4]
// 00632acc  895604               mov dword ptr [esi + 4], edx
// 00632acf  8b4108               mov eax, dword ptr [ecx + 8]
// 00632ad2  8b542410             mov edx, dword ptr [esp + 0x10]
// 00632ad6  894608               mov dword ptr [esi + 8], eax
// 00632ad9  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00632add  8b490c               mov ecx, dword ptr [ecx + 0xc]
// 00632ae0  52                   push edx
// 00632ae1  50                   push eax
// 00632ae2  56                   push esi
// 00632ae3  894e0c               mov dword ptr [esi + 0xc], ecx
// 00632ae6  ff1558ed7700         call dword ptr [0x77ed58]
// 00632aec  8bc6                 mov eax, esi
// 00632aee  5e                   pop esi
// 00632aef  c20c00               ret 0xc
// library xtp-15.2.1/Source\CommandBars\XTPPaintManager.cpp (function ??HCRect@@QBE?AV0@UtagPOINT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPPaintManager.cpp
