// from server: 100% by auto
// roc 2012-06 00628750  unit: G3D::ReferenceCountedObject  size: 207 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00628750
//
// 00628750  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00628754  8b442414             mov eax, dword ptr [esp + 0x14]
// 00628758  53                   push ebx
// 00628759  8b5c240c             mov ebx, dword ptr [esp + 0xc]
// 0062875d  55                   push ebp
// 0062875e  03c1                 add eax, ecx
// 00628760  394310               cmp dword ptr [ebx + 0x10], eax
// 00628763  56                   push esi
// 00628764  57                   push edi
// 00628765  0f8cad000000         jl 0x628818
// 0062876b  8b6c2428             mov ebp, dword ptr [esp + 0x28]
// 0062876f  8b442430             mov eax, dword ptr [esp + 0x30]
// 00628773  8d1428               lea edx, [eax + ebp]
// 00628776  395314               cmp dword ptr [ebx + 0x14], edx
// 00628779  0f8c99000000         jl 0x628818
// 0062877f  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 00628783  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 00628787  03d1                 add edx, ecx
// 00628789  395710               cmp dword ptr [edi + 0x10], edx
// 0062878c  0f8c86000000         jl 0x628818
// 00628792  8b742420             mov esi, dword ptr [esp + 0x20]
// 00628796  8d1406               lea edx, [esi + eax]
// 00628799  395714               cmp dword ptr [edi + 0x14], edx
// 0062879c  7c7a                 jl 0x628818
// 0062879e  85ed                 test ebp, ebp
// 006287a0  7c76                 jl 0x628818
// 006287a2  837c242400           cmp dword ptr [esp + 0x24], 0
// 006287a7  7c6f                 jl 0x628818
// 006287a9  85f6                 test esi, esi
// 006287ab  7c6b                 jl 0x628818
// 006287ad  837c241c00           cmp dword ptr [esp + 0x1c], 0
// 006287b2  7c64                 jl 0x628818
// 006287b4  8b530c               mov edx, dword ptr [ebx + 0xc]
// 006287b7  3b570c               cmp edx, dword ptr [edi + 0xc]
// 006287ba  755c                 jne 0x628818
// 006287bc  85c0                 test eax, eax
// 006287be  7e51                 jle 0x628811
// 006287c0  2bee                 sub ebp, esi
// 006287c2  89442418             mov dword ptr [esp + 0x18], eax
// 006287c6  eb0c                 jmp 0x6287d4
// 006287c8  eb06                 jmp 0x6287d0
// 006287ca  8d9b00000000         lea ebx, [ebx]
// 006287d0  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 006287d4  8b430c               mov eax, dword ptr [ebx + 0xc]
// 006287d7  8bd0                 mov edx, eax
// 006287d9  0fafd1               imul edx, ecx
// 006287dc  52                   push edx
// 006287dd  8b5710               mov edx, dword ptr [edi + 0x10]
// 006287e0  8d0c2e               lea ecx, [esi + ebp]
// 006287e3  0fafd6               imul edx, esi
// 006287e6  0faf4b10             imul ecx, dword ptr [ebx + 0x10]
// 006287ea  034c2428             add ecx, dword ptr [esp + 0x28]
// 006287ee  03542420             add edx, dword ptr [esp + 0x20]
// 006287f2  0fafc8               imul ecx, eax
// 006287f5  0faf570c             imul edx, dword ptr [edi + 0xc]
// 006287f9  034b08               add ecx, dword ptr [ebx + 8]
// 006287fc  035708               add edx, dword ptr [edi + 8]
// 006287ff  51                   push ecx
// 00628800  52                   push edx
// 00628801  e856ae3500           call 0x98365c
// 00628806  83c40c               add esp, 0xc
// 00628809  46                   inc esi
// 0062880a  836c241801           sub dword ptr [esp + 0x18], 1
// 0062880f  75bf                 jne 0x6287d0
// 00628811  5f                   pop edi
// 00628812  5e                   pop esi
// 00628813  5d                   pop ebp
// 00628814  b001                 mov al, 1
// 00628816  5b                   pop ebx
// 00628817  c3                   ret 
// 00628818  5f                   pop edi
// 00628819  5e                   pop esi
// 0062881a  5d                   pop ebp
// 0062881b  32c0                 xor al, al
// 0062881d  5b                   pop ebx
// 0062881e  c3                   ret 
// library rbx2016-g3d/GImage.cpp (function ?pasteSubImage@GImage@G3D@@SA_NAAV12@ABV12@HHHHHH@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-g3d GImage.cpp
