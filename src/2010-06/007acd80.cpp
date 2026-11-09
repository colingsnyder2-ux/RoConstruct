// from server: 100% by auto
// roc 2010-06 007acd80  unit: CXTPControl  size: 103 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007acd80
//
// 007acd80  51                   push ecx
// 007acd81  56                   push esi
// 007acd82  57                   push edi
// 007acd83  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 007acd87  8bf1                 mov esi, ecx
// 007acd89  8d442410             lea eax, [esp + 0x10]
// 007acd8d  50                   push eax
// 007acd8e  8d4c240c             lea ecx, [esp + 0xc]
// 007acd92  51                   push ecx
// 007acd93  57                   push edi
// 007acd94  8bce                 mov ecx, esi
// 007acd96  e875edffff           call 0x7abb10
// 007acd9b  85c0                 test eax, eax
// 007acd9d  753f                 jne 0x7acdde
// 007acd9f  394604               cmp dword ptr [esi + 4], eax
// 007acda2  7518                 jne 0x7acdbc
// 007acda4  8b5608               mov edx, dword ptr [esi + 8]
// 007acda7  6a01                 push 1
// 007acda9  52                   push edx
// 007acdaa  8bce                 mov ecx, esi
// 007acdac  e82f8c0300           call 0x7e59e0
// 007acdb1  837e0400             cmp dword ptr [esi + 4], 0
// 007acdb5  7505                 jne 0x7acdbc
// 007acdb7  e890aeffff           call 0x7a7c4c
// 007acdbc  57                   push edi
// 007acdbd  8bce                 mov ecx, esi
// 007acdbf  e8cc600c00           call 0x872e90
// 007acdc4  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007acdc8  89480c               mov dword ptr [eax + 0xc], ecx
// 007acdcb  8b5604               mov edx, dword ptr [esi + 4]
// 007acdce  8b4c2408             mov ecx, dword ptr [esp + 8]
// 007acdd2  8b148a               mov edx, dword ptr [edx + ecx*4]
// 007acdd5  895008               mov dword ptr [eax + 8], edx
// 007acdd8  8b5604               mov edx, dword ptr [esi + 4]
// 007acddb  89048a               mov dword ptr [edx + ecx*4], eax
// 007acdde  5f                   pop edi
// 007acddf  83c004               add eax, 4
// 007acde2  5e                   pop esi
// 007acde3  59                   pop ecx
// 007acde4  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??A?$CMap@PAUHICON__@@PAU1@HH@@QAEAAHPAUHICON__@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
