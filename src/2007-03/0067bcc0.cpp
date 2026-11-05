// from server: 100% by auto
// roc 2007-03 0067bcc0  unit: seg_00670000  size: 121 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0067bcc0
//
// 0067bcc0  8b442408             mov eax, dword ptr [esp + 8]
// 0067bcc4  83ec0c               sub esp, 0xc
// 0067bcc7  56                   push esi
// 0067bcc8  57                   push edi
// 0067bcc9  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 0067bccd  50                   push eax
// 0067bcce  57                   push edi
// 0067bccf  8bf1                 mov esi, ecx
// 0067bcd1  e894f10b00           call 0x73ae6a
// 0067bcd6  8bce                 mov ecx, esi
// 0067bcd8  e8e7ee0b00           call 0x73abc4
// 0067bcdd  a900010000           test eax, 0x100
// 0067bce2  744d                 je 0x67bd31
// 0067bce4  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 0067bce7  51                   push ecx
// 0067bce8  ff15c8ec7700         call dword ptr [0x77ecc8]
// 0067bcee  50                   push eax
// 0067bcef  ff153cee7700         call dword ptr [0x77ee3c]
// 0067bcf5  85c0                 test eax, eax
// 0067bcf7  7538                 jne 0x67bd31
// 0067bcf9  8b16                 mov edx, dword ptr [esi]
// 0067bcfb  8b9218010000         mov edx, dword ptr [edx + 0x118]
// 0067bd01  53                   push ebx
// 0067bd02  8d44240c             lea eax, [esp + 0xc]
// 0067bd06  50                   push eax
// 0067bd07  6a00                 push 0
// 0067bd09  6807040000           push 0x407
// 0067bd0e  8bce                 mov ecx, esi
// 0067bd10  ffd2                 call edx
// 0067bd12  8b1dbced7700         mov ebx, dword ptr [0x77edbc]
// 0067bd18  6a05                 push 5
// 0067bd1a  ffd3                 call ebx
// 0067bd1c  8b7708               mov esi, dword ptr [edi + 8]
// 0067bd1f  03c0                 add eax, eax
// 0067bd21  2bf0                 sub esi, eax
// 0067bd23  2b74240c             sub esi, dword ptr [esp + 0xc]
// 0067bd27  6a02                 push 2
// 0067bd29  ffd3                 call ebx
// 0067bd2b  2bf0                 sub esi, eax
// 0067bd2d  897708               mov dword ptr [edi + 8], esi
// 0067bd30  5b                   pop ebx
// 0067bd31  5f                   pop edi
// 0067bd32  5e                   pop esi
// 0067bd33  83c40c               add esp, 0xc
// 0067bd36  c20800               ret 8
// library mfc-9.0/atlmfc\src\mfc\barstat.cpp (function ?CalcInsideRect@CStatusBar@@UBEXAAVCRect@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/barstat.cpp
