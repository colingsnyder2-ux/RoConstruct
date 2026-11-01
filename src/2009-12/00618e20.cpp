// from server: 100% by auto
// roc 2009-12 00618e20  unit: seg_00610000  size: 436 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00618e20
//
// 00618e20  53                   push ebx
// 00618e21  55                   push ebp
// 00618e22  56                   push esi
// 00618e23  8b742410             mov esi, dword ptr [esp + 0x10]
// 00618e27  f6466801             test byte ptr [esi + 0x68], 1
// 00618e2b  57                   push edi
// 00618e2c  750e                 jne 0x618e3c
// 00618e2e  68349c9c00           push 0x9c9c34
// 00618e33  56                   push esi
// 00618e34  e85773ffff           call 0x610190
// 00618e39  83c408               add esp, 8
// 00618e3c  8b4668               mov eax, dword ptr [esi + 0x68]
// 00618e3f  a804                 test al, 4
// 00618e41  7406                 je 0x618e49
// 00618e43  83c808               or eax, 8
// 00618e46  894668               mov dword ptr [esi + 0x68], eax
// 00618e49  8b8688020000         mov eax, dword ptr [esi + 0x288]
// 00618e4f  50                   push eax
// 00618e50  56                   push esi
// 00618e51  e88a7effff           call 0x610ce0
// 00618e56  8b6c2424             mov ebp, dword ptr [esp + 0x24]
// 00618e5a  8d4d01               lea ecx, [ebp + 1]
// 00618e5d  51                   push ecx
// 00618e5e  56                   push esi
// 00618e5f  e8ac7effff           call 0x610d10
// 00618e64  8bf8                 mov edi, eax
// 00618e66  33db                 xor ebx, ebx
// 00618e68  83c410               add esp, 0x10
// 00618e6b  89be88020000         mov dword ptr [esi + 0x288], edi
// 00618e71  3bfb                 cmp edi, ebx
// 00618e73  7513                 jne 0x618e88
// 00618e75  680c9c9c00           push 0x9c9c0c
// 00618e7a  56                   push esi
// 00618e7b  e8c073ffff           call 0x610240
// 00618e80  83c408               add esp, 8
// 00618e83  5f                   pop edi
// 00618e84  5e                   pop esi
// 00618e85  5d                   pop ebp
// 00618e86  5b                   pop ebx
// 00618e87  c3                   ret 
// 00618e88  55                   push ebp
// 00618e89  57                   push edi
// 00618e8a  56                   push esi
// 00618e8b  e8001cffff           call 0x60aa90
// 00618e90  55                   push ebp
// 00618e91  57                   push edi
// 00618e92  56                   push esi
// 00618e93  e8d8a7feff           call 0x603670
// 00618e98  53                   push ebx
// 00618e99  56                   push esi
// 00618e9a  e851ddffff           call 0x616bf0
// 00618e9f  83c420               add esp, 0x20
// 00618ea2  85c0                 test eax, eax
// 00618ea4  741b                 je 0x618ec1
// 00618ea6  8b9688020000         mov edx, dword ptr [esi + 0x288]
// 00618eac  52                   push edx
// 00618ead  56                   push esi
// 00618eae  e82d7effff           call 0x610ce0
// 00618eb3  83c408               add esp, 8
// 00618eb6  5f                   pop edi
// 00618eb7  899e88020000         mov dword ptr [esi + 0x288], ebx
// 00618ebd  5e                   pop esi
// 00618ebe  5d                   pop ebp
// 00618ebf  5b                   pop ebx
// 00618ec0  c3                   ret 
// 00618ec1  8b8688020000         mov eax, dword ptr [esi + 0x288]
// 00618ec7  881c28               mov byte ptr [eax + ebp], bl
// 00618eca  8b8688020000         mov eax, dword ptr [esi + 0x288]
// 00618ed0  8bf8                 mov edi, eax
// 00618ed2  381f                 cmp byte ptr [edi], bl
// 00618ed4  7405                 je 0x618edb
// 00618ed6  47                   inc edi
// 00618ed7  381f                 cmp byte ptr [edi], bl
// 00618ed9  75fb                 jne 0x618ed6
// 00618edb  8d4c28fe             lea ecx, [eax + ebp - 2]
// 00618edf  3bf9                 cmp edi, ecx
// 00618ee1  7226                 jb 0x618f09
// 00618ee3  68f49b9c00           push 0x9c9bf4
// 00618ee8  56                   push esi
// 00618ee9  e85273ffff           call 0x610240
// 00618eee  8b9688020000         mov edx, dword ptr [esi + 0x288]
// 00618ef4  52                   push edx
// 00618ef5  56                   push esi
// 00618ef6  e8e57dffff           call 0x610ce0
// 00618efb  83c410               add esp, 0x10
// 00618efe  5f                   pop edi
// 00618eff  899e88020000         mov dword ptr [esi + 0x288], ebx
// 00618f05  5e                   pop esi
// 00618f06  5d                   pop ebp
// 00618f07  5b                   pop ebx
// 00618f08  c3                   ret 
// 00618f09  0fbe5f01             movsx ebx, byte ptr [edi + 1]
// 00618f0d  47                   inc edi
// 00618f0e  85db                 test ebx, ebx
// 00618f10  7410                 je 0x618f22
// 00618f12  68cc9b9c00           push 0x9c9bcc
// 00618f17  56                   push esi
// 00618f18  e82373ffff           call 0x610240
// 00618f1d  83c408               add esp, 8
// 00618f20  33db                 xor ebx, ebx
// 00618f22  2bbe88020000         sub edi, dword ptr [esi + 0x288]
// 00618f28  8d442414             lea eax, [esp + 0x14]
// 00618f2c  50                   push eax
// 00618f2d  47                   inc edi
// 00618f2e  57                   push edi
// 00618f2f  55                   push ebp
// 00618f30  53                   push ebx
// 00618f31  56                   push esi
// 00618f32  e809ccffff           call 0x615b40
// 00618f37  6a10                 push 0x10
// 00618f39  56                   push esi
// 00618f3a  e8d17dffff           call 0x610d10
// 00618f3f  8be8                 mov ebp, eax
// 00618f41  83c41c               add esp, 0x1c
// 00618f44  85ed                 test ebp, ebp
// 00618f46  7526                 jne 0x618f6e
// 00618f48  68a09b9c00           push 0x9c9ba0
// 00618f4d  56                   push esi
// 00618f4e  e8ed72ffff           call 0x610240
// 00618f53  8b8e88020000         mov ecx, dword ptr [esi + 0x288]
// 00618f59  51                   push ecx
// 00618f5a  56                   push esi
// 00618f5b  e8807dffff           call 0x610ce0
// 00618f60  83c410               add esp, 0x10
// 00618f63  5f                   pop edi
// 00618f64  89ae88020000         mov dword ptr [esi + 0x288], ebp
// 00618f6a  5e                   pop esi
// 00618f6b  5d                   pop ebp
// 00618f6c  5b                   pop ebx
// 00618f6d  c3                   ret 
// 00618f6e  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00618f72  895d00               mov dword ptr [ebp], ebx
// 00618f75  8b9688020000         mov edx, dword ptr [esi + 0x288]
// 00618f7b  6a01                 push 1
// 00618f7d  895504               mov dword ptr [ebp + 4], edx
// 00618f80  8b8688020000         mov eax, dword ptr [esi + 0x288]
// 00618f86  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 00618f8a  55                   push ebp
// 00618f8b  52                   push edx
// 00618f8c  03c7                 add eax, edi
// 00618f8e  56                   push esi
// 00618f8f  894508               mov dword ptr [ebp + 8], eax
// 00618f92  894d0c               mov dword ptr [ebp + 0xc], ecx
// 00618f95  e8269efeff           call 0x602dc0
// 00618f9a  55                   push ebp
// 00618f9b  56                   push esi
// 00618f9c  8bf8                 mov edi, eax
// 00618f9e  e83d7dffff           call 0x610ce0
// 00618fa3  8b8688020000         mov eax, dword ptr [esi + 0x288]
// 00618fa9  50                   push eax
// 00618faa  56                   push esi
// 00618fab  e8307dffff           call 0x610ce0
// 00618fb0  83c420               add esp, 0x20
// 00618fb3  c7868802000000000000 mov dword ptr [esi + 0x288], 0
// 00618fbd  85ff                 test edi, edi
// 00618fbf  740e                 je 0x618fcf
// 00618fc1  68749b9c00           push 0x9c9b74
// 00618fc6  56                   push esi
// 00618fc7  e8c471ffff           call 0x610190
// 00618fcc  83c408               add esp, 8
// 00618fcf  5f                   pop edi
// 00618fd0  5e                   pop esi
// 00618fd1  5d                   pop ebp
// 00618fd2  5b                   pop ebx
// 00618fd3  c3                   ret 
// library libpng-1.2.32/pngrutil.c (function _png_handle_zTXt)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.32 pngrutil.c
