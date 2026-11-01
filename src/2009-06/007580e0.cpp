// from server: 100% by auto
// roc 2009-06 007580e0  unit: CXTTreeBase  size: 179 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007580e0
//
// 007580e0  83ec10               sub esp, 0x10
// 007580e3  56                   push esi
// 007580e4  8bf1                 mov esi, ecx
// 007580e6  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 007580e9  e8ee3d0f00           call 0x84bedc
// 007580ee  a900020000           test eax, 0x200
// 007580f3  0f848b000000         je 0x758184
// 007580f9  837c241855           cmp dword ptr [esp + 0x18], 0x55
// 007580fe  0f8580000000         jne 0x758184
// 00758104  837e1400             cmp dword ptr [esi + 0x14], 0
// 00758108  7464                 je 0x75816e
// 0075810a  53                   push ebx
// 0075810b  57                   push edi
// 0075810c  ff15a4ee8900         call dword ptr [0x89eea4]
// 00758112  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 00758115  8b5120               mov edx, dword ptr [ecx + 0x20]
// 00758118  0fbff8               movsx edi, ax
// 0075811b  c1e810               shr eax, 0x10
// 0075811e  0fbfd8               movsx ebx, ax
// 00758121  8d44240c             lea eax, [esp + 0xc]
// 00758125  50                   push eax
// 00758126  52                   push edx
// 00758127  ff15f4ed8900         call dword ptr [0x89edf4]
// 0075812d  53                   push ebx
// 0075812e  57                   push edi
// 0075812f  8d442414             lea eax, [esp + 0x14]
// 00758133  50                   push eax
// 00758134  ff15c0ed8900         call dword ptr [0x89edc0]
// 0075813a  5f                   pop edi
// 0075813b  5b                   pop ebx
// 0075813c  85c0                 test eax, eax
// 0075813e  754c                 jne 0x75818c
// 00758140  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 00758143  8b5120               mov edx, dword ptr [ecx + 0x20]
// 00758146  6a55                 push 0x55
// 00758148  52                   push edx
// 00758149  ff1584ee8900         call dword ptr [0x89ee84]
// 0075814f  8b4634               mov eax, dword ptr [esi + 0x34]
// 00758152  6a00                 push 0
// 00758154  c7461400000000       mov dword ptr [esi + 0x14], 0
// 0075815b  8b4820               mov ecx, dword ptr [eax + 0x20]
// 0075815e  6a00                 push 0
// 00758160  51                   push ecx
// 00758161  ff157cee8900         call dword ptr [0x89ee7c]
// 00758167  5e                   pop esi
// 00758168  83c410               add esp, 0x10
// 0075816b  c20400               ret 4
// 0075816e  8b5634               mov edx, dword ptr [esi + 0x34]
// 00758171  8b4220               mov eax, dword ptr [edx + 0x20]
// 00758174  6a55                 push 0x55
// 00758176  50                   push eax
// 00758177  ff1584ee8900         call dword ptr [0x89ee84]
// 0075817d  5e                   pop esi
// 0075817e  83c410               add esp, 0x10
// 00758181  c20400               ret 4
// 00758184  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 00758187  e87c0efcff           call 0x719008
// 0075818c  5e                   pop esi
// 0075818d  83c410               add esp, 0x10
// 00758190  c20400               ret 4
// library xtp-15.2.1/Source\Controls\Tree\XTPTreeBase.cpp (function ?OnTimer@CXTPTreeBase@@IAEXI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Controls/Tree/XTPTreeBase.cpp
