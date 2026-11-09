// from server: 100% by auto
// roc 2007-08 005c8710  unit: lua_exception  size: 150 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005c8710
//
// 005c8710  53                   push ebx
// 005c8711  56                   push esi
// 005c8712  57                   push edi
// 005c8713  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 005c8717  6884000000           push 0x84
// 005c871c  33db                 xor ebx, ebx
// 005c871e  53                   push ebx
// 005c871f  53                   push ebx
// 005c8720  57                   push edi
// 005c8721  e8cab20400           call 0x6139f0
// 005c8726  8bf0                 mov esi, eax
// 005c8728  6a08                 push 8
// 005c872a  83c60c               add esi, 0xc
// 005c872d  56                   push esi
// 005c872e  57                   push edi
// 005c872f  e81c780400           call 0x60ff50
// 005c8734  8b4710               mov eax, dword ptr [edi + 0x10]
// 005c8737  83c41c               add esp, 0x1c
// 005c873a  894610               mov dword ptr [esi + 0x10], eax
// 005c873d  895e20               mov dword ptr [esi + 0x20], ebx
// 005c8740  895e2c               mov dword ptr [esi + 0x2c], ebx
// 005c8743  895e70               mov dword ptr [esi + 0x70], ebx
// 005c8746  895e40               mov dword ptr [esi + 0x40], ebx
// 005c8749  885e36               mov byte ptr [esi + 0x36], bl
// 005c874c  895e38               mov dword ptr [esi + 0x38], ebx
// 005c874f  c6463701             mov byte ptr [esi + 0x37], 1
// 005c8753  895e3c               mov dword ptr [esi + 0x3c], ebx
// 005c8756  895e68               mov dword ptr [esi + 0x68], ebx
// 005c8759  895e30               mov dword ptr [esi + 0x30], ebx
// 005c875c  66895e34             mov word ptr [esi + 0x34], bx
// 005c8760  885e06               mov byte ptr [esi + 6], bl
// 005c8763  895e14               mov dword ptr [esi + 0x14], ebx
// 005c8766  895e28               mov dword ptr [esi + 0x28], ebx
// 005c8769  895e18               mov dword ptr [esi + 0x18], ebx
// 005c876c  895e74               mov dword ptr [esi + 0x74], ebx
// 005c876f  895e50               mov dword ptr [esi + 0x50], ebx
// 005c8772  e809feffff           call 0x5c8580
// 005c8777  8b4f48               mov ecx, dword ptr [edi + 0x48]
// 005c877a  894e48               mov dword ptr [esi + 0x48], ecx
// 005c877d  8b574c               mov edx, dword ptr [edi + 0x4c]
// 005c8780  89564c               mov dword ptr [esi + 0x4c], edx
// 005c8783  8b4750               mov eax, dword ptr [edi + 0x50]
// 005c8786  894650               mov dword ptr [esi + 0x50], eax
// 005c8789  8a4f36               mov cl, byte ptr [edi + 0x36]
// 005c878c  884e36               mov byte ptr [esi + 0x36], cl
// 005c878f  8b5738               mov edx, dword ptr [edi + 0x38]
// 005c8792  895638               mov dword ptr [esi + 0x38], edx
// 005c8795  8b4740               mov eax, dword ptr [edi + 0x40]
// 005c8798  894640               mov dword ptr [esi + 0x40], eax
// 005c879b  8bca                 mov ecx, edx
// 005c879d  5f                   pop edi
// 005c879e  894e3c               mov dword ptr [esi + 0x3c], ecx
// 005c87a1  8bc6                 mov eax, esi
// 005c87a3  5e                   pop esi
// 005c87a4  5b                   pop ebx
// 005c87a5  c3                   ret 
// library lua-5.1.2-rbx/lstate.c (function _luaE_newthread)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.2-rbx lstate.c
