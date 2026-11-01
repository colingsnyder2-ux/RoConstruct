// from server: 100% by auto
// roc 2011-06 00902040  unit: CXTCaptionButtonTheme  size: 367 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00902040
//
// 00902040  83ec20               sub esp, 0x20
// 00902043  53                   push ebx
// 00902044  8b5c2430             mov ebx, dword ptr [esp + 0x30]
// 00902048  8b03                 mov eax, dword ptr [ebx]
// 0090204a  8b5308               mov edx, dword ptr [ebx + 8]
// 0090204d  55                   push ebp
// 0090204e  56                   push esi
// 0090204f  57                   push edi
// 00902050  8be9                 mov ebp, ecx
// 00902052  8b4b04               mov ecx, dword ptr [ebx + 4]
// 00902055  6a00                 push 0
// 00902057  894c2428             mov dword ptr [esp + 0x28], ecx
// 0090205b  89442424             mov dword ptr [esp + 0x24], eax
// 0090205f  8b430c               mov eax, dword ptr [ebx + 0xc]
// 00902062  6afe                 push -2
// 00902064  8d4c2428             lea ecx, [esp + 0x28]
// 00902068  51                   push ecx
// 00902069  89542434             mov dword ptr [esp + 0x34], edx
// 0090206d  89442438             mov dword ptr [esp + 0x38], eax
// 00902071  ff15e41ba400         call dword ptr [0xa41be4]
// 00902077  8b742434             mov esi, dword ptr [esp + 0x34]
// 0090207b  8b542420             mov edx, dword ptr [esp + 0x20]
// 0090207f  8b442424             mov eax, dword ptr [esp + 0x24]
// 00902083  8b7c2444             mov edi, dword ptr [esp + 0x44]
// 00902087  8916                 mov dword ptr [esi], edx
// 00902089  894604               mov dword ptr [esi + 4], eax
// 0090208c  837f7800             cmp dword ptr [edi + 0x78], 0
// 00902090  7422                 je 0x9020b4
// 00902092  8d4c2410             lea ecx, [esp + 0x10]
// 00902096  51                   push ecx
// 00902097  8bcf                 mov ecx, edi
// 00902099  e8420cffff           call 0x8f2ce0
// 0090209e  8b10                 mov edx, dword ptr [eax]
// 009020a0  8916                 mov dword ptr [esi], edx
// 009020a2  8b4004               mov eax, dword ptr [eax + 4]
// 009020a5  5f                   pop edi
// 009020a6  894604               mov dword ptr [esi + 4], eax
// 009020a9  8bc6                 mov eax, esi
// 009020ab  5e                   pop esi
// 009020ac  5d                   pop ebp
// 009020ad  5b                   pop ebx
// 009020ae  83c420               add esp, 0x20
// 009020b1  c21400               ret 0x14
// 009020b4  8b442440             mov eax, dword ptr [esp + 0x40]
// 009020b8  8b4804               mov ecx, dword ptr [eax + 4]
// 009020bb  8b00                 mov eax, dword ptr [eax]
// 009020bd  8b5500               mov edx, dword ptr [ebp]
// 009020c0  8b5240               mov edx, dword ptr [edx + 0x40]
// 009020c3  57                   push edi
// 009020c4  51                   push ecx
// 009020c5  50                   push eax
// 009020c6  56                   push esi
// 009020c7  8bcd                 mov ecx, ebp
// 009020c9  ffd2                 call edx
// 009020cb  8b476c               mov eax, dword ptr [edi + 0x6c]
// 009020ce  8906                 mov dword ptr [esi], eax
// 009020d0  8b17                 mov edx, dword ptr [edi]
// 009020d2  8b8268010000         mov eax, dword ptr [edx + 0x168]
// 009020d8  8bcf                 mov ecx, edi
// 009020da  ffd0                 call eax
// 009020dc  a804                 test al, 4
// 009020de  7425                 je 0x902105
// 009020e0  8b6f70               mov ebp, dword ptr [edi + 0x70]
// 009020e3  8d4c2410             lea ecx, [esp + 0x10]
// 009020e7  51                   push ecx
// 009020e8  8bcf                 mov ecx, edi
// 009020ea  e8710bffff           call 0x8f2c60
// 009020ef  8b4004               mov eax, dword ptr [eax + 4]
// 009020f2  99                   cdq 
// 009020f3  2bc2                 sub eax, edx
// 009020f5  8bc8                 mov ecx, eax
// 009020f7  8bc5                 mov eax, ebp
// 009020f9  99                   cdq 
// 009020fa  2bc2                 sub eax, edx
// 009020fc  d1f9                 sar ecx, 1
// 009020fe  d1f8                 sar eax, 1
// 00902100  03c8                 add ecx, eax
// 00902102  014e04               add dword ptr [esi + 4], ecx
// 00902105  8bcf                 mov ecx, edi
// 00902107  e80ca50c00           call 0x9cc618
// 0090210c  2500030000           and eax, 0x300
// 00902111  3d00010000           cmp eax, 0x100
// 00902116  7466                 je 0x90217e
// 00902118  3d00020000           cmp eax, 0x200
// 0090211d  7445                 je 0x902164
// 0090211f  8b17                 mov edx, dword ptr [edi]
// 00902121  8b8268010000         mov eax, dword ptr [edx + 0x168]
// 00902127  8bcf                 mov ecx, edi
// 00902129  ffd0                 call eax
// 0090212b  a804                 test al, 4
// 0090212d  7510                 jne 0x90213f
// 0090212f  8d4c2410             lea ecx, [esp + 0x10]
// 00902133  51                   push ecx
// 00902134  8bcf                 mov ecx, edi
// 00902136  e8250bffff           call 0x8f2c60
// 0090213b  8b10                 mov edx, dword ptr [eax]
// 0090213d  0116                 add dword ptr [esi], edx
// 0090213f  8b4308               mov eax, dword ptr [ebx + 8]
// 00902142  2b476c               sub eax, dword ptr [edi + 0x6c]
// 00902145  8b542440             mov edx, dword ptr [esp + 0x40]
// 00902149  2b02                 sub eax, dword ptr [edx]
// 0090214b  8b0e                 mov ecx, dword ptr [esi]
// 0090214d  2bc1                 sub eax, ecx
// 0090214f  99                   cdq 
// 00902150  2bc2                 sub eax, edx
// 00902152  d1f8                 sar eax, 1
// 00902154  03c1                 add eax, ecx
// 00902156  5f                   pop edi
// 00902157  8906                 mov dword ptr [esi], eax
// 00902159  8bc6                 mov eax, esi
// 0090215b  5e                   pop esi
// 0090215c  5d                   pop ebp
// 0090215d  5b                   pop ebx
// 0090215e  83c420               add esp, 0x20
// 00902161  c21400               ret 0x14
// 00902164  8b4308               mov eax, dword ptr [ebx + 8]
// 00902167  2b476c               sub eax, dword ptr [edi + 0x6c]
// 0090216a  8b4c2440             mov ecx, dword ptr [esp + 0x40]
// 0090216e  2b01                 sub eax, dword ptr [ecx]
// 00902170  5f                   pop edi
// 00902171  8906                 mov dword ptr [esi], eax
// 00902173  8bc6                 mov eax, esi
// 00902175  5e                   pop esi
// 00902176  5d                   pop ebp
// 00902177  5b                   pop ebx
// 00902178  83c420               add esp, 0x20
// 0090217b  c21400               ret 0x14
// 0090217e  8b17                 mov edx, dword ptr [edi]
// 00902180  8b8268010000         mov eax, dword ptr [edx + 0x168]
// 00902186  8bcf                 mov ecx, edi
// 00902188  ffd0                 call eax
// 0090218a  a804                 test al, 4
// 0090218c  7515                 jne 0x9021a3
// 0090218e  8b5f70               mov ebx, dword ptr [edi + 0x70]
// 00902191  8d4c2418             lea ecx, [esp + 0x18]
// 00902195  51                   push ecx
// 00902196  8bcf                 mov ecx, edi
// 00902198  e8c30affff           call 0x8f2c60
// 0090219d  8b10                 mov edx, dword ptr [eax]
// 0090219f  03d3                 add edx, ebx
// 009021a1  0116                 add dword ptr [esi], edx
// 009021a3  5f                   pop edi
// 009021a4  8bc6                 mov eax, esi
// 009021a6  5e                   pop esi
// 009021a7  5d                   pop ebp
// 009021a8  5b                   pop ebx
// 009021a9  83c420               add esp, 0x20
// 009021ac  c21400               ret 0x14
// library xtp-15.2.1-shared-mfc/Source\Controls\Deprecated\XTButtonTheme.cpp (function ?GetTextPosition@CXTButtonTheme@@MAE?AVCPoint@@IAAVCRect@@AAVCSize@@PAVCXTButton@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/Controls/Deprecated/XTButtonTheme.cpp
