// from server: 100% by auto
// roc 2010-06 00844e30  unit: CXTPDockContext  size: 408 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00844e30
//
// 00844e30  83ec20               sub esp, 0x20
// 00844e33  53                   push ebx
// 00844e34  55                   push ebp
// 00844e35  56                   push esi
// 00844e36  57                   push edi
// 00844e37  8b3d84bc9e00         mov edi, dword ptr [0x9ebc84]
// 00844e3d  8bf1                 mov esi, ecx
// 00844e3f  ffd7                 call edi
// 00844e41  85c0                 test eax, eax
// 00844e43  0f8577010000         jne 0x844fc0
// 00844e49  8b4604               mov eax, dword ptr [esi + 4]
// 00844e4c  8b4020               mov eax, dword ptr [eax + 0x20]
// 00844e4f  50                   push eax
// 00844e50  ff1580bc9e00         call dword ptr [0x9ebc80]
// 00844e56  50                   push eax
// 00844e57  e80e2ef6ff           call 0x7a7c6a
// 00844e5c  8b4e04               mov ecx, dword ptr [esi + 4]
// 00844e5f  e86c37f7ff           call 0x7b85d0
// 00844e64  89442410             mov dword ptr [esp + 0x10], eax
// 00844e68  85c0                 test eax, eax
// 00844e6a  0f8450010000         je 0x844fc0
// 00844e70  33db                 xor ebx, ebx
// 00844e72  33ed                 xor ebp, ebp
// 00844e74  ffd7                 call edi
// 00844e76  50                   push eax
// 00844e77  e8ee2df6ff           call 0x7a7c6a
// 00844e7c  3b4604               cmp eax, dword ptr [esi + 4]
// 00844e7f  0f8527010000         jne 0x844fac
// 00844e85  8b3d88bc9e00         mov edi, dword ptr [0x9ebc88]
// 00844e8b  eb03                 jmp 0x844e90
// 00844e8d  8d4900               lea ecx, [ecx]
// 00844e90  6a00                 push 0
// 00844e92  6a0f                 push 0xf
// 00844e94  6a0f                 push 0xf
// 00844e96  6a00                 push 0
// 00844e98  8d4c2424             lea ecx, [esp + 0x24]
// 00844e9c  51                   push ecx
// 00844e9d  ffd7                 call edi
// 00844e9f  85c0                 test eax, eax
// 00844ea1  7433                 je 0x844ed6
// 00844ea3  6a0f                 push 0xf
// 00844ea5  6a0f                 push 0xf
// 00844ea7  6a00                 push 0
// 00844ea9  8d542420             lea edx, [esp + 0x20]
// 00844ead  52                   push edx
// 00844eae  ff15f0bb9e00         call dword ptr [0x9ebbf0]
// 00844eb4  85c0                 test eax, eax
// 00844eb6  741e                 je 0x844ed6
// 00844eb8  8d442414             lea eax, [esp + 0x14]
// 00844ebc  50                   push eax
// 00844ebd  ff1508bc9e00         call dword ptr [0x9ebc08]
// 00844ec3  6a00                 push 0
// 00844ec5  6a0f                 push 0xf
// 00844ec7  6a0f                 push 0xf
// 00844ec9  6a00                 push 0
// 00844ecb  8d4c2424             lea ecx, [esp + 0x24]
// 00844ecf  51                   push ecx
// 00844ed0  ffd7                 call edi
// 00844ed2  85c0                 test eax, eax
// 00844ed4  75cd                 jne 0x844ea3
// 00844ed6  6a00                 push 0
// 00844ed8  6a00                 push 0
// 00844eda  6a00                 push 0
// 00844edc  8d542420             lea edx, [esp + 0x20]
// 00844ee0  52                   push edx
// 00844ee1  ff15f0bb9e00         call dword ptr [0x9ebbf0]
// 00844ee7  85c0                 test eax, eax
// 00844ee9  0f84b3000000         je 0x844fa2
// 00844eef  8b442418             mov eax, dword ptr [esp + 0x18]
// 00844ef3  3d02020000           cmp eax, 0x202
// 00844ef8  0f84ae000000         je 0x844fac
// 00844efe  3d00020000           cmp eax, 0x200
// 00844f03  7562                 jne 0x844f67
// 00844f05  8b442428             mov eax, dword ptr [esp + 0x28]
// 00844f09  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 00844f0d  3bd8                 cmp ebx, eax
// 00844f0f  7504                 jne 0x844f15
// 00844f11  3be9                 cmp ebp, ecx
// 00844f13  7462                 je 0x844f77
// 00844f15  837e0801             cmp dword ptr [esi + 8], 1
// 00844f19  8bd8                 mov ebx, eax
// 00844f1b  8be9                 mov ebp, ecx
// 00844f1d  7515                 jne 0x844f34
// 00844f1f  8bd0                 mov edx, eax
// 00844f21  83ec08               sub esp, 8
// 00844f24  8bc4                 mov eax, esp
// 00844f26  894804               mov dword ptr [eax + 4], ecx
// 00844f29  8bce                 mov ecx, esi
// 00844f2b  8910                 mov dword ptr [eax], edx
// 00844f2d  e8def7ffff           call 0x844710
// 00844f32  eb4e                 jmp 0x844f82
// 00844f34  8b4e04               mov ecx, dword ptr [esi + 4]
// 00844f37  8b01                 mov eax, dword ptr [ecx]
// 00844f39  8b9098010000         mov edx, dword ptr [eax + 0x198]
// 00844f3f  ffd2                 call edx
// 00844f41  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00844f45  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 00844f49  83ec08               sub esp, 8
// 00844f4c  85c0                 test eax, eax
// 00844f4e  8bc4                 mov eax, esp
// 00844f50  8908                 mov dword ptr [eax], ecx
// 00844f52  895004               mov dword ptr [eax + 4], edx
// 00844f55  8bce                 mov ecx, esi
// 00844f57  7407                 je 0x844f60
// 00844f59  e862f9ffff           call 0x8448c0
// 00844f5e  eb22                 jmp 0x844f82
// 00844f60  e87bfaffff           call 0x8449e0
// 00844f65  eb1b                 jmp 0x844f82
// 00844f67  3d00010000           cmp eax, 0x100
// 00844f6c  7509                 jne 0x844f77
// 00844f6e  837c241c1b           cmp dword ptr [esp + 0x1c], 0x1b
// 00844f73  7437                 je 0x844fac
// 00844f75  eb0b                 jmp 0x844f82
// 00844f77  8d442414             lea eax, [esp + 0x14]
// 00844f7b  50                   push eax
// 00844f7c  ff1508bc9e00         call dword ptr [0x9ebc08]
// 00844f82  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00844f86  e8e531f8ff           call 0x7c8170
// 00844f8b  ff1584bc9e00         call dword ptr [0x9ebc84]
// 00844f91  50                   push eax
// 00844f92  e8d32cf6ff           call 0x7a7c6a
// 00844f97  3b4604               cmp eax, dword ptr [esi + 4]
// 00844f9a  0f84f0feffff         je 0x844e90
// 00844fa0  eb0a                 jmp 0x844fac
// 00844fa2  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00844fa6  51                   push ecx
// 00844fa7  e8d6821300           call 0x97d282
// 00844fac  ff158cbc9e00         call dword ptr [0x9ebc8c]
// 00844fb2  8b542410             mov edx, dword ptr [esp + 0x10]
// 00844fb6  8b4274               mov eax, dword ptr [edx + 0x74]
// 00844fb9  c7404c01000000       mov dword ptr [eax + 0x4c], 1
// 00844fc0  5f                   pop edi
// 00844fc1  5e                   pop esi
// 00844fc2  5d                   pop ebp
// 00844fc3  5b                   pop ebx
// 00844fc4  83c420               add esp, 0x20
// 00844fc7  c3                   ret 
// library xtp-13.2.1-shared-mfc/Source\CommandBars\XTPDockContext.cpp (function ?Track@CXTPDockContext@@MAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/CommandBars/XTPDockContext.cpp
