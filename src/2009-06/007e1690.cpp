// from server: 100% by auto
// roc 2009-06 007e1690  unit: XTPDockingPanePaintThemes::CXTPDockingPaneNativeXPTheme  size: 76 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007e1690
//
// 007e1690  8b442408             mov eax, dword ptr [esp + 8]
// 007e1694  56                   push esi
// 007e1695  8b742408             mov esi, dword ptr [esp + 8]
// 007e1699  8b0e                 mov ecx, dword ptr [esi]
// 007e169b  3bc1                 cmp eax, ecx
// 007e169d  7d04                 jge 0x7e16a3
// 007e169f  2bc1                 sub eax, ecx
// 007e16a1  eb0d                 jmp 0x7e16b0
// 007e16a3  8b4e08               mov ecx, dword ptr [esi + 8]
// 007e16a6  3bc1                 cmp eax, ecx
// 007e16a8  7e04                 jle 0x7e16ae
// 007e16aa  2bc1                 sub eax, ecx
// 007e16ac  eb02                 jmp 0x7e16b0
// 007e16ae  33c0                 xor eax, eax
// 007e16b0  8b5604               mov edx, dword ptr [esi + 4]
// 007e16b3  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007e16b7  3bca                 cmp ecx, edx
// 007e16b9  7c07                 jl 0x7e16c2
// 007e16bb  8b560c               mov edx, dword ptr [esi + 0xc]
// 007e16be  3bca                 cmp ecx, edx
// 007e16c0  7e0d                 jle 0x7e16cf
// 007e16c2  2bca                 sub ecx, edx
// 007e16c4  51                   push ecx
// 007e16c5  50                   push eax
// 007e16c6  56                   push esi
// 007e16c7  ff15f8ed8900         call dword ptr [0x89edf8]
// 007e16cd  5e                   pop esi
// 007e16ce  c3                   ret 
// 007e16cf  33c9                 xor ecx, ecx
// 007e16d1  51                   push ecx
// 007e16d2  50                   push eax
// 007e16d3  56                   push esi
// 007e16d4  ff15f8ed8900         call dword ptr [0x89edf8]
// 007e16da  5e                   pop esi
// 007e16db  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPDockContext.cpp (function ?AdjustRectangle@CXTPDockContext@@CAXAAVCRect@@VCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPDockContext.cpp
