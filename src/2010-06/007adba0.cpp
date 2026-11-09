// from server: 100% by auto
// roc 2010-06 007adba0  unit: CXTPPaintManager  size: 50 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007adba0
//
// 007adba0  8b01                 mov eax, dword ptr [ecx]
// 007adba2  56                   push esi
// 007adba3  8b742408             mov esi, dword ptr [esp + 8]
// 007adba7  8906                 mov dword ptr [esi], eax
// 007adba9  8b5104               mov edx, dword ptr [ecx + 4]
// 007adbac  895604               mov dword ptr [esi + 4], edx
// 007adbaf  8b4108               mov eax, dword ptr [ecx + 8]
// 007adbb2  8b542410             mov edx, dword ptr [esp + 0x10]
// 007adbb6  894608               mov dword ptr [esi + 8], eax
// 007adbb9  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007adbbd  8b490c               mov ecx, dword ptr [ecx + 0xc]
// 007adbc0  52                   push edx
// 007adbc1  50                   push eax
// 007adbc2  56                   push esi
// 007adbc3  894e0c               mov dword ptr [esi + 0xc], ecx
// 007adbc6  ff1540bc9e00         call dword ptr [0x9ebc40]
// 007adbcc  8bc6                 mov eax, esi
// 007adbce  5e                   pop esi
// 007adbcf  c20c00               ret 0xc
// library xtp-13.2.1/Source\CommandBars\XTPPaintManager.cpp (function ??HCRect@@QBE?AV0@UtagPOINT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPPaintManager.cpp
