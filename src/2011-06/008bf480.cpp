// from server: 100% by auto
// roc 2011-06 008bf480  unit: CXTPDockingPaneKeyboardHook  size: 103 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 008bf480
//
// 008bf480  51                   push ecx
// 008bf481  56                   push esi
// 008bf482  57                   push edi
// 008bf483  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 008bf487  8bf1                 mov esi, ecx
// 008bf489  8d442410             lea eax, [esp + 0x10]
// 008bf48d  50                   push eax
// 008bf48e  8d4c240c             lea ecx, [esp + 0xc]
// 008bf492  51                   push ecx
// 008bf493  57                   push edi
// 008bf494  8bce                 mov ecx, esi
// 008bf496  e875f9faff           call 0x86ee10
// 008bf49b  85c0                 test eax, eax
// 008bf49d  753f                 jne 0x8bf4de
// 008bf49f  394604               cmp dword ptr [esi + 4], eax
// 008bf4a2  7518                 jne 0x8bf4bc
// 008bf4a4  8b5608               mov edx, dword ptr [esi + 8]
// 008bf4a7  6a01                 push 1
// 008bf4a9  52                   push edx
// 008bf4aa  8bce                 mov ecx, esi
// 008bf4ac  e88f51b8ff           call 0x444640
// 008bf4b1  837e0400             cmp dword ptr [esi + 4], 0
// 008bf4b5  7505                 jne 0x8bf4bc
// 008bf4b7  e84eaef4ff           call 0x80a30a
// 008bf4bc  57                   push edi
// 008bf4bd  8bce                 mov ecx, esi
// 008bf4bf  e84cfeffff           call 0x8bf310
// 008bf4c4  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 008bf4c8  89480c               mov dword ptr [eax + 0xc], ecx
// 008bf4cb  8b5604               mov edx, dword ptr [esi + 4]
// 008bf4ce  8b4c2408             mov ecx, dword ptr [esp + 8]
// 008bf4d2  8b148a               mov edx, dword ptr [edx + ecx*4]
// 008bf4d5  895008               mov dword ptr [eax + 8], edx
// 008bf4d8  8b5604               mov edx, dword ptr [esi + 4]
// 008bf4db  89048a               mov dword ptr [edx + ecx*4], eax
// 008bf4de  5f                   pop edi
// 008bf4df  83c004               add eax, 4
// 008bf4e2  5e                   pop esi
// 008bf4e3  59                   pop ecx
// 008bf4e4  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??A?$CMap@PAUHICON__@@PAU1@HH@@QAEAAHPAUHICON__@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
