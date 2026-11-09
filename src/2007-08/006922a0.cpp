// from server: 100% by auto
// roc 2007-08 006922a0  unit: CXTPStatusBar  size: 121 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006922a0
//
// 006922a0  8b442408             mov eax, dword ptr [esp + 8]
// 006922a4  83ec0c               sub esp, 0xc
// 006922a7  56                   push esi
// 006922a8  57                   push edi
// 006922a9  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 006922ad  50                   push eax
// 006922ae  57                   push edi
// 006922af  8bf1                 mov esi, ecx
// 006922b1  e89c660a00           call 0x738952
// 006922b6  8bce                 mov ecx, esi
// 006922b8  e855610a00           call 0x738412
// 006922bd  a900010000           test eax, 0x100
// 006922c2  744d                 je 0x692311
// 006922c4  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 006922c7  51                   push ecx
// 006922c8  ff15f8eb7700         call dword ptr [0x77ebf8]
// 006922ce  50                   push eax
// 006922cf  ff155cec7700         call dword ptr [0x77ec5c]
// 006922d5  85c0                 test eax, eax
// 006922d7  7538                 jne 0x692311
// 006922d9  8b16                 mov edx, dword ptr [esi]
// 006922db  8b9218010000         mov edx, dword ptr [edx + 0x118]
// 006922e1  53                   push ebx
// 006922e2  8d44240c             lea eax, [esp + 0xc]
// 006922e6  50                   push eax
// 006922e7  6a00                 push 0
// 006922e9  6807040000           push 0x407
// 006922ee  8bce                 mov ecx, esi
// 006922f0  ffd2                 call edx
// 006922f2  8b1db8ed7700         mov ebx, dword ptr [0x77edb8]
// 006922f8  6a05                 push 5
// 006922fa  ffd3                 call ebx
// 006922fc  8b7708               mov esi, dword ptr [edi + 8]
// 006922ff  03c0                 add eax, eax
// 00692301  2bf0                 sub esi, eax
// 00692303  2b74240c             sub esi, dword ptr [esp + 0xc]
// 00692307  6a02                 push 2
// 00692309  ffd3                 call ebx
// 0069230b  2bf0                 sub esi, eax
// 0069230d  897708               mov dword ptr [edi + 8], esi
// 00692310  5b                   pop ebx
// 00692311  5f                   pop edi
// 00692312  5e                   pop esi
// 00692313  83c40c               add esp, 0xc
// 00692316  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\barstat.cpp (function ?CalcInsideRect@CStatusBar@@UBEXAAVCRect@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/barstat.cpp
