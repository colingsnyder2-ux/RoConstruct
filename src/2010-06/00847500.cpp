// from server: 100% by auto
// roc 2010-06 00847500  unit: CXTPMenuBar::CControlMDIButton  size: 138 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00847500
//
// 00847500  8b442404             mov eax, dword ptr [esp + 4]
// 00847504  56                   push esi
// 00847505  57                   push edi
// 00847506  50                   push eax
// 00847507  e85e07f6ff           call 0x7a7c6a
// 0084750c  50                   push eax
// 0084750d  e8f2591300           call 0x97cf04
// 00847512  50                   push eax
// 00847513  e86608f6ff           call 0x7a7d7e
// 00847518  8bf0                 mov esi, eax
// 0084751a  83c408               add esp, 8
// 0084751d  85f6                 test esi, esi
// 0084751f  7417                 je 0x847538
// 00847521  8bce                 mov ecx, esi
// 00847523  e82008f6ff           call 0x7a7d48
// 00847528  85c0                 test eax, eax
// 0084752a  740c                 je 0x847538
// 0084752c  8bce                 mov ecx, esi
// 0084752e  e81508f6ff           call 0x7a7d48
// 00847533  8b4054               mov eax, dword ptr [eax + 0x54]
// 00847536  eb02                 jmp 0x84753a
// 00847538  33c0                 xor eax, eax
// 0084753a  50                   push eax
// 0084753b  e84e5d1300           call 0x97d28e
// 00847540  50                   push eax
// 00847541  e83808f6ff           call 0x7a7d7e
// 00847546  8bf8                 mov edi, eax
// 00847548  83c408               add esp, 8
// 0084754b  85ff                 test edi, edi
// 0084754d  7434                 je 0x847583
// 0084754f  85f6                 test esi, esi
// 00847551  7430                 je 0x847583
// 00847553  53                   push ebx
// 00847554  8b1f                 mov ebx, dword ptr [edi]
// 00847556  8bce                 mov ecx, esi
// 00847558  e8eb07f6ff           call 0x7a7d48
// 0084755d  8b93b8000000         mov edx, dword ptr [ebx + 0xb8]
// 00847563  50                   push eax
// 00847564  8bcf                 mov ecx, edi
// 00847566  ffd2                 call edx
// 00847568  50                   push eax
// 00847569  e886601300           call 0x97d5f4
// 0084756e  50                   push eax
// 0084756f  e80a08f6ff           call 0x7a7d7e
// 00847574  83c408               add esp, 8
// 00847577  f7d8                 neg eax
// 00847579  5b                   pop ebx
// 0084757a  1bc0                 sbb eax, eax
// 0084757c  5f                   pop edi
// 0084757d  f7d8                 neg eax
// 0084757f  5e                   pop esi
// 00847580  c20400               ret 4
// 00847583  5f                   pop edi
// 00847584  33c0                 xor eax, eax
// 00847586  5e                   pop esi
// 00847587  c20400               ret 4
// library xtp-13.2.1-shared-mfc/Source\CommandBars\XTPMenuBar.cpp (function ?IsOleDocumentActive@CXTPMenuBar@@ABEHPAUHWND__@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/CommandBars/XTPMenuBar.cpp
