// from server: 100% by auto
// roc 2007-08 00439ca0  unit: RBX::VSoundId::?$XItem  size: 103 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00439ca0
//
// 00439ca0  51                   push ecx
// 00439ca1  56                   push esi
// 00439ca2  57                   push edi
// 00439ca3  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00439ca7  8bf1                 mov esi, ecx
// 00439ca9  8d442410             lea eax, [esp + 0x10]
// 00439cad  50                   push eax
// 00439cae  8d4c240c             lea ecx, [esp + 0xc]
// 00439cb2  51                   push ecx
// 00439cb3  57                   push edi
// 00439cb4  8bce                 mov ecx, esi
// 00439cb6  e825f4ffff           call 0x4390e0
// 00439cbb  85c0                 test eax, eax
// 00439cbd  753f                 jne 0x439cfe
// 00439cbf  394604               cmp dword ptr [esi + 4], eax
// 00439cc2  7518                 jne 0x439cdc
// 00439cc4  8b5608               mov edx, dword ptr [esi + 8]
// 00439cc7  6a01                 push 1
// 00439cc9  52                   push edx
// 00439cca  8bce                 mov ecx, esi
// 00439ccc  e89ff3ffff           call 0x439070
// 00439cd1  837e0400             cmp dword ptr [esi + 4], 0
// 00439cd5  7505                 jne 0x439cdc
// 00439cd7  e844621f00           call 0x62ff20
// 00439cdc  57                   push edi
// 00439cdd  8bce                 mov ecx, esi
// 00439cdf  e8bc642500           call 0x6901a0
// 00439ce4  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00439ce8  89480c               mov dword ptr [eax + 0xc], ecx
// 00439ceb  8b5604               mov edx, dword ptr [esi + 4]
// 00439cee  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00439cf2  8b148a               mov edx, dword ptr [edx + ecx*4]
// 00439cf5  895008               mov dword ptr [eax + 8], edx
// 00439cf8  8b5604               mov edx, dword ptr [esi + 4]
// 00439cfb  89048a               mov dword ptr [edx + ecx*4], eax
// 00439cfe  5f                   pop edi
// 00439cff  83c004               add eax, 4
// 00439d02  5e                   pop esi
// 00439d03  59                   pop ecx
// 00439d04  c20400               ret 4
// library mfc-9.0/atlmfc\src\mfc\afxbasetabctrl.cpp (function ??A?$CMap@PAUHICON__@@PAU1@HH@@QAEAAHPAUHICON__@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxbasetabctrl.cpp
