// from server: 100% by auto
// roc 2011-06 0055be70  unit: seg_00550000  size: 195 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0055be70
//
// 0055be70  51                   push ecx
// 0055be71  8b442408             mov eax, dword ptr [esp + 8]
// 0055be75  53                   push ebx
// 0055be76  57                   push edi
// 0055be77  33ff                 xor edi, edi
// 0055be79  33db                 xor ebx, ebx
// 0055be7b  85c0                 test eax, eax
// 0055be7d  0f84ac000000         je 0x55bf2f
// 0055be83  56                   push esi
// 0055be84  8b30                 mov esi, dword ptr [eax]
// 0055be86  85f6                 test esi, esi
// 0055be88  0f84a0000000         je 0x55bf2e
// 0055be8e  8b8644020000         mov eax, dword ptr [esi + 0x244]
// 0055be94  8944240c             mov dword ptr [esp + 0xc], eax
// 0055be98  8b442418             mov eax, dword ptr [esp + 0x18]
// 0055be9c  55                   push ebp
// 0055be9d  8bae4c020000         mov ebp, dword ptr [esi + 0x24c]
// 0055bea3  85c0                 test eax, eax
// 0055bea5  7402                 je 0x55bea9
// 0055bea7  8b38                 mov edi, dword ptr [eax]
// 0055bea9  8b442420             mov eax, dword ptr [esp + 0x20]
// 0055bead  85c0                 test eax, eax
// 0055beaf  7402                 je 0x55beb3
// 0055beb1  8b18                 mov ebx, dword ptr [eax]
// 0055beb3  53                   push ebx
// 0055beb4  57                   push edi
// 0055beb5  56                   push esi
// 0055beb6  e8e5fcffff           call 0x55bba0
// 0055bebb  83c40c               add esp, 0xc
// 0055bebe  85ff                 test edi, edi
// 0055bec0  7427                 je 0x55bee9
// 0055bec2  6aff                 push -1
// 0055bec4  6800400000           push 0x4000
// 0055bec9  57                   push edi
// 0055beca  56                   push esi
// 0055becb  e8d049ffff           call 0x5508a0
// 0055bed0  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0055bed4  51                   push ecx
// 0055bed5  55                   push ebp
// 0055bed6  57                   push edi
// 0055bed7  e884560000           call 0x561560
// 0055bedc  8b542438             mov edx, dword ptr [esp + 0x38]
// 0055bee0  83c41c               add esp, 0x1c
// 0055bee3  c70200000000         mov dword ptr [edx], 0
// 0055bee9  85db                 test ebx, ebx
// 0055beeb  7427                 je 0x55bf14
// 0055beed  6aff                 push -1
// 0055beef  6800400000           push 0x4000
// 0055bef4  53                   push ebx
// 0055bef5  56                   push esi
// 0055bef6  e8a549ffff           call 0x5508a0
// 0055befb  8b442420             mov eax, dword ptr [esp + 0x20]
// 0055beff  50                   push eax
// 0055bf00  55                   push ebp
// 0055bf01  53                   push ebx
// 0055bf02  e859560000           call 0x561560
// 0055bf07  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 0055bf0b  83c41c               add esp, 0x1c
// 0055bf0e  c70100000000         mov dword ptr [ecx], 0
// 0055bf14  8b542410             mov edx, dword ptr [esp + 0x10]
// 0055bf18  52                   push edx
// 0055bf19  55                   push ebp
// 0055bf1a  56                   push esi
// 0055bf1b  e840560000           call 0x561560
// 0055bf20  8b442424             mov eax, dword ptr [esp + 0x24]
// 0055bf24  83c40c               add esp, 0xc
// 0055bf27  c70000000000         mov dword ptr [eax], 0
// 0055bf2d  5d                   pop ebp
// 0055bf2e  5e                   pop esi
// 0055bf2f  5f                   pop edi
// 0055bf30  5b                   pop ebx
// 0055bf31  59                   pop ecx
// 0055bf32  c3                   ret 
// library libpng-1.2.29/pngread.c (function _png_destroy_read_struct)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.29 pngread.c
