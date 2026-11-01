// from server: 100% by auto
// roc 2009-12 008df8a0  unit: CXTPRichRender  size: 343 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008df8a0
//
// 008df8a0  83ec30               sub esp, 0x30
// 008df8a3  53                   push ebx
// 008df8a4  8bd9                 mov ebx, ecx
// 008df8a6  8b4b24               mov ecx, dword ptr [ebx + 0x24]
// 008df8a9  55                   push ebp
// 008df8aa  33ed                 xor ebp, ebp
// 008df8ac  3bcd                 cmp ecx, ebp
// 008df8ae  7511                 jne 0x8df8c1
// 008df8b0  8b44243c             mov eax, dword ptr [esp + 0x3c]
// 008df8b4  8928                 mov dword ptr [eax], ebp
// 008df8b6  896804               mov dword ptr [eax + 4], ebp
// 008df8b9  5d                   pop ebp
// 008df8ba  5b                   pop ebx
// 008df8bb  83c430               add esp, 0x30
// 008df8be  c20c00               ret 0xc
// 008df8c1  56                   push esi
// 008df8c2  8d542414             lea edx, [esp + 0x14]
// 008df8c6  52                   push edx
// 008df8c7  6800000400           push 0x40000
// 008df8cc  896c241c             mov dword ptr [esp + 0x1c], ebp
// 008df8d0  8b01                 mov eax, dword ptr [ecx]
// 008df8d2  8b400c               mov eax, dword ptr [eax + 0xc]
// 008df8d5  55                   push ebp
// 008df8d6  6845040000           push 0x445
// 008df8db  ffd0                 call eax
// 008df8dd  8b442448             mov eax, dword ptr [esp + 0x48]
// 008df8e1  33f6                 xor esi, esi
// 008df8e3  03c0                 add eax, eax
// 008df8e5  89ab28010000         mov dword ptr [ebx + 0x128], ebp
// 008df8eb  89ab24010000         mov dword ptr [ebx + 0x124], ebp
// 008df8f1  89742410             mov dword ptr [esp + 0x10], esi
// 008df8f5  896c240c             mov dword ptr [esp + 0xc], ebp
// 008df8f9  89442448             mov dword ptr [esp + 0x48], eax
// 008df8fd  896c241c             mov dword ptr [esp + 0x1c], ebp
// 008df901  896c2420             mov dword ptr [esp + 0x20], ebp
// 008df905  896c2424             mov dword ptr [esp + 0x24], ebp
// 008df909  896c2428             mov dword ptr [esp + 0x28], ebp
// 008df90d  57                   push edi
// 008df90e  8bff                 mov edi, edi
// 008df910  8b7b24               mov edi, dword ptr [ebx + 0x24]
// 008df913  55                   push ebp
// 008df914  55                   push ebp
// 008df915  03c6                 add eax, esi
// 008df917  55                   push ebp
// 008df918  99                   cdq 
// 008df919  8d4c242c             lea ecx, [esp + 0x2c]
// 008df91d  51                   push ecx
// 008df91e  8b4c2458             mov ecx, dword ptr [esp + 0x58]
// 008df922  2bc2                 sub eax, edx
// 008df924  55                   push ebp
// 008df925  8d542444             lea edx, [esp + 0x44]
// 008df929  8bf0                 mov esi, eax
// 008df92b  52                   push edx
// 008df92c  d1fe                 sar esi, 1
// 008df92e  55                   push ebp
// 008df92f  896c244c             mov dword ptr [esp + 0x4c], ebp
// 008df933  896c2450             mov dword ptr [esp + 0x50], ebp
// 008df937  89742454             mov dword ptr [esp + 0x54], esi
// 008df93b  c744245801000000     mov dword ptr [esp + 0x58], 1
// 008df943  e8c8e7f1ff           call 0x7fe110
// 008df948  50                   push eax
// 008df949  8b07                 mov eax, dword ptr [edi]
// 008df94b  8b4010               mov eax, dword ptr [eax + 0x10]
// 008df94e  33ed                 xor ebp, ebp
// 008df950  55                   push ebp
// 008df951  55                   push ebp
// 008df952  55                   push ebp
// 008df953  6a01                 push 1
// 008df955  8bcf                 mov ecx, edi
// 008df957  ffd0                 call eax
// 008df959  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 008df95d  3bcd                 cmp ecx, ebp
// 008df95f  750a                 jne 0x8df96b
// 008df961  8b8b28010000         mov ecx, dword ptr [ebx + 0x128]
// 008df967  894c2410             mov dword ptr [esp + 0x10], ecx
// 008df96b  398b28010000         cmp dword ptr [ebx + 0x128], ecx
// 008df971  7e0b                 jle 0x8df97e
// 008df973  8b44244c             mov eax, dword ptr [esp + 0x4c]
// 008df977  46                   inc esi
// 008df978  89742414             mov dword ptr [esp + 0x14], esi
// 008df97c  eb0b                 jmp 0x8df989
// 008df97e  8d46ff               lea eax, [esi - 1]
// 008df981  8b742414             mov esi, dword ptr [esp + 0x14]
// 008df985  8944244c             mov dword ptr [esp + 0x4c], eax
// 008df989  3bf0                 cmp esi, eax
// 008df98b  7c83                 jl 0x8df910
// 008df98d  398b28010000         cmp dword ptr [ebx + 0x128], ecx
// 008df993  5f                   pop edi
// 008df994  7e43                 jle 0x8df9d9
// 008df996  40                   inc eax
// 008df997  89442434             mov dword ptr [esp + 0x34], eax
// 008df99b  8b442444             mov eax, dword ptr [esp + 0x44]
// 008df99f  896c242c             mov dword ptr [esp + 0x2c], ebp
// 008df9a3  896c2430             mov dword ptr [esp + 0x30], ebp
// 008df9a7  c744243801000000     mov dword ptr [esp + 0x38], 1
// 008df9af  3bc5                 cmp eax, ebp
// 008df9b1  7504                 jne 0x8df9b7
// 008df9b3  33c0                 xor eax, eax
// 008df9b5  eb03                 jmp 0x8df9ba
// 008df9b7  8b4004               mov eax, dword ptr [eax + 4]
// 008df9ba  8b4b24               mov ecx, dword ptr [ebx + 0x24]
// 008df9bd  8b11                 mov edx, dword ptr [ecx]
// 008df9bf  55                   push ebp
// 008df9c0  55                   push ebp
// 008df9c1  55                   push ebp
// 008df9c2  8d742428             lea esi, [esp + 0x28]
// 008df9c6  56                   push esi
// 008df9c7  55                   push ebp
// 008df9c8  8d742440             lea esi, [esp + 0x40]
// 008df9cc  56                   push esi
// 008df9cd  55                   push ebp
// 008df9ce  50                   push eax
// 008df9cf  8b4210               mov eax, dword ptr [edx + 0x10]
// 008df9d2  55                   push ebp
// 008df9d3  55                   push ebp
// 008df9d4  55                   push ebp
// 008df9d5  6a01                 push 1
// 008df9d7  ffd0                 call eax
// 008df9d9  8b8b24010000         mov ecx, dword ptr [ebx + 0x124]
// 008df9df  8b442440             mov eax, dword ptr [esp + 0x40]
// 008df9e3  8b9328010000         mov edx, dword ptr [ebx + 0x128]
// 008df9e9  5e                   pop esi
// 008df9ea  5d                   pop ebp
// 008df9eb  8908                 mov dword ptr [eax], ecx
// 008df9ed  895004               mov dword ptr [eax + 4], edx
// 008df9f0  5b                   pop ebx
// 008df9f1  83c430               add esp, 0x30
// 008df9f4  c20c00               ret 0xc
// library xtp-15.2.1/Source\Common\XTPRichRender.cpp (function ?GetTextExtent@CXTPRichRender@@QAE?AVCSize@@PAVCDC@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPRichRender.cpp
