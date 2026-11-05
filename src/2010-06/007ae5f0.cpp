// from server: 100% by auto
// roc 2010-06 007ae5f0  unit: CXTPPaintManager  size: 113 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007ae5f0
//
// 007ae5f0  53                   push ebx
// 007ae5f1  8b5c240c             mov ebx, dword ptr [esp + 0xc]
// 007ae5f5  56                   push esi
// 007ae5f6  8b742418             mov esi, dword ptr [esp + 0x18]
// 007ae5fa  8d041e               lea eax, [esi + ebx]
// 007ae5fd  99                   cdq 
// 007ae5fe  2bc2                 sub eax, edx
// 007ae600  8b542414             mov edx, dword ptr [esp + 0x14]
// 007ae604  8bc8                 mov ecx, eax
// 007ae606  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 007ae60a  03c2                 add eax, edx
// 007ae60c  99                   cdq 
// 007ae60d  2bc2                 sub eax, edx
// 007ae60f  57                   push edi
// 007ae610  8bf8                 mov edi, eax
// 007ae612  8bc6                 mov eax, esi
// 007ae614  2bc3                 sub eax, ebx
// 007ae616  99                   cdq 
// 007ae617  2bc2                 sub eax, edx
// 007ae619  d1f8                 sar eax, 1
// 007ae61b  8d70fc               lea esi, [eax - 4]
// 007ae61e  d1f9                 sar ecx, 1
// 007ae620  d1ff                 sar edi, 1
// 007ae622  83fe02               cmp esi, 2
// 007ae625  7d05                 jge 0x7ae62c
// 007ae627  be02000000           mov esi, 2
// 007ae62c  8bc6                 mov eax, esi
// 007ae62e  99                   cdq 
// 007ae62f  2bc2                 sub eax, edx
// 007ae631  8bd0                 mov edx, eax
// 007ae633  d1fa                 sar edx, 1
// 007ae635  8bc7                 mov eax, edi
// 007ae637  2bc2                 sub eax, edx
// 007ae639  8d3c30               lea edi, [eax + esi]
// 007ae63c  8bd1                 mov edx, ecx
// 007ae63e  8d1c31               lea ebx, [ecx + esi]
// 007ae641  2bd6                 sub edx, esi
// 007ae643  8b742424             mov esi, dword ptr [esp + 0x24]
// 007ae647  56                   push esi
// 007ae648  57                   push edi
// 007ae649  51                   push ecx
// 007ae64a  50                   push eax
// 007ae64b  53                   push ebx
// 007ae64c  50                   push eax
// 007ae64d  8b442428             mov eax, dword ptr [esp + 0x28]
// 007ae651  52                   push edx
// 007ae652  50                   push eax
// 007ae653  e848fbffff           call 0x7ae1a0
// 007ae658  83c420               add esp, 0x20
// 007ae65b  5f                   pop edi
// 007ae65c  5e                   pop esi
// 007ae65d  5b                   pop ebx
// 007ae65e  c21800               ret 0x18
// library xtp-13.2.1/Source\CommandBars\XTPPaintManager.cpp (function ?DrawComboExpandMark@CXTPPaintManager@@UAEXPAVCDC@@VCRect@@K@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPPaintManager.cpp
