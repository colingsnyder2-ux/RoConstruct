// from server: 100% by auto
// roc 2011-06 0086b200  unit: CXTPPropertyGrid  size: 139 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0086b200
//
// 0086b200  8b542408             mov edx, dword ptr [esp + 8]
// 0086b204  56                   push esi
// 0086b205  8b742408             mov esi, dword ptr [esp + 8]
// 0086b209  57                   push edi
// 0086b20a  6a00                 push 0
// 0086b20c  8bf9                 mov edi, ecx
// 0086b20e  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0086b212  8b07                 mov eax, dword ptr [edi]
// 0086b214  8b4060               mov eax, dword ptr [eax + 0x60]
// 0086b217  51                   push ecx
// 0086b218  52                   push edx
// 0086b219  56                   push esi
// 0086b21a  6800000346           push 0x46030000
// 0086b21f  68cabea500           push 0xa5beca
// 0086b224  68dcb6ac00           push 0xacb6dc
// 0086b229  6a00                 push 0
// 0086b22b  8bcf                 mov ecx, edi
// 0086b22d  ffd0                 call eax
// 0086b22f  85c0                 test eax, eax
// 0086b231  7507                 jne 0x86b23a
// 0086b233  5f                   pop edi
// 0086b234  33c0                 xor eax, eax
// 0086b236  5e                   pop esi
// 0086b237  c21000               ret 0x10
// 0086b23a  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0086b23e  51                   push ecx
// 0086b23f  8bcf                 mov ecx, edi
// 0086b241  e81affffff           call 0x86b160
// 0086b246  85c0                 test eax, eax
// 0086b248  74e9                 je 0x86b233
// 0086b24a  8b460c               mov eax, dword ptr [esi + 0xc]
// 0086b24d  2b4604               sub eax, dword ptr [esi + 4]
// 0086b250  8b4e08               mov ecx, dword ptr [esi + 8]
// 0086b253  2b0e                 sub ecx, dword ptr [esi]
// 0086b255  8b17                 mov edx, dword ptr [edi]
// 0086b257  8b9258010000         mov edx, dword ptr [edx + 0x158]
// 0086b25d  50                   push eax
// 0086b25e  51                   push ecx
// 0086b25f  8bcf                 mov ecx, edi
// 0086b261  ffd2                 call edx
// 0086b263  8b4604               mov eax, dword ptr [esi + 4]
// 0086b266  8b560c               mov edx, dword ptr [esi + 0xc]
// 0086b269  8b0e                 mov ecx, dword ptr [esi]
// 0086b26b  6a44                 push 0x44
// 0086b26d  2bd0                 sub edx, eax
// 0086b26f  52                   push edx
// 0086b270  8b5608               mov edx, dword ptr [esi + 8]
// 0086b273  2bd1                 sub edx, ecx
// 0086b275  52                   push edx
// 0086b276  50                   push eax
// 0086b277  51                   push ecx
// 0086b278  6a00                 push 0
// 0086b27a  8bcf                 mov ecx, edi
// 0086b27c  e8a9f1f9ff           call 0x80a42a
// 0086b281  5f                   pop edi
// 0086b282  b801000000           mov eax, 1
// 0086b287  5e                   pop esi
// 0086b288  c21000               ret 0x10
// library xtp-15.2.1-shared-mfc/Source\PropertyGrid\XTPPropertyGrid.cpp (function ?Create@CXTPPropertyGrid@@UAEHABUtagRECT@@PAVCWnd@@IK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/PropertyGrid/XTPPropertyGrid.cpp
