// from server: 100% by auto
// roc 2007-08 00610190  unit: RBX::Ball  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00610190
//
// 00610190  53                   push ebx
// 00610191  8a5e36               mov bl, byte ptr [esi + 0x36]
// 00610194  80fb04               cmp bl, 4
// 00610197  55                   push ebp
// 00610198  8b6c240c             mov ebp, dword ptr [esp + 0xc]
// 0061019c  57                   push edi
// 0061019d  8b7e18               mov edi, dword ptr [esi + 0x18]
// 006101a0  896e18               mov dword ptr [esi + 0x18], ebp
// 006101a3  7619                 jbe 0x6101be
// 006101a5  837e3c00             cmp dword ptr [esi + 0x3c], 0
// 006101a9  7513                 jne 0x6101be
// 006101ab  8b4638               mov eax, dword ptr [esi + 0x38]
// 006101ae  6aff                 push -1
// 006101b0  6a03                 push 3
// 006101b2  56                   push esi
// 006101b3  89463c               mov dword ptr [esi + 0x3c], eax
// 006101b6  e88559fbff           call 0x5c5b40
// 006101bb  83c40c               add esp, 0xc
// 006101be  f6c304               test bl, 4
// 006101c1  744f                 je 0x610212
// 006101c3  8b4e14               mov ecx, dword ptr [esi + 0x14]
// 006101c6  8b5104               mov edx, dword ptr [ecx + 4]
// 006101c9  8b02                 mov eax, dword ptr [edx]
// 006101cb  8b4810               mov ecx, dword ptr [eax + 0x10]
// 006101ce  8b510c               mov edx, dword ptr [ecx + 0xc]
// 006101d1  8b4914               mov ecx, dword ptr [ecx + 0x14]
// 006101d4  8bc5                 mov eax, ebp
// 006101d6  2bc2                 sub eax, edx
// 006101d8  c1f802               sar eax, 2
// 006101db  83e801               sub eax, 1
// 006101de  85c9                 test ecx, ecx
// 006101e0  7405                 je 0x6101e7
// 006101e2  8b1c81               mov ebx, dword ptr [ecx + eax*4]
// 006101e5  eb02                 jmp 0x6101e9
// 006101e7  33db                 xor ebx, ebx
// 006101e9  85c0                 test eax, eax
// 006101eb  7419                 je 0x610206
// 006101ed  3bef                 cmp ebp, edi
// 006101ef  7615                 jbe 0x610206
// 006101f1  85c9                 test ecx, ecx
// 006101f3  740b                 je 0x610200
// 006101f5  2bfa                 sub edi, edx
// 006101f7  c1ff02               sar edi, 2
// 006101fa  8b4cb9fc             mov ecx, dword ptr [ecx + edi*4 - 4]
// 006101fe  eb02                 jmp 0x610202
// 00610200  33c9                 xor ecx, ecx
// 00610202  3bd9                 cmp ebx, ecx
// 00610204  740c                 je 0x610212
// 00610206  53                   push ebx
// 00610207  6a02                 push 2
// 00610209  56                   push esi
// 0061020a  e83159fbff           call 0x5c5b40
// 0061020f  83c40c               add esp, 0xc
// 00610212  5f                   pop edi
// 00610213  5d                   pop ebp
// 00610214  5b                   pop ebx
// 00610215  c3                   ret 
// library lua-5.1.2/lvm.c (function _traceexec)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.2 lvm.c
