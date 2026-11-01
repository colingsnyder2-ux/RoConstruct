// from server: 100% by auto
// roc 2009-12 00832f60  unit: CXTTreeBase  size: 179 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00832f60
//
// 00832f60  83ec10               sub esp, 0x10
// 00832f63  56                   push esi
// 00832f64  8bf1                 mov esi, ecx
// 00832f66  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 00832f69  e804350f00           call 0x926472
// 00832f6e  a900020000           test eax, 0x200
// 00832f73  0f848b000000         je 0x833004
// 00832f79  837c241855           cmp dword ptr [esp + 0x18], 0x55
// 00832f7e  0f8580000000         jne 0x833004
// 00832f84  837e1400             cmp dword ptr [esi + 0x14], 0
// 00832f88  7464                 je 0x832fee
// 00832f8a  53                   push ebx
// 00832f8b  57                   push edi
// 00832f8c  ff1534cb9800         call dword ptr [0x98cb34]
// 00832f92  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 00832f95  8b5120               mov edx, dword ptr [ecx + 0x20]
// 00832f98  0fbff8               movsx edi, ax
// 00832f9b  c1e810               shr eax, 0x10
// 00832f9e  0fbfd8               movsx ebx, ax
// 00832fa1  8d44240c             lea eax, [esp + 0xc]
// 00832fa5  50                   push eax
// 00832fa6  52                   push edx
// 00832fa7  ff1570cc9800         call dword ptr [0x98cc70]
// 00832fad  53                   push ebx
// 00832fae  57                   push edi
// 00832faf  8d442414             lea eax, [esp + 0x14]
// 00832fb3  50                   push eax
// 00832fb4  ff155cca9800         call dword ptr [0x98ca5c]
// 00832fba  5f                   pop edi
// 00832fbb  5b                   pop ebx
// 00832fbc  85c0                 test eax, eax
// 00832fbe  754c                 jne 0x83300c
// 00832fc0  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 00832fc3  8b5120               mov edx, dword ptr [ecx + 0x20]
// 00832fc6  6a55                 push 0x55
// 00832fc8  52                   push edx
// 00832fc9  ff15d0cb9800         call dword ptr [0x98cbd0]
// 00832fcf  8b4634               mov eax, dword ptr [esi + 0x34]
// 00832fd2  6a00                 push 0
// 00832fd4  c7461400000000       mov dword ptr [esi + 0x14], 0
// 00832fdb  8b4820               mov ecx, dword ptr [eax + 0x20]
// 00832fde  6a00                 push 0
// 00832fe0  51                   push ecx
// 00832fe1  ff15e8cb9800         call dword ptr [0x98cbe8]
// 00832fe7  5e                   pop esi
// 00832fe8  83c410               add esp, 0x10
// 00832feb  c20400               ret 4
// 00832fee  8b5634               mov edx, dword ptr [esi + 0x34]
// 00832ff1  8b4220               mov eax, dword ptr [edx + 0x20]
// 00832ff4  6a55                 push 0x55
// 00832ff6  50                   push eax
// 00832ff7  ff15d0cb9800         call dword ptr [0x98cbd0]
// 00832ffd  5e                   pop esi
// 00832ffe  83c410               add esp, 0x10
// 00833001  c20400               ret 4
// 00833004  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 00833007  e8240efcff           call 0x7f3e30
// 0083300c  5e                   pop esi
// 0083300d  83c410               add esp, 0x10
// 00833010  c20400               ret 4
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ?OnTimer@CXTPTreeBase@@IAEXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
