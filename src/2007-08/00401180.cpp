// from server: 100% by auto
// roc 2007-08 00401180  unit: CSettingsDialog  size: 149 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00401180
//
// 00401180  51                   push ecx
// 00401181  56                   push esi
// 00401182  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00401186  85f6                 test esi, esi
// 00401188  57                   push edi
// 00401189  0f8480000000         je 0x40120f
// 0040118f  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 00401193  85ff                 test edi, edi
// 00401195  7478                 je 0x40120f
// 00401197  53                   push ebx
// 00401198  ff1564ab8b00         call dword ptr [0x8bab64]
// 0040119e  6a00                 push 0
// 004011a0  6a00                 push 0
// 004011a2  57                   push edi
// 004011a3  56                   push esi
// 004011a4  8bd8                 mov ebx, eax
// 004011a6  6a00                 push 0
// 004011a8  53                   push ebx
// 004011a9  c744242400000000     mov dword ptr [esp + 0x24], 0
// 004011b1  ff1518d37700         call dword ptr [0x77d318]
// 004011b7  83ffff               cmp edi, -1
// 004011ba  8bf0                 mov esi, eax
// 004011bc  7503                 jne 0x4011c1
// 004011be  8d46ff               lea eax, [esi - 1]
// 004011c1  55                   push ebp
// 004011c2  50                   push eax
// 004011c3  6a00                 push 0
// 004011c5  ff15b4e97700         call dword ptr [0x77e9b4]
// 004011cb  8be8                 mov ebp, eax
// 004011cd  85ed                 test ebp, ebp
// 004011cf  742d                 je 0x4011fe
// 004011d1  8b442418             mov eax, dword ptr [esp + 0x18]
// 004011d5  56                   push esi
// 004011d6  55                   push ebp
// 004011d7  57                   push edi
// 004011d8  50                   push eax
// 004011d9  6a00                 push 0
// 004011db  53                   push ebx
// 004011dc  ff1518d37700         call dword ptr [0x77d318]
// 004011e2  3bc6                 cmp eax, esi
// 004011e4  7418                 je 0x4011fe
// 004011e6  55                   push ebp
// 004011e7  ff15b0e97700         call dword ptr [0x77e9b0]
// 004011ed  8d4c2410             lea ecx, [esp + 0x10]
// 004011f1  e85affffff           call 0x401150
// 004011f6  5d                   pop ebp
// 004011f7  5b                   pop ebx
// 004011f8  5f                   pop edi
// 004011f9  33c0                 xor eax, eax
// 004011fb  5e                   pop esi
// 004011fc  59                   pop ecx
// 004011fd  c3                   ret 
// 004011fe  8d4c2410             lea ecx, [esp + 0x10]
// 00401202  e849ffffff           call 0x401150
// 00401207  8bc5                 mov eax, ebp
// 00401209  5d                   pop ebp
// 0040120a  5b                   pop ebx
// 0040120b  5f                   pop edi
// 0040120c  5e                   pop esi
// 0040120d  59                   pop ecx
// 0040120e  c3                   ret 
// 0040120f  5f                   pop edi
// 00401210  33c0                 xor eax, eax
// 00401212  5e                   pop esi
// 00401213  59                   pop ecx
// 00401214  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\dlgdhtml.cpp (function ?A2WBSTR@@YAPA_WPBDH@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/dlgdhtml.cpp
