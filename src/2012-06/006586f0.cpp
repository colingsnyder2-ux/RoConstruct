// from server: 100% by auto
// roc 2012-06 006586f0  unit: seg_00650000  size: 169 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006586f0
//
// 006586f0  83ec10               sub esp, 0x10
// 006586f3  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 006586f7  8a4102               mov al, byte ptr [ecx + 2]
// 006586fa  c6042474             mov byte ptr [esp], 0x74
// 006586fe  c644240149           mov byte ptr [esp + 1], 0x49
// 00658703  c64424024d           mov byte ptr [esp + 2], 0x4d
// 00658708  c644240345           mov byte ptr [esp + 3], 0x45
// 0065870d  c644240400           mov byte ptr [esp + 4], 0
// 00658712  3c0c                 cmp al, 0xc
// 00658714  776d                 ja 0x658783
// 00658716  3c01                 cmp al, 1
// 00658718  7269                 jb 0x658783
// 0065871a  8a4103               mov al, byte ptr [ecx + 3]
// 0065871d  3c1f                 cmp al, 0x1f
// 0065871f  7762                 ja 0x658783
// 00658721  3c01                 cmp al, 1
// 00658723  725e                 jb 0x658783
// 00658725  80790417             cmp byte ptr [ecx + 4], 0x17
// 00658729  7758                 ja 0x658783
// 0065872b  8a5106               mov dl, byte ptr [ecx + 6]
// 0065872e  80fa3c               cmp dl, 0x3c
// 00658731  7750                 ja 0x658783
// 00658733  0fb701               movzx eax, word ptr [ecx]
// 00658736  53                   push ebx
// 00658737  8bd8                 mov ebx, eax
// 00658739  8844240d             mov byte ptr [esp + 0xd], al
// 0065873d  8a4102               mov al, byte ptr [ecx + 2]
// 00658740  8844240e             mov byte ptr [esp + 0xe], al
// 00658744  8a4103               mov al, byte ptr [ecx + 3]
// 00658747  8844240f             mov byte ptr [esp + 0xf], al
// 0065874b  8a4104               mov al, byte ptr [ecx + 4]
// 0065874e  88442410             mov byte ptr [esp + 0x10], al
// 00658752  0fb64105             movzx eax, byte ptr [ecx + 5]
// 00658756  6a07                 push 7
// 00658758  8d4c2410             lea ecx, [esp + 0x10]
// 0065875c  88542416             mov byte ptr [esp + 0x16], dl
// 00658760  51                   push ecx
// 00658761  8d54240c             lea edx, [esp + 0xc]
// 00658765  88442419             mov byte ptr [esp + 0x19], al
// 00658769  8b442420             mov eax, dword ptr [esp + 0x20]
// 0065876d  52                   push edx
// 0065876e  c1eb08               shr ebx, 8
// 00658771  50                   push eax
// 00658772  885c241c             mov byte ptr [esp + 0x1c], bl
// 00658776  e8a5eaffff           call 0x657220
// 0065877b  83c410               add esp, 0x10
// 0065877e  5b                   pop ebx
// 0065877f  83c410               add esp, 0x10
// 00658782  c3                   ret 
// 00658783  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00658787  6844a0b800           push 0xb8a044
// 0065878c  51                   push ecx
// 0065878d  e8ce5affff           call 0x64e260
// 00658792  83c408               add esp, 8
// 00658795  83c410               add esp, 0x10
// 00658798  c3                   ret 
// library libpng-1.2.22/pngwutil.c (function _png_write_tIME)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngwutil.c
