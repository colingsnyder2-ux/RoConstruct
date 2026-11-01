// from server: 100% by auto
// roc 2009-06 008105b0  unit: CXTPScrollBase  size: 106 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 008105b0
//
// 008105b0  53                   push ebx
// 008105b1  56                   push esi
// 008105b2  8b74240c             mov esi, dword ptr [esp + 0xc]
// 008105b6  8b4634               mov eax, dword ptr [esi + 0x34]
// 008105b9  83785800             cmp dword ptr [eax + 0x58], 0
// 008105bd  57                   push edi
// 008105be  8d7e04               lea edi, [esi + 4]
// 008105c1  8bdf                 mov ebx, edi
// 008105c3  740d                 je 0x8105d2
// 008105c5  6a09                 push 9
// 008105c7  ff15dced8900         call dword ptr [0x89eddc]
// 008105cd  83c704               add edi, 4
// 008105d0  eb0b                 jmp 0x8105dd
// 008105d2  6a0a                 push 0xa
// 008105d4  ff15dced8900         call dword ptr [0x89eddc]
// 008105da  8d5f04               lea ebx, [edi + 4]
// 008105dd  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 008105e0  8b5118               mov edx, dword ptr [ecx + 0x18]
// 008105e3  8b491c               mov ecx, dword ptr [ecx + 0x1c]
// 008105e6  2bca                 sub ecx, edx
// 008105e8  03c9                 add ecx, ecx
// 008105ea  03c9                 add ecx, ecx
// 008105ec  03c9                 add ecx, ecx
// 008105ee  2bd1                 sub edx, ecx
// 008105f0  8913                 mov dword ptr [ebx], edx
// 008105f2  8b5634               mov edx, dword ptr [esi + 0x34]
// 008105f5  8b5210               mov edx, dword ptr [edx + 0x10]
// 008105f8  03c0                 add eax, eax
// 008105fa  2bd0                 sub edx, eax
// 008105fc  8917                 mov dword ptr [edi], edx
// 008105fe  8b5634               mov edx, dword ptr [esi + 0x34]
// 00810601  8b521c               mov edx, dword ptr [edx + 0x1c]
// 00810604  03d1                 add edx, ecx
// 00810606  895308               mov dword ptr [ebx + 8], edx
// 00810609  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 0081060c  8b5114               mov edx, dword ptr [ecx + 0x14]
// 0081060f  03d0                 add edx, eax
// 00810611  895708               mov dword ptr [edi + 8], edx
// 00810614  5f                   pop edi
// 00810615  5e                   pop esi
// 00810616  5b                   pop ebx
// 00810617  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPScrollBase.cpp (function ?CalcTrackDragRect@CXTPScrollBase@@IBEXPAUSCROLLBARTRACKINFO@1@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPScrollBase.cpp
