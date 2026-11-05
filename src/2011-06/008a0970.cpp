// from server: 100% by auto
// roc 2011-06 008a0970  unit: ATL::D::DV?$ChTraitsCRT::DV?$StrTraitMFC_DLL::IIV?$CStringT::?$CMap  size: 103 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008a0970
//
// 008a0970  51                   push ecx
// 008a0971  56                   push esi
// 008a0972  57                   push edi
// 008a0973  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 008a0977  8bf1                 mov esi, ecx
// 008a0979  8d442410             lea eax, [esp + 0x10]
// 008a097d  50                   push eax
// 008a097e  8d4c240c             lea ecx, [esp + 0xc]
// 008a0982  51                   push ecx
// 008a0983  57                   push edi
// 008a0984  8bce                 mov ecx, esi
// 008a0986  e885e4fcff           call 0x86ee10
// 008a098b  85c0                 test eax, eax
// 008a098d  753f                 jne 0x8a09ce
// 008a098f  394604               cmp dword ptr [esi + 4], eax
// 008a0992  7518                 jne 0x8a09ac
// 008a0994  8b5608               mov edx, dword ptr [esi + 8]
// 008a0997  6a01                 push 1
// 008a0999  52                   push edx
// 008a099a  8bce                 mov ecx, esi
// 008a099c  e89f3cbaff           call 0x444640
// 008a09a1  837e0400             cmp dword ptr [esi + 4], 0
// 008a09a5  7505                 jne 0x8a09ac
// 008a09a7  e85e99f6ff           call 0x80a30a
// 008a09ac  57                   push edi
// 008a09ad  8bce                 mov ecx, esi
// 008a09af  e86cfdffff           call 0x8a0720
// 008a09b4  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 008a09b8  89480c               mov dword ptr [eax + 0xc], ecx
// 008a09bb  8b5604               mov edx, dword ptr [esi + 4]
// 008a09be  8b4c2408             mov ecx, dword ptr [esp + 8]
// 008a09c2  8b148a               mov edx, dword ptr [edx + ecx*4]
// 008a09c5  895008               mov dword ptr [eax + 8], edx
// 008a09c8  8b5604               mov edx, dword ptr [esi + 4]
// 008a09cb  89048a               mov dword ptr [edx + ecx*4], eax
// 008a09ce  5f                   pop edi
// 008a09cf  83c004               add eax, 4
// 008a09d2  5e                   pop esi
// 008a09d3  59                   pop ecx
// 008a09d4  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??A?$CMap@PAUHICON__@@PAU1@HH@@QAEAAHPAUHICON__@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
