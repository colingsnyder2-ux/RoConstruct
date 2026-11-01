// from server: 100% by auto
// roc 2007-03 00417430  unit: seg_00410000  size: 410 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00417430
//
// 00417430  83ec70               sub esp, 0x70
// 00417433  53                   push ebx
// 00417434  56                   push esi
// 00417435  8b74247c             mov esi, dword ptr [esp + 0x7c]
// 00417439  85f6                 test esi, esi
// 0041743b  0f8480010000         je 0x4175c1
// 00417441  8b842480000000       mov eax, dword ptr [esp + 0x80]
// 00417448  85c0                 test eax, eax
// 0041744a  0f8471010000         je 0x4175c1
// 00417450  8b9c2484000000       mov ebx, dword ptr [esp + 0x84]
// 00417457  85db                 test ebx, ebx
// 00417459  0f8462010000         je 0x4175c1
// 0041745f  83bc248800000000     cmp dword ptr [esp + 0x88], 0
// 00417467  0f8454010000         je 0x4175c1
// 0041746d  66837b4000           cmp word ptr [ebx + 0x40], 0
// 00417472  55                   push ebp
// 00417473  57                   push edi
// 00417474  0f8529010000         jne 0x4175a3
// 0041747a  83c004               add eax, 4
// 0041747d  8d4c2418             lea ecx, [esp + 0x18]
// 00417481  89442418             mov dword ptr [esp + 0x18], eax
// 00417485  c644241c00           mov byte ptr [esp + 0x1c], 0
// 0041748a  e861b5feff           call 0x4029f0
// 0041748f  85c0                 test eax, eax
// 00417491  7c4f                 jl 0x4174e2
// 00417493  66837b4000           cmp word ptr [ebx + 0x40], 0
// 00417498  0f85fc000000         jne 0x41759a
// 0041749e  8b4330               mov eax, dword ptr [ebx + 0x30]
// 004174a1  85c0                 test eax, eax
// 004174a3  8b2decec7700         mov ebp, dword ptr [0x77ecec]
// 004174a9  7475                 je 0x417520
// 004174ab  8b4b28               mov ecx, dword ptr [ebx + 0x28]
// 004174ae  8b5308               mov edx, dword ptr [ebx + 8]
// 004174b1  894c2410             mov dword ptr [esp + 0x10], ecx
// 004174b5  8d4c2420             lea ecx, [esp + 0x20]
// 004174b9  51                   push ecx
// 004174ba  50                   push eax
// 004174bb  6a00                 push 0
// 004174bd  89542420             mov dword ptr [esp + 0x20], edx
// 004174c1  c744242c30000000     mov dword ptr [esp + 0x2c], 0x30
// 004174c9  ffd5                 call ebp
// 004174cb  85c0                 test eax, eax
// 004174cd  7527                 jne 0x4174f6
// 004174cf  8b4330               mov eax, dword ptr [ebx + 0x30]
// 004174d2  8b4e04               mov ecx, dword ptr [esi + 4]
// 004174d5  8d542420             lea edx, [esp + 0x20]
// 004174d9  52                   push edx
// 004174da  50                   push eax
// 004174db  51                   push ecx
// 004174dc  ffd5                 call ebp
// 004174de  85c0                 test eax, eax
// 004174e0  7514                 jne 0x4174f6
// 004174e2  8d4c2418             lea ecx, [esp + 0x18]
// 004174e6  e8e5b4feff           call 0x4029d0
// 004174eb  5f                   pop edi
// 004174ec  5d                   pop ebp
// 004174ed  5e                   pop esi
// 004174ee  6633c0               xor ax, ax
// 004174f1  5b                   pop ebx
// 004174f2  83c470               add esp, 0x70
// 004174f5  c3                   ret 
// 004174f6  8b542414             mov edx, dword ptr [esp + 0x14]
// 004174fa  b90c000000           mov ecx, 0xc
// 004174ff  8d742420             lea esi, [esp + 0x20]
// 00417503  8bfb                 mov edi, ebx
// 00417505  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 00417507  8b4308               mov eax, dword ptr [ebx + 8]
// 0041750a  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0041750e  8bb42484000000       mov esi, dword ptr [esp + 0x84]
// 00417515  894334               mov dword ptr [ebx + 0x34], eax
// 00417518  894b28               mov dword ptr [ebx + 0x28], ecx
// 0041751b  895308               mov dword ptr [ebx + 8], edx
// 0041751e  eb1b                 jmp 0x41753b
// 00417520  837b3c00             cmp dword ptr [ebx + 0x3c], 0
// 00417524  7404                 je 0x41752a
// 00417526  33c0                 xor eax, eax
// 00417528  eb03                 jmp 0x41752d
// 0041752a  8b4608               mov eax, dword ptr [esi + 8]
// 0041752d  8b4b38               mov ecx, dword ptr [ebx + 0x38]
// 00417530  51                   push ecx
// 00417531  50                   push eax
// 00417532  ff15f0ec7700         call dword ptr [0x77ecf0]
// 00417538  89431c               mov dword ptr [ebx + 0x1c], eax
// 0041753b  8b4604               mov eax, dword ptr [esi + 4]
// 0041753e  816304ffbfffff       and dword ptr [ebx + 4], 0xffffbfff
// 00417545  837b2800             cmp dword ptr [ebx + 0x28], 0
// 00417549  894314               mov dword ptr [ebx + 0x14], eax
// 0041754c  7512                 jne 0x417560
// 0041754e  53                   push ebx
// 0041754f  8d7342               lea esi, [ebx + 0x42]
// 00417552  6a25                 push 0x25
// 00417554  56                   push esi
// 00417555  e816d1ffff           call 0x414670
// 0041755a  83c40c               add esp, 0xc
// 0041755d  897328               mov dword ptr [ebx + 0x28], esi
// 00417560  8b4328               mov eax, dword ptr [ebx + 0x28]
// 00417563  8d542450             lea edx, [esp + 0x50]
// 00417567  52                   push edx
// 00417568  b90c000000           mov ecx, 0xc
// 0041756d  8bf3                 mov esi, ebx
// 0041756f  8d7c2454             lea edi, [esp + 0x54]
// 00417573  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 00417575  8b4b14               mov ecx, dword ptr [ebx + 0x14]
// 00417578  50                   push eax
// 00417579  51                   push ecx
// 0041757a  ffd5                 call ebp
// 0041757c  6685c0               test ax, ax
// 0041757f  66894340             mov word ptr [ebx + 0x40], ax
// 00417583  7515                 jne 0x41759a
// 00417585  8b842488000000       mov eax, dword ptr [esp + 0x88]
// 0041758c  53                   push ebx
// 0041758d  50                   push eax
// 0041758e  e8fdf7ffff           call 0x416d90
// 00417593  83c408               add esp, 8
// 00417596  66894340             mov word ptr [ebx + 0x40], ax
// 0041759a  8d4c2418             lea ecx, [esp + 0x18]
// 0041759e  e82db4feff           call 0x4029d0
// 004175a3  837b3000             cmp dword ptr [ebx + 0x30], 0
// 004175a7  740c                 je 0x4175b5
// 004175a9  8b4b34               mov ecx, dword ptr [ebx + 0x34]
// 004175ac  8b942490000000       mov edx, dword ptr [esp + 0x90]
// 004175b3  890a                 mov dword ptr [edx], ecx
// 004175b5  668b4340             mov ax, word ptr [ebx + 0x40]
// 004175b9  5f                   pop edi
// 004175ba  5d                   pop ebp
// 004175bb  5e                   pop esi
// 004175bc  5b                   pop ebx
// 004175bd  83c470               add esp, 0x70
// 004175c0  c3                   ret 
// 004175c1  5e                   pop esi
// 004175c2  6633c0               xor ax, ax
// 004175c5  5b                   pop ebx
// 004175c6  83c470               add esp, 0x70
// 004175c9  c3                   ret 
// library atl-8.0/atl.cpp (function ??$AtlModuleRegisterWndClassInfoT@VAtlModuleRegisterWndClassInfoParamA@ATL@@@ATL@@YAGPAU_ATL_BASE_MODULE70@0@PAU_ATL_WIN_MODULE70@0@PAU_ATL_WNDCLASSINFOA@0@PAP6GJPAUHWND__@@IIJ@ZVAtlModuleRegisterWndClassInfoParamA@0@@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
