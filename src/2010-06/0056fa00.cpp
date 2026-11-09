// from server: 100% by auto
// roc 2010-06 0056fa00  unit: G3D::LineSegment  size: 214 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0056fa00
//
// 0056fa00  83ec10               sub esp, 0x10
// 0056fa03  dd442418             fld qword ptr [esp + 0x18]
// 0056fa07  b041                 mov al, 0x41
// 0056fa09  dc0d307aa100         fmul qword ptr [0xa17a30]
// 0056fa0f  88442409             mov byte ptr [esp + 9], al
// 0056fa13  d97c2418             fnstcw word ptr [esp + 0x18]
// 0056fa17  8844240b             mov byte ptr [esp + 0xb], al
// 0056fa1b  0fb7442418           movzx eax, word ptr [esp + 0x18]
// 0056fa20  dc057850a100         fadd qword ptr [0xa15078]
// 0056fa26  0d000c0000           or eax, 0xc00
// 0056fa2b  890424               mov dword ptr [esp], eax
// 0056fa2e  56                   push esi
// 0056fa2f  8b742418             mov esi, dword ptr [esp + 0x18]
// 0056fa33  d96c2404             fldcw word ptr [esp + 4]
// 0056fa37  c644240c67           mov byte ptr [esp + 0xc], 0x67
// 0056fa3c  c644240e4d           mov byte ptr [esp + 0xe], 0x4d
// 0056fa41  c644241000           mov byte ptr [esp + 0x10], 0
// 0056fa46  df7c2404             fistp qword ptr [esp + 4]
// 0056fa4a  8b442404             mov eax, dword ptr [esp + 4]
// 0056fa4e  8bc8                 mov ecx, eax
// 0056fa50  c1e918               shr ecx, 0x18
// 0056fa53  d96c241c             fldcw word ptr [esp + 0x1c]
// 0056fa57  8bd0                 mov edx, eax
// 0056fa59  c1ea10               shr edx, 0x10
// 0056fa5c  884c241c             mov byte ptr [esp + 0x1c], cl
// 0056fa60  8bc8                 mov ecx, eax
// 0056fa62  c1e908               shr ecx, 8
// 0056fa65  8854241d             mov byte ptr [esp + 0x1d], dl
// 0056fa69  884c241e             mov byte ptr [esp + 0x1e], cl
// 0056fa6d  8844241f             mov byte ptr [esp + 0x1f], al
// 0056fa71  85f6                 test esi, esi
// 0056fa73  745c                 je 0x56fad1
// 0056fa75  6a04                 push 4
// 0056fa77  8d542410             lea edx, [esp + 0x10]
// 0056fa7b  52                   push edx
// 0056fa7c  56                   push esi
// 0056fa7d  e8aee7ffff           call 0x56e230
// 0056fa82  6a04                 push 4
// 0056fa84  8d44242c             lea eax, [esp + 0x2c]
// 0056fa88  50                   push eax
// 0056fa89  56                   push esi
// 0056fa8a  e87152ffff           call 0x564d00
// 0056fa8f  6a04                 push 4
// 0056fa91  8d4c2438             lea ecx, [esp + 0x38]
// 0056fa95  51                   push ecx
// 0056fa96  56                   push esi
// 0056fa97  e84455ffff           call 0x564fe0
// 0056fa9c  8b8610010000         mov eax, dword ptr [esi + 0x110]
// 0056faa2  8bd0                 mov edx, eax
// 0056faa4  c1ea18               shr edx, 0x18
// 0056faa7  8854243c             mov byte ptr [esp + 0x3c], dl
// 0056faab  8bc8                 mov ecx, eax
// 0056faad  8bd0                 mov edx, eax
// 0056faaf  8844243f             mov byte ptr [esp + 0x3f], al
// 0056fab3  6a04                 push 4
// 0056fab5  8d442440             lea eax, [esp + 0x40]
// 0056fab9  50                   push eax
// 0056faba  c1e910               shr ecx, 0x10
// 0056fabd  c1ea08               shr edx, 8
// 0056fac0  56                   push esi
// 0056fac1  884c2449             mov byte ptr [esp + 0x49], cl
// 0056fac5  8854244a             mov byte ptr [esp + 0x4a], dl
// 0056fac9  e83252ffff           call 0x564d00
// 0056face  83c430               add esp, 0x30
// 0056fad1  5e                   pop esi
// 0056fad2  83c410               add esp, 0x10
// 0056fad5  c3                   ret 
// library libpng-1.2.22/pngwutil.c (function _png_write_gAMA)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngwutil.c
