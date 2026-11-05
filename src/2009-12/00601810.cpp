// from server: 100% by auto
// roc 2009-12 00601810  unit: G3D::_internal::DialogTemplate  size: 286 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00601810
//
// 00601810  83ec40               sub esp, 0x40
// 00601813  53                   push ebx
// 00601814  8b5c2448             mov ebx, dword ptr [esp + 0x48]
// 00601818  55                   push ebp
// 00601819  56                   push esi
// 0060181a  8d4374               lea eax, [ebx + 0x74]
// 0060181d  57                   push edi
// 0060181e  50                   push eax
// 0060181f  e87cfd0000           call 0x6115a0
// 00601824  8b8bac000000         mov ecx, dword ptr [ebx + 0xac]
// 0060182a  51                   push ecx
// 0060182b  53                   push ebx
// 0060182c  e8aff40000           call 0x610ce0
// 00601831  8b93ec000000         mov edx, dword ptr [ebx + 0xec]
// 00601837  52                   push edx
// 00601838  53                   push ebx
// 00601839  e8a2f40000           call 0x610ce0
// 0060183e  8b83e8000000         mov eax, dword ptr [ebx + 0xe8]
// 00601844  50                   push eax
// 00601845  53                   push ebx
// 00601846  e895f40000           call 0x610ce0
// 0060184b  8b8bf0000000         mov ecx, dword ptr [ebx + 0xf0]
// 00601851  51                   push ecx
// 00601852  53                   push ebx
// 00601853  e888f40000           call 0x610ce0
// 00601858  8b93f4000000         mov edx, dword ptr [ebx + 0xf4]
// 0060185e  52                   push edx
// 0060185f  53                   push ebx
// 00601860  e87bf40000           call 0x610ce0
// 00601865  8b83f8000000         mov eax, dword ptr [ebx + 0xf8]
// 0060186b  50                   push eax
// 0060186c  53                   push ebx
// 0060186d  e86ef40000           call 0x610ce0
// 00601872  8b8bfc000000         mov ecx, dword ptr [ebx + 0xfc]
// 00601878  51                   push ecx
// 00601879  53                   push ebx
// 0060187a  e861f40000           call 0x610ce0
// 0060187f  8b9310020000         mov edx, dword ptr [ebx + 0x210]
// 00601885  52                   push edx
// 00601886  53                   push ebx
// 00601887  e854f40000           call 0x610ce0
// 0060188c  8b83fc010000         mov eax, dword ptr [ebx + 0x1fc]
// 00601892  83c444               add esp, 0x44
// 00601895  50                   push eax
// 00601896  53                   push ebx
// 00601897  e844f40000           call 0x610ce0
// 0060189c  8b8b00020000         mov ecx, dword ptr [ebx + 0x200]
// 006018a2  51                   push ecx
// 006018a3  53                   push ebx
// 006018a4  e837f40000           call 0x610ce0
// 006018a9  8b9304020000         mov edx, dword ptr [ebx + 0x204]
// 006018af  52                   push edx
// 006018b0  53                   push ebx
// 006018b1  e82af40000           call 0x610ce0
// 006018b6  8b8308020000         mov eax, dword ptr [ebx + 0x208]
// 006018bc  50                   push eax
// 006018bd  53                   push ebx
// 006018be  e81df40000           call 0x610ce0
// 006018c3  8b8b0c020000         mov ecx, dword ptr [ebx + 0x20c]
// 006018c9  51                   push ecx
// 006018ca  53                   push ebx
// 006018cb  e810f40000           call 0x610ce0
// 006018d0  8b934c020000         mov edx, dword ptr [ebx + 0x24c]
// 006018d6  8b6b48               mov ebp, dword ptr [ebx + 0x48]
// 006018d9  688c020000           push 0x28c
// 006018de  b910000000           mov ecx, 0x10
// 006018e3  8bf3                 mov esi, ebx
// 006018e5  8d7c243c             lea edi, [esp + 0x3c]
// 006018e9  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 006018eb  8b7340               mov esi, dword ptr [ebx + 0x40]
// 006018ee  8b7b44               mov edi, dword ptr [ebx + 0x44]
// 006018f1  6a00                 push 0
// 006018f3  53                   push ebx
// 006018f4  89942488000000       mov dword ptr [esp + 0x88], edx
// 006018fb  e8a4311f00           call 0x7f4aa4
// 00601900  8b842488000000       mov eax, dword ptr [esp + 0x88]
// 00601907  83c434               add esp, 0x34
// 0060190a  897340               mov dword ptr [ebx + 0x40], esi
// 0060190d  897b44               mov dword ptr [ebx + 0x44], edi
// 00601910  896b48               mov dword ptr [ebx + 0x48], ebp
// 00601913  89834c020000         mov dword ptr [ebx + 0x24c], eax
// 00601919  b910000000           mov ecx, 0x10
// 0060191e  8bfb                 mov edi, ebx
// 00601920  8d742410             lea esi, [esp + 0x10]
// 00601924  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 00601926  5f                   pop edi
// 00601927  5e                   pop esi
// 00601928  5d                   pop ebp
// 00601929  5b                   pop ebx
// 0060192a  83c440               add esp, 0x40
// 0060192d  c3                   ret 
// library libpng-1.2.32/pngwrite.c (function _png_write_destroy)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.32 pngwrite.c
