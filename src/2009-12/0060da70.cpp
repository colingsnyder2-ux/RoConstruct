// from server: 100% by auto
// roc 2009-12 0060da70  unit: seg_00600000  size: 118 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0060da70
//
// 0060da70  56                   push esi
// 0060da71  8b742408             mov esi, dword ptr [esp + 8]
// 0060da75  85f6                 test esi, esi
// 0060da77  746b                 je 0x60dae4
// 0060da79  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0060da7d  53                   push ebx
// 0060da7e  57                   push edi
// 0060da7f  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 0060da83  57                   push edi
// 0060da84  50                   push eax
// 0060da85  56                   push esi
// 0060da86  e885eeffff           call 0x60c910
// 0060da8b  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 0060da8f  83c40c               add esp, 0xc
// 0060da92  85db                 test ebx, ebx
// 0060da94  7417                 je 0x60daad
// 0060da96  85ff                 test edi, edi
// 0060da98  7613                 jbe 0x60daad
// 0060da9a  57                   push edi
// 0060da9b  53                   push ebx
// 0060da9c  56                   push esi
// 0060da9d  e8ee58ffff           call 0x603390
// 0060daa2  57                   push edi
// 0060daa3  53                   push ebx
// 0060daa4  56                   push esi
// 0060daa5  e8c65bffff           call 0x603670
// 0060daaa  83c418               add esp, 0x18
// 0060daad  8b8610010000         mov eax, dword ptr [esi + 0x110]
// 0060dab3  8bd0                 mov edx, eax
// 0060dab5  8bc8                 mov ecx, eax
// 0060dab7  c1e918               shr ecx, 0x18
// 0060daba  c1ea10               shr edx, 0x10
// 0060dabd  884c2410             mov byte ptr [esp + 0x10], cl
// 0060dac1  88542411             mov byte ptr [esp + 0x11], dl
// 0060dac5  6a04                 push 4
// 0060dac7  8d542414             lea edx, [esp + 0x14]
// 0060dacb  8bc8                 mov ecx, eax
// 0060dacd  52                   push edx
// 0060dace  c1e908               shr ecx, 8
// 0060dad1  56                   push esi
// 0060dad2  884c241e             mov byte ptr [esp + 0x1e], cl
// 0060dad6  8844241f             mov byte ptr [esp + 0x1f], al
// 0060dada  e8b158ffff           call 0x603390
// 0060dadf  83c40c               add esp, 0xc
// 0060dae2  5f                   pop edi
// 0060dae3  5b                   pop ebx
// 0060dae4  5e                   pop esi
// 0060dae5  c3                   ret 
// library libpng-1.2.16/pngwutil.c (function _png_write_chunk)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.16 pngwutil.c
