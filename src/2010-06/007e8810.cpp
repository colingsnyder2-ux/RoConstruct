// from server: 100% by auto
// roc 2010-06 007e8810  unit: CRobloxTreeCtrl  size: 103 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007e8810
//
// 007e8810  51                   push ecx
// 007e8811  56                   push esi
// 007e8812  57                   push edi
// 007e8813  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 007e8817  8bf1                 mov esi, ecx
// 007e8819  8d442410             lea eax, [esp + 0x10]
// 007e881d  50                   push eax
// 007e881e  8d4c240c             lea ecx, [esp + 0xc]
// 007e8822  51                   push ecx
// 007e8823  57                   push edi
// 007e8824  8bce                 mov ecx, esi
// 007e8826  e815ebffff           call 0x7e7340
// 007e882b  85c0                 test eax, eax
// 007e882d  753f                 jne 0x7e886e
// 007e882f  394604               cmp dword ptr [esi + 4], eax
// 007e8832  7518                 jne 0x7e884c
// 007e8834  8b5608               mov edx, dword ptr [esi + 8]
// 007e8837  6a01                 push 1
// 007e8839  52                   push edx
// 007e883a  8bce                 mov ecx, esi
// 007e883c  e89fd1ffff           call 0x7e59e0
// 007e8841  837e0400             cmp dword ptr [esi + 4], 0
// 007e8845  7505                 jne 0x7e884c
// 007e8847  e800f4fbff           call 0x7a7c4c
// 007e884c  57                   push edi
// 007e884d  8bce                 mov ecx, esi
// 007e884f  e80cf6ffff           call 0x7e7e60
// 007e8854  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007e8858  89484c               mov dword ptr [eax + 0x4c], ecx
// 007e885b  8b5604               mov edx, dword ptr [esi + 4]
// 007e885e  8b4c2408             mov ecx, dword ptr [esp + 8]
// 007e8862  8b148a               mov edx, dword ptr [edx + ecx*4]
// 007e8865  895048               mov dword ptr [eax + 0x48], edx
// 007e8868  8b5604               mov edx, dword ptr [esi + 4]
// 007e886b  89048a               mov dword ptr [edx + ecx*4], eax
// 007e886e  5f                   pop edi
// 007e886f  83c004               add eax, 4
// 007e8872  5e                   pop esi
// 007e8873  59                   pop ecx
// 007e8874  c20400               ret 4
// library xtp-13.2.1/Source\Controls\XTTreeBase.cpp (function ??A?$CMap@PAXPAXUCLRFONT@CXTTreeBase@@AAU12@@@QAEAAUCLRFONT@CXTTreeBase@@PAX@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Controls/XTTreeBase.cpp
