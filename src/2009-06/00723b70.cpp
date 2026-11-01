// from server: 100% by auto
// roc 2009-06 00723b70  unit: CXTPPaintManager  size: 113 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00723b70
//
// 00723b70  53                   push ebx
// 00723b71  8b5c240c             mov ebx, dword ptr [esp + 0xc]
// 00723b75  56                   push esi
// 00723b76  8b742418             mov esi, dword ptr [esp + 0x18]
// 00723b7a  8d041e               lea eax, [esi + ebx]
// 00723b7d  99                   cdq 
// 00723b7e  2bc2                 sub eax, edx
// 00723b80  8b542414             mov edx, dword ptr [esp + 0x14]
// 00723b84  8bc8                 mov ecx, eax
// 00723b86  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00723b8a  03c2                 add eax, edx
// 00723b8c  99                   cdq 
// 00723b8d  2bc2                 sub eax, edx
// 00723b8f  57                   push edi
// 00723b90  8bf8                 mov edi, eax
// 00723b92  8bc6                 mov eax, esi
// 00723b94  2bc3                 sub eax, ebx
// 00723b96  99                   cdq 
// 00723b97  2bc2                 sub eax, edx
// 00723b99  d1f8                 sar eax, 1
// 00723b9b  8d70fc               lea esi, [eax - 4]
// 00723b9e  d1f9                 sar ecx, 1
// 00723ba0  d1ff                 sar edi, 1
// 00723ba2  83fe02               cmp esi, 2
// 00723ba5  7d05                 jge 0x723bac
// 00723ba7  be02000000           mov esi, 2
// 00723bac  8bc6                 mov eax, esi
// 00723bae  99                   cdq 
// 00723baf  2bc2                 sub eax, edx
// 00723bb1  8bd0                 mov edx, eax
// 00723bb3  d1fa                 sar edx, 1
// 00723bb5  8bc7                 mov eax, edi
// 00723bb7  2bc2                 sub eax, edx
// 00723bb9  8d3c30               lea edi, [eax + esi]
// 00723bbc  8bd1                 mov edx, ecx
// 00723bbe  8d1c31               lea ebx, [ecx + esi]
// 00723bc1  2bd6                 sub edx, esi
// 00723bc3  8b742424             mov esi, dword ptr [esp + 0x24]
// 00723bc7  56                   push esi
// 00723bc8  57                   push edi
// 00723bc9  51                   push ecx
// 00723bca  50                   push eax
// 00723bcb  53                   push ebx
// 00723bcc  50                   push eax
// 00723bcd  8b442428             mov eax, dword ptr [esp + 0x28]
// 00723bd1  52                   push edx
// 00723bd2  50                   push eax
// 00723bd3  e8d8d70400           call 0x7713b0
// 00723bd8  83c420               add esp, 0x20
// 00723bdb  5f                   pop edi
// 00723bdc  5e                   pop esi
// 00723bdd  5b                   pop ebx
// 00723bde  c21800               ret 0x18
// library xtp-15.2.1/Source\CommandBars\XTPPaintManager.cpp (function ?DrawComboExpandMark@CXTPPaintManager@@UAEXPAVCDC@@VCRect@@K@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPPaintManager.cpp
