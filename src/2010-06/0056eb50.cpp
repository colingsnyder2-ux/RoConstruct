// from server: 100% by auto
// roc 2010-06 0056eb50  unit: G3D::LineSegment  size: 324 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0056eb50
//
// 0056eb50  83ec20               sub esp, 0x20
// 0056eb53  8b442428             mov eax, dword ptr [esp + 0x28]
// 0056eb57  55                   push ebp
// 0056eb58  56                   push esi
// 0056eb59  8b74242c             mov esi, dword ptr [esp + 0x2c]
// 0056eb5d  57                   push edi
// 0056eb5e  33ff                 xor edi, edi
// 0056eb60  c64424107a           mov byte ptr [esp + 0x10], 0x7a
// 0056eb65  c644241154           mov byte ptr [esp + 0x11], 0x54
// 0056eb6a  c644241258           mov byte ptr [esp + 0x12], 0x58
// 0056eb6f  c644241374           mov byte ptr [esp + 0x13], 0x74
// 0056eb74  c644241400           mov byte ptr [esp + 0x14], 0
// 0056eb79  897c2420             mov dword ptr [esp + 0x20], edi
// 0056eb7d  897c2424             mov dword ptr [esp + 0x24], edi
// 0056eb81  897c2428             mov dword ptr [esp + 0x28], edi
// 0056eb85  897c2418             mov dword ptr [esp + 0x18], edi
// 0056eb89  897c241c             mov dword ptr [esp + 0x1c], edi
// 0056eb8d  3bc7                 cmp eax, edi
// 0056eb8f  0f84df000000         je 0x56ec74
// 0056eb95  8d4c240c             lea ecx, [esp + 0xc]
// 0056eb99  51                   push ecx
// 0056eb9a  50                   push eax
// 0056eb9b  56                   push esi
// 0056eb9c  e8effcffff           call 0x56e890
// 0056eba1  8be8                 mov ebp, eax
// 0056eba3  83c40c               add esp, 0xc
// 0056eba6  3bef                 cmp ebp, edi
// 0056eba8  0f84c6000000         je 0x56ec74
// 0056ebae  8b542438             mov edx, dword ptr [esp + 0x38]
// 0056ebb2  53                   push ebx
// 0056ebb3  3bd7                 cmp edx, edi
// 0056ebb5  0f849a000000         je 0x56ec55
// 0056ebbb  803a00               cmp byte ptr [edx], 0
// 0056ebbe  0f8491000000         je 0x56ec55
// 0056ebc4  8b5c2444             mov ebx, dword ptr [esp + 0x44]
// 0056ebc8  83fbff               cmp ebx, -1
// 0056ebcb  0f8484000000         je 0x56ec55
// 0056ebd1  8bc2                 mov eax, edx
// 0056ebd3  8d7801               lea edi, [eax + 1]
// 0056ebd6  8a08                 mov cl, byte ptr [eax]
// 0056ebd8  40                   inc eax
// 0056ebd9  84c9                 test cl, cl
// 0056ebdb  75f9                 jne 0x56ebd6
// 0056ebdd  2bc7                 sub eax, edi
// 0056ebdf  8bc8                 mov ecx, eax
// 0056ebe1  52                   push edx
// 0056ebe2  8d7c2420             lea edi, [esp + 0x20]
// 0056ebe6  8bc3                 mov eax, ebx
// 0056ebe8  8bd6                 mov edx, esi
// 0056ebea  e831f7ffff           call 0x56e320
// 0056ebef  8d542802             lea edx, [eax + ebp + 2]
// 0056ebf3  52                   push edx
// 0056ebf4  8d44241c             lea eax, [esp + 0x1c]
// 0056ebf8  50                   push eax
// 0056ebf9  56                   push esi
// 0056ebfa  e831f6ffff           call 0x56e230
// 0056ebff  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0056ec03  45                   inc ebp
// 0056ec04  55                   push ebp
// 0056ec05  57                   push edi
// 0056ec06  56                   push esi
// 0056ec07  e894f6ffff           call 0x56e2a0
// 0056ec0c  57                   push edi
// 0056ec0d  56                   push esi
// 0056ec0e  e8ed390000           call 0x572600
// 0056ec13  83c424               add esp, 0x24
// 0056ec16  885c2438             mov byte ptr [esp + 0x38], bl
// 0056ec1a  85f6                 test esi, esi
// 0056ec1c  741d                 je 0x56ec3b
// 0056ec1e  6a01                 push 1
// 0056ec20  8d4c243c             lea ecx, [esp + 0x3c]
// 0056ec24  51                   push ecx
// 0056ec25  56                   push esi
// 0056ec26  e8d560ffff           call 0x564d00
// 0056ec2b  6a01                 push 1
// 0056ec2d  8d542448             lea edx, [esp + 0x48]
// 0056ec31  52                   push edx
// 0056ec32  56                   push esi
// 0056ec33  e8a863ffff           call 0x564fe0
// 0056ec38  83c418               add esp, 0x18
// 0056ec3b  8d44241c             lea eax, [esp + 0x1c]
// 0056ec3f  e85cf9ffff           call 0x56e5a0
// 0056ec44  56                   push esi
// 0056ec45  e896f6ffff           call 0x56e2e0
// 0056ec4a  83c404               add esp, 4
// 0056ec4d  5b                   pop ebx
// 0056ec4e  5f                   pop edi
// 0056ec4f  5e                   pop esi
// 0056ec50  5d                   pop ebp
// 0056ec51  83c420               add esp, 0x20
// 0056ec54  c3                   ret 
// 0056ec55  57                   push edi
// 0056ec56  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 0056ec5a  52                   push edx
// 0056ec5b  57                   push edi
// 0056ec5c  56                   push esi
// 0056ec5d  e80efeffff           call 0x56ea70
// 0056ec62  57                   push edi
// 0056ec63  56                   push esi
// 0056ec64  e897390000           call 0x572600
// 0056ec69  83c418               add esp, 0x18
// 0056ec6c  5b                   pop ebx
// 0056ec6d  5f                   pop edi
// 0056ec6e  5e                   pop esi
// 0056ec6f  5d                   pop ebp
// 0056ec70  83c420               add esp, 0x20
// 0056ec73  c3                   ret 
// 0056ec74  680039a200           push 0xa23900
// 0056ec79  56                   push esi
// 0056ec7a  e8e12e0000           call 0x571b60
// 0056ec7f  8b442414             mov eax, dword ptr [esp + 0x14]
// 0056ec83  50                   push eax
// 0056ec84  56                   push esi
// 0056ec85  e876390000           call 0x572600
// 0056ec8a  83c410               add esp, 0x10
// 0056ec8d  5f                   pop edi
// 0056ec8e  5e                   pop esi
// 0056ec8f  5d                   pop ebp
// 0056ec90  83c420               add esp, 0x20
// 0056ec93  c3                   ret 
// library libpng-1.2.32/pngwutil.c (function _png_write_zTXt)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.32 pngwutil.c
