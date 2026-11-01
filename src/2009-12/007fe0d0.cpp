// from server: 100% by auto
// roc 2009-12 007fe0d0  unit: CXTPPaintManager  size: 50 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007fe0d0
//
// 007fe0d0  8b01                 mov eax, dword ptr [ecx]
// 007fe0d2  56                   push esi
// 007fe0d3  8b742408             mov esi, dword ptr [esp + 8]
// 007fe0d7  8906                 mov dword ptr [esi], eax
// 007fe0d9  8b5104               mov edx, dword ptr [ecx + 4]
// 007fe0dc  895604               mov dword ptr [esi + 4], edx
// 007fe0df  8b4108               mov eax, dword ptr [ecx + 8]
// 007fe0e2  8b542410             mov edx, dword ptr [esp + 0x10]
// 007fe0e6  894608               mov dword ptr [esi + 8], eax
// 007fe0e9  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007fe0ed  8b490c               mov ecx, dword ptr [ecx + 0xc]
// 007fe0f0  52                   push edx
// 007fe0f1  50                   push eax
// 007fe0f2  56                   push esi
// 007fe0f3  894e0c               mov dword ptr [esi + 0xc], ecx
// 007fe0f6  ff156ccc9800         call dword ptr [0x98cc6c]
// 007fe0fc  8bc6                 mov eax, esi
// 007fe0fe  5e                   pop esi
// 007fe0ff  c20c00               ret 0xc
// library xtp-15.2.1/Source\CommandBars\XTPPaintManager.cpp (function ??HCRect@@QBE?AV0@UtagPOINT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPPaintManager.cpp
