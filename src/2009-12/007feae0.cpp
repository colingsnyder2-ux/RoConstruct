// from server: 100% by auto
// roc 2009-12 007feae0  unit: CXTPPaintManager  size: 113 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007feae0
//
// 007feae0  53                   push ebx
// 007feae1  8b5c240c             mov ebx, dword ptr [esp + 0xc]
// 007feae5  56                   push esi
// 007feae6  8b742418             mov esi, dword ptr [esp + 0x18]
// 007feaea  8d041e               lea eax, [esi + ebx]
// 007feaed  99                   cdq 
// 007feaee  2bc2                 sub eax, edx
// 007feaf0  8b542414             mov edx, dword ptr [esp + 0x14]
// 007feaf4  8bc8                 mov ecx, eax
// 007feaf6  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 007feafa  03c2                 add eax, edx
// 007feafc  99                   cdq 
// 007feafd  2bc2                 sub eax, edx
// 007feaff  57                   push edi
// 007feb00  8bf8                 mov edi, eax
// 007feb02  8bc6                 mov eax, esi
// 007feb04  2bc3                 sub eax, ebx
// 007feb06  99                   cdq 
// 007feb07  2bc2                 sub eax, edx
// 007feb09  d1f8                 sar eax, 1
// 007feb0b  8d70fc               lea esi, [eax - 4]
// 007feb0e  d1f9                 sar ecx, 1
// 007feb10  d1ff                 sar edi, 1
// 007feb12  83fe02               cmp esi, 2
// 007feb15  7d05                 jge 0x7feb1c
// 007feb17  be02000000           mov esi, 2
// 007feb1c  8bc6                 mov eax, esi
// 007feb1e  99                   cdq 
// 007feb1f  2bc2                 sub eax, edx
// 007feb21  8bd0                 mov edx, eax
// 007feb23  d1fa                 sar edx, 1
// 007feb25  8bc7                 mov eax, edi
// 007feb27  2bc2                 sub eax, edx
// 007feb29  8d3c30               lea edi, [eax + esi]
// 007feb2c  8bd1                 mov edx, ecx
// 007feb2e  8d1c31               lea ebx, [ecx + esi]
// 007feb31  2bd6                 sub edx, esi
// 007feb33  8b742424             mov esi, dword ptr [esp + 0x24]
// 007feb37  56                   push esi
// 007feb38  57                   push edi
// 007feb39  51                   push ecx
// 007feb3a  50                   push eax
// 007feb3b  53                   push ebx
// 007feb3c  50                   push eax
// 007feb3d  8b442428             mov eax, dword ptr [esp + 0x28]
// 007feb41  52                   push edx
// 007feb42  50                   push eax
// 007feb43  e848fbffff           call 0x7fe690
// 007feb48  83c420               add esp, 0x20
// 007feb4b  5f                   pop edi
// 007feb4c  5e                   pop esi
// 007feb4d  5b                   pop ebx
// 007feb4e  c21800               ret 0x18
// library xtp-15.2.1/Source\CommandBars\XTPPaintManager.cpp (function ?DrawComboExpandMark@CXTPPaintManager@@UAEXPAVCDC@@VCRect@@K@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPPaintManager.cpp
