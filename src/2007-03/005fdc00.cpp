// from server: 100% by auto
// roc 2007-03 005fdc00  unit: seg_005f0000  size: 467 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005fdc00
//
// 005fdc00  53                   push ebx
// 005fdc01  55                   push ebp
// 005fdc02  8b6c240c             mov ebp, dword ptr [esp + 0xc]
// 005fdc06  8b5d34               mov ebx, dword ptr [ebp + 0x34]
// 005fdc09  56                   push esi
// 005fdc0a  57                   push edi
// 005fdc0b  8b7d30               mov edi, dword ptr [ebp + 0x30]
// 005fdc0e  8b37                 mov esi, dword ptr [edi]
// 005fdc10  33d2                 xor edx, edx
// 005fdc12  8bc5                 mov eax, ebp
// 005fdc14  e897faffff           call 0x5fd6b0
// 005fdc19  52                   push edx
// 005fdc1a  52                   push edx
// 005fdc1b  57                   push edi
// 005fdc1c  e85f710100           call 0x614d80
// 005fdc21  8b4718               mov eax, dword ptr [edi + 0x18]
// 005fdc24  8d4801               lea ecx, [eax + 1]
// 005fdc27  83c40c               add esp, 0xc
// 005fdc2a  81f9ffffff3f         cmp ecx, 0x3fffffff
// 005fdc30  771f                 ja 0x5fdc51
// 005fdc32  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 005fdc35  8d148500000000       lea edx, [eax*4]
// 005fdc3c  8b462c               mov eax, dword ptr [esi + 0x2c]
// 005fdc3f  52                   push edx
// 005fdc40  03c0                 add eax, eax
// 005fdc42  03c0                 add eax, eax
// 005fdc44  50                   push eax
// 005fdc45  51                   push ecx
// 005fdc46  53                   push ebx
// 005fdc47  e854f7ffff           call 0x5fd3a0
// 005fdc4c  83c410               add esp, 0x10
// 005fdc4f  eb09                 jmp 0x5fdc5a
// 005fdc51  53                   push ebx
// 005fdc52  e829f7ffff           call 0x5fd380
// 005fdc57  83c404               add esp, 4
// 005fdc5a  89460c               mov dword ptr [esi + 0xc], eax
// 005fdc5d  8b5718               mov edx, dword ptr [edi + 0x18]
// 005fdc60  89562c               mov dword ptr [esi + 0x2c], edx
// 005fdc63  8b4718               mov eax, dword ptr [edi + 0x18]
// 005fdc66  83c001               add eax, 1
// 005fdc69  3dffffff3f           cmp eax, 0x3fffffff
// 005fdc6e  771f                 ja 0x5fdc8f
// 005fdc70  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 005fdc73  8b5630               mov edx, dword ptr [esi + 0x30]
// 005fdc76  8b4614               mov eax, dword ptr [esi + 0x14]
// 005fdc79  03c9                 add ecx, ecx
// 005fdc7b  03c9                 add ecx, ecx
// 005fdc7d  51                   push ecx
// 005fdc7e  03d2                 add edx, edx
// 005fdc80  03d2                 add edx, edx
// 005fdc82  52                   push edx
// 005fdc83  50                   push eax
// 005fdc84  53                   push ebx
// 005fdc85  e816f7ffff           call 0x5fd3a0
// 005fdc8a  83c410               add esp, 0x10
// 005fdc8d  eb09                 jmp 0x5fdc98
// 005fdc8f  53                   push ebx
// 005fdc90  e8ebf6ffff           call 0x5fd380
// 005fdc95  83c404               add esp, 4
// 005fdc98  894614               mov dword ptr [esi + 0x14], eax
// 005fdc9b  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 005fdc9e  894e30               mov dword ptr [esi + 0x30], ecx
// 005fdca1  8b4728               mov eax, dword ptr [edi + 0x28]
// 005fdca4  8d5001               lea edx, [eax + 1]
// 005fdca7  81faffffff0f         cmp edx, 0xfffffff
// 005fdcad  771a                 ja 0x5fdcc9
// 005fdcaf  8b4e08               mov ecx, dword ptr [esi + 8]
// 005fdcb2  c1e004               shl eax, 4
// 005fdcb5  50                   push eax
// 005fdcb6  8b4628               mov eax, dword ptr [esi + 0x28]
// 005fdcb9  c1e004               shl eax, 4
// 005fdcbc  50                   push eax
// 005fdcbd  51                   push ecx
// 005fdcbe  53                   push ebx
// 005fdcbf  e8dcf6ffff           call 0x5fd3a0
// 005fdcc4  83c410               add esp, 0x10
// 005fdcc7  eb09                 jmp 0x5fdcd2
// 005fdcc9  53                   push ebx
// 005fdcca  e8b1f6ffff           call 0x5fd380
// 005fdccf  83c404               add esp, 4
// 005fdcd2  894608               mov dword ptr [esi + 8], eax
// 005fdcd5  8b5728               mov edx, dword ptr [edi + 0x28]
// 005fdcd8  895628               mov dword ptr [esi + 0x28], edx
// 005fdcdb  8b472c               mov eax, dword ptr [edi + 0x2c]
// 005fdcde  8d4801               lea ecx, [eax + 1]
// 005fdce1  81f9ffffff3f         cmp ecx, 0x3fffffff
// 005fdce7  771f                 ja 0x5fdd08
// 005fdce9  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 005fdcec  8d148500000000       lea edx, [eax*4]
// 005fdcf3  8b4634               mov eax, dword ptr [esi + 0x34]
// 005fdcf6  52                   push edx
// 005fdcf7  03c0                 add eax, eax
// 005fdcf9  03c0                 add eax, eax
// 005fdcfb  50                   push eax
// 005fdcfc  51                   push ecx
// 005fdcfd  53                   push ebx
// 005fdcfe  e89df6ffff           call 0x5fd3a0
// 005fdd03  83c410               add esp, 0x10
// 005fdd06  eb09                 jmp 0x5fdd11
// 005fdd08  53                   push ebx
// 005fdd09  e872f6ffff           call 0x5fd380
// 005fdd0e  83c404               add esp, 4
// 005fdd11  894610               mov dword ptr [esi + 0x10], eax
// 005fdd14  8b572c               mov edx, dword ptr [edi + 0x2c]
// 005fdd17  895634               mov dword ptr [esi + 0x34], edx
// 005fdd1a  0fbf4730             movsx eax, word ptr [edi + 0x30]
// 005fdd1e  8d4801               lea ecx, [eax + 1]
// 005fdd21  81f955555515         cmp ecx, 0x15555555
// 005fdd27  7722                 ja 0x5fdd4b
// 005fdd29  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 005fdd2c  8d1440               lea edx, [eax + eax*2]
// 005fdd2f  8b4638               mov eax, dword ptr [esi + 0x38]
// 005fdd32  8d0440               lea eax, [eax + eax*2]
// 005fdd35  03d2                 add edx, edx
// 005fdd37  03d2                 add edx, edx
// 005fdd39  52                   push edx
// 005fdd3a  03c0                 add eax, eax
// 005fdd3c  03c0                 add eax, eax
// 005fdd3e  50                   push eax
// 005fdd3f  51                   push ecx
// 005fdd40  53                   push ebx
// 005fdd41  e85af6ffff           call 0x5fd3a0
// 005fdd46  83c410               add esp, 0x10
// 005fdd49  eb09                 jmp 0x5fdd54
// 005fdd4b  53                   push ebx
// 005fdd4c  e82ff6ffff           call 0x5fd380
// 005fdd51  83c404               add esp, 4
// 005fdd54  894618               mov dword ptr [esi + 0x18], eax
// 005fdd57  0fb64648             movzx eax, byte ptr [esi + 0x48]
// 005fdd5b  0fbf5730             movsx edx, word ptr [edi + 0x30]
// 005fdd5f  8d4801               lea ecx, [eax + 1]
// 005fdd62  81f9ffffff3f         cmp ecx, 0x3fffffff
// 005fdd68  895638               mov dword ptr [esi + 0x38], edx
// 005fdd6b  771f                 ja 0x5fdd8c
// 005fdd6d  8b4e1c               mov ecx, dword ptr [esi + 0x1c]
// 005fdd70  8d148500000000       lea edx, [eax*4]
// 005fdd77  8b4624               mov eax, dword ptr [esi + 0x24]
// 005fdd7a  52                   push edx
// 005fdd7b  03c0                 add eax, eax
// 005fdd7d  03c0                 add eax, eax
// 005fdd7f  50                   push eax
// 005fdd80  51                   push ecx
// 005fdd81  53                   push ebx
// 005fdd82  e819f6ffff           call 0x5fd3a0
// 005fdd87  83c410               add esp, 0x10
// 005fdd8a  eb09                 jmp 0x5fdd95
// 005fdd8c  53                   push ebx
// 005fdd8d  e8eef5ffff           call 0x5fd380
// 005fdd92  83c404               add esp, 4
// 005fdd95  0fb65648             movzx edx, byte ptr [esi + 0x48]
// 005fdd99  89461c               mov dword ptr [esi + 0x1c], eax
// 005fdd9c  895624               mov dword ptr [esi + 0x24], edx
// 005fdd9f  8b4708               mov eax, dword ptr [edi + 8]
// 005fdda2  894530               mov dword ptr [ebp + 0x30], eax
// 005fdda5  834308e0             add dword ptr [ebx + 8], -0x20
// 005fdda9  8b4510               mov eax, dword ptr [ebp + 0x10]
// 005fddac  3d1d010000           cmp eax, 0x11d
// 005fddb1  7407                 je 0x5fddba
// 005fddb3  3d1e010000           cmp eax, 0x11e
// 005fddb8  7514                 jne 0x5fddce
// 005fddba  8b4518               mov eax, dword ptr [ebp + 0x18]
// 005fddbd  8b480c               mov ecx, dword ptr [eax + 0xc]
// 005fddc0  51                   push ecx
// 005fddc1  83c010               add eax, 0x10
// 005fddc4  50                   push eax
// 005fddc5  55                   push ebp
// 005fddc6  e8c5310000           call 0x600f90
// 005fddcb  83c40c               add esp, 0xc
// 005fddce  5f                   pop edi
// 005fddcf  5e                   pop esi
// 005fddd0  5d                   pop ebp
// 005fddd1  5b                   pop ebx
// 005fddd2  c3                   ret 
// library lua-5.1.1/lparser.c (function _close_func)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lparser.c
