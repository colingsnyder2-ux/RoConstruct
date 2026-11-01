// from server: 100% by auto
// roc 2009-06 007a8410  unit: CXTPOffice2007Theme  size: 101 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007a8410
//
// 007a8410  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007a8414  56                   push esi
// 007a8415  8b742408             mov esi, dword ptr [esp + 8]
// 007a8419  8d4801               lea ecx, [eax + 1]
// 007a841c  51                   push ecx
// 007a841d  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 007a8421  8d5101               lea edx, [ecx + 1]
// 007a8424  52                   push edx
// 007a8425  50                   push eax
// 007a8426  51                   push ecx
// 007a8427  8bce                 mov ecx, esi
// 007a8429  e8b83f0a00           call 0x84c3e6
// 007a842e  8b442410             mov eax, dword ptr [esp + 0x10]
// 007a8432  8d4801               lea ecx, [eax + 1]
// 007a8435  51                   push ecx
// 007a8436  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 007a843a  51                   push ecx
// 007a843b  49                   dec ecx
// 007a843c  50                   push eax
// 007a843d  51                   push ecx
// 007a843e  8bce                 mov ecx, esi
// 007a8440  e8a13f0a00           call 0x84c3e6
// 007a8445  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 007a8449  8b442418             mov eax, dword ptr [esp + 0x18]
// 007a844d  50                   push eax
// 007a844e  8d5101               lea edx, [ecx + 1]
// 007a8451  52                   push edx
// 007a8452  48                   dec eax
// 007a8453  50                   push eax
// 007a8454  51                   push ecx
// 007a8455  8bce                 mov ecx, esi
// 007a8457  e88a3f0a00           call 0x84c3e6
// 007a845c  8b442418             mov eax, dword ptr [esp + 0x18]
// 007a8460  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 007a8464  50                   push eax
// 007a8465  51                   push ecx
// 007a8466  48                   dec eax
// 007a8467  49                   dec ecx
// 007a8468  50                   push eax
// 007a8469  51                   push ecx
// 007a846a  8bce                 mov ecx, esi
// 007a846c  e8753f0a00           call 0x84c3e6
// 007a8471  5e                   pop esi
// 007a8472  c21400               ret 0x14
// library xtp-15.2.1/Source\CommandBars\XTPOffice2003Theme.cpp (function ?ExcludeCorners@CXTPOffice2003Theme@@QAEXPAVCDC@@VCRect@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPOffice2003Theme.cpp
