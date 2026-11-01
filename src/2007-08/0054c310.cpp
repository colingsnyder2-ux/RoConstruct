// from server: 100% by colin
// roc 2007-08 0054c310  unit: VHttpRequest_source::?$stream_buffer  size: 172 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0054c310
//
// 0054c310  53                   push ebx
// 0054c311  56                   push esi
// 0054c312  8bf1                 mov esi, ecx
// 0054c314  8b4658               mov eax, dword ptr [esi + 0x58]
// 0054c317  c1e803               shr eax, 3
// 0054c31a  a801                 test al, 1
// 0054c31c  7411                 je 0x54c32f
// 0054c31e  8b4e24               mov ecx, dword ptr [esi + 0x24]
// 0054c321  833900               cmp dword ptr [ecx], 0
// 0054c324  7509                 jne 0x54c32f
// 0054c326  8b16                 mov edx, dword ptr [esi]
// 0054c328  8b4258               mov eax, dword ptr [edx + 0x58]
// 0054c32b  8bce                 mov ecx, esi
// 0054c32d  ffd0                 call eax
// 0054c32f  8b5c240c             mov ebx, dword ptr [esp + 0xc]
// 0054c333  83fbff               cmp ebx, -1
// 0054c336  747d                 je 0x54c3b5
// 0054c338  8b4e58               mov ecx, dword ptr [esi + 0x58]
// 0054c33b  c1e903               shr ecx, 3
// 0054c33e  f6c101               test cl, 1
// 0054c341  745e                 je 0x54c3a1
// 0054c343  8b5634               mov edx, dword ptr [esi + 0x34]
// 0054c346  8b4624               mov eax, dword ptr [esi + 0x24]
// 0054c349  8b00                 mov eax, dword ptr [eax]
// 0054c34b  8b12                 mov edx, dword ptr [edx]
// 0054c34d  8d0c10               lea ecx, [eax + edx]
// 0054c350  3bc1                 cmp eax, ecx
// 0054c352  7533                 jne 0x54c387
// 0054c354  8b4614               mov eax, dword ptr [esi + 0x14]
// 0054c357  8b08                 mov ecx, dword ptr [eax]
// 0054c359  8b4624               mov eax, dword ptr [esi + 0x24]
// 0054c35c  8b00                 mov eax, dword ptr [eax]
// 0054c35e  2bc1                 sub eax, ecx
// 0054c360  85c0                 test eax, eax
// 0054c362  7e0f                 jle 0x54c373
// 0054c364  50                   push eax
// 0054c365  51                   push ecx
// 0054c366  8b4e48               mov ecx, dword ptr [esi + 0x48]
// 0054c369  51                   push ecx
// 0054c36a  83c640               add esi, 0x40
// 0054c36d  56                   push esi
// 0054c36e  e8cdf3ffff           call 0x54b740
// 0054c373  8b4624               mov eax, dword ptr [esi + 0x24]
// 0054c376  8b00                 mov eax, dword ptr [eax]
// 0054c378  8d0c10               lea ecx, [eax + edx]
// 0054c37b  3bc1                 cmp eax, ecx
// 0054c37d  7508                 jne 0x54c387
// 0054c37f  5e                   pop esi
// 0054c380  83c8ff               or eax, 0xffffffff
// 0054c383  5b                   pop ebx
// 0054c384  c20400               ret 4
// 0054c387  8b5624               mov edx, dword ptr [esi + 0x24]
// 0054c38a  8b02                 mov eax, dword ptr [edx]
// 0054c38c  8818                 mov byte ptr [eax], bl
// 0054c38e  8b4634               mov eax, dword ptr [esi + 0x34]
// 0054c391  8300ff               add dword ptr [eax], -1
// 0054c394  8b7624               mov esi, dword ptr [esi + 0x24]
// 0054c397  830601               add dword ptr [esi], 1
// 0054c39a  5e                   pop esi
// 0054c39b  8bc3                 mov eax, ebx
// 0054c39d  5b                   pop ebx
// 0054c39e  c20400               ret 4
// 0054c3a1  8b5648               mov edx, dword ptr [esi + 0x48]
// 0054c3a4  6a01                 push 1
// 0054c3a6  8d4c2410             lea ecx, [esp + 0x10]
// 0054c3aa  51                   push ecx
// 0054c3ab  52                   push edx
// 0054c3ac  83c640               add esi, 0x40
// 0054c3af  56                   push esi
// 0054c3b0  e88bf3ffff           call 0x54b740
// 0054c3b5  5e                   pop esi
// 0054c3b6  33c0                 xor eax, eax
// 0054c3b8  5b                   pop ebx
// 0054c3b9  c20400               ret 4
// copied from an identical function in another client (function ?overflow@?$indirect_streambuf@V?$reference_wrapper@V?$basic_istream@DU?$char_traits@D@std@@@std@@@boost@@U?$char_traits@D@std@@V?$allocator@D@4@Uinput_seekable@iostreams@2@@detail@iostreams@boost@@MAEHH@Z)

// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_34_1-dll roc_boost_resume_389d0bd197ae56e1.cpp