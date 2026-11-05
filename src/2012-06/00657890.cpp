// from server: 100% by auto
// roc 2012-06 00657890  unit: seg_00650000  size: 214 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00657890
//
// 00657890  83ec10               sub esp, 0x10
// 00657893  dd442418             fld qword ptr [esp + 0x18]
// 00657897  b041                 mov al, 0x41
// 00657899  dc0de03ab500         fmul qword ptr [0xb53ae0]
// 0065789f  88442409             mov byte ptr [esp + 9], al
// 006578a3  d97c2418             fnstcw word ptr [esp + 0x18]
// 006578a7  8844240b             mov byte ptr [esp + 0xb], al
// 006578ab  0fb7442418           movzx eax, word ptr [esp + 0x18]
// 006578b0  dc0500a2b600         fadd qword ptr [0xb6a200]
// 006578b6  0d000c0000           or eax, 0xc00
// 006578bb  890424               mov dword ptr [esp], eax
// 006578be  56                   push esi
// 006578bf  8b742418             mov esi, dword ptr [esp + 0x18]
// 006578c3  d96c2404             fldcw word ptr [esp + 4]
// 006578c7  c644240c67           mov byte ptr [esp + 0xc], 0x67
// 006578cc  c644240e4d           mov byte ptr [esp + 0xe], 0x4d
// 006578d1  c644241000           mov byte ptr [esp + 0x10], 0
// 006578d6  df7c2404             fistp qword ptr [esp + 4]
// 006578da  8b442404             mov eax, dword ptr [esp + 4]
// 006578de  8bc8                 mov ecx, eax
// 006578e0  c1e918               shr ecx, 0x18
// 006578e3  d96c241c             fldcw word ptr [esp + 0x1c]
// 006578e7  8bd0                 mov edx, eax
// 006578e9  c1ea10               shr edx, 0x10
// 006578ec  884c241c             mov byte ptr [esp + 0x1c], cl
// 006578f0  8bc8                 mov ecx, eax
// 006578f2  c1e908               shr ecx, 8
// 006578f5  8854241d             mov byte ptr [esp + 0x1d], dl
// 006578f9  884c241e             mov byte ptr [esp + 0x1e], cl
// 006578fd  8844241f             mov byte ptr [esp + 0x1f], al
// 00657901  85f6                 test esi, esi
// 00657903  745c                 je 0x657961
// 00657905  6a04                 push 4
// 00657907  8d542410             lea edx, [esp + 0x10]
// 0065790b  52                   push edx
// 0065790c  56                   push esi
// 0065790d  e8aee7ffff           call 0x6560c0
// 00657912  6a04                 push 4
// 00657914  8d44242c             lea eax, [esp + 0x2c]
// 00657918  50                   push eax
// 00657919  56                   push esi
// 0065791a  e8a1fdfeff           call 0x6476c0
// 0065791f  6a04                 push 4
// 00657921  8d4c2438             lea ecx, [esp + 0x38]
// 00657925  51                   push ecx
// 00657926  56                   push esi
// 00657927  e86465feff           call 0x63de90
// 0065792c  8b8610010000         mov eax, dword ptr [esi + 0x110]
// 00657932  8bd0                 mov edx, eax
// 00657934  c1ea18               shr edx, 0x18
// 00657937  8854243c             mov byte ptr [esp + 0x3c], dl
// 0065793b  8bc8                 mov ecx, eax
// 0065793d  8bd0                 mov edx, eax
// 0065793f  8844243f             mov byte ptr [esp + 0x3f], al
// 00657943  6a04                 push 4
// 00657945  8d442440             lea eax, [esp + 0x40]
// 00657949  50                   push eax
// 0065794a  c1e910               shr ecx, 0x10
// 0065794d  c1ea08               shr edx, 8
// 00657950  56                   push esi
// 00657951  884c2449             mov byte ptr [esp + 0x49], cl
// 00657955  8854244a             mov byte ptr [esp + 0x4a], dl
// 00657959  e862fdfeff           call 0x6476c0
// 0065795e  83c430               add esp, 0x30
// 00657961  5e                   pop esi
// 00657962  83c410               add esp, 0x10
// 00657965  c3                   ret 
// library libpng-1.2.22/pngwutil.c (function _png_write_gAMA)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngwutil.c
