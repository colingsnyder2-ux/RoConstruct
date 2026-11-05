// from server: 100% by auto
// roc 2009-12 00433f30  unit: CPropGrid::UpdateItemsJob  size: 103 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00433f30
//
// 00433f30  51                   push ecx
// 00433f31  56                   push esi
// 00433f32  57                   push edi
// 00433f33  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00433f37  8bf1                 mov esi, ecx
// 00433f39  8d442410             lea eax, [esp + 0x10]
// 00433f3d  50                   push eax
// 00433f3e  8d4c240c             lea ecx, [esp + 0xc]
// 00433f42  51                   push ecx
// 00433f43  57                   push edi
// 00433f44  8bce                 mov ecx, esi
// 00433f46  e815f6ffff           call 0x433560
// 00433f4b  85c0                 test eax, eax
// 00433f4d  753f                 jne 0x433f8e
// 00433f4f  394604               cmp dword ptr [esi + 4], eax
// 00433f52  7518                 jne 0x433f6c
// 00433f54  8b5608               mov edx, dword ptr [esi + 8]
// 00433f57  6a01                 push 1
// 00433f59  52                   push edx
// 00433f5a  8bce                 mov ecx, esi
// 00433f5c  e84fa64500           call 0x88e5b0
// 00433f61  837e0400             cmp dword ptr [esi + 4], 0
// 00433f65  7505                 jne 0x433f6c
// 00433f67  e8a0fb3b00           call 0x7f3b0c
// 00433f6c  57                   push edi
// 00433f6d  8bce                 mov ecx, esi
// 00433f6f  e83c8a3d00           call 0x80c9b0
// 00433f74  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00433f78  89480c               mov dword ptr [eax + 0xc], ecx
// 00433f7b  8b5604               mov edx, dword ptr [esi + 4]
// 00433f7e  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00433f82  8b148a               mov edx, dword ptr [edx + ecx*4]
// 00433f85  895008               mov dword ptr [eax + 8], edx
// 00433f88  8b5604               mov edx, dword ptr [esi + 4]
// 00433f8b  89048a               mov dword ptr [edx + ecx*4], eax
// 00433f8e  5f                   pop edi
// 00433f8f  83c004               add eax, 4
// 00433f92  5e                   pop esi
// 00433f93  59                   pop ecx
// 00433f94  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??A?$CMap@PAUHICON__@@PAU1@HH@@QAEAAHPAUHICON__@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
