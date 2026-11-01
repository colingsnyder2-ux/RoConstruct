// from server: 100% by auto
// roc 2009-12 007cdfa0  unit: RBX::PartDropTool  size: 132 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007cdfa0
//
// 007cdfa0  53                   push ebx
// 007cdfa1  8a5e38               mov bl, byte ptr [esi + 0x38]
// 007cdfa4  55                   push ebp
// 007cdfa5  8b6c240c             mov ebp, dword ptr [esp + 0xc]
// 007cdfa9  57                   push edi
// 007cdfaa  8b7e18               mov edi, dword ptr [esi + 0x18]
// 007cdfad  896e18               mov dword ptr [esi + 0x18], ebp
// 007cdfb0  f6c308               test bl, 8
// 007cdfb3  7419                 je 0x7cdfce
// 007cdfb5  837e4000             cmp dword ptr [esi + 0x40], 0
// 007cdfb9  7513                 jne 0x7cdfce
// 007cdfbb  8b463c               mov eax, dword ptr [esi + 0x3c]
// 007cdfbe  6aff                 push -1
// 007cdfc0  6a03                 push 3
// 007cdfc2  56                   push esi
// 007cdfc3  894640               mov dword ptr [esi + 0x40], eax
// 007cdfc6  e89593fcff           call 0x797360
// 007cdfcb  83c40c               add esp, 0xc
// 007cdfce  f6c304               test bl, 4
// 007cdfd1  744d                 je 0x7ce020
// 007cdfd3  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 007cdfd6  8b5104               mov edx, dword ptr [ecx + 4]
// 007cdfd9  8b02                 mov eax, dword ptr [edx]
// 007cdfdb  8b4810               mov ecx, dword ptr [eax + 0x10]
// 007cdfde  8b510c               mov edx, dword ptr [ecx + 0xc]
// 007cdfe1  8b4914               mov ecx, dword ptr [ecx + 0x14]
// 007cdfe4  8bc5                 mov eax, ebp
// 007cdfe6  2bc2                 sub eax, edx
// 007cdfe8  c1f802               sar eax, 2
// 007cdfeb  48                   dec eax
// 007cdfec  85c9                 test ecx, ecx
// 007cdfee  7405                 je 0x7cdff5
// 007cdff0  8b1c81               mov ebx, dword ptr [ecx + eax*4]
// 007cdff3  eb02                 jmp 0x7cdff7
// 007cdff5  33db                 xor ebx, ebx
// 007cdff7  85c0                 test eax, eax
// 007cdff9  7419                 je 0x7ce014
// 007cdffb  3bef                 cmp ebp, edi
// 007cdffd  7615                 jbe 0x7ce014
// 007cdfff  85c9                 test ecx, ecx
// 007ce001  740b                 je 0x7ce00e
// 007ce003  2bfa                 sub edi, edx
// 007ce005  c1ff02               sar edi, 2
// 007ce008  8b4cb9fc             mov ecx, dword ptr [ecx + edi*4 - 4]
// 007ce00c  eb02                 jmp 0x7ce010
// 007ce00e  33c9                 xor ecx, ecx
// 007ce010  3bd9                 cmp ebx, ecx
// 007ce012  740c                 je 0x7ce020
// 007ce014  53                   push ebx
// 007ce015  6a02                 push 2
// 007ce017  56                   push esi
// 007ce018  e84393fcff           call 0x797360
// 007ce01d  83c40c               add esp, 0xc
// 007ce020  5f                   pop edi
// 007ce021  5d                   pop ebp
// 007ce022  5b                   pop ebx
// 007ce023  c3                   ret 
// library lua-5.1.3/lvm.c (function _traceexec)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.3 lvm.c
