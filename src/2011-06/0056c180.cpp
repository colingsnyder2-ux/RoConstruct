// from server: 100% by auto
// roc 2011-06 0056c180  unit: seg_00560000  size: 214 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0056c180
//
// 0056c180  83ec10               sub esp, 0x10
// 0056c183  dd442418             fld qword ptr [esp + 0x18]
// 0056c187  b041                 mov al, 0x41
// 0056c189  dc0dc890a600         fmul qword ptr [0xa690c8]
// 0056c18f  88442409             mov byte ptr [esp + 9], al
// 0056c193  d97c2418             fnstcw word ptr [esp + 0x18]
// 0056c197  8844240b             mov byte ptr [esp + 0xb], al
// 0056c19b  0fb7442418           movzx eax, word ptr [esp + 0x18]
// 0056c1a0  dc0508afa700         fadd qword ptr [0xa7af08]
// 0056c1a6  0d000c0000           or eax, 0xc00
// 0056c1ab  890424               mov dword ptr [esp], eax
// 0056c1ae  56                   push esi
// 0056c1af  8b742418             mov esi, dword ptr [esp + 0x18]
// 0056c1b3  d96c2404             fldcw word ptr [esp + 4]
// 0056c1b7  c644240c67           mov byte ptr [esp + 0xc], 0x67
// 0056c1bc  c644240e4d           mov byte ptr [esp + 0xe], 0x4d
// 0056c1c1  c644241000           mov byte ptr [esp + 0x10], 0
// 0056c1c6  df7c2404             fistp qword ptr [esp + 4]
// 0056c1ca  8b442404             mov eax, dword ptr [esp + 4]
// 0056c1ce  8bc8                 mov ecx, eax
// 0056c1d0  c1e918               shr ecx, 0x18
// 0056c1d3  d96c241c             fldcw word ptr [esp + 0x1c]
// 0056c1d7  8bd0                 mov edx, eax
// 0056c1d9  c1ea10               shr edx, 0x10
// 0056c1dc  884c241c             mov byte ptr [esp + 0x1c], cl
// 0056c1e0  8bc8                 mov ecx, eax
// 0056c1e2  c1e908               shr ecx, 8
// 0056c1e5  8854241d             mov byte ptr [esp + 0x1d], dl
// 0056c1e9  884c241e             mov byte ptr [esp + 0x1e], cl
// 0056c1ed  8844241f             mov byte ptr [esp + 0x1f], al
// 0056c1f1  85f6                 test esi, esi
// 0056c1f3  745c                 je 0x56c251
// 0056c1f5  6a04                 push 4
// 0056c1f7  8d542410             lea edx, [esp + 0x10]
// 0056c1fb  52                   push edx
// 0056c1fc  56                   push esi
// 0056c1fd  e8aee7ffff           call 0x56a9b0
// 0056c202  6a04                 push 4
// 0056c204  8d44242c             lea eax, [esp + 0x2c]
// 0056c208  50                   push eax
// 0056c209  56                   push esi
// 0056c20a  e831e6feff           call 0x55a840
// 0056c20f  6a04                 push 4
// 0056c211  8d4c2438             lea ecx, [esp + 0x38]
// 0056c215  51                   push ecx
// 0056c216  56                   push esi
// 0056c217  e83446feff           call 0x550850
// 0056c21c  8b8610010000         mov eax, dword ptr [esi + 0x110]
// 0056c222  8bd0                 mov edx, eax
// 0056c224  c1ea18               shr edx, 0x18
// 0056c227  8854243c             mov byte ptr [esp + 0x3c], dl
// 0056c22b  8bc8                 mov ecx, eax
// 0056c22d  8bd0                 mov edx, eax
// 0056c22f  8844243f             mov byte ptr [esp + 0x3f], al
// 0056c233  6a04                 push 4
// 0056c235  8d442440             lea eax, [esp + 0x40]
// 0056c239  50                   push eax
// 0056c23a  c1e910               shr ecx, 0x10
// 0056c23d  c1ea08               shr edx, 8
// 0056c240  56                   push esi
// 0056c241  884c2449             mov byte ptr [esp + 0x49], cl
// 0056c245  8854244a             mov byte ptr [esp + 0x4a], dl
// 0056c249  e8f2e5feff           call 0x55a840
// 0056c24e  83c430               add esp, 0x30
// 0056c251  5e                   pop esi
// 0056c252  83c410               add esp, 0x10
// 0056c255  c3                   ret 
// library libpng-1.2.22/pngwutil.c (function _png_write_gAMA)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngwutil.c
