// from server: 100% by auto
// roc 2007-03 00518c10  unit: seg_00510000  size: 364 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00518c10
//
// 00518c10  56                   push esi
// 00518c11  8b742408             mov esi, dword ptr [esp + 8]
// 00518c15  85f6                 test esi, esi
// 00518c17  0f845d010000         je 0x518d7a
// 00518c1d  f7467000001000       test dword ptr [esi + 0x70], 0x100000
// 00518c24  741e                 je 0x518c44
// 00518c26  8b465c               mov eax, dword ptr [esi + 0x5c]
// 00518c29  85c0                 test eax, eax
// 00518c2b  7417                 je 0x518c44
// 00518c2d  8b8eec000000         mov ecx, dword ptr [esi + 0xec]
// 00518c33  83c101               add ecx, 1
// 00518c36  51                   push ecx
// 00518c37  8d9600010000         lea edx, [esi + 0x100]
// 00518c3d  52                   push edx
// 00518c3e  56                   push esi
// 00518c3f  ffd0                 call eax
// 00518c41  83c40c               add esp, 0xc
// 00518c44  f7467000800000       test dword ptr [esi + 0x70], 0x8000
// 00518c4b  741d                 je 0x518c6a
// 00518c4d  8b466c               mov eax, dword ptr [esi + 0x6c]
// 00518c50  8b8eec000000         mov ecx, dword ptr [esi + 0xec]
// 00518c56  50                   push eax
// 00518c57  83c101               add ecx, 1
// 00518c5a  51                   push ecx
// 00518c5b  8d9600010000         lea edx, [esi + 0x100]
// 00518c61  52                   push edx
// 00518c62  e87955ffff           call 0x50e1e0
// 00518c67  83c40c               add esp, 0xc
// 00518c6a  f7467000000100       test dword ptr [esi + 0x70], 0x10000
// 00518c71  7419                 je 0x518c8c
// 00518c73  8b86ec000000         mov eax, dword ptr [esi + 0xec]
// 00518c79  83c001               add eax, 1
// 00518c7c  50                   push eax
// 00518c7d  8d8e00010000         lea ecx, [esi + 0x100]
// 00518c83  51                   push ecx
// 00518c84  e8f754ffff           call 0x50e180
// 00518c89  83c408               add esp, 8
// 00518c8c  f6467004             test byte ptr [esi + 0x70], 4
// 00518c90  7421                 je 0x518cb3
// 00518c92  0fb69627010000       movzx edx, byte ptr [esi + 0x127]
// 00518c99  8b86ec000000         mov eax, dword ptr [esi + 0xec]
// 00518c9f  52                   push edx
// 00518ca0  83c001               add eax, 1
// 00518ca3  50                   push eax
// 00518ca4  8d8e00010000         lea ecx, [esi + 0x100]
// 00518caa  51                   push ecx
// 00518cab  e8f0f7ffff           call 0x5184a0
// 00518cb0  83c40c               add esp, 0xc
// 00518cb3  f6467010             test byte ptr [esi + 0x70], 0x10
// 00518cb7  7419                 je 0x518cd2
// 00518cb9  8b96ec000000         mov edx, dword ptr [esi + 0xec]
// 00518cbf  83c201               add edx, 1
// 00518cc2  52                   push edx
// 00518cc3  8d8600010000         lea eax, [esi + 0x100]
// 00518cc9  50                   push eax
// 00518cca  e87154ffff           call 0x50e140
// 00518ccf  83c408               add esp, 8
// 00518cd2  f6467008             test byte ptr [esi + 0x70], 8
// 00518cd6  7420                 je 0x518cf8
// 00518cd8  8b96ec000000         mov edx, dword ptr [esi + 0xec]
// 00518cde  8d8e81010000         lea ecx, [esi + 0x181]
// 00518ce4  51                   push ecx
// 00518ce5  83c201               add edx, 1
// 00518ce8  52                   push edx
// 00518ce9  8d8600010000         lea eax, [esi + 0x100]
// 00518cef  50                   push eax
// 00518cf0  e8ebf8ffff           call 0x5185e0
// 00518cf5  83c40c               add esp, 0xc
// 00518cf8  f7467000000800       test dword ptr [esi + 0x70], 0x80000
// 00518cff  7419                 je 0x518d1a
// 00518d01  8b8eec000000         mov ecx, dword ptr [esi + 0xec]
// 00518d07  83c101               add ecx, 1
// 00518d0a  51                   push ecx
// 00518d0b  8d9600010000         lea edx, [esi + 0x100]
// 00518d11  52                   push edx
// 00518d12  e8c9fcffff           call 0x5189e0
// 00518d17  83c408               add esp, 8
// 00518d1a  f7467000000200       test dword ptr [esi + 0x70], 0x20000
// 00518d21  7419                 je 0x518d3c
// 00518d23  8b86ec000000         mov eax, dword ptr [esi + 0xec]
// 00518d29  83c001               add eax, 1
// 00518d2c  50                   push eax
// 00518d2d  8d8e00010000         lea ecx, [esi + 0x100]
// 00518d33  51                   push ecx
// 00518d34  e837fbffff           call 0x518870
// 00518d39  83c408               add esp, 8
// 00518d3c  f6467001             test byte ptr [esi + 0x70], 1
// 00518d40  7419                 je 0x518d5b
// 00518d42  8b96ec000000         mov edx, dword ptr [esi + 0xec]
// 00518d48  83c201               add edx, 1
// 00518d4b  52                   push edx
// 00518d4c  8d8600010000         lea eax, [esi + 0x100]
// 00518d52  50                   push eax
// 00518d53  e81857ffff           call 0x50e470
// 00518d58  83c408               add esp, 8
// 00518d5b  f6467020             test byte ptr [esi + 0x70], 0x20
// 00518d5f  7419                 je 0x518d7a
// 00518d61  8b8eec000000         mov ecx, dword ptr [esi + 0xec]
// 00518d67  83c101               add ecx, 1
// 00518d6a  51                   push ecx
// 00518d6b  81c600010000         add esi, 0x100
// 00518d71  56                   push esi
// 00518d72  e83953ffff           call 0x50e0b0
// 00518d77  83c408               add esp, 8
// 00518d7a  5e                   pop esi
// 00518d7b  c3                   ret 
// library libpng-1.2.7/pngwtran.c (function _png_do_write_transformations)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.7 pngwtran.c
