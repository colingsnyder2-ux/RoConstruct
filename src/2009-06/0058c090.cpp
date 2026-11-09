// from server: 100% by auto
// roc 2009-06 0058c090  unit: seg_00580000  size: 214 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0058c090
//
// 0058c090  83ec10               sub esp, 0x10
// 0058c093  dd442418             fld qword ptr [esp + 0x18]
// 0058c097  b041                 mov al, 0x41
// 0058c099  dc0d70c48c00         fmul qword ptr [0x8cc470]
// 0058c09f  88442409             mov byte ptr [esp + 9], al
// 0058c0a3  d97c2418             fnstcw word ptr [esp + 0x18]
// 0058c0a7  8844240b             mov byte ptr [esp + 0xb], al
// 0058c0ab  0fb7442418           movzx eax, word ptr [esp + 0x18]
// 0058c0b0  dc05f8018c00         fadd qword ptr [0x8c01f8]
// 0058c0b6  0d000c0000           or eax, 0xc00
// 0058c0bb  890424               mov dword ptr [esp], eax
// 0058c0be  56                   push esi
// 0058c0bf  8b742418             mov esi, dword ptr [esp + 0x18]
// 0058c0c3  d96c2404             fldcw word ptr [esp + 4]
// 0058c0c7  c644240c67           mov byte ptr [esp + 0xc], 0x67
// 0058c0cc  c644240e4d           mov byte ptr [esp + 0xe], 0x4d
// 0058c0d1  c644241000           mov byte ptr [esp + 0x10], 0
// 0058c0d6  df7c2404             fistp qword ptr [esp + 4]
// 0058c0da  8b442404             mov eax, dword ptr [esp + 4]
// 0058c0de  8bc8                 mov ecx, eax
// 0058c0e0  c1e918               shr ecx, 0x18
// 0058c0e3  d96c241c             fldcw word ptr [esp + 0x1c]
// 0058c0e7  8bd0                 mov edx, eax
// 0058c0e9  c1ea10               shr edx, 0x10
// 0058c0ec  884c241c             mov byte ptr [esp + 0x1c], cl
// 0058c0f0  8bc8                 mov ecx, eax
// 0058c0f2  c1e908               shr ecx, 8
// 0058c0f5  8854241d             mov byte ptr [esp + 0x1d], dl
// 0058c0f9  884c241e             mov byte ptr [esp + 0x1e], cl
// 0058c0fd  8844241f             mov byte ptr [esp + 0x1f], al
// 0058c101  85f6                 test esi, esi
// 0058c103  745c                 je 0x58c161
// 0058c105  6a04                 push 4
// 0058c107  8d542410             lea edx, [esp + 0x10]
// 0058c10b  52                   push edx
// 0058c10c  56                   push esi
// 0058c10d  e8aee7ffff           call 0x58a8c0
// 0058c112  6a04                 push 4
// 0058c114  8d44242c             lea eax, [esp + 0x2c]
// 0058c118  50                   push eax
// 0058c119  56                   push esi
// 0058c11a  e8c154ffff           call 0x5815e0
// 0058c11f  6a04                 push 4
// 0058c121  8d4c2438             lea ecx, [esp + 0x38]
// 0058c125  51                   push ecx
// 0058c126  56                   push esi
// 0058c127  e89457ffff           call 0x5818c0
// 0058c12c  8b8610010000         mov eax, dword ptr [esi + 0x110]
// 0058c132  8bd0                 mov edx, eax
// 0058c134  c1ea18               shr edx, 0x18
// 0058c137  8854243c             mov byte ptr [esp + 0x3c], dl
// 0058c13b  8bc8                 mov ecx, eax
// 0058c13d  8bd0                 mov edx, eax
// 0058c13f  8844243f             mov byte ptr [esp + 0x3f], al
// 0058c143  6a04                 push 4
// 0058c145  8d442440             lea eax, [esp + 0x40]
// 0058c149  50                   push eax
// 0058c14a  c1e910               shr ecx, 0x10
// 0058c14d  c1ea08               shr edx, 8
// 0058c150  56                   push esi
// 0058c151  884c2449             mov byte ptr [esp + 0x49], cl
// 0058c155  8854244a             mov byte ptr [esp + 0x4a], dl
// 0058c159  e88254ffff           call 0x5815e0
// 0058c15e  83c430               add esp, 0x30
// 0058c161  5e                   pop esi
// 0058c162  83c410               add esp, 0x10
// 0058c165  c3                   ret 
// library libpng-1.2.22/pngwutil.c (function _png_write_gAMA)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngwutil.c
