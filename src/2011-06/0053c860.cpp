// from server: 100% by auto
// roc 2011-06 0053c860  unit: G3D::ReferenceCountedObject  size: 207 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0053c860
//
// 0053c860  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0053c864  8b442414             mov eax, dword ptr [esp + 0x14]
// 0053c868  53                   push ebx
// 0053c869  8b5c240c             mov ebx, dword ptr [esp + 0xc]
// 0053c86d  55                   push ebp
// 0053c86e  03c1                 add eax, ecx
// 0053c870  394310               cmp dword ptr [ebx + 0x10], eax
// 0053c873  56                   push esi
// 0053c874  57                   push edi
// 0053c875  0f8cad000000         jl 0x53c928
// 0053c87b  8b6c2428             mov ebp, dword ptr [esp + 0x28]
// 0053c87f  8b442430             mov eax, dword ptr [esp + 0x30]
// 0053c883  8d1428               lea edx, [eax + ebp]
// 0053c886  395314               cmp dword ptr [ebx + 0x14], edx
// 0053c889  0f8c99000000         jl 0x53c928
// 0053c88f  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0053c893  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 0053c897  03d1                 add edx, ecx
// 0053c899  395710               cmp dword ptr [edi + 0x10], edx
// 0053c89c  0f8c86000000         jl 0x53c928
// 0053c8a2  8b742420             mov esi, dword ptr [esp + 0x20]
// 0053c8a6  8d1406               lea edx, [esi + eax]
// 0053c8a9  395714               cmp dword ptr [edi + 0x14], edx
// 0053c8ac  7c7a                 jl 0x53c928
// 0053c8ae  85ed                 test ebp, ebp
// 0053c8b0  7c76                 jl 0x53c928
// 0053c8b2  837c242400           cmp dword ptr [esp + 0x24], 0
// 0053c8b7  7c6f                 jl 0x53c928
// 0053c8b9  85f6                 test esi, esi
// 0053c8bb  7c6b                 jl 0x53c928
// 0053c8bd  837c241c00           cmp dword ptr [esp + 0x1c], 0
// 0053c8c2  7c64                 jl 0x53c928
// 0053c8c4  8b530c               mov edx, dword ptr [ebx + 0xc]
// 0053c8c7  3b570c               cmp edx, dword ptr [edi + 0xc]
// 0053c8ca  755c                 jne 0x53c928
// 0053c8cc  85c0                 test eax, eax
// 0053c8ce  7e51                 jle 0x53c921
// 0053c8d0  2bee                 sub ebp, esi
// 0053c8d2  89442418             mov dword ptr [esp + 0x18], eax
// 0053c8d6  eb0c                 jmp 0x53c8e4
// 0053c8d8  eb06                 jmp 0x53c8e0
// 0053c8da  8d9b00000000         lea ebx, [ebx]
// 0053c8e0  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 0053c8e4  8b430c               mov eax, dword ptr [ebx + 0xc]
// 0053c8e7  8bd0                 mov edx, eax
// 0053c8e9  0fafd1               imul edx, ecx
// 0053c8ec  52                   push edx
// 0053c8ed  8b5710               mov edx, dword ptr [edi + 0x10]
// 0053c8f0  8d0c2e               lea ecx, [esi + ebp]
// 0053c8f3  0fafd6               imul edx, esi
// 0053c8f6  0faf4b10             imul ecx, dword ptr [ebx + 0x10]
// 0053c8fa  034c2428             add ecx, dword ptr [esp + 0x28]
// 0053c8fe  03542420             add edx, dword ptr [esp + 0x20]
// 0053c902  0fafc8               imul ecx, eax
// 0053c905  0faf570c             imul edx, dword ptr [edi + 0xc]
// 0053c909  034b08               add ecx, dword ptr [ebx + 8]
// 0053c90c  035708               add edx, dword ptr [edi + 8]
// 0053c90f  51                   push ecx
// 0053c910  52                   push edx
// 0053c911  e8c6ec2c00           call 0x80b5dc
// 0053c916  83c40c               add esp, 0xc
// 0053c919  46                   inc esi
// 0053c91a  836c241801           sub dword ptr [esp + 0x18], 1
// 0053c91f  75bf                 jne 0x53c8e0
// 0053c921  5f                   pop edi
// 0053c922  5e                   pop esi
// 0053c923  5d                   pop ebp
// 0053c924  b001                 mov al, 1
// 0053c926  5b                   pop ebx
// 0053c927  c3                   ret 
// 0053c928  5f                   pop edi
// 0053c929  5e                   pop esi
// 0053c92a  5d                   pop ebp
// 0053c92b  32c0                 xor al, al
// 0053c92d  5b                   pop ebx
// 0053c92e  c3                   ret 
// library rbx2016-g3d/GImage.cpp (function ?pasteSubImage@GImage@G3D@@SA_NAAV12@ABV12@HHHHHH@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-g3d GImage.cpp
