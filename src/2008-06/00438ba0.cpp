// from server: 100% by auto
// roc 2008-06 00438ba0  unit: IIHAAH::?$CMap  size: 103 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00438ba0
//
// 00438ba0  51                   push ecx
// 00438ba1  56                   push esi
// 00438ba2  57                   push edi
// 00438ba3  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00438ba7  8bf1                 mov esi, ecx
// 00438ba9  8d442410             lea eax, [esp + 0x10]
// 00438bad  50                   push eax
// 00438bae  8d4c240c             lea ecx, [esp + 0xc]
// 00438bb2  51                   push ecx
// 00438bb3  57                   push edi
// 00438bb4  8bce                 mov ecx, esi
// 00438bb6  e805fdffff           call 0x4388c0
// 00438bbb  85c0                 test eax, eax
// 00438bbd  753f                 jne 0x438bfe
// 00438bbf  394604               cmp dword ptr [esi + 4], eax
// 00438bc2  7518                 jne 0x438bdc
// 00438bc4  8b5608               mov edx, dword ptr [esi + 8]
// 00438bc7  6a01                 push 1
// 00438bc9  52                   push edx
// 00438bca  8bce                 mov ecx, esi
// 00438bcc  e87ffcffff           call 0x438850
// 00438bd1  837e0400             cmp dword ptr [esi + 4], 0
// 00438bd5  7505                 jne 0x438bdc
// 00438bd7  e8687d2600           call 0x6a0944
// 00438bdc  57                   push edi
// 00438bdd  8bce                 mov ecx, esi
// 00438bdf  e85c882e00           call 0x721440
// 00438be4  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00438be8  89480c               mov dword ptr [eax + 0xc], ecx
// 00438beb  8b5604               mov edx, dword ptr [esi + 4]
// 00438bee  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00438bf2  8b148a               mov edx, dword ptr [edx + ecx*4]
// 00438bf5  895008               mov dword ptr [eax + 8], edx
// 00438bf8  8b5604               mov edx, dword ptr [esi + 4]
// 00438bfb  89048a               mov dword ptr [edx + ecx*4], eax
// 00438bfe  5f                   pop edi
// 00438bff  83c004               add eax, 4
// 00438c02  5e                   pop esi
// 00438c03  59                   pop ecx
// 00438c04  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??A?$CMap@PAUHICON__@@PAU1@HH@@QAEAAHPAUHICON__@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
