// from server: 100% by auto
// roc 2010-06 008711f0  unit: CXTPDockingPaneContext  size: 153 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008711f0
//
// 008711f0  8b4c2404             mov ecx, dword ptr [esp + 4]
// 008711f4  8b01                 mov eax, dword ptr [ecx]
// 008711f6  8b5018               mov edx, dword ptr [eax + 0x18]
// 008711f9  56                   push esi
// 008711fa  ffd2                 call edx
// 008711fc  8bf0                 mov esi, eax
// 008711fe  85f6                 test esi, esi
// 00871200  747e                 je 0x871280
// 00871202  e88913ffff           call 0x862590
// 00871207  50                   push eax
// 00871208  8bce                 mov ecx, esi
// 0087120a  e8196df3ff           call 0x7a7f28
// 0087120f  85c0                 test eax, eax
// 00871211  746d                 je 0x871280
// 00871213  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00871217  8b01                 mov eax, dword ptr [ecx]
// 00871219  8b5018               mov edx, dword ptr [eax + 0x18]
// 0087121c  53                   push ebx
// 0087121d  ffd2                 call edx
// 0087121f  8bd8                 mov ebx, eax
// 00871221  85db                 test ebx, ebx
// 00871223  7454                 je 0x871279
// 00871225  e86613ffff           call 0x862590
// 0087122a  50                   push eax
// 0087122b  8bcb                 mov ecx, ebx
// 0087122d  e8f66cf3ff           call 0x7a7f28
// 00871232  85c0                 test eax, eax
// 00871234  7443                 je 0x871279
// 00871236  8b4620               mov eax, dword ptr [esi + 0x20]
// 00871239  57                   push edi
// 0087123a  8b3d90ba9e00         mov edi, dword ptr [0x9eba90]
// 00871240  6a02                 push 2
// 00871242  50                   push eax
// 00871243  ffd7                 call edi
// 00871245  8bf0                 mov esi, eax
// 00871247  85f6                 test esi, esi
// 00871249  741b                 je 0x871266
// 0087124b  eb03                 jmp 0x871250
// 0087124d  8d4900               lea ecx, [ecx]
// 00871250  8bcb                 mov ecx, ebx
// 00871252  e819bab9ff           call 0x40cc70
// 00871257  3bf0                 cmp esi, eax
// 00871259  7416                 je 0x871271
// 0087125b  6a02                 push 2
// 0087125d  56                   push esi
// 0087125e  ffd7                 call edi
// 00871260  8bf0                 mov esi, eax
// 00871262  85f6                 test esi, esi
// 00871264  75ea                 jne 0x871250
// 00871266  5f                   pop edi
// 00871267  5b                   pop ebx
// 00871268  b801000000           mov eax, 1
// 0087126d  5e                   pop esi
// 0087126e  c20800               ret 8
// 00871271  5f                   pop edi
// 00871272  5b                   pop ebx
// 00871273  33c0                 xor eax, eax
// 00871275  5e                   pop esi
// 00871276  c20800               ret 8
// 00871279  5b                   pop ebx
// 0087127a  33c0                 xor eax, eax
// 0087127c  5e                   pop esi
// 0087127d  c20800               ret 8
// 00871280  b801000000           mov eax, 1
// 00871285  5e                   pop esi
// 00871286  c20800               ret 8
// library xtp-13.2.1-shared-mfc/Source\DockingPane\XTPDockingPaneContext.cpp (function ?IsBehind@CXTPDockingPaneContext@@IAEHPAVCXTPDockingPaneBase@@0@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/DockingPane/XTPDockingPaneContext.cpp
