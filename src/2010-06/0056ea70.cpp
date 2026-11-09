// from server: 100% by auto
// roc 2010-06 0056ea70  unit: G3D::LineSegment  size: 221 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0056ea70
//
// 0056ea70  83ec08               sub esp, 8
// 0056ea73  b074                 mov al, 0x74
// 0056ea75  880424               mov byte ptr [esp], al
// 0056ea78  88442403             mov byte ptr [esp + 3], al
// 0056ea7c  8b442410             mov eax, dword ptr [esp + 0x10]
// 0056ea80  56                   push esi
// 0056ea81  8b742410             mov esi, dword ptr [esp + 0x10]
// 0056ea85  57                   push edi
// 0056ea86  c644240945           mov byte ptr [esp + 9], 0x45
// 0056ea8b  c644240a58           mov byte ptr [esp + 0xa], 0x58
// 0056ea90  c644240c00           mov byte ptr [esp + 0xc], 0
// 0056ea95  85c0                 test eax, eax
// 0056ea97  0f849c000000         je 0x56eb39
// 0056ea9d  8d4c2418             lea ecx, [esp + 0x18]
// 0056eaa1  51                   push ecx
// 0056eaa2  50                   push eax
// 0056eaa3  56                   push esi
// 0056eaa4  e8e7fdffff           call 0x56e890
// 0056eaa9  8bf8                 mov edi, eax
// 0056eaab  83c40c               add esp, 0xc
// 0056eaae  85ff                 test edi, edi
// 0056eab0  0f8483000000         je 0x56eb39
// 0056eab6  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0056eaba  53                   push ebx
// 0056eabb  55                   push ebp
// 0056eabc  85c0                 test eax, eax
// 0056eabe  7415                 je 0x56ead5
// 0056eac0  803800               cmp byte ptr [eax], 0
// 0056eac3  7410                 je 0x56ead5
// 0056eac5  8d5001               lea edx, [eax + 1]
// 0056eac8  8a08                 mov cl, byte ptr [eax]
// 0056eaca  40                   inc eax
// 0056eacb  84c9                 test cl, cl
// 0056eacd  75f9                 jne 0x56eac8
// 0056eacf  2bc2                 sub eax, edx
// 0056ead1  8bd8                 mov ebx, eax
// 0056ead3  eb02                 jmp 0x56ead7
// 0056ead5  33db                 xor ebx, ebx
// 0056ead7  8d541f01             lea edx, [edi + ebx + 1]
// 0056eadb  52                   push edx
// 0056eadc  8d442414             lea eax, [esp + 0x14]
// 0056eae0  50                   push eax
// 0056eae1  56                   push esi
// 0056eae2  e849f7ffff           call 0x56e230
// 0056eae7  8b6c242c             mov ebp, dword ptr [esp + 0x2c]
// 0056eaeb  83c40c               add esp, 0xc
// 0056eaee  47                   inc edi
// 0056eaef  85f6                 test esi, esi
// 0056eaf1  741b                 je 0x56eb0e
// 0056eaf3  85ed                 test ebp, ebp
// 0056eaf5  7417                 je 0x56eb0e
// 0056eaf7  85ff                 test edi, edi
// 0056eaf9  7613                 jbe 0x56eb0e
// 0056eafb  57                   push edi
// 0056eafc  55                   push ebp
// 0056eafd  56                   push esi
// 0056eafe  e8fd61ffff           call 0x564d00
// 0056eb03  57                   push edi
// 0056eb04  55                   push ebp
// 0056eb05  56                   push esi
// 0056eb06  e8d564ffff           call 0x564fe0
// 0056eb0b  83c418               add esp, 0x18
// 0056eb0e  85db                 test ebx, ebx
// 0056eb10  740f                 je 0x56eb21
// 0056eb12  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0056eb16  53                   push ebx
// 0056eb17  51                   push ecx
// 0056eb18  56                   push esi
// 0056eb19  e882f7ffff           call 0x56e2a0
// 0056eb1e  83c40c               add esp, 0xc
// 0056eb21  56                   push esi
// 0056eb22  e8b9f7ffff           call 0x56e2e0
// 0056eb27  55                   push ebp
// 0056eb28  56                   push esi
// 0056eb29  e8d23a0000           call 0x572600
// 0056eb2e  83c40c               add esp, 0xc
// 0056eb31  5d                   pop ebp
// 0056eb32  5b                   pop ebx
// 0056eb33  5f                   pop edi
// 0056eb34  5e                   pop esi
// 0056eb35  83c408               add esp, 8
// 0056eb38  c3                   ret 
// 0056eb39  68e438a200           push 0xa238e4
// 0056eb3e  56                   push esi
// 0056eb3f  e81c300000           call 0x571b60
// 0056eb44  83c408               add esp, 8
// 0056eb47  5f                   pop edi
// 0056eb48  5e                   pop esi
// 0056eb49  83c408               add esp, 8
// 0056eb4c  c3                   ret 
// library libpng-1.2.22/pngwutil.c (function _png_write_tEXt)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngwutil.c
