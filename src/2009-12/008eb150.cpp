// from server: 100% by auto
// roc 2009-12 008eb150  unit: CXTPScrollBase  size: 106 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008eb150
//
// 008eb150  53                   push ebx
// 008eb151  56                   push esi
// 008eb152  8b74240c             mov esi, dword ptr [esp + 0xc]
// 008eb156  8b4634               mov eax, dword ptr [esi + 0x34]
// 008eb159  83785800             cmp dword ptr [eax + 0x58], 0
// 008eb15d  57                   push edi
// 008eb15e  8d7e04               lea edi, [esi + 4]
// 008eb161  8bdf                 mov ebx, edi
// 008eb163  740d                 je 0x8eb172
// 008eb165  6a09                 push 9
// 008eb167  ff15dccb9800         call dword ptr [0x98cbdc]
// 008eb16d  83c704               add edi, 4
// 008eb170  eb0b                 jmp 0x8eb17d
// 008eb172  6a0a                 push 0xa
// 008eb174  ff15dccb9800         call dword ptr [0x98cbdc]
// 008eb17a  8d5f04               lea ebx, [edi + 4]
// 008eb17d  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 008eb180  8b5118               mov edx, dword ptr [ecx + 0x18]
// 008eb183  8b491c               mov ecx, dword ptr [ecx + 0x1c]
// 008eb186  2bca                 sub ecx, edx
// 008eb188  03c9                 add ecx, ecx
// 008eb18a  03c9                 add ecx, ecx
// 008eb18c  03c9                 add ecx, ecx
// 008eb18e  2bd1                 sub edx, ecx
// 008eb190  8913                 mov dword ptr [ebx], edx
// 008eb192  8b5634               mov edx, dword ptr [esi + 0x34]
// 008eb195  8b5210               mov edx, dword ptr [edx + 0x10]
// 008eb198  03c0                 add eax, eax
// 008eb19a  2bd0                 sub edx, eax
// 008eb19c  8917                 mov dword ptr [edi], edx
// 008eb19e  8b5634               mov edx, dword ptr [esi + 0x34]
// 008eb1a1  8b521c               mov edx, dword ptr [edx + 0x1c]
// 008eb1a4  03d1                 add edx, ecx
// 008eb1a6  895308               mov dword ptr [ebx + 8], edx
// 008eb1a9  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 008eb1ac  8b5114               mov edx, dword ptr [ecx + 0x14]
// 008eb1af  03d0                 add edx, eax
// 008eb1b1  895708               mov dword ptr [edi + 8], edx
// 008eb1b4  5f                   pop edi
// 008eb1b5  5e                   pop esi
// 008eb1b6  5b                   pop ebx
// 008eb1b7  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPScrollBase.cpp (function ?CalcTrackDragRect@CXTPScrollBase@@IBEXPAUSCROLLBARTRACKINFO@1@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPScrollBase.cpp
