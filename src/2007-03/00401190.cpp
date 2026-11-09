// from server: 100% by auto
// roc 2007-03 00401190  unit: seg_00400000  size: 149 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00401190
//
// 00401190  51                   push ecx
// 00401191  56                   push esi
// 00401192  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00401196  85f6                 test esi, esi
// 00401198  57                   push edi
// 00401199  0f8480000000         je 0x40121f
// 0040119f  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 004011a3  85ff                 test edi, edi
// 004011a5  7478                 je 0x40121f
// 004011a7  53                   push ebx
// 004011a8  ff1550508b00         call dword ptr [0x8b5050]
// 004011ae  6a00                 push 0
// 004011b0  6a00                 push 0
// 004011b2  57                   push edi
// 004011b3  56                   push esi
// 004011b4  8bd8                 mov ebx, eax
// 004011b6  6a00                 push 0
// 004011b8  53                   push ebx
// 004011b9  c744242400000000     mov dword ptr [esp + 0x24], 0
// 004011c1  ff15d8d27700         call dword ptr [0x77d2d8]
// 004011c7  83ffff               cmp edi, -1
// 004011ca  8bf0                 mov esi, eax
// 004011cc  7503                 jne 0x4011d1
// 004011ce  8d46ff               lea eax, [esi - 1]
// 004011d1  55                   push ebp
// 004011d2  50                   push eax
// 004011d3  6a00                 push 0
// 004011d5  ff158cea7700         call dword ptr [0x77ea8c]
// 004011db  8be8                 mov ebp, eax
// 004011dd  85ed                 test ebp, ebp
// 004011df  742d                 je 0x40120e
// 004011e1  8b442418             mov eax, dword ptr [esp + 0x18]
// 004011e5  56                   push esi
// 004011e6  55                   push ebp
// 004011e7  57                   push edi
// 004011e8  50                   push eax
// 004011e9  6a00                 push 0
// 004011eb  53                   push ebx
// 004011ec  ff15d8d27700         call dword ptr [0x77d2d8]
// 004011f2  3bc6                 cmp eax, esi
// 004011f4  7418                 je 0x40120e
// 004011f6  55                   push ebp
// 004011f7  ff1588ea7700         call dword ptr [0x77ea88]
// 004011fd  8d4c2410             lea ecx, [esp + 0x10]
// 00401201  e85affffff           call 0x401160
// 00401206  5d                   pop ebp
// 00401207  5b                   pop ebx
// 00401208  5f                   pop edi
// 00401209  33c0                 xor eax, eax
// 0040120b  5e                   pop esi
// 0040120c  59                   pop ecx
// 0040120d  c3                   ret 
// 0040120e  8d4c2410             lea ecx, [esp + 0x10]
// 00401212  e849ffffff           call 0x401160
// 00401217  8bc5                 mov eax, ebp
// 00401219  5d                   pop ebp
// 0040121a  5b                   pop ebx
// 0040121b  5f                   pop edi
// 0040121c  5e                   pop esi
// 0040121d  59                   pop ecx
// 0040121e  c3                   ret 
// 0040121f  5f                   pop edi
// 00401220  33c0                 xor eax, eax
// 00401222  5e                   pop esi
// 00401223  59                   pop ecx
// 00401224  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\dlgdhtml.cpp (function ?A2WBSTR@@YAPA_WPBDH@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/dlgdhtml.cpp
