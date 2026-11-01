// from server: 100% by auto
// roc 2009-12 0060e0e0  unit: seg_00600000  size: 214 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0060e0e0
//
// 0060e0e0  83ec10               sub esp, 0x10
// 0060e0e3  dd442418             fld qword ptr [esp + 0x18]
// 0060e0e7  b041                 mov al, 0x41
// 0060e0e9  dc0dd09d9b00         fmul qword ptr [0x9b9dd0]
// 0060e0ef  88442409             mov byte ptr [esp + 9], al
// 0060e0f3  d97c2418             fnstcw word ptr [esp + 0x18]
// 0060e0f7  8844240b             mov byte ptr [esp + 0xb], al
// 0060e0fb  0fb7442418           movzx eax, word ptr [esp + 0x18]
// 0060e100  dc0510329b00         fadd qword ptr [0x9b3210]
// 0060e106  0d000c0000           or eax, 0xc00
// 0060e10b  890424               mov dword ptr [esp], eax
// 0060e10e  56                   push esi
// 0060e10f  8b742418             mov esi, dword ptr [esp + 0x18]
// 0060e113  d96c2404             fldcw word ptr [esp + 4]
// 0060e117  c644240c67           mov byte ptr [esp + 0xc], 0x67
// 0060e11c  c644240e4d           mov byte ptr [esp + 0xe], 0x4d
// 0060e121  c644241000           mov byte ptr [esp + 0x10], 0
// 0060e126  df7c2404             fistp qword ptr [esp + 4]
// 0060e12a  8b442404             mov eax, dword ptr [esp + 4]
// 0060e12e  8bc8                 mov ecx, eax
// 0060e130  c1e918               shr ecx, 0x18
// 0060e133  d96c241c             fldcw word ptr [esp + 0x1c]
// 0060e137  8bd0                 mov edx, eax
// 0060e139  c1ea10               shr edx, 0x10
// 0060e13c  884c241c             mov byte ptr [esp + 0x1c], cl
// 0060e140  8bc8                 mov ecx, eax
// 0060e142  c1e908               shr ecx, 8
// 0060e145  8854241d             mov byte ptr [esp + 0x1d], dl
// 0060e149  884c241e             mov byte ptr [esp + 0x1e], cl
// 0060e14d  8844241f             mov byte ptr [esp + 0x1f], al
// 0060e151  85f6                 test esi, esi
// 0060e153  745c                 je 0x60e1b1
// 0060e155  6a04                 push 4
// 0060e157  8d542410             lea edx, [esp + 0x10]
// 0060e15b  52                   push edx
// 0060e15c  56                   push esi
// 0060e15d  e8aee7ffff           call 0x60c910
// 0060e162  6a04                 push 4
// 0060e164  8d44242c             lea eax, [esp + 0x2c]
// 0060e168  50                   push eax
// 0060e169  56                   push esi
// 0060e16a  e82152ffff           call 0x603390
// 0060e16f  6a04                 push 4
// 0060e171  8d4c2438             lea ecx, [esp + 0x38]
// 0060e175  51                   push ecx
// 0060e176  56                   push esi
// 0060e177  e8f454ffff           call 0x603670
// 0060e17c  8b8610010000         mov eax, dword ptr [esi + 0x110]
// 0060e182  8bd0                 mov edx, eax
// 0060e184  c1ea18               shr edx, 0x18
// 0060e187  8854243c             mov byte ptr [esp + 0x3c], dl
// 0060e18b  8bc8                 mov ecx, eax
// 0060e18d  8bd0                 mov edx, eax
// 0060e18f  8844243f             mov byte ptr [esp + 0x3f], al
// 0060e193  6a04                 push 4
// 0060e195  8d442440             lea eax, [esp + 0x40]
// 0060e199  50                   push eax
// 0060e19a  c1e910               shr ecx, 0x10
// 0060e19d  c1ea08               shr edx, 8
// 0060e1a0  56                   push esi
// 0060e1a1  884c2449             mov byte ptr [esp + 0x49], cl
// 0060e1a5  8854244a             mov byte ptr [esp + 0x4a], dl
// 0060e1a9  e8e251ffff           call 0x603390
// 0060e1ae  83c430               add esp, 0x30
// 0060e1b1  5e                   pop esi
// 0060e1b2  83c410               add esp, 0x10
// 0060e1b5  c3                   ret 
// library libpng-1.2.22/pngwutil.c (function _png_write_gAMA)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngwutil.c
