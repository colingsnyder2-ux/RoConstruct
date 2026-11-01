// from server: 100% by auto
// roc 2007-03 00633430  unit: seg_00630000  size: 113 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00633430
//
// 00633430  53                   push ebx
// 00633431  8b5c240c             mov ebx, dword ptr [esp + 0xc]
// 00633435  56                   push esi
// 00633436  8b742418             mov esi, dword ptr [esp + 0x18]
// 0063343a  8d041e               lea eax, [esi + ebx]
// 0063343d  99                   cdq 
// 0063343e  2bc2                 sub eax, edx
// 00633440  8b542414             mov edx, dword ptr [esp + 0x14]
// 00633444  8bc8                 mov ecx, eax
// 00633446  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0063344a  03c2                 add eax, edx
// 0063344c  99                   cdq 
// 0063344d  2bc2                 sub eax, edx
// 0063344f  57                   push edi
// 00633450  8bf8                 mov edi, eax
// 00633452  8bc6                 mov eax, esi
// 00633454  2bc3                 sub eax, ebx
// 00633456  99                   cdq 
// 00633457  2bc2                 sub eax, edx
// 00633459  d1f8                 sar eax, 1
// 0063345b  8d70fc               lea esi, [eax - 4]
// 0063345e  d1f9                 sar ecx, 1
// 00633460  d1ff                 sar edi, 1
// 00633462  83fe02               cmp esi, 2
// 00633465  7d05                 jge 0x63346c
// 00633467  be02000000           mov esi, 2
// 0063346c  8bc6                 mov eax, esi
// 0063346e  99                   cdq 
// 0063346f  2bc2                 sub eax, edx
// 00633471  8bd0                 mov edx, eax
// 00633473  d1fa                 sar edx, 1
// 00633475  8bc7                 mov eax, edi
// 00633477  2bc2                 sub eax, edx
// 00633479  8d3c30               lea edi, [eax + esi]
// 0063347c  8bd1                 mov edx, ecx
// 0063347e  8d1c31               lea ebx, [ecx + esi]
// 00633481  2bd6                 sub edx, esi
// 00633483  8b742424             mov esi, dword ptr [esp + 0x24]
// 00633487  56                   push esi
// 00633488  57                   push edi
// 00633489  51                   push ecx
// 0063348a  50                   push eax
// 0063348b  53                   push ebx
// 0063348c  50                   push eax
// 0063348d  8b442428             mov eax, dword ptr [esp + 0x28]
// 00633491  52                   push edx
// 00633492  50                   push eax
// 00633493  e858fbffff           call 0x632ff0
// 00633498  83c420               add esp, 0x20
// 0063349b  5f                   pop edi
// 0063349c  5e                   pop esi
// 0063349d  5b                   pop ebx
// 0063349e  c21800               ret 0x18
// library xtp-15.2.1/Source\CommandBars\XTPPaintManager.cpp (function ?DrawComboExpandMark@CXTPPaintManager@@UAEXPAVCDC@@VCRect@@K@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPPaintManager.cpp
