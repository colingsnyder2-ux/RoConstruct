// from server: 100% by auto
// roc 2012-06 006568f0  unit: seg_00650000  size: 265 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006568f0
//
// 006568f0  83ec0c               sub esp, 0xc
// 006568f3  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 006568f7  53                   push ebx
// 006568f8  b074                 mov al, 0x74
// 006568fa  56                   push esi
// 006568fb  8b742418             mov esi, dword ptr [esp + 0x18]
// 006568ff  8844240c             mov byte ptr [esp + 0xc], al
// 00656903  8844240f             mov byte ptr [esp + 0xf], al
// 00656907  8d442408             lea eax, [esp + 8]
// 0065690b  50                   push eax
// 0065690c  51                   push ecx
// 0065690d  56                   push esi
// 0065690e  c644241945           mov byte ptr [esp + 0x19], 0x45
// 00656913  c644241a58           mov byte ptr [esp + 0x1a], 0x58
// 00656918  c644241c00           mov byte ptr [esp + 0x1c], 0
// 0065691d  e8eefdffff           call 0x656710
// 00656922  8bd8                 mov ebx, eax
// 00656924  83c40c               add esp, 0xc
// 00656927  85db                 test ebx, ebx
// 00656929  0f84c4000000         je 0x6569f3
// 0065692f  8b442420             mov eax, dword ptr [esp + 0x20]
// 00656933  55                   push ebp
// 00656934  57                   push edi
// 00656935  85c0                 test eax, eax
// 00656937  7415                 je 0x65694e
// 00656939  803800               cmp byte ptr [eax], 0
// 0065693c  7410                 je 0x65694e
// 0065693e  8d5001               lea edx, [eax + 1]
// 00656941  8a08                 mov cl, byte ptr [eax]
// 00656943  40                   inc eax
// 00656944  84c9                 test cl, cl
// 00656946  75f9                 jne 0x656941
// 00656948  2bc2                 sub eax, edx
// 0065694a  8bf8                 mov edi, eax
// 0065694c  eb02                 jmp 0x656950
// 0065694e  33ff                 xor edi, edi
// 00656950  8d543b01             lea edx, [ebx + edi + 1]
// 00656954  52                   push edx
// 00656955  8d442418             lea eax, [esp + 0x18]
// 00656959  50                   push eax
// 0065695a  56                   push esi
// 0065695b  e860f7ffff           call 0x6560c0
// 00656960  8b6c241c             mov ebp, dword ptr [esp + 0x1c]
// 00656964  83c40c               add esp, 0xc
// 00656967  43                   inc ebx
// 00656968  85f6                 test esi, esi
// 0065696a  741b                 je 0x656987
// 0065696c  85ed                 test ebp, ebp
// 0065696e  7417                 je 0x656987
// 00656970  85db                 test ebx, ebx
// 00656972  7613                 jbe 0x656987
// 00656974  53                   push ebx
// 00656975  55                   push ebp
// 00656976  56                   push esi
// 00656977  e8440dffff           call 0x6476c0
// 0065697c  53                   push ebx
// 0065697d  55                   push ebp
// 0065697e  56                   push esi
// 0065697f  e80c75feff           call 0x63de90
// 00656984  83c418               add esp, 0x18
// 00656987  85ff                 test edi, edi
// 00656989  7423                 je 0x6569ae
// 0065698b  85f6                 test esi, esi
// 0065698d  7458                 je 0x6569e7
// 0065698f  8b5c2428             mov ebx, dword ptr [esp + 0x28]
// 00656993  85db                 test ebx, ebx
// 00656995  7417                 je 0x6569ae
// 00656997  85ff                 test edi, edi
// 00656999  7613                 jbe 0x6569ae
// 0065699b  57                   push edi
// 0065699c  53                   push ebx
// 0065699d  56                   push esi
// 0065699e  e81d0dffff           call 0x6476c0
// 006569a3  57                   push edi
// 006569a4  53                   push ebx
// 006569a5  56                   push esi
// 006569a6  e8e574feff           call 0x63de90
// 006569ab  83c418               add esp, 0x18
// 006569ae  85f6                 test esi, esi
// 006569b0  7435                 je 0x6569e7
// 006569b2  8b8610010000         mov eax, dword ptr [esi + 0x110]
// 006569b8  8bd0                 mov edx, eax
// 006569ba  8bc8                 mov ecx, eax
// 006569bc  c1e918               shr ecx, 0x18
// 006569bf  c1ea10               shr edx, 0x10
// 006569c2  884c2410             mov byte ptr [esp + 0x10], cl
// 006569c6  88542411             mov byte ptr [esp + 0x11], dl
// 006569ca  6a04                 push 4
// 006569cc  8d542414             lea edx, [esp + 0x14]
// 006569d0  8bc8                 mov ecx, eax
// 006569d2  52                   push edx
// 006569d3  c1e908               shr ecx, 8
// 006569d6  56                   push esi
// 006569d7  884c241e             mov byte ptr [esp + 0x1e], cl
// 006569db  8844241f             mov byte ptr [esp + 0x1f], al
// 006569df  e8dc0cffff           call 0x6476c0
// 006569e4  83c40c               add esp, 0xc
// 006569e7  55                   push ebp
// 006569e8  56                   push esi
// 006569e9  e8327bffff           call 0x64e520
// 006569ee  83c408               add esp, 8
// 006569f1  5f                   pop edi
// 006569f2  5d                   pop ebp
// 006569f3  5e                   pop esi
// 006569f4  5b                   pop ebx
// 006569f5  83c40c               add esp, 0xc
// 006569f8  c3                   ret 
// library libpng-1.2.35/pngwutil.c (function _png_write_tEXt)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.35 pngwutil.c
