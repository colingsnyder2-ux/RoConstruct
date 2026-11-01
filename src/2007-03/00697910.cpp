// from server: 100% by auto
// roc 2007-03 00697910  unit: seg_00690000  size: 103 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00697910
//
// 00697910  51                   push ecx
// 00697911  56                   push esi
// 00697912  57                   push edi
// 00697913  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00697917  8bf1                 mov esi, ecx
// 00697919  8d442410             lea eax, [esp + 0x10]
// 0069791d  50                   push eax
// 0069791e  8d4c240c             lea ecx, [esp + 0xc]
// 00697922  51                   push ecx
// 00697923  57                   push edi
// 00697924  8bce                 mov ecx, esi
// 00697926  e805f8ffff           call 0x697130
// 0069792b  85c0                 test eax, eax
// 0069792d  753f                 jne 0x69796e
// 0069792f  394604               cmp dword ptr [esi + 4], eax
// 00697932  7518                 jne 0x69794c
// 00697934  8b5608               mov edx, dword ptr [esi + 8]
// 00697937  6a01                 push 1
// 00697939  52                   push edx
// 0069793a  8bce                 mov ecx, esi
// 0069793c  e85f8dfeff           call 0x6806a0
// 00697941  837e0400             cmp dword ptr [esi + 4], 0
// 00697945  7505                 jne 0x69794c
// 00697947  e8626af8ff           call 0x61e3ae
// 0069794c  57                   push edi
// 0069794d  8bce                 mov ecx, esi
// 0069794f  e85cfdffff           call 0x6976b0
// 00697954  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00697958  89480c               mov dword ptr [eax + 0xc], ecx
// 0069795b  8b5604               mov edx, dword ptr [esi + 4]
// 0069795e  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00697962  8b148a               mov edx, dword ptr [edx + ecx*4]
// 00697965  895008               mov dword ptr [eax + 8], edx
// 00697968  8b5604               mov edx, dword ptr [esi + 4]
// 0069796b  89048a               mov dword ptr [edx + ecx*4], eax
// 0069796e  5f                   pop edi
// 0069796f  83c004               add eax, 4
// 00697972  5e                   pop esi
// 00697973  59                   pop ecx
// 00697974  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??A?$CMap@PAUHICON__@@PAU1@HH@@QAEAAHPAUHICON__@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
