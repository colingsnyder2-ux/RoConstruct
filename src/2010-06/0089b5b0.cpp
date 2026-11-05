// from server: 100% by auto
// roc 2010-06 0089b5b0  unit: CXTPScrollBase  size: 106 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0089b5b0
//
// 0089b5b0  53                   push ebx
// 0089b5b1  56                   push esi
// 0089b5b2  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0089b5b6  8b4634               mov eax, dword ptr [esi + 0x34]
// 0089b5b9  83785800             cmp dword ptr [eax + 0x58], 0
// 0089b5bd  57                   push edi
// 0089b5be  8d7e04               lea edi, [esi + 4]
// 0089b5c1  8bdf                 mov ebx, edi
// 0089b5c3  740d                 je 0x89b5d2
// 0089b5c5  6a09                 push 9
// 0089b5c7  ff156cba9e00         call dword ptr [0x9eba6c]
// 0089b5cd  83c704               add edi, 4
// 0089b5d0  eb0b                 jmp 0x89b5dd
// 0089b5d2  6a0a                 push 0xa
// 0089b5d4  ff156cba9e00         call dword ptr [0x9eba6c]
// 0089b5da  8d5f04               lea ebx, [edi + 4]
// 0089b5dd  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 0089b5e0  8b5118               mov edx, dword ptr [ecx + 0x18]
// 0089b5e3  8b491c               mov ecx, dword ptr [ecx + 0x1c]
// 0089b5e6  2bca                 sub ecx, edx
// 0089b5e8  03c9                 add ecx, ecx
// 0089b5ea  03c9                 add ecx, ecx
// 0089b5ec  03c9                 add ecx, ecx
// 0089b5ee  2bd1                 sub edx, ecx
// 0089b5f0  8913                 mov dword ptr [ebx], edx
// 0089b5f2  8b5634               mov edx, dword ptr [esi + 0x34]
// 0089b5f5  8b5210               mov edx, dword ptr [edx + 0x10]
// 0089b5f8  03c0                 add eax, eax
// 0089b5fa  2bd0                 sub edx, eax
// 0089b5fc  8917                 mov dword ptr [edi], edx
// 0089b5fe  8b5634               mov edx, dword ptr [esi + 0x34]
// 0089b601  8b521c               mov edx, dword ptr [edx + 0x1c]
// 0089b604  03d1                 add edx, ecx
// 0089b606  895308               mov dword ptr [ebx + 8], edx
// 0089b609  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 0089b60c  8b5114               mov edx, dword ptr [ecx + 0x14]
// 0089b60f  03d0                 add edx, eax
// 0089b611  895708               mov dword ptr [edi + 8], edx
// 0089b614  5f                   pop edi
// 0089b615  5e                   pop esi
// 0089b616  5b                   pop ebx
// 0089b617  c20400               ret 4
// library xtp-13.2.1/Source\CommandBars\XTPScrollBase.cpp (function ?CalcTrackDragRect@CXTPScrollBase@@IBEXPAUSCROLLBARTRACKINFO@1@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPScrollBase.cpp
