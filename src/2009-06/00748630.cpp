// from server: 100% by auto
// roc 2009-06 00748630  unit: CXTPReportControl  size: 107 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00748630
//
// 00748630  53                   push ebx
// 00748631  56                   push esi
// 00748632  8bd9                 mov ebx, ecx
// 00748634  ff1578ee8900         call dword ptr [0x89ee78]
// 0074863a  50                   push eax
// 0074863b  e8c206fdff           call 0x718d02
// 00748640  8bf0                 mov esi, eax
// 00748642  85f6                 test esi, esi
// 00748644  7503                 jne 0x748649
// 00748646  5e                   pop esi
// 00748647  5b                   pop ebx
// 00748648  c3                   ret 
// 00748649  8b4620               mov eax, dword ptr [esi + 0x20]
// 0074864c  57                   push edi
// 0074864d  3b4320               cmp eax, dword ptr [ebx + 0x20]
// 00748650  7440                 je 0x748692
// 00748652  8b3d98ee8900         mov edi, dword ptr [0x89ee98]
// 00748658  50                   push eax
// 00748659  ffd7                 call edi
// 0074865b  50                   push eax
// 0074865c  e8a106fdff           call 0x718d02
// 00748661  85c0                 test eax, eax
// 00748663  7403                 je 0x748668
// 00748665  8b4020               mov eax, dword ptr [eax + 0x20]
// 00748668  3b4320               cmp eax, dword ptr [ebx + 0x20]
// 0074866b  7425                 je 0x748692
// 0074866d  8b4638               mov eax, dword ptr [esi + 0x38]
// 00748670  85c0                 test eax, eax
// 00748672  7506                 jne 0x74867a
// 00748674  8b4620               mov eax, dword ptr [esi + 0x20]
// 00748677  50                   push eax
// 00748678  ffd7                 call edi
// 0074867a  50                   push eax
// 0074867b  e88206fdff           call 0x718d02
// 00748680  85c0                 test eax, eax
// 00748682  7403                 je 0x748687
// 00748684  8b4020               mov eax, dword ptr [eax + 0x20]
// 00748687  3b4320               cmp eax, dword ptr [ebx + 0x20]
// 0074868a  7406                 je 0x748692
// 0074868c  5f                   pop edi
// 0074868d  5e                   pop esi
// 0074868e  33c0                 xor eax, eax
// 00748690  5b                   pop ebx
// 00748691  c3                   ret 
// 00748692  5f                   pop edi
// 00748693  5e                   pop esi
// 00748694  b801000000           mov eax, 1
// 00748699  5b                   pop ebx
// 0074869a  c3                   ret 
// library xtp-15.2.1/Source\ReportControl\XTPReportControl.cpp (function ?HasFocus@CXTPReportControl@@QBEHXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/ReportControl/XTPReportControl.cpp
